#pragma once
#pragma once
#include<iostream>
#include<conio.h>

using namespace std;
using namespace System;
#define ANCHO 140
#define ALTO 40

//FONDO DE ESCENARIO DEPORTIVO
void dibujaCielo(int x, int y, int color)
{
	int contador = 0;
	while (contador < 21)
	{
		setXY(x, y);
		for (int i = 0; i < ANCHO; i++)
		{
			setBGcolor(color);
			cout << " ";
		}
		y++; contador++;

	}
}
void dibujaNube1(int x, int y)
{
	char block = char(219);

	setColor(15);
	setXY(x, y); cout << "                                                               " << block << block << block << block << block << block << block << block << "     " << block << block << block << block << block << block << block << block << "\n";
	setXY(x, y + 1); cout << "                        " << block << block << block << "     " << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << "\n";
	setXY(x, y + 2); cout << "                 " << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << "\n";
	setXY(x, y + 3); cout << "       " << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << "\n";
	setXY(x, y + 4); cout << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << "\n";
	setXY(x, y + 5); cout << "       " << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << "\n";
	setXY(x, y + 6); cout << "                           " << block << block << block << "   " << block << block << block << block << block << block << block << block << block << "  " << block << block << block << block << block << block << block << block << "  " << block << block << block << block << block << block << block << "\n";
}
void dibujaNube2(int x, int y)
{
	char block = char(219);

	setColor(15);
	setXY(x, y); cout << "                                                               " << block << block << block << block << block << block << block << block << "     " << block << block << block << block << block << block << block << block << "\n";
	setXY(x, y + 1); cout << "                        " << block << block << block << "     " << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << "\n";
	setXY(x, y + 2); cout << "                 " << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << "\n";
	setXY(x, y + 3); cout << "       " << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << "\n";
	setXY(x, y + 4); cout << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << "\n";
	setXY(x, y + 5); cout << "       " << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << "\n";
	setXY(x, y + 6); cout << "                           " << block << block << block << "   " << block << block << block << block << block << block << block << block << block << "  " << block << block << block << block << block << block << block << block << "\n";
}
void dibujaNube3(int x, int y)
{
	char block = char(219);

	setColor(15);
	setXY(x, y); cout << "                               " << block << block << block << block << block << block << block << "           \n";
	setXY(x, y + 1); cout << "                        " << block << block << block << block << block << block << block << block << block << block << block << "      \n";
	setXY(x, y + 2); cout << "       " << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << " \n";
	setXY(x, y + 3); cout << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << "\n";

}


void Cielo_1()
{
	dibujaCielo(0, 0, 3);
	dibujaNube1(5, 1);
	dibujaNube1(19, 5);
	dibujaNube1(2, 10);
	dibujaNube2(90, 5);
	dibujaNube2(100, 0);
	dibujaNube3(80, 11);
	dibujaNube3(90, 13);
}

void dibujaGrass(int x, int y)
{
	int contador = 0;
	while (contador < 21)
	{
		setXY(x, y);
		for (int i = 0; i < ANCHO; i++)
		{
			setBGcolor(12);
			cout << " ";
		}
		y++; contador++;

	}
}
//ESCENARIO DEPORTIVO
int Aleatorio(int a, int b)
{
	return a + rand() % (b - a + 1);
}
void dibujaGrass2(int N, int x, int y)
{
	char caracter = '^';

	setBGcolor(12);
	setColor(7);
	for (int i = 1; i < N; i++)
	{
		setXY(Aleatorio(2, x), Aleatorio(18, y)); cout << caracter;
	}

}
void dibujaLinea(int x, int y)
{
	int contador = 0;
	while (contador < 2)
	{
		setXY(x, y);
		for (int i = 0; i < ANCHO; i++)
		{
			setBGcolor(7);
			cout << " ";
		}
		y++; contador++;

	}
}

void Grass_1()
{
	int N = 300;
	dibujaLinea(0, 17);
	dibujaGrass(0, 18);
	dibujaGrass2(N, 139, 38);
}

void Zona_de_Tiro(int x, int y)
{
	char block = char(219);

	setColor(15);
	setXY(x, y); cout << "                                  " << block << block << "  " << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << "\n";
	setXY(x, y + 1); cout << "                             " << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << "\n";
	setXY(x, y + 2); cout << "                        " << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << "\n";
	setXY(x, y + 3); cout << "                      " << block << block << block << block << block << block << block << block << block << block << block << block << "  \n";
	setXY(x, y + 4); cout << "                    " << block << block << block << block << block << block << block << block << block << block << block << block << "     \n";
	setXY(x, y + 5); cout << "                 " << block << block << block << block << block << block << block << block << block << block << block << block << block << "     \n";
	setXY(x, y + 6); cout << "                 " << block << block << block << block << block << block << block << block << block << block << block << block << "       \n";
	setXY(x, y + 7); cout << "               " << block << block << block << block << block << block << block << block << block << block << block << block << block << "      \n";
	setXY(x, y + 8); cout << "                " << block << block << block << block << block << block << block << block << block << block << block << block << block << "    \n";
	setXY(x, y + 9); cout << "                 " << block << block << block << block << block << block << block << block << block << block << block << block << block << "  \n";
	setXY(x, y + 10); cout << "                 " << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << "\n";
	setXY(x, y + 11); cout << "                   " << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << "    " << block << block << block << block << block << block << block << "    " << block << block << block << block << block << block << block << block << block << "       " << block << block << block << block << block << block << block << "\n";
	setXY(x, y + 12); cout << "                    " << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << "\n";
	setXY(x, y + 13); cout << "                        " << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << "\n";
	setXY(x, y + 14); cout << "                              " << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << "\n";
	setXY(x, y + 15); cout << "                                  " << block << block << block << block << block << "  " << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << "   " << block << block << block << "\n";

}

void Caseta1(int x, int y)
{
	char block = char(219);

	setColor(10);
	setBGcolor(3); setXY(x, y); cout << "        " << block << block << block << block << block << block << block << block << block << block << block << block;
	setBGcolor(15); setXY(x, y + 1); cout << "        " << block << block << block << block << block << block << block << block << block << block << block << block;
	setBGcolor(15); setXY(x, y + 2); cout << "        " << block << block << block << block << block << block << block << block << block << block << block << block;
	setBGcolor(3); setXY(x, y + 3); cout << "        " << block << block << block << block << block << block << block << block << block << block << block << block;
	setBGcolor(15); setXY(x, y + 4); cout << "        " << block << block << block << block << block << block << block << block << block << block << block << block;
	setBGcolor(3); setXY(x, y + 5); cout << "        " << block << block << block << block << block << block << block << block << block << block << block << block;
	setXY(x, y + 6); cout << "        " << block << block << block << block << block << block << block << block << block << block << block << block;
	setBGcolor(7); setXY(x, y + 7); cout << "          " << block << block << block << "  " << block << block << block;
	setBGcolor(12); setXY(x, y + 8); cout << "          " << block << block << block << "  " << block << block << block;
	setXY(x, y + 9); cout << "          " << block << block << block << "  " << block << block << block;
	setXY(x, y + 10); cout << "          " << block << block << block << "  " << block << block << block;
	setXY(x, y + 11); cout << "          " << block << block << block << "  " << block << block << block;
	setXY(x, y + 12); cout << "          " << block << block << block << "  " << block << block << block;

}
void Caseta2(int x, int y)
{
	char block = char(219);

	setColor(10);
	setXY(x, y); cout << "        " << block << block << block << block << block << block << block << block << block << block << block << block;
	setXY(x, y + 1); cout << "        " << block << block << block << block << block << block << block << block << block << block << block << block;
	setXY(x, y + 2); cout << "        " << block << block << block << block << block << block << block << block << block << block << block << block;
	setXY(x, y + 3); cout << "        " << block << block << block << block << block << block << block << block << block << block << block << block;
	setXY(x, y + 4); cout << "        " << block << block << block << block << block << block << block << block << block << block << block << block;
	setXY(x, y + 5); cout << "        " << block << block << block << block << block << block << block << block << block << block << block << block;
	setXY(x, y + 6); cout << "        " << block << block << block << block << block << block << block << block << block << block << block << block;
	setXY(x, y + 7); cout << "          " << block << block << block << "  " << block << block << block;
	setXY(x, y + 8); cout << "          " << block << block << block << "  " << block << block << block;
	setXY(x, y + 9); cout << "          " << block << block << block << "  " << block << block << block;
	setXY(x, y + 10); cout << "          " << block << block << block << "  " << block << block << block;
	setXY(x, y + 11); cout << "          " << block << block << block << "  " << block << block << block;
	setXY(x, y + 12); cout << "          " << block << block << block << "  " << block << block << block;

}
void Hoyo_Caseta(int x, int y)
{
	char block = char(219);

	setColor(1);
	setXY(x, y); cout << block << block << block << block << block << block << block << block;
	setXY(x, y + 1); cout << block << block << block << block << block << block << block << block;
	setXY(x, y + 2); cout << block << block << block << block << block << block << block << block;
}

void Caseta_de_Tiro()
{
	Caseta1(115, 10);
	Caseta2(110, 25);
	Hoyo_Caseta(125, 12);
}

void DibujarEscenarioDeportivo()
{
	Cielo_1();
	Grass_1();
	Zona_de_Tiro(30, 21);
	Caseta_de_Tiro();
}

void Escenario_Deportivo()
{
	DibujarEscenarioDeportivo();
}
