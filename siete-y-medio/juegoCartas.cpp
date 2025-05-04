
#include <iostream>
#include <conio.h>

using namespace std;
using namespace System;


#define SCREEN_WIDTH 140
#define SCREEN_HEIGHT 40

#define ESPACIO 32
#define ESCAPE 27

int GeneraAleatorio(int n1, int n2);
void GeneraCuadro(int ancho, int largo);
void Presentacion(int ancho, int largo, int partidas);
float AsignarValor(int n);
float CalculaDiferencia(float n);
int NumeroCarta(int carta);
void GeneraCarta(int x, int y, int carta, int palo, int valor);
void GeneraFigura(int x, int y, int palo);
float Juego(short Player, int x, int y);
void Resultados(int x, int y, float puntos1, float puntos2);
int main()
{
	Console::SetWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	srand(time(NULL));

	int partidas;
	int contador = 0;
	short Player = 1;
	float acumulador1 = 0, acumulador2 = 0;
	int puntos1 = 0, puntos2 = 0;
	short partidas_ganadas1 = 0, partidas_ganadas2 = 0;
	int x = 20;
	int y = 7;

	partidas = GeneraAleatorio(3, 7);

	Presentacion(SCREEN_WIDTH, SCREEN_HEIGHT, partidas);
	getch();

	Console::Clear();

	for (int i = 1; i <= partidas; i++)
	{
		Console::Clear();
		//Puntos de cada Partida
		Console::ForegroundColor = ConsoleColor::White;
		Console::SetCursorPosition(SCREEN_WIDTH / 2 - 50, y - 1);
		cout << "Player 1: " << puntos1;
		Console::SetCursorPosition(SCREEN_WIDTH / 2 + 35, y - 1);
		cout << "Player 2: " << puntos2;

		Console::ForegroundColor = ConsoleColor::Magenta;
		Console::SetCursorPosition(SCREEN_WIDTH / 2 - 12, y - 1);
		cout << "\a>>> PARTIDA " << i;
		cout << " / " << partidas << " <<<";

		Console::ForegroundColor = ConsoleColor::Green;
		acumulador1 = Juego(1, x, y + 2);

		Console::SetCursorPosition(SCREEN_WIDTH / 2 - 22, y + 26);

		Console::ForegroundColor = ConsoleColor::Cyan;
		cout << "[Presiona cualquier tecla para continuar]";
		_getch();

		Console::Clear();
		//Puntos de cada Partida
		Console::ForegroundColor = ConsoleColor::White;
		Console::SetCursorPosition(SCREEN_WIDTH / 2 - 50, y - 1);
		cout << "Player 1: " << puntos1;
		Console::SetCursorPosition(SCREEN_WIDTH / 2 + 35, y - 1);
		cout << "Player 2: " << puntos2;

		Console::ForegroundColor = ConsoleColor::Magenta;
		Console::SetCursorPosition(SCREEN_WIDTH / 2 - 12, y - 1);
		cout << "\a>>> PARTIDA " << i;
		cout << " / " << partidas << " <<<";

		Console::ForegroundColor = ConsoleColor::Blue;
		acumulador2 = Juego(2, x, y + 2);

		Console::SetCursorPosition(SCREEN_WIDTH / 2 - 22, y + 26);

		//Asignar puntos
		if (acumulador1 < acumulador2)puntos1++;
		else if (acumulador2 == acumulador1) { puntos1++; puntos2++; }
		else puntos2++;

		Console::ForegroundColor = ConsoleColor::Cyan;
		cout << "[Presiona cualquier tecla para continuar]";
		_getch();

	}

	Console::Clear(); _sleep(100);
	Resultados(x, y, puntos1, puntos2);


	_getch();
	return 0;

}
int GeneraAleatorio(int n1, int n2)
{
	return n1 + rand() % (n2 - n1 + 1);
}

float AsignarValor(int n)
{
	if (n > 0 && n < 10)
		return n;
	else
		return 0.5;
}

float CalculaDiferencia(float n)
{
	if (n <= 7.5)
		return 7.5 - n;
	else
		return n - 7.5;
}

int NumeroCarta(int carta)
{
	if (carta == 1)
		return 65;

	if (carta == 11)
		return 74;

	if (carta == 12)
		return 81;

	if (carta == 13)
		return 75;

	else
		return 48 + carta; //48=0

}



void GeneraFigura(int x, int y, int palo)
{

	if (palo == 3)
	{
		Console::ForegroundColor = ConsoleColor::DarkRed;
		Console::SetCursorPosition(x + 5, y + 3);

		for (int i = 1; i <= 5; i++)
		{
			if (i == 1 || i == 5)
			{
				cout << "*";
				_sleep(100);
			}
			else
				cout << " ";

		}
		Console::SetCursorPosition(x + 4, y + 4);

		for (int i = 1; i <= 7; i++)
		{
			if (i == 4)
			{
				cout << " ";
				_sleep(100);
			}
			else
				cout << "*";

		}

		Console::SetCursorPosition(x + 4, y + 5);
		for (int i = 1; i <= 7; i++)
		{
			cout << "*";
			_sleep(100);
		}

		Console::SetCursorPosition(x + 4, y + 6);
		for (int i = 1; i <= 7; i++)
		{
			cout << "*";
			_sleep(100);
		}

		Console::SetCursorPosition(x + 5, y + 7);
		for (int i = 1; i <= 5; i++)
		{
			cout << "*";
			_sleep(100);
		}

		Console::SetCursorPosition(x + 6, y + 8);
		for (int i = 1; i <= 3; i++)
		{
			cout << "*";
			_sleep(100);
		}

		Console::SetCursorPosition(x + 7, y + 9);
		cout << "*";
		_sleep(100);

	}
	if (palo == 4) //Diamante
	{
		Console::ForegroundColor = ConsoleColor::Blue;

		Console::SetCursorPosition(x + 7, y + 3);
		cout << "*";
		_sleep(100);

		Console::SetCursorPosition(x + 6, y + 4);
		for (int i = 1; i <= 3; i++)
		{
			cout << "*";
			_sleep(100);
		}

		Console::SetCursorPosition(x + 5, y + 5);
		for (int i = 1; i <= 5; i++)
		{
			cout << "*";
			_sleep(100);
		}

		Console::SetCursorPosition(x + 4, y + 6);
		for (int i = 1; i <= 7; i++)
		{
			cout << "*";
			_sleep(100);
		}

		Console::SetCursorPosition(x + 5, y + 7);
		for (int i = 1; i <= 5; i++)
		{
			cout << "*";
			_sleep(100);
		}

		Console::SetCursorPosition(x + 6, y + 8);
		for (int i = 1; i <= 3; i++)
		{
			cout << "*";
			_sleep(100);
		}

		Console::SetCursorPosition(x + 7, y + 9);
		cout << "*";
		_sleep(100);

		//BorrarCaracter(x, y, palo);


	}
	if (palo == 5)
	{
		Console::ForegroundColor = ConsoleColor::Green;

		Console::SetCursorPosition(x + 7, y + 3);
		cout << "*";
		_sleep(100);

		Console::SetCursorPosition(x + 6, y + 4);
		for (int i = 1; i <= 3; i++)
		{
			cout << "*";
			_sleep(100);
		}
		Console::SetCursorPosition(x + 7, y + 5);
		cout << "*";
		_sleep(100);

		Console::SetCursorPosition(x + 4, y + 6);
		for (int i = 1; i <= 7; i++)
		{
			if (i == 1 || i == 4 || i == 7) //Cada 3 expacios imprime
			{
				cout << "*";
				_sleep(100);
			}
			else
				cout << " ";

		}

		Console::SetCursorPosition(x + 3, y + 7);
		for (int i = 1; i <= 9; i++)
		{
			cout << "*";
			_sleep(100);
		}
		Console::SetCursorPosition(x + 4, y + 8);
		for (int i = 1; i <= 7; i++)
		{
			if (i == 1 || i == 4 || i == 7) //Cada 3 expacios imprime
			{
				cout << "*";
				_sleep(100);
			}

			else
				cout << " ";

		}

		Console::SetCursorPosition(x + 7, y + 9);
		cout << "*";
		_sleep(100);

	}
	if (palo == 6)
	{
		Console::ForegroundColor = ConsoleColor::DarkGray;

		_sleep(100);
		Console::SetCursorPosition(x + 7, y + 3);
		cout << "*";
		_sleep(100);
		Console::SetCursorPosition(x + 6, y + 4);
		for (int i = 1; i <= 3; i++)
		{
			cout << "*";
			_sleep(100);
		}
		Console::SetCursorPosition(x + 5, y + 5);
		for (int i = 1; i <= 5; i++)
		{
			cout << "*";
			_sleep(100);
		}
		Console::SetCursorPosition(x + 4, y + 6);
		for (int i = 1; i <= 7; i++)
		{
			cout << "*";
			_sleep(100);
		}

		Console::SetCursorPosition(x + 5, y + 7);
		for (int i = 1; i <= 5; i++)
		{
			cout << "*";
			_sleep(100);
		}

		Console::SetCursorPosition(x + 7, y + 8);
		cout << "*";
		_sleep(100);
		Console::SetCursorPosition(x + 6, y + 9);
		for (int i = 1; i <= 3; i++)
		{
			cout << "*";
			_sleep(100);
		}
	}
}

void GeneraContorno(int x, int y, int carta, int valor) //Palo no tiene relevancia aqui
{

	Console::ForegroundColor = ConsoleColor::White;

	//linea horizontal Arriba
	Console::SetCursorPosition(x + 2, y);

	for (int i = 1; i <= 12; i++)
		cout << char(196);
	cout << char(191); //esquina

	//Linea Vertical Izquierda

	y++;

	for (int i = 1; i <= 11; i++)
	{

		Console::SetCursorPosition(x, y);
		cout << char(179);
		y++;
	}

	//Linea Horizontal abajo
	Console::SetCursorPosition(x, y);
	cout << char(192); //esquina

	for (int i = 1; i <= 12; i++)
	{
		cout << char(196);
		x++;

	}
	//x incrementa en 2 

	if (valor == 58) //48 + 10
		cout << "10";
	else
		cout << " " << (char)valor;


	//Linea Vertical Derecha
	x = x + 2;
	y = y - 1; //Ye sube un espacio

	for (int i = 1; i <= 11; i++)
	{
		Console::SetCursorPosition(x, y);
		cout << char(179);
		y--;
	}
}

void GeneraCarta(int x, int y, int carta, int palo, int valor)
{
	Console::SetCursorPosition(x, y);
	Console::ForegroundColor = ConsoleColor::White;


	if (carta == 10)
	{
		cout << "10";
		GeneraContorno(x, y, carta, valor);
		GeneraFigura(x, y, palo);

	}
	else
	{
		cout << char(valor);
		cout << " ";
		GeneraContorno(x, y, carta, valor);
		GeneraFigura(x, y, palo);

	}
}

void BorrarTexto(int x, int y)
{
	Console::SetCursorPosition(x, y);
	for (int i = 1; i <= 40; i++)
		cout << " ";

}

float Juego(short Player, int x, int y)
{
	short NumCarta, palo;
	char OtraCarta, Mostrar;
	float Valor;
	int numero;
	float ValorAcumulado;
	int contadorCartas = 0;
	int xCarta;
	int yCarta;
	int yTexto;
	int xTexto;
	int xAcumulado;
	int yAcumulado;

	while (true)
	{
		ValorAcumulado = 0;


		yTexto = y + 2;
		xTexto = x;
		Console::SetCursorPosition(xTexto, yTexto);

		cout << "TURNO: PLAYER " << Player;

		Console::ForegroundColor = ConsoleColor::Cyan;

		yCarta = y + 4;
		xCarta = x;

		NumCarta = GeneraAleatorio(1, 13);
		palo = GeneraAleatorio(3, 6);
		numero = NumeroCarta(NumCarta);

		GeneraCarta(xCarta, yCarta, NumCarta, palo, numero);

		contadorCartas++;
		Valor = AsignarValor(NumCarta);
		ValorAcumulado = ValorAcumulado + Valor;

		xAcumulado = x + 60;
		yAcumulado = y + 2;

		Console::SetCursorPosition(xAcumulado, yAcumulado);
		Console::ForegroundColor = ConsoleColor::DarkGray;
		cout << "Valor Acumulado: " << ValorAcumulado;

		yTexto = yTexto + 16; //14 por el largo de las cartas

		if (ValorAcumulado <= 7.5) {

			do
			{
				Console::SetCursorPosition(xTexto, yTexto);
				Console::ForegroundColor = ConsoleColor::Cyan;
				cout << "Desea Pedir Otra Carta? ";
				Console::SetCursorPosition(xTexto, yTexto + 1);
				cout << "(S:Si, N:No) -> ";	cin >> OtraCarta;
				BorrarTexto(xTexto, yTexto + 1);
				BorrarTexto(xTexto, yTexto);

			} while (!(toupper(OtraCarta) == 'S' || toupper(OtraCarta) == 'N'));



			while (toupper(OtraCarta) == 'S') {
				BorrarTexto(xAcumulado, yAcumulado);

				contadorCartas++;
				NumCarta = GeneraAleatorio(1, 13);
				palo = GeneraAleatorio(3, 6);
				numero = NumeroCarta(NumCarta);
				if (contadorCartas == 1)
					xCarta = x;
				else
					xCarta = xCarta + 40;

				GeneraCarta(xCarta, yCarta, NumCarta, palo, numero);
				Valor = AsignarValor(NumCarta);
				ValorAcumulado = ValorAcumulado + Valor;

				Console::SetCursorPosition(xAcumulado, yAcumulado);
				Console::ForegroundColor = ConsoleColor::DarkGray;
				cout << "Valor Acumulado: " << ValorAcumulado;

				if (ValorAcumulado <= 7.5) {
					do
					{
						Console::SetCursorPosition(xTexto, yTexto);
						Console::ForegroundColor = ConsoleColor::Cyan;
						cout << "Desea Pedir Otra Carta? ";
						Console::SetCursorPosition(xTexto, yTexto + 1);
						cout << "(S:Si, N:No) -> ";	cin >> OtraCarta;
						BorrarTexto(xTexto, yTexto + 1);
						BorrarTexto(xTexto, yTexto);

					} while (!(toupper(OtraCarta) == 'S' || toupper(OtraCarta) == 'N'));

					if (contadorCartas == 3 && toupper(OtraCarta) == 'S')
					{
						Console::Clear();

						yTexto = y + 2;
						xTexto = x;
						Console::SetCursorPosition(xTexto, yTexto);
						cout << "TURNO: PLAYER " << Player;

						yTexto = yTexto + 16;

						contadorCartas = 0;


					}

				}
				else
					OtraCarta = 'N';
			}
			if (toupper(OtraCarta) == 'N')
				break;

		}
		else
			break;



	}
	return CalculaDiferencia(ValorAcumulado);
}

void GeneraCuadro(int ancho, int largo)
{
	Console::ForegroundColor = ConsoleColor::White;
	Console::SetCursorPosition(ancho, largo);
	cout << char(218);
	for (int i = 1; i < 95; i++)
		cout << char(196);

	cout << char(191);

	largo++;
	for (int i = 1; i < 11; i++)
	{
		Console::SetCursorPosition(ancho, largo);
		cout << char(179);
		largo++;
	}
	Console::SetCursorPosition(ancho, largo);
	cout << char(192);

	ancho = ancho + 1;

	for (int i = 1; i < 95; i++)
	{
		Console::SetCursorPosition(ancho, largo);
		cout << char(196);
		ancho++;
	}
	cout << char(217);

	largo--;
	for (int i = 1; i < 11; i++)
	{
		Console::SetCursorPosition(ancho, largo);
		cout << char(179);
		largo--;
	}

}

void Presentacion(int ancho, int largo, int partidas)
{
	ancho = ancho / 7; //20 a los lados
	largo = 4;
	Console::SetCursorPosition(ancho, largo);
	Console::ForegroundColor = ConsoleColor::Magenta;
	cout << "Bienvenidos a..."; _sleep(100);

	largo = largo + 2;
	Console::ForegroundColor = ConsoleColor::Cyan;
	Console::SetCursorPosition(ancho, largo);
	cout << " #####   ###  #######  #######  #######    #     #    #     #   #######   ######   ###   ####### "; _sleep(100);
	Console::SetCursorPosition(ancho, largo + 1);
	cout << "#         #   #           #     #           #   #     ##   ##   #         #     #   #    #     # "; _sleep(100);
	Console::SetCursorPosition(ancho, largo + 2);
	cout << "#         #   #           #     #            # #      # # # #   #         #     #   #    #     # "; _sleep(100);
	Console::SetCursorPosition(ancho, largo + 3);
	cout << " #####    #   #####       #     #####         #       #  #  #   #####     #     #   #    #     # "; _sleep(100);
	Console::SetCursorPosition(ancho, largo + 4);
	cout << "      #   #   #           #     #             #       #     #   #         #     #   #    #     #  "; _sleep(100);
	Console::SetCursorPosition(ancho, largo + 5);
	cout << "      #   #   #           #     #             #       #     #   #         #     #   #    #     # "; _sleep(100);
	Console::SetCursorPosition(ancho, largo + 6);
	cout << " #####   ###  #######     #     #######       #       #     #   #######   ######   ###   ####### "; _sleep(100);

	largo = largo + 6;  //Actualizamos el valor del largo
	ancho = ancho + 25;

	Console::ForegroundColor = ConsoleColor::Magenta;

	largo = largo + 3;
	Console::SetCursorPosition(ancho, largo); _sleep(350);
	cout << "ACUMULA CARTAS HASTA LLEGAR A SIETE Y MEDIO!"; _sleep(350);

	ancho = 20;
	GeneraCuadro(ancho, largo + 3);

	ancho = ancho + 40;
	largo = largo + 5;

	Console::SetCursorPosition(ancho, largo);
	Console::ForegroundColor = ConsoleColor::Blue;
	cout << "INSTRUCCIONES:";

	ancho = ancho - 26;
	largo = largo + 2;
	Console::SetCursorPosition(ancho, largo);
	Console::ForegroundColor = ConsoleColor::Blue;
	cout << "> El juego consiste en acumular cartas hasta obtener el valor de 7.5";
	Console::SetCursorPosition(ancho, largo + 1);
	cout << "> Gana el jugador que tenga mas partidas iguales o cercanas a 7.5";

	ancho = ancho + 28; //+26+2
	largo = largo + 3;//+1+2

	Console::ForegroundColor = ConsoleColor::Blue;
	Console::SetCursorPosition(ancho, largo);
	cout << "IMPORTANTE:";

	ancho = ancho - 28;
	largo = largo + 2;

	Console::SetCursorPosition(ancho, largo);
	Console::ForegroundColor = ConsoleColor::Blue;
	cout << "Las cartas de numeros del 10 al 13 valen 0.5 y el resto su valor original "; _sleep(350);

	ancho = ancho + 12;
	largo = largo + 5;

	Console::SetCursorPosition(ancho, largo);
	Console::ForegroundColor = ConsoleColor::Cyan; _sleep(250);
	cout << "El numero de partidas para esta ronda es de: " << partidas;

	largo = largo + 2;
	ancho = ancho + 4;
	Console::SetCursorPosition(ancho, largo); _sleep(350);

	cout << "< Presione cualquier tecla para Iniciar > ";

}

void Resultados(int x, int y, float puntos1, float puntos2)
{
	//Puntos de cada Partida
	Console::ForegroundColor = ConsoleColor::White;
	Console::SetCursorPosition(SCREEN_WIDTH / 2 - 50, 4);
	cout << "Player 1: " << puntos1;
	Console::SetCursorPosition(SCREEN_WIDTH / 2 + 35, 4);
	cout << "Player 2: " << puntos2;

	cout << "\a";
	if (puntos1 != puntos2) {
		Console::SetCursorPosition(x, y);
		Console::ForegroundColor = ConsoleColor::Cyan;
		cout << "   .::::         .:        .:::     .::       .:        .:::::         .::::      .:::::::    "; _sleep(100);
		Console::SetCursorPosition(x, y + 1);
		cout << " .:    .::      .: ::      .: .::   .::      .: ::      .::   .::    .::    .::   .::    .::  "; _sleep(100);
		Console::SetCursorPosition(x, y + 2);
		cout << ".::            .:  .::     .:: .::  .::     .:  .::     .::    .:: .::        .:: .::    .::  "; _sleep(100);
		Console::SetCursorPosition(x, y + 3);
		cout << ".::           .::   .::    .::  .:: .::    .::   .::    .::    .:: .::        .:: .: .::      "; _sleep(100);
		Console::SetCursorPosition(x, y + 4);
		cout << ".::   .::::  .:::::: .::   .::   .: .::   .:::::: .::   .::    .:: .::        .:: .::  .::    "; _sleep(100);
		Console::SetCursorPosition(x, y + 5);
		cout << " .::    .:  .::       .::  .::    .: ::  .::       .::  .::   .::    .::     .::  .::    .::  "; _sleep(100);
		Console::SetCursorPosition(x, y + 6);
		cout << "  .:::::   .::         .:: .::      .:: .::         .:: .:::::         .::::      .::      .::"; _sleep(100);
	}
	y = y + 6;//Actualiza y
	x = x + 4;

	if (puntos1 < puntos2) {

		Console::ForegroundColor = ConsoleColor::Blue;
		Console::SetCursorPosition(x, y + 5);
		cout << ".:::::::   .::              .:     .::     .::  .::::::::  .:::::::            .::::.      "; _sleep(100);
		Console::SetCursorPosition(x, y + 6);
		cout << ".::    .:: .::             .: ::    .::   .::   .::        .::    .::        .:     .:"; _sleep(100);
		Console::SetCursorPosition(x, y + 7);
		cout << ".::    .:: .::            .:  .::    .:: .::    .::        .::    .::       .:     .:"; _sleep(100);
		Console::SetCursorPosition(x, y + 8);
		cout << ".:::::::   .::           .::   .::     .::      .::::::    .: .::               .:: "; _sleep(100);
		Console::SetCursorPosition(x, y + 9);
		cout << ".::        .::          .:::::: .::    .::      .::        .::  .::            .::  "; _sleep(100);
		Console::SetCursorPosition(x, y + 10);
		cout << ".::        .::         .::       .::   .::      .::        .::    .::         .::   "; _sleep(100);
		Console::SetCursorPosition(x, y + 11);
		cout << ".::        .::::::::  .::         .::  .::      .::::::::  .::      .::     .:::::::::"; _sleep(100);

		x = x + 6;
		y = y + 11;

		Console::SetCursorPosition(x + 28, y + 5);
		Console::ForegroundColor = ConsoleColor::Cyan; _sleep(100);
		cout << "F E L I C I D A D E S !";
	}

	else if (puntos1 > puntos2) {

		Console::ForegroundColor = ConsoleColor::Green;
		Console::SetCursorPosition(x, y + 5);
		cout << ".:::::::    .::              .:      .::     .::  .::::::::   .:::::::             ::"; _sleep(100);
		Console::SetCursorPosition(x, y + 6);
		cout << ".::    .::  .::             .: ::     .::   .::   .::         .::    .::       .:  .:"; _sleep(100);
		Console::SetCursorPosition(x, y + 7);
		cout << ".::    .::  .::            .:  .::     .:: .::     .::        .::    .::           .:"; _sleep(100);
		Console::SetCursorPosition(x, y + 8);
		cout << ".:::::::    .::           .::   .::      .::       .::::::    .: .::              .:: "; _sleep(100);
		Console::SetCursorPosition(x, y + 9);
		cout << ".::         .::          .:::::: .::     .::       .::        .::  .::            .::  "; _sleep(100);
		Console::SetCursorPosition(x, y + 10);
		cout << ".::         .::         .::       .::    .::       .::        .::    .::          .::  "; _sleep(100);
		Console::SetCursorPosition(x, y + 11);
		cout << ".::         .::::::::  .::         .::   .::       .::::::::  .::      .::     .:::::::"; _sleep(100);

		x = x + 6;
		y = y + 11;

		Console::SetCursorPosition(x + 28, y + 5);
		Console::ForegroundColor = ConsoleColor::Cyan; _sleep(100);
		cout << "F E L I C I D A D E S !";
	}

	else
	{
		x = x + 5;
		y -= 3;
		Console::ForegroundColor = ConsoleColor::Yellow;
		Console::SetCursorPosition(x, y + 1);
		cout << ".::::::::   .::       .::   .:::::::        .:       .:::::::::::  .::::::::"; _sleep(100);
		Console::SetCursorPosition(x, y + 2);
		cout << ".::         .: .::   .:::   .::    .::     .: ::          .::      .::      "; _sleep(100);
		Console::SetCursorPosition(x, y + 3);
		cout << ".::         .:: .:: . .::   .::    .::    .:  .::         .::      .::      "; _sleep(100);
		Console::SetCursorPosition(x, y + 4);
		cout << ".::::::     .::  .::  .::   .:::::::     .::   .::        .::      .::::::  "; _sleep(100);
		Console::SetCursorPosition(x, y + 5);
		cout << ".::         .::   .:  .::   .::         .:::::: .::       .::      .::      "; _sleep(100);
		Console::SetCursorPosition(x, y + 6);
		cout << ".::         .::       .::   .::        .::       .::      .::      .::      "; _sleep(100);
		Console::SetCursorPosition(x, y + 7);
		cout << ".::::::::   .::       .::   .::       .::         .::     .::      .::::::::"; _sleep(100);

		x = x + 6;
		y = y + 7;

		Console::SetCursorPosition(x + 5, y + 7);
		Console::ForegroundColor = ConsoleColor::Cyan; _sleep(100);
		cout << "F E L I C I D A D E S   A   A M B O S   P L A Y E R S !";

		x = x - 6;
	}

	x = x + 20;
	y = y + 9;

	Console::SetCursorPosition(x, y); _sleep(100);
	cout << "< Presiona cualquier tecla para salir >";
	_getch();
	exit(0);

}