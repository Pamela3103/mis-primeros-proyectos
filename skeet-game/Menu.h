#pragma once

#include<iostream>
#include<conio.h>

using namespace std;
using namespace System;
#define ANCHO 140
#define ALTO 40

void setXY(int x, int y)
{
	Console::SetCursorPosition(x, y);
}
void setColor(int c)
{
	switch (c)
	{
	case 1:Console::ForegroundColor = ConsoleColor::Black;       break;
	case 2:Console::ForegroundColor = ConsoleColor::Blue;		 break;
	case 3:Console::ForegroundColor = ConsoleColor::Cyan;		 break;
	case 4:Console::ForegroundColor = ConsoleColor::DarkBlue;	 break;
	case 5:Console::ForegroundColor = ConsoleColor::DarkCyan;	 break;
	case 6:Console::ForegroundColor = ConsoleColor::DarkGray;	 break;
	case 7:Console::ForegroundColor = ConsoleColor::DarkGreen;	 break;
	case 8:Console::ForegroundColor = ConsoleColor::DarkMagenta; break;
	case 9:Console::ForegroundColor = ConsoleColor::DarkRed;	 break;
	case 10:Console::ForegroundColor = ConsoleColor::DarkYellow; break;
	case 11:Console::ForegroundColor = ConsoleColor::Gray;		 break;
	case 12:Console::ForegroundColor = ConsoleColor::Green;		 break;
	case 13:Console::ForegroundColor = ConsoleColor::Magenta;	 break;
	case 14:Console::ForegroundColor = ConsoleColor::Red;		 break;
	case 15:Console::ForegroundColor = ConsoleColor::White;		 break;
	case 16:Console::ForegroundColor = ConsoleColor::Yellow;	 break;
	}
}
void setBGcolor(int c)
{
	switch (c)
	{
	case 1:Console::BackgroundColor = ConsoleColor::Black;       break;
	case 2:Console::BackgroundColor = ConsoleColor::Blue;		 break;
	case 3:Console::BackgroundColor = ConsoleColor::Cyan;		 break;
	case 4:Console::BackgroundColor = ConsoleColor::DarkBlue;	 break;
	case 5:Console::BackgroundColor = ConsoleColor::DarkCyan;	 break;
	case 6:Console::BackgroundColor = ConsoleColor::DarkGray;	 break;
	case 7:Console::BackgroundColor = ConsoleColor::DarkGreen;	 break;
	case 8:Console::BackgroundColor = ConsoleColor::DarkMagenta; break;
	case 9:Console::BackgroundColor = ConsoleColor::DarkRed;	 break;
	case 10:Console::BackgroundColor = ConsoleColor::DarkYellow; break;
	case 11:Console::BackgroundColor = ConsoleColor::Gray;		 break;
	case 12:Console::BackgroundColor = ConsoleColor::Green;		 break;
	case 13:Console::BackgroundColor = ConsoleColor::Magenta;	 break;
	case 14:Console::BackgroundColor = ConsoleColor::Red;		 break;
	case 15:Console::BackgroundColor = ConsoleColor::White;		 break;
	case 16:Console::BackgroundColor = ConsoleColor::Yellow;	 break;
	}
}
void dibujaNube_1(int x, int y)
{
	char block = char(219);
	setBGcolor(3);
	setColor(15);
	setXY(x, y); cout << "                        " << block << block << block << block << block << block << block << block << "     " << block << block << block << block << block << block << block << block << "\n";
	setXY(x, y + 1); cout << "                        " << block << block << block << "     " << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << "\n";
	setXY(x, y + 2); cout << "                 " << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << "\n";
	setXY(x, y + 3); cout << "       " << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << "\n";
	setXY(x, y + 4); cout << "   " << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << "\n";
	setXY(x, y + 5); cout << "       " << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << "\n";
	setXY(x, y + 6); cout << "                           " << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << "  " << block << block << block << block << block << block << block << "\n";
}

void dibujaNube_2(int x, int y)
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
void dibujaNube_3(int x, int y)
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

void Fondo_1()
{
	setBGcolor(3);
	Console::Clear();
	dibujaNube_1(0, 15);
	dibujaNube_2(100, ALTO - 10);
	dibujaNube_2(100, ALTO - 30);
	dibujaNube_3(0, ALTO - 12);
}
void Fondo_2()
{
	setBGcolor(3);
	Console::Clear();
	dibujaNube_1(85, 12);
	dibujaNube_2(5, ALTO - 11);
	dibujaNube_3(0, 4);

}
void GeneraCuadroMenu(int x, int y, int ancho, int alto, int color)
{

	setBGcolor(color);
	for (int j = 0; j < alto; j++)
	{
		for (int i = 0; i < ancho; i++)
		{
			setXY(x + i, y);
			cout << " ";

		}
		y = y + 1;
	}

}

void Titulo_AcercaDe()
{
	int x = ANCHO / 10 + 33;
	int y = 5;
	setXY(x, y);	 setColor(4); cout << "    _                                _      ";
	setXY(x, y + 1); setColor(4); cout << "   / \\   ___ ___ _ __ ___ __ _    __| | ___ ";
	setXY(x, y + 2); setColor(4); cout << "  / _ \\ / __/ _ \\ '__/ __/ _` |  / _` |/ _ \\";
	setXY(x, y + 3); setColor(4); cout << " / ___ \\ (_|  __/ | | (_| (_| | | (_| |  __/";
	setXY(x, y + 4); setColor(4); cout << "/_/   \\_\\___\\___|_|  \\___\\__,_|  \\__,_|\\___|";

}
void Creadoras()
{
	int x = 16;
	int y = 16;
	//PAMELA
	setXY(x, y); setColor(1); setBGcolor(16);
	cout << " PAMELA RIVERA ";

	y = y + 3; x = 10; setColor(15); setBGcolor(7);
	setXY(x, y); cout << "Edad: 18";

	y = y + 2; x = 10;
	setXY(x, y); cout << "Universidad: UPC";

	y = y + 2; x = 10;
	setXY(x, y); cout << "Carrera: Computer Science";

	y = y + 2;
	setXY(x, y); cout << "Hobbie: Ver Netflix";

	y = y + 2;
	setXY(x, y); cout << "Deporte: Patinaje y Surf";

	//XIMENA
	x = 62; y = 16; setColor(1); setBGcolor(16);
	setXY(x, y); cout << " XIMENA GONZALES ";
	y = y + 3; x = 57;  setColor(15); setBGcolor(7);
	setXY(x, y); cout << "Edad: 20";
	y = y + 2;
	setXY(x, y); cout << "Universidad: UPC";
	y = y + 2;
	setXY(x, y); cout << "Carrera: Computer Science";
	y = y + 2;
	setXY(x, y); cout << "Hobbie: Leer";

	y = y + 2;
	setXY(x, y); cout << "Deporte: Patinaje sobre";
	setXY(x + 9, y + 1); cout << "Hielo";
	//NADIA
	x = 110; y = 16; setColor(1); setBGcolor(16);
	setXY(x, y); cout << " NADIA HUAMAN ";
	y = y + 3; x = 104; setColor(15); setBGcolor(7);
	setXY(x, y); cout << "Edad: 26";
	y = y + 2;
	setXY(x, y); cout << "Universidad: UPC";
	y = y + 2;
	setXY(x, y); cout << "Carrera: Ing. Sotware";
	y = y + 2;
	setXY(x, y); cout << "Hobbie: Ver Netflix";

	y = y + 2;
	setXY(x, y); cout << "Deporte: Tenis de Mesa";
}
void AcercaDe()
{
	Console::Clear();
	Fondo_2();
	Titulo_AcercaDe();

	GeneraCuadroMenu(8, 15, 30, 16, 12);
	GeneraCuadroMenu(55, 15, 30, 16, 12);
	GeneraCuadroMenu(102, 15, 30, 16, 12);

	Creadoras();

	int x = ANCHO / 2 - 12;
	int y = ALTO - 4;
	setBGcolor(3);
	setXY(x, y); setColor(14); cout << "[Presione cualquier tecla]";
}

void Titulo_Instrucciones()
{
	int x = ANCHO / 10 + 25;
	int y = 5;
	setXY(x, y);	 setColor(4); cout << " ___           _                       _                       ";
	setXY(x, y + 1); setColor(4); cout << "|_ _|_ __  ___| |_ _ __ _   _  ___ ___(_) ___  _ __   ___  ___ ";
	setXY(x, y + 2); setColor(4); cout << " | || '_ \\/ __| __| '__| | | |/ __/ __| |/ _ \\| '_ \\ / _ \\/ __|";
	setXY(x, y + 3); setColor(4); cout << " | || | | \\__ \\ |_| |  | |_| | (_| (__| | (_) | | | |  __/\\__ \\";
	setXY(x, y + 4); setColor(4); cout << "|___|_| |_|___/\\__|_|   \\__,_|\\___\\___|_|\\___/|_| |_|\\___||___/";
}
void Texto()
{
	int x = ANCHO / 10 + 12;
	int y = 15;

	setXY(x, y);
	setColor(1); setBGcolor(16); cout << " 1 "; setBGcolor(12); cout << " "; setBGcolor(7); setColor(15); cout << "El presente juego esta basado en la disciplina deportiva 'tiro al plato'. El cual";
	y = y + 1;
	setXY(x + 4, y); cout << "tiene como proposito dispararle a los objetivos en movimiento.";
	y = y + 2;
	setColor(1); setBGcolor(16); setXY(x, y); cout << " 2 "; setBGcolor(12); cout << " "; setBGcolor(7); setColor(15); cout << "El juego consta de 3 fases, en la fase 1 sale un objetivo a la vez y en la fase";
	y = y + 1;
	setXY(x + 4, y); cout << "2 y 3 pueden salir 1 o 2 objetivos en simultaneo.";
	y = y + 2;
	setColor(1); setBGcolor(16); setXY(x, y); cout << " 3 "; setBGcolor(12); cout << " "; setBGcolor(7); setColor(15); cout << "Para iniciar el juego debes dar la se" << char(164) << "al presionando cualquier tecla y empezara la";
	y = y + 1;
	setXY(x + 4, y); cout << "cuenta regresiva de 3 a 0 para empezar a jugar.";
	y = y + 2;
	setColor(1); setBGcolor(16); setXY(x, y); cout << " 4 "; setBGcolor(12); cout << " "; setBGcolor(7); setColor(15); cout << "Solo podras moverte de izquierda a derecha y disparar presionando la tecla espacio.";
	y = y + 1;
	setXY(x + 4, y); cout << "La velocidad de los objetivos y los disparos permitidos dependen de la fase";
	y = y + 2;
	setColor(1); setBGcolor(16); setXY(x, y); cout << " 5 "; setBGcolor(12); cout << " "; setBGcolor(7); setColor(15); cout << "Una vez en el juego, encontraras toda la informacion necesaria en la parte superior";
	y = y + 1;
	setXY(x + 4, y); cout << "de la pantalla.";
	y = y + 2;
	setColor(1); setBGcolor(16); setXY(x, y); cout << " 6 "; setBGcolor(12); cout << " "; setBGcolor(7); setColor(15); cout << "La parte final del juego es un podio con los 3 mejores paises. Una vez llegado ahi";
	y = y + 1;
	setXY(x + 4, y); cout << "deberas presionar cualquier tecla para salir.";

}
void Instrucciones()
{
	Console::Clear();
	Fondo_2();
	Titulo_Instrucciones();
	GeneraCuadroMenu(ANCHO / 10 + 10, 13, 92, 21, 12);

	int x = ANCHO / 2 - 12;
	int y = ALTO - 4;
	setBGcolor(3);
	setXY(x, y); setColor(14); cout << "[Presione cualquier tecla]";

	Texto();
}
void BorrarTexto(int x, int y)
{
	setXY(x, y); cout << "                         ";
}
void dibujaSeparacion(int x, int y)
{
	char block = char(219);

	setColor(3);
	for (int f = 1; f <= 1; f++)
	{
		setXY(x, y);
		for (int c = 1; c <= 92; c++)
		{
			cout << block;
		}
		cout << endl;
		y++;
	}
}

void dibujaSeparacion2(int x, int y)
{
	char block = char(219);

	setColor(3);
	for (int f = 1; f <= 21; f++)
	{
		setXY(x, y);
		for (int c = 1; c <= 2; c++)
		{
			cout << block;
		}
		cout << endl;
		y++;
	}
}

void dibujaPuntaje40(int x, int y)
{
	setColor(1);
	setXY(x, y);	 cout << "        __  ";
	setXY(x, y + 1); cout << " |  |  /  % ";
	setXY(x, y + 2); cout << " |__|_|    |";
	setXY(x, y + 3); cout << "    | |    |"; cout << " puntos";
	setXY(x, y + 4); cout << "    |  %__/ ";
}

void dibujaPuntaje20(int x, int y)
{
	setColor(1);
	setXY(x, y); cout << "  __  __  ";
	setXY(x, y + 1); cout << " /  )/  % ";
	setXY(x, y + 2); cout << "   /|    |";
	setXY(x, y + 3); cout << "  / |    |"; cout << " puntos";
	setXY(x, y + 4); cout << " /___%__/ ";

}

void dibujaPuntajeMenos5(int x, int y)
{
	setColor(1);
	setXY(x, y); cout << "         ____";
	setXY(x, y + 1); cout << "        |    ";
	setXY(x, y + 2); cout << "        |___ ";
	setXY(x, y + 3); cout << " -----      %"; cout << "  puntos";
	setXY(x, y + 4); cout << "        %___/";

}
void Titulo_Puntajes()
{
	int x = ANCHO / 10 + 39;
	int y = 5;
	setXY(x, y);	 setColor(4); cout << " ____              _         _          ";
	setXY(x, y + 1); setColor(4); cout << "|  _ \\ _   _ _ __ | |_ __ _ (_) ___  ___";
	setXY(x, y + 2); setColor(4); cout << "| |_) | | | | '_ \\| __/ _` || |/ _ \\/ __|";
	setXY(x, y + 3); setColor(4); cout << "|  __/| |_| | | | | || (_| || |  __/\\__ \\";
	setXY(x, y + 4); setColor(4); cout << "|_|    \\__,_|_| |_|\\__\\__,_|/ |\\___||___/";
	setXY(x, y + 5); setColor(4); cout << "                          |__/           ";
}
void Puntajes()
{
	Console::Clear();
	Fondo_2();
	Titulo_Puntajes();
	GeneraCuadroMenu(ANCHO / 10 + 15, 13, 90, 21, 12);
	dibujaSeparacion(ANCHO / 10 + 15, 19);
	dibujaSeparacion(ANCHO / 10 + 15, 26);
	dibujaSeparacion2(75, 13);
	dibujaPuntaje20(44, 13);
	dibujaPuntaje40(43, 20);
	dibujaPuntajeMenos5(40, 28);
	setXY(92, 16); cout << "TIRO   NORMAL";
	setXY(90, 23); cout << "COLISION   DOBLE";
	setXY(86, 29); cout << "SI   TE   SALES   DE  LOS";
	setXY(89, 30); cout << "LIMITES   DE   LAS";
	setXY(89, 31); cout << "CASETAS   DE   TIRO";

	int x = ANCHO / 2 - 10;
	int y = ALTO - 4;
	setBGcolor(3);
	setXY(x, y); setColor(14); cout << "[Presione cualquier tecla]";
}


void MenuOpciones()
{

	int x1 = 58;
	int y1 = 13;

	setXY(x1, y1); setBGcolor(16);

	for (int j = 0; j < 3; j++)
	{
		for (int i = 0; i < 25; i++)
		{
			setXY(x1 + i, y1);
			cout << " ";

		}
		y1 = y1 + 1;
	}
	x1 = x1 + 9;
	y1 = 14;

	setXY(x1, y1); setColor(1); cout << "M E N U";

	x1 = x1 - 6;
	y1 = 18;
	setXY(x1, y1); setBGcolor(10); setColor(15); cout << " 1 ";
	setBGcolor(4); cout << "  Instrucciones";

	y1 = 20;
	setXY(x1, y1); setBGcolor(10); setColor(15); cout << " 2 ";
	setBGcolor(4); cout << "  Acerca de";

	y1 = 22;
	setXY(x1, y1); setBGcolor(10); setColor(15); cout << " 3 ";
	setBGcolor(4); cout << "  Puntajes";

	y1 = 24;
	setXY(x1, y1); setBGcolor(10); setColor(15); cout << " 4 ";
	setBGcolor(4); cout << "  Iniciar Juego";
}

void dibujarEscopeta(int x, int y, int color)
{
	char block = char(219);

	setColor(1);
	setBGcolor(color);
	setXY(x + 26, y); cout << block << block;
	setXY(x + 23, y + 1); cout << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block;
	setXY(x + 20, y + 2); cout << block << block << block << "           " << block << block << "                              " << block << block;
	setXY(x, y + 3); cout << block << block << block << block << block << block << block; setBGcolor(11); cout << "       " << block << block << block << block << block << block; setBGcolor(color); cout << "              " << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << "       " << block << block << "      " << block << block << block;
	setXY(x, y + 4); cout << block << block << "    " << block << block << block; setBGcolor(11); cout << "  " << block << block << block; setBGcolor(color); cout << "   " << block << "                " << block << block << "            " << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block;
	setXY(x, y + 5); cout << block << block << "      " << block << block << block << block << "     " << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block;
	setXY(x, y + 6); cout << block << block << "   " << block << block << "         " << block << block << block << block << block << block << block << block << block;
	setXY(x, y + 7); cout << block << block << "  " << block << block << block << block << "       " << block << block;
	setBGcolor(11); setXY(x, y + 8); cout << block << block << block << block << "    " << block << block << block << block << block << block << block;
}

void Escopeta(int x, int y, int color)
{
	dibujarEscopeta(x, y, color);
}
void dibujarEscopetaLogo(int x, int y, int color)
{
	char block = char(219);

	setColor(1);
	setBGcolor(color);
	setXY(x + 26, y); cout << block << block;
	setXY(x + 23, y + 1); cout << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block;
	setXY(x + 20, y + 2); cout << block << block << block << "           " << block << block << "                              " << block << block;
	setXY(x, y + 3); cout << block << block << block << block << block << block << block; setBGcolor(11); cout << "       " << block << block << block << block << block << block; setBGcolor(color); cout << "              " << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << "       " << block << block << "      " << block << block << block;
	setXY(x, y + 4); cout << block << block << "    " << block << block << block; setBGcolor(11); cout << "  " << block << block << block; setBGcolor(color); cout << "   " << block << "                " << block << block << "            " << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block;
	setXY(x, y + 5); cout << block << block << "      " << block << block << block << block << "     " << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block;
	setXY(x, y + 6); cout << block << block << "   " << block << block << "         " << block << block << block << block << block << block << block << block << block;
	setXY(x, y + 7); cout << block << block << "  " << block << block << block << block << "       " << block << block;
	setBGcolor(11); setXY(x, y + 8); cout << block << block << block << block << "    " << block << block << block << block << block << block << block;
}
void GeneraBarra(int x, int y)
{
	setXY(x, y); setBGcolor(9); cout << " ";
}
void GeneraPorcentaje(int x, int y, int contador)
{
	setXY(x, y); setBGcolor(11); setColor(1); cout << contador << "%";
}
void GeneraLoading(int x, int y)
{
	GeneraCuadroMenu(x, y, 102, 1, 1);
	GeneraCuadroMenu(x, y, 1, 3, 1);
	GeneraCuadroMenu(x, y + 2, 102, 1, 1);
	GeneraCuadroMenu(x + 102, y, 1, 3, 1);

	int x1 = x + 1;
	int contador = 0;

	int xP = ANCHO - 15;
	int yP = y + 1;

	setBGcolor(11);
	setXY(71, ALTO - 2); setColor(1); cout << "LOADING ...";

	while (contador <= 100)
	{
		;
		GeneraBarra(x1, y + 1);
		GeneraPorcentaje(xP, yP, contador);
		contador++;
		x1++;
		_sleep(75);
	}
	_sleep(700);
}
void dibujaskeet(float x1, float y1)
{
	setColor(4); setXY(x1, y1);  cout << char(219) << char(219) << char(219) << char(219) << char(219) << char(219); setColor(7); setXY(x1 + 7, y1); cout << char(219) << char(219) << " " << " " << char(219) << char(219); setColor(14);  setXY(x1 + 14, y1); cout << char(219) << char(219) << char(219) << char(219) << char(219) << char(219); setXY(x1 + 21, y1); setColor(16);  cout << char(219) << char(219) << char(219) << char(219) << char(219) << char(219); setXY(x1 + 28, y1); setColor(8);  cout << char(219) << char(219) << char(219) << char(219) << char(219) << char(219);
	setColor(4); setXY(x1, y1 + 1);  cout << char(219) << char(219); setColor(7); setXY(x1 + 7, y1 + 1); cout << char(219) << char(219) << " " << char(219) << char(219); setColor(14);  setXY(x1 + 14, y1 + 1); cout << char(219) << char(219); setColor(16);  setXY(x1 + 21, y1 + 1); cout << char(219) << char(219); setXY(x1 + 28, y1 + 1); setColor(8);  cout << " " << " " << char(219) << char(219);
	setColor(4); setXY(x1, y1 + 2);  cout << char(219) << char(219) << char(219) << char(219) << char(219) << char(219); setColor(7);  setXY(x1 + 7, y1 + 2); cout << char(219) << char(219) << char(219) << char(219); setColor(14);  setXY(x1 + 14, y1 + 2); cout << char(219) << char(219) << char(219) << char(219) << char(219) << char(219); setColor(16);  setXY(x1 + 21, y1 + 2); cout << char(219) << char(219) << char(219) << char(219) << char(219) << char(219); setXY(x1 + 28, y1 + 2); setColor(8);  cout << " " << " " << char(219) << char(219);
	setColor(4); setXY(x1, y1 + 3); cout << " " << " " << " " << " " << char(219) << char(219); setColor(7);  setXY(x1 + 7, y1 + 3); cout << char(219) << char(219) << " " << char(219) << char(219); setColor(14);  setXY(x1 + 14, y1 + 3); cout << char(219) << char(219); setColor(16);  setXY(x1 + 21, y1 + 3); cout << char(219) << char(219); setXY(x1 + 28, y1 + 3); setColor(8);  cout << " " << " " << char(219) << char(219);
	setColor(4); setXY(x1, y1 + 4); cout << char(219) << char(219) << char(219) << char(219) << char(219) << char(219); setColor(7);  setXY(x1 + 7, y1 + 4); cout << char(219) << char(219) << " " << " " << char(219) << char(219); setColor(14);  setXY(x1 + 14, y1 + 4); cout << char(219) << char(219) << char(219) << char(219) << char(219) << char(219); setColor(16); setXY(x1 + 21, y1 + 4); cout << char(219) << char(219) << char(219) << char(219) << char(219) << char(219); setXY(x1 + 28, y1 + 4); setColor(8);  cout << " " << " " << char(219) << char(219);
}

void dibujagame(float x1, float y1)
{
	setColor(13); setXY(x1, y1);  cout << char(219) << char(219) << char(219) << char(219) << char(219) << char(219); setColor(9); setXY(x1 + 7, y1);  cout << char(219) << char(219) << char(219) << char(219) << char(219) << char(219); setColor(15); setXY(x1 + 14, y1);  cout << char(219) << char(219) << " " << " " << " " << " " << " " << " " << char(219) << char(219); setXY(x1 + 25, y1); setColor(12);  cout << char(219) << char(219) << char(219) << char(219) << char(219) << char(219);
	setColor(13); setXY(x1, y1 + 1);  cout << char(219) << char(219); setColor(9); setXY(x1 + 7, y1 + 1);  cout << char(219) << char(219) << " " << " " << char(219) << char(219); setColor(15); setXY(x1 + 14, y1 + 1);  cout << char(219) << char(219) << char(219) << char(219) << " " << " " << char(219) << char(219) << char(219) << char(219); setXY(x1 + 25, y1 + 1); setColor(12);  cout << char(219) << char(219);
	setColor(13); setXY(x1, y1 + 2);  cout << char(219) << char(219) << " " << char(219) << char(219) << char(219); setColor(9); setXY(x1 + 7, y1 + 2);  cout << char(219) << char(219) << char(219) << char(219) << char(219) << char(219); setColor(15); setXY(x1 + 14, y1 + 2);  cout << char(219) << char(219) << " " << " " << char(219) << char(219) << " " << " " << char(219) << char(219); setXY(x1 + 25, y1 + 2); setColor(12);  cout << char(219) << char(219) << char(219) << char(219) << char(219) << char(219);
	setColor(13); setXY(x1, y1 + 3);  cout << char(219) << char(219) << " " << " " << char(219) << char(219); setColor(9); setXY(x1 + 7, y1 + 3);  cout << char(219) << char(219) << " " << " " << char(219) << char(219); setColor(15); setXY(x1 + 14, y1 + 3);  cout << char(219) << char(219) << " " << " " << " " << " " << " " << " " << char(219) << char(219); setXY(x1 + 25, y1 + 3); setColor(12);  cout << char(219) << char(219);
	setColor(13); setXY(x1, y1 + 4);  cout << char(219) << char(219) << char(219) << char(219) << char(219) << char(219); setColor(9); setXY(x1 + 7, y1 + 4);  cout << char(219) << char(219) << " " << " " << char(219) << char(219); setColor(15); setXY(x1 + 14, y1 + 4);  cout << char(219) << char(219) << " " << " " << " " << " " << " " << " " << char(219) << char(219); setXY(x1 + 25, y1 + 4); setColor(12);  cout << char(219) << char(219) << char(219) << char(219) << char(219) << char(219);

}
void VentanaInicio()
{
	setBGcolor(11);
	Console::Clear();
	dibujaskeet(ANCHO / 2 - 12, 6);
	dibujarEscopeta(35, 14, 2);
	dibujagame(ANCHO / 2 - 10, 23);
	GeneraLoading(18, ALTO - 6);
}
void Presentacion()
{
	int opc;
	VentanaInicio();
	Console::Clear();
	while (!(opc == 4))
	{
		Fondo_1();

		GeneraCuadroMenu(45, 14, 50, 13, 4);
		MenuOpciones();

		int x = ANCHO / 2 - 7;
		int y = ALTO - 8;


		do {
			setXY(x, y); setColor(13); setBGcolor(3); cout << "Elige una opcion -> "; cin >> opc;
			BorrarTexto(x, y);
		} while (!(opc == 1 || opc == 2 || opc == 3 || opc == 4));
		switch (opc)
		{
		case 1: Instrucciones(); _getch(); setBGcolor(3); Console::Clear(); break;
		case 2: AcercaDe(); _getch(); setBGcolor(3); Console::Clear(); break;
		case 3: Puntajes(); _getch(); setBGcolor(3); Console::Clear(); break;
		}

	}
	setBGcolor(1);
	Console::Clear();
}
