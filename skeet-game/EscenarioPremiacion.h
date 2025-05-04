#pragma once
#include<iostream>
#include<conio.h>

using namespace std;
using namespace System;
#define ANCHO 140
#define ALTO 40



//Fondo de Premiacion
void dibujaNube_1_2(int x, int y)
{
	char block = char(219);

	setColor(15);
	setXY(x, y); cout << "                                         " << block << block << block << block << block << block << block << block << "     " << block << block << block << block << block << block << block << block << "\n";
	setXY(x, y + 1); cout << "                        " << block << block << block << "     " << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << "\n";
	setXY(x, y + 2); cout << "                 " << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << "\n";
	setXY(x, y + 3); cout << "       " << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << "\n";
	setXY(x, y + 4); cout << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << "\n";
	setXY(x, y + 5); cout << "       " << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << "\n";
	setXY(x, y + 6); cout << "                           " << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << "  " << block << block << block << block << block << block << block << "\n";
}

void dibujaNube_2_2(int x, int y)
{
	char block = char(219);

	setColor(15);
	setXY(x, y); cout << "                        " << block << block << block << block << block << block << block << block << "   " << block << block << "\n";
	setXY(x, y + 1); cout << "                        " << block << block << block << "     " << block << block << block << block << block << block << block << block << block << "\n";
	setXY(x, y + 2); cout << "               " << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << "\n";
	setXY(x, y + 3); cout << "     " << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << "\n";
	setXY(x, y + 4); cout << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << "\n";
	setXY(x, y + 5); cout << "       " << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << "\n";
	setXY(x, y + 6); cout << "                           " << block << block << block << " " << block << block << block << block << block << block << block << block << block;
}
void dibujaNube_3_2(int x, int y)
{
	char block = char(219);
	setColor(15);
	setXY(x, y);	 cout << block << block << block << "     " << block << block << block << block << block << block << block << block << block;
	setXY(x, y + 1); cout << "      " << block << block << block << block << block << block << block << block << block << block << block << block << block << block;
	setXY(x, y + 2);	 cout << block << block << block << block << block << block << block << "     " << block << block << block << block << block << block << block << block << block << block;
	setXY(x, y + 3); cout << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << "      " << block << block << block;
	setXY(x, y + 4); cout << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block;
	setXY(x, y + 5); cout << block << block << block << block << "     " << block << block << block << block << block << block << block << block << block << block << "   " << block << block << block << block << block << block << block << block << block << block;
	setXY(x, y + 5); cout << "     " << block << block << block << block << "     " << block << block << block << block << block << block << block << block << block << block << block << block;
}
void Cielo_2()
{
	int x = 0;
	int y = 0;

	for (int j = 0; j < ALTO - 6; j++)
	{
		for (int i = 0; i < ANCHO; i++)
		{

			setXY(x + i, y);
			setBGcolor(3);
			cout << " ";
		}
		y = y + 1;
	}
	dibujaNube_1_2(5, 2);
	dibujaNube_2_2(100, 10);
	dibujaNube_3_2(0, 13);
}

void  Pasto(int N)
{
	char caracter = '^';
	setBGcolor(12);
	setColor(7);
	for (int i = 1; i < N; i++)
	{
		setXY(Aleatorio(0, ANCHO), Aleatorio(ALTO - 5, ALTO)); cout << caracter;
	}

}
void DibujarEscenario()
{
	Cielo_2();
	Grass_2(0, ALTO, 6);
	Pasto(30);
}
//DIBUJAR JUGADORES AL REVES
//PREMIACION
void DesplazarH_Jugador(int& x, int y)
{

	x = x + 1;
}
void DesplazarV_Jugador(int x, int& y)
{

	y = y - 1;
}
void dibujaJugador2(int& x1, int y1, int num_jugador)
{

	if (num_jugador == 1)
	{//Argentina
		dibujaJugadorargentina2(x1, y1);
	}
	if (num_jugador == 2)
	{//Peru
		dibujaJugadorPeru2(x1, y1);
	}
	if (num_jugador == 3)
	{//Colombia
		dibujaJugadorColombia2(x1, y1);
	}
	if (num_jugador == 4)
	{//Chile
		dibujaJugadorChile2(x1, y1);
	}
	if (num_jugador == 5)
	{//Brasil
		dibujaJugadorBrazil2(x1, y1);
	}
	if (num_jugador == 6)
	{//Mexico
		dibujaJugadormexico2(x1, y1);
	}
	if (num_jugador == 7)
	{//Nicaragua
		dibujaJugadorNicaragua2(x1, y1);
	}
	if (num_jugador == 8)
	{//Bolivia
		dibujaJugadorBolivia2(x1, y1);
	}
	if (num_jugador == 9)
	{//Francia
		dibujaJugadorfrancia2(x1, y1);
	}
	if (num_jugador == 10)
	{//Venezuela
		dibujaJugadorvenezuela2(x1, y1);
	}
}
void Mover_JugadorH(int& x, int y, int pos_x, int num_jugador)
{
	while (x < pos_x)
	{
		BorrarJugador2(x, y);
		DesplazarH_Jugador(x, y);
		dibujaJugador2(x, y, num_jugador);
		_sleep(75);
	}
}
void Mover_JugadorV(int x, int& y, int num_jugador)
{
	BorrarJugador2(x, y);
	DesplazarV_Jugador(x, y);
	dibujaJugador2(x, y, num_jugador);
}
void Podio(int x, int y, int color)
{
	for (int i = 0; i < 20; i++)
	{

		setXY(x + i, y);
		setBGcolor(color);
		cout << " ";
	}
	setBGcolor(3);
}

void GenerarPodio(int x, int& y, int& yP, int altura, int color, int num_jugador)
{
	int contador = 0;
	while (contador < altura)
	{
		Mover_JugadorV(x + 6, yP, num_jugador);
		Podio(x, y, color); _sleep(75);
		y = y - 1;
		contador++;
	}

}
void Dibujar_Generador_Puesto(int x, int& y, int color)
{

	setXY(x, y); setBGcolor(color); setColor(1); cout << char(220);
	setXY(x + 1, y); setBGcolor(color); setColor(1); cout << char(220);
}
void Borrar_Generador_Puesto(int x, int& y, int color)
{
	setXY(x, y); setBGcolor(color);  cout << "  ";
}
void Desplazar_Generador_Puesto(int& y)
{
	y = y - 1;
}
void Mover_Generador_Puesto(int x, int& y, int color)
{
	Borrar_Generador_Puesto(x, y, color);
	Desplazar_Generador_Puesto(y);
	Dibujar_Generador_Puesto(x, y, color);
}
void Puesto(int puesto)
{
	if (puesto == 1)
	{
		int x = 68;
		int y = ALTO - 17;
		setColor(1);
		setBGcolor(10);

		setXY(x, y);		 cout << " db";
		setXY(x, y + 1);	 cout << "o88";
		setXY(x, y + 2);	 cout << " 88";
		setXY(x, y + 3);	 cout << " 88";
		setXY(x, y + 4);	 cout << " 88";
		setXY(x, y + 5);	 cout << " VP";

	}
	if (puesto == 2)
	{
		int x = 47;
		int y = ALTO - 14;
		setColor(1);
		setBGcolor(2);

		setXY(x, y);		 cout << ".d888b.";
		setXY(x, y + 1);	 cout << "VP  `8D";
		setXY(x, y + 2);	 cout << "   odD'";
		setXY(x, y + 3);	 cout << " .88'  ";
		setXY(x, y + 4);	 cout << "j88.   ";
		setXY(x, y + 5);	 cout << "888888D";

	}
	if (puesto == 3)
	{
		int x = 87;
		int y = ALTO - 13;
		setColor(1);
		setBGcolor(9);

		setXY(x, y);		 cout << "d8888b.";
		setXY(x, y + 1);	 cout << "V   `8D";
		setXY(x, y + 2);	 cout << "  oooY'";
		setXY(x, y + 3);	 cout << "     8D";
		setXY(x, y + 4);	 cout << "db   8D";
		setXY(x, y + 5);	 cout << "Y8888P'";


	}
}
void GeneradorPuesto(int x, int& y, int altura, int color)
{
	int contador = 0;
	while (contador < altura)
	{
		if (y > ALTO - altura)
		{
			Mover_Generador_Puesto(x, y, color); _sleep(75);
		}
		else
			break;
		contador++;
	}
}
void Borrar_Fuegos_Artificiales(int x, int y, int color)
{
	setBGcolor(3); setColor(15);
	setXY(x, y);						   cout << "          ";
	setXY(x, y + 2); setColor(color);	   cout << "          ";
	setXY(x, y + 3); setColor(15); cout << "     "; setColor(color); cout << "     "; setColor(15); cout << "     "; setColor(color);
	setXY(x, y + 4); cout << "             ";
	setXY(x, y + 5); cout << "             ";
	setXY(x, y + 6); setColor(15); cout << " "; setColor(color); cout << "                "; setColor(15); cout << " ";
	setXY(x, y + 7); setColor(color); cout << "           ";
	setXY(x, y + 8); cout << "             ";
	setXY(x, y + 9); cout << "              ";
	setXY(x, y + 10); setColor(15); cout << "     "; setColor(color); cout << "     "; setColor(15); cout << "     ";
	setXY(x, y + 11); setColor(15); cout << "          ";
}
void Dibujar_Fuegos_Artificiales(int x, int y, int color)
{
	setBGcolor(3); setColor(15);
	setXY(x, y);						   cout << "         .";
	setXY(x, y + 2); setColor(color);	   cout << "         |";
	setXY(x, y + 3); setColor(15); cout << "    ."; setColor(color); cout << "    |"; setColor(15); cout << "    ."; setColor(color);
	setXY(x, y + 4); cout << "      \\  |  /";
	setXY(x, y + 5); cout << "       \\ | /";
	setXY(x, y + 6); setColor(15); cout << "."; setColor(color); cout << "  _____\\|/_____  "; setColor(15); cout << ".";
	setXY(x, y + 7); setColor(color); cout << "        /|\\";
	setXY(x, y + 8); cout << "       / | \\";
	setXY(x, y + 9); cout << "      /  |  \\";
	setXY(x, y + 10); setColor(15); cout << "    ."; setColor(color); cout << "    |"; setColor(15); cout << "    .";
	setXY(x, y + 11); setColor(15); cout << "         .";
}
void Parpadea_Fuegos_Artificiales(int x, int y, int color)
{
	Borrar_Fuegos_Artificiales(x, y, color); _sleep(200);
	Dibujar_Fuegos_Artificiales(x, y, color);
}
void GeneraFuegosArtificiales()
{
	int contador = 0;
	while (contador == 0)
	{
		if (_kbhit())
			exit(0);
		else
		{
			Parpadea_Fuegos_Artificiales(13, 19, 14);
			Parpadea_Fuegos_Artificiales(80, 2, 7);
			Parpadea_Fuegos_Artificiales(110, 17, 13);
		}
	}
}int AsignarNumFinalista(string*& Paises, int pos)
{
	if (Paises[pos] == "Argentina")
		return  1;
	if (Paises[pos] == "Peru")
		return  2;
	if (Paises[pos] == "Colombia")
		return  3;
	if (Paises[pos] == "Chile")
		return  4;
	if (Paises[pos] == "Brasil")
		return  5;
	if (Paises[pos] == "Mexico")
		return  6;
	if (Paises[pos] == "Nicaragua")
		return  7;
	if (Paises[pos] == "Bolivia")
		return  8;
	if (Paises[pos] == "Francia")
		return  9;
	if (Paises[pos] == "Venezuela")
		return  10;

}
void LiberarMemoria(string*& Paises, Jugadores*& participante)
{
	if (Paises != NULL) delete[]Paises;
	if (participante != NULL) delete[]participante;

}
void Premiacion(string*& Paises, Jugadores*& participante)
{
	setBGcolor(1);
	Console::Clear();
	DibujarEscenario();

	int num_jugador2;
	int num_jugador1;
	int num_jugador0;

	int x = 0;
	int y = ALTO - 7;
	int y2 = y;
	int yP = ALTO - 7;

	//entrada de los 3 finalistas
	num_jugador2 = AsignarNumFinalista(Paises, 2);
	Mover_JugadorH(x, y, 86, num_jugador2);

	x = 0;
	num_jugador0 = AsignarNumFinalista(Paises, 0);
	Mover_JugadorH(x, y, 66, num_jugador0);

	x = 0;
	num_jugador1 = AsignarNumFinalista(Paises, 1);
	Mover_JugadorH(x, y, 46, num_jugador1);

	GenerarPodio(40, y2, yP, 12, 2, num_jugador1);

	y2 = ALTO - 7;
	yP = y2;
	GenerarPodio(60, y2, yP, 16, 10, num_jugador0);

	y2 = ALTO - 7;
	yP = y2;
	GenerarPodio(80, y2, yP, 9, 9, num_jugador2);

	y2 = ALTO - 7;

	GeneradorPuesto(49, y2, 14, 2);
	Puesto(2); _sleep(150);
	y2 = ALTO - 7;

	GeneradorPuesto(69, y2, 16, 10);
	Puesto(1); _sleep(150);
	y2 = ALTO - 7;

	GeneradorPuesto(89, y2, 13, 9);
	Puesto(3); _sleep(150);

	LiberarMemoria(Paises, participante);
	_sleep(150);
	GeneraFuegosArtificiales();

}