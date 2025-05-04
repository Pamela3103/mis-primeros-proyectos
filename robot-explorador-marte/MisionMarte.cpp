
#include<iostream>
#include<conio.h>
#include<vector>

using namespace std;
using namespace System;

#include "gamejam.h"
#define ANCHO 120
#define ALTO 40

#define ARRIBA 72
#define ABAJO 80
#define DERECHA 77
#define IZQUIERDA 75

int main()
{
	Console::SetWindowSize(ANCHO, ALTO);
	srand(time(NULL));
	Console::CursorVisible = false;

	//PARTE 1 - MENU
	Presentacion();
	//PARTE 2 - LLENDO A MARTE
	int xN = 2, vxN = 1;
	int yN = 1, vyN = 1;
	int xM = ANCHO - 18;
	int yM = 10;
	
	PresentacionJuego();
	DibujarNave(xN, yN);
	DibujarMarte(xM, yM);
	DibujarEstrellas(0, 0);

	Console::ForegroundColor = ConsoleColor::White;
	setXY(ANCHO / 2 - 5, ALTO - 2); cout << "De camino a Marte...";
	while (true)
	{
		if (xN < ANCHO - 25)
		{
			NaveMarte(xN, yN, vxN, vyN);
		}
		if (xN == ANCHO - 27)
		{
			Console::Clear();
			break;
		}

		_sleep(100);
	}
	
	//PARTE 3-ADVERTENCIA DE METEORITOS
	
	int numParpadeos = 6;
	ParpadearWarning(22, 7, numParpadeos);
	Console::Clear();
	AlertaMeteoritos(5, 10);
	_sleep(2400);
	Console::Clear();
	
	//PARTE 4 - METEOROS
	
	int N = Aleatorio(1,2);
	float* arrX = new float[N];
	float* arrY = new float[N];
	int* arrColor = new int[N];
	float* arrVx = new float[N];
	float* arrVy = new float[N];

	float vel;
	do {
		vel = AleatorioDec();
	} while (!(vel>0.00005 && vel<0.7));
	

	GenerarMeteoros(N, arrColor, arrX, arrY, arrVx, arrVy,vel);

	 xN = 1;
	 yN = ALTO - 7;

	vxN = 2;
	vyN = 1;
	char tecla;
	bool activo = false;
	bool roverColisionado = false;
	int colisiones = 0;
	int vidas = 3;

	//METEORITO ESTATICO (2)
	int x1, x2;
	int y1, y2;
	int color1, color2;

	x1 = Aleatorio(2, 90); y1 = Aleatorio(2, 25); color1 = Aleatorio(2, 15);
	x2 = Aleatorio(2, 90); y2 = Aleatorio(2, 25); color2 = Aleatorio(2, 15);

	DibujarMeteorito(x1, y1, color1);
	DibujarMeteorito(x2, y2, color2);
	DibujarNave(xN, yN);

	while (!roverColisionado)
	{
		if (_kbhit())
		{
			tecla = _getch();
			switch (tecla)
			{
			case IZQUIERDA: vxN = -1; vyN = 0; activo = true; break;
			case DERECHA: vxN = 1; vyN = 0; activo = true; break;
			case ARRIBA: vyN = -1; vxN = 0; activo = true; break;
			case ABAJO: vyN = 1;  vxN = 0; activo = true; break;
			}
		}
		if (activo)
		{
			DibujarMeteorito(x1, y1, color1);
			DibujarMeteorito(x2, y2, color2);
			MoverNave(xN, yN, vxN, vyN);
			Meteoritos(N, arrColor, arrX, arrY, arrVx, arrVy); _sleep(75);
		}
		
		
		
		setXY(10, 0); setColor(5); cout << "Velocidad Meteorito: " << vel;
		setXY(45, 0); setColor(5); cout << "Meteoritos Estaticos: 2";
		setXY(75, 0); setColor(5); cout << "Meteoritos en Movimiento: " << N;

		for (int i = 0; i < N; i++)
		{
			if (VerificarColision(xN, yN, 5, 5, arrX[i], arrY[i], 24, 8))
			{
				roverColisionado = true;
				break;
			}
		}
		
		if (xN+vxN>ANCHO-18)
			break;


	}
	if (roverColisionado)
	{
		Console::Clear();
		GameOver(); return 0;
	}
	//LIBERANDO MEMORIA

	if (arrX != NULL) delete[] arrX;
	if (arrY != NULL) delete[] arrY;
	if (arrColor != NULL) delete[] arrColor;
	if (arrVx != NULL) delete[] arrVx;
	if (arrVy != NULL) delete[] arrVy;



	//ATERRIZANDO
	//Volviendo a Inicializar
	xN = 5, yN = 10, vyN = 1;
	int xR = ANCHO / 2, yR = 16;
	Console::Clear();
	DibujarNave(xN, yN);
	setColor(15); setXY(50, 2); cout << "Aterrizando en Marte ...";
	while (true)
	{
		if (xN < ANCHO / 2 - 5)
		{
			NaveH(xN, yN, vxN);
		}
		if (yR < ALTO - 10 && xN == ANCHO / 2 - 5)
		{
			RoverV(xR, yR, vyN);
			setColor(15); setXY(ANCHO / 2 - 12, ALTO - 2); cout << "[Preparate para Recoger Muestras]";
		}
		if (yR == ALTO - 10)
		{
			if (xR < ANCHO - 13)
				RoverH(xR, yR, vxN);
		}
		if (xR == ANCHO - 13)
		{
			Console::Clear();
			break;
		}

		_sleep(100);
	}
	
	//PARTE 5 - MUESTRAS
	
	Console::Clear();
	xR = 1, yR = ALTO - 7;
	int vxR = 0; int vyR = 0;
	int numMuestras = Aleatorio(25, 50);

	vector<pair<int, int>> pxy;
	vector<bool> disponible(numMuestras, true);
	DibujarMuestras(numMuestras, 0, 0, pxy);
	int muestraRecolectada = 0;
	setColor(15); setXY(50, 2); cout << "Recogiendo Muestras ...";

	float tiempo = 100;
	float disTiempo;
	do {
		disTiempo = AleatorioDec();
	} while (!(disTiempo > 0.5));

	char tecla_Juego;
	bool transporteLlego = false;
	bool activo1 = false;

	DibujarRover(xR, yR);
	int anchoRover = 13, altoRover = 5;
	while (tiempo>0)
	{
		if (kbhit())
		{
			tecla_Juego = _getch();
			switch (tecla_Juego)
			{
			case ARRIBA:
				activo1 = true;
				vxR = 0;
				vyR = -1;
				break;
			case ABAJO:
				activo1 = true;
				vxR = 0;
				vyR = 1;
				break;
			case DERECHA:
				activo1 = true;
				vxR = 1;
				vyR = 0;
				break;
			case IZQUIERDA:
				activo1 = true;
				vxR = -1;
				vyR = 0;
				break;
			}
		}
		else {
			vxR = 0;
			vyR = 0;
		}
		DibujarEntorno(0, 20);
		DibujarEntorno2(ANCHO - 42, 20);
		setXY(10, 0); setColor(5); cout << "MUESTRAS TOTALES: " << numMuestras;
		if (tiempo > 10)
		{
			setXY(35, 0); setColor(5); cout << "TIEMPO: " << tiempo;
		}
		else
		{
			setXY(35, 0); setColor(14); cout << "TIEMPO: " << tiempo;
		}
		setXY(60, 0); setColor(5); cout << "MUESTRAS RECOLECTADAS: " << muestraRecolectada;
		if (activo1 && tiempo > 0)
		{
			MoverRoverManualmente(xR, yR, vxR, vyR);
			tiempo = tiempo - disTiempo;
		}
		//Verificar colisiones
		for (int i = 0; i < pxy.size(); i++) {
			int xMuestra = pxy[i].first, yMuestra = pxy[i].second;
			bool colisiona = xR < xMuestra + 1 &&
				xR + anchoRover > xMuestra &&
				yR < yMuestra + 1 &&
				yR + altoRover > yMuestra;

			if (colisiona && disponible[i]) {
				disponible[i] = false;
				muestraRecolectada++;
			}
		}
		_sleep(50);

	}
	_sleep(150);
	Console::Clear();
	PantallaTiempo();
	
	//Depositar Muestras
	PantallaDepositandoMuestras(muestraRecolectada);
	//PARTE 6 - TRANSPORTAR MUESTRAS
	int xC = 1; int yC = ALTO / 2;
	int vxC = 1; int vyC = 1;

	//TRANSPORTANDO MUESTRAS
	Console::Clear();
	DibujarEstrellas(0, 0);
	setColor(15); setXY(50, 2); cout << "Transportando Muestras ...";
	while (true)
	{
		Cohete(xC, yC, vxC);
		_sleep(100);

		if (xC == ANCHO - 13)
		{
			Console::Clear();
			break;
		}
	}
	//DEPOSITANDO MUESTRAS
	xC = 1; yC = ALTO / 2 - 5;
	vxC = 1;
	int xS = ANCHO - 50;
	int yS = ALTO / 2 - 10;
	DibujarEstrellas(0, 0);
	DibujarSatelite(xS, yS);
	setColor(15); setXY(50, 2); cout << "Transportando Muestras ...";
	while (true)
	{
		if (xC < ANCHO - 62)
		{
			Cohete(xC, yC, vxC);
		}
		else if (xC == ANCHO - 62)
		{
			setColor(15); setXY(50, 20); cout << "                                          ";
			setColor(15); setXY(50, 2); cout << "Depositando Muestras ...";
			BorrarCohete2(xC, yC);
			break;
		}
		_sleep(100);
	}
	_sleep(900);
	xC = 1; yC = ALTO / 2 - 5;
	vxC = 1;
	while (true)
	{
		setColor(15); setXY(50, 2); cout << "Procesando Muestras ...";
		if (xC < ANCHO - 62)
		{
			Traces(xC, yC, vxC);
		}
		else if (xC == ANCHO - 62)
		{
			break;
		}
		_sleep(160);
	}
	setColor(15); setXY(50, 2); cout << "Procesando Muestras ...";
	_sleep(1000);
	setColor(15); setXY(45, 2); cout << "Listo! Retornando muestras a la Tierra...";
	while (true)
	{
		_sleep(500);
		if (xS < ANCHO - 40)
		{
			Satelite(xS, yS, vxC);
		}
		if (xS == ANCHO - 40)
		{
			Console::Clear();
			break;
		}
		_sleep(100);
	}

	//TRANSPORTANDO MUESTRAS EN SATELITE
	vxC = 1;
	xS = 0; yS = ALTO / 2 - 10;
	DibujarEstrellas(0, 0);
	setColor(15); setXY(50, 2); cout << "Retornando muestras a la Tierra...";
	while (true)
	{
		if (xS < ANCHO - 90)
		{
			Satelite(xS, yS, vxC);
		}
		if (xS == ANCHO - 90)
		{
			break;
		}
		_sleep(600);
	}

	xN = ANCHO - 70;  yN = ALTO - 17;
	vxN = 1;
	vyN = 1;
	while (yN != ALTO - 6)
	{
		if (yN < ALTO - 6)
		{
			NaveD(xN, yN, vxN, vyN);
		}
		_sleep(100);
	}
	Console::Clear();
	//RETORNANDO MUESTRAS A LA TIERRA
	DibujarEstrellas(0, 0);
	DibujarTierra(ANCHO - 90, ALTO - 12);
	xN = 5; yN = 1;
	vxN = 1;
	vyN = 1;
	setColor(15); setXY(40, 2); cout << "Ahi esta la Tierra! Ya casi lo logramos...";
	while (yN!=ALTO-13)
	{
		if (yN < ALTO - 13)
		{
			NaveD(xN, yN, vxN, vyN);
		}
		_sleep(100);
	}
	setColor(15); setXY(40, 2); cout << "                                          ";
	_sleep(800);
	
	PantallaFinMision();

	_getch();
	return 0;
}