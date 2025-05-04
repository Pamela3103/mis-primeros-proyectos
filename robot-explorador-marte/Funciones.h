#pragma once


#define ANCHO 120
#define ALTO 40

void setXY(int x, int y)
{
	Console::SetCursorPosition(x, y);
}
void BorrarNave(int x, int y)
{
	setXY(x, y);    	cout << "                    ";
	setXY(x, y + 1);	cout << "                    ";
	setXY(x, y + 2);	cout << "                    ";
	setXY(x, y + 3);	cout << "                    ";
	setXY(x, y + 4);	cout << "                    ";
	setXY(x, y + 5);	cout << "                    ";
}
void DesplazarNaveMarte(int& x, int& y, int vx, int& vy)
{
	if (y >= 30 && x > 0)
	{
		vy = (-1) * vy;
	}
	if (vy < 0 && y == 1)
		vy = (-1) * vy;
	x = x + vx;
	y = y + vy;

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
void DibujarNave(int& x, int& y)
{
	setXY(x, y); setColor(2);      cout << "    ______;______  ";
	setXY(x, y + 1);  cout << "   //           \\\\";
	setXY(x, y + 2);  cout << "  //______0______\\\\";
	setXY(x, y + 3);  cout << "    //       \\\\ ";
	setXY(x, y + 4); setColor(16); cout << "   ;;;        ;;;";
	setXY(x, y + 5);  cout << "  ;;;;;      ;;;;;     ";
}
void NaveMarte(int& x, int& y, int vx, int& vy)
{
	BorrarNave(x, y);
	DesplazarNaveMarte(x, y, vx, vy);
	DibujarNave(x, y);
}
void DibujarMarte(int x, int y)
{
	Console::ForegroundColor = ConsoleColor::DarkRed;
	setXY(x, y);		cout << "          .,:;////";
	setXY(x, y + 1);	cout << "        _.uUU[[///";
	setXY(x, y + 2);    cout << "      _.u8UUU[[[[[";
	setXY(x, y + 3);	cout << "     .8O888UU[[[[[";
	setXY(x, y + 4);	cout << "    ON88888UU[[[[[";
	setXY(x, y + 5);	cout << "   dNMMNN888UU[[[[";
	setXY(x, y + 6);	cout << "  MMMMMMN888UU[[[[";
	setXY(x, y + 7);	cout << " NNMMMNN888UUU[[[[";
	setXY(x, y + 8);	cout << " 8888888888UU[[[[[";
	setXY(x, y + 9);	cout << " I88888888UUUU[[[[";
	setXY(x, y + 10);	cout << " Y8888888UUU[[[[[[";
	setXY(x, y + 11);	cout << " ^/O888UUUU[[[[[[[";
	setXY(x, y + 12);	cout << "  ^/88UUU[[[[[[[[[";
	setXY(x, y + 13);	cout << "   ^/UU[[[[[[[[[\\\\";
	setXY(x, y + 14);	cout << "    ^/[[[[[[[[\\\\\\\\";
	setXY(x, y + 15);	cout << "      ^/[[[[[\\\\\\\\\\";
	setXY(x, y + 16);	cout << "       ../\\\\\\\\\\\\\\";
	setXY(x, y + 17);	cout << "        .,:;\\\\\\\\\\\\";
}
int Aleatorio(int a, int b)
{
	return a + rand() % (b - a + 1);
}
float AleatorioDec()
{
	return ((float)rand() / RAND_MAX);
}
void DibujarEstrellas(int x, int y)
{
	int cont = 25;
	Console::ForegroundColor = ConsoleColor::White;
	for (int i = 1; i < cont; i++)
	{
		setXY(Aleatorio(2, 100), Aleatorio(2, 30)); cout << "+.";
	}

}

void GeneraCuadro(int ancho, int largo, int n)
{
	Console::ForegroundColor = ConsoleColor::White;
	Console::SetCursorPosition(ancho, largo);
	cout << char(218);
	for (int i = 1; i < n; i++)
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

	for (int i = 1; i < n; i++)
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
void Titulo(int& x, int& y)
{
	setColor(11); setXY(x, y);		cout << " _______  _______  __   __  _______        ___  _______  __   __ ";
	setColor(2); setXY(x, y + 1);  cout << "|       ||   _   ||  |_|  ||       |      |   ||   _   ||  |_|  |";
	setXY(x, y + 2);				cout << "|    ___||  |_|  ||       ||    ___|      |   ||  |_|  ||       |";
	setXY(x, y + 3);				cout << "|   | __ |       ||       ||   |___       |   ||       ||       |";
	setColor(3); setXY(x, y + 4);  cout << "|   ||  ||       ||       ||    ___|   ___|   ||       ||       |";
	setXY(x, y + 5);				cout << "|   |_| ||   _   || ||_|| ||   |___   |       ||   _   || ||_|| |";
	setXY(x, y + 6);				cout << "|_______||__| |__||_|   |_||_______|  |_______||__| |__||_|   |_|";
}
void TituloCredito(int x, int y)
{
	setColor(11); setXY(x, y);			cout << " .o88b. d8888b. d88888b d8888b. d888888b d888888b  .d88b.  .d8888.";
	setColor(2); setXY(x, y + 1);		cout << "d8P  Y8 88  `8D 88'     88  `8D   `88'   `~~88~~' .8P  Y8. 88'  YP";
	setColor(2); setXY(x, y + 2);		cout << "8P      88oobY' 88ooooo 88   88    88       88    88    88 `8bo.";
	setColor(2); setXY(x, y + 3);		cout << "8b      88`8b   88~~~~~ 88   88    88       88    88    88   `Y8b.";
	setColor(3); setXY(x, y + 4);		cout << "Y8b  d8 88 `88. 88.     88  .8D   .88.      88    `8b  d8' db   8D";
	setColor(3); setXY(x, y + 5);		cout << " `Y88P' 88   YD Y88888P Y8888D' Y888888P    YP     `Y88P'  `8888Y";

}
void TituloInstrucciones(int x, int y)
{
	setColor(11); setXY(x, y);			cout << "d888888b d8b   db .d8888. d888888b d8888b. db    db  .o88b.  .o88b. d888888b  .d88b.  d8b   db d88888b .d8888. ";
	setColor(2); setXY(x, y + 1);		cout << "  `88'   888o  88 88'  YP `~~88~~' 88  `8D 88    88 d8P  Y8 d8P  Y8   `88'   .8P  Y8. 888o  88 88'     88'  YP";
	setColor(2); setXY(x, y + 2);		cout << "   88    88V8o 88 `8bo.      88    88oobY' 88    88 8P      8P         88    88    88 88V8o 88 88ooooo `8bo.  ";
	setColor(2); setXY(x, y + 3);		cout << "   88    88 V8o88   `Y8b.    88    88`8b   88    88 8b      8b         88    88    88 88 V8o88 88~~~~~   `Y8b.";
	setColor(3); setXY(x, y + 4);		cout << "  .88.   88  V888 db   8D    88    88 `88. 88b  d88 Y8b  d8 Y8b  d8   .88.   `8b  d8' 88  V888 88.     db   8D";
	setColor(3); setXY(x, y + 5);		cout << "Y888888P VP   V8P `8888Y'    YP    88   YD ~Y8888P'  `Y88P'  `Y88P' Y888888P  `Y88P'  VP   V8P Y88888P `8888Y'";
}
void Creditos()
{
	Console::Clear();
	int x = ANCHO / 6 + 10, y = ALTO / 10;
	TituloCredito(x, y);

	y = y + 10;
	GeneraCuadro(x, y, 65);

	x = x + 5;
	setXY(x, y + 2); setColor(5); cout << "Pamela Rivera: Menu, Interfaz Ludica e Interfaz Grafica";
	setXY(x, y + 5); setColor(5);  cout << "Ximena Perez: Pantallas de Transicion e Interfaz Grafica";
	setXY(x, y + 8); setColor(5);  cout << "Nadia Huaman: Dise"; cout << char(164); cout << "o de personajes e Interfaz Grafica";

	y = ALTO - 10;
	setXY(x + 11, y); setColor(7);  cout << "[Ingrese Cualquier Tecla para Volver]";
	//Presentacion();

}

void Instrucciones()
{
	Console::Clear();
	int x = ANCHO / 6 - 15, y = ALTO / 10;
	TituloInstrucciones(x, y);
	y = y + 10;
	GeneraCuadro(x + 15, y, 80);

	x = x + 15;

	setXY(x + 5, y + 2); setColor(5); cout << "1) En el juego te encontraras con Meteoritos, los cuales te impediran";
	setXY(x + 5, y + 3); setColor(5); cout << "   aterrizar. Los Meteoritos estaticos no causan gran da" << char(164); cout << "o, puedes";
	setXY(x + 5, y + 4); setColor(5); cout << "   pasar a traves de ellos pero los Meteoritos en Movimiento si causan";
	setXY(x + 5, y + 5); setColor(5); cout << "   da" << char(164); cout << "o a la Nave.";
	setXY(x + 5, y + 6); setColor(5); cout << "   Debes evitar chocar con ellos para poder extraer las muestras.";
	setXY(x + 5, y + 8); setColor(5); cout << "2) Para extraer las Muestras tendras un tiempo limite.";
	setXY(x + 5, y + 9); setColor(5); cout << "   Extrae la mayor Cantidad de Muestras que puedas antes de enviarlas.";



	setXY(x + 23, ALTO - 10); setColor(7); cout << "[Ingrese Cualquier Tecla para Volver]";
}
int Opcion(int x, int y)
{
	int opc;
	setXY(x, y); setColor(7); cout << "Ingrese Opcion: "; cin >> opc;
	return opc;
}
void BorrarTexto(int x, int y)
{
	setXY(x, y);
	cout << "                                    ";
}
void Presentacion()
{
	int opc;
	int x = ANCHO / 6, y = ALTO / 10;
	x = x + 10;

	Titulo(x, y);

	y = y + 10;
	setXY(x + 20, y); setColor(7); cout << "M I S I O N  A  M A R T E";

	y = y + 3;
	GeneraCuadro(x, y, 65);

	y = y + 2;
	x = x + 20;

	setXY(x + 7, y); setColor(5); cout << "OBJETIVO:";
	x = x - 10;
	setColor(3);
	setXY(x, y + 1); cout << "Aterrizar en la superficie del planeta Marte";
	setXY(x, y + 2); cout << " y enviar muestras recolectadas a la Tierra.";
	setColor(5);
	setXY(x + 18, y + 4); cout << "MENU:";
	x = x + 7;
	y = y + 4;
	setColor(3);
	setXY(x, y + 1); cout << "[1] Creditos";
	setXY(x, y + 2); cout << "[2] Instrucciones";
	setXY(x, y + 3); cout << "[3] Comenzar Mision";

	do {
		BorrarTexto(ANCHO / 2 - 5, ALTO - 7);
		setXY(ANCHO / 2 - 5, ALTO - 7); setColor(7); cout << "Ingrese Opcion: "; cin >> opc;
	} while (!(opc == 1 || opc == 2 || opc == 3));

	if (opc == 1)
	{
		Creditos(); _getch(); Console::Clear(); Presentacion();
	}

	if (opc == 2)
	{
		Instrucciones(); _getch(); Console::Clear(); Presentacion();
	}
	if (opc == 3)
	{
		Console::Clear();
	}
	if (!(opc == 3 || opc == 1 || opc == 2))
	{
		BorrarTexto(ANCHO / 2 - 7, ALTO - 5);
		Opcion(ANCHO / 2 - 7, ALTO - 5);
	}
}

void TituloTiempo(int x, int y)
{
	setColor(11); setXY(x, y);			cout << "d888888b d888888b d88888b .88b  d88. d8888b.  .d88b.    db";
	setColor(16); setXY(x, y + 1);		cout << "`~~88~~'   `88'   88'     88'YbdP`88 88  `8D .8P  Y8.   88";
	setColor(16); setXY(x, y + 2);		cout << "   88       88    88ooooo 88  88  88 88oodD' 88    88   YP";
	setColor(10); setXY(x, y + 3);		cout << "   88       88    88~~~~~ 88  88  88 88~~~   88    88     ";
	setColor(10); setXY(x, y + 4);		cout << "   88      .88.   88.     88  88  88 88      `8b  d8'   db";
	setColor(10); setXY(x, y + 5);		cout << "   YP    Y888888P Y88888P YP  YP  YP 88       `Y88P'    YP";
}
void PantallaTiempo()
{

	int x = ANCHO / 6 + 15;
	int y = 13;

	TituloTiempo(x, y); _sleep(800);
	y = y + 8;
	setXY(x + 7, y + 4); setColor(7); cout << "[Ingrese Cualquier Tecla para Enviar Muestras]"; _getch();
}
void TituloGameOver(int x, int y)
{
	setColor(11); setXY(x - 2, y);			cout << "d888b   .d8b.  .88b  d88.  d88888b   .d88b.  db    db d88888b d8888b.";
	setColor(9); setXY(x - 2, y + 1);		cout << "88' Y8b d8' `8b 88'YbdP`88 88'      .8P  Y8. 88    88 88'     88  `8D";
	setColor(9); setXY(x - 2, y + 2);		cout << "88      88ooo88 88  88  88 88ooooo  88    88 Y8    8P 88ooooo 88oobY'";
	setColor(14); setXY(x - 2, y + 3);		cout << "88  ooo 88~~~88 88  88  88 88~~~~~  88    88 `8b  d8' 88~~~~~ 88`8b  ";
	setColor(14); setXY(x - 2, y + 4);		cout << "88. ~8~ 88   88 88  88  88 88.      `8b  d8'  `8bd8'  88.     88 `88.";
	setColor(14); setXY(x - 2, y + 5);		cout << " Y888P  YP   YP YP  YP  YP Y88888P   `Y88P'     YP    Y88888P 88   YD";

}
void GameOver()
{
	int x = ANCHO / 6 + 8;
	int y = 13;

	TituloGameOver(x, y);
	y = y + 8;

	setXY(x + 17, y + 2); setColor(15); cout << "NO LOGRASTE COMPLETAR LA MISION";
	setXY(x + 15, y + 4); setColor(7); cout << "[Ingrese Cualquier Tecla para Salir]"; _getch(); exit(0);


}
void Warning(int x, int y)
{
	setColor(9); // Establecer el color antes de dibujar
	setXY(x, y);	cout << "                                      :-=-                                      ";
	setXY(x, y + 1); cout << "                                    +@@@@@@*                                    ";
	setXY(x, y + 2); cout << "                                   *@@%:.*@@%.                                  ";
	setXY(x, y + 3); cout << "                                 .#@@*    =@@@:                                 ";
	setXY(x, y + 4); cout << "                                :@@@=      -@@@-                                ";
	setXY(x, y + 5); cout << "                               -@@@=        :@@@=                               ";
	setXY(x, y + 6); cout << "                              -@@@-          .%@@*                              ";
	setXY(x, y + 7); cout << "                             +@@%.    =##+:    #@@#                             ";
	setXY(x, y + 8); cout << "                            #@@#     %@@@@@.    #@@#                            ";
	setXY(x, y + 9); cout << "                           #@@#      @@@@@@:     +@@%.                          ";
	setXY(x, y + 10); cout << "                         .%@@*       #@@@@@       -@@@-                         ";
	setXY(x, y + 11); cout << "                        :@@@=        =@@@@#        -@@@=                        ";
	setXY(x, y + 12); cout << "                       -@@@-          @@@@-         :@@@=                       ";
	setXY(x, y + 13); cout << "                      =@@@:           *@@@           .#@@*                      ";
	setXY(x, y + 14); cout << "                     *@@%.            -@@#             *@@%                     ";
	setXY(x, y + 15); cout << "                    #@@#               @@=              *@@%.                   ";
	setXY(x, y + 16); cout << "                   %@@#                .:                =@@@:                  ";
	setXY(x, y + 17); cout << "                 .%@@+               :#@@%=               :@@@=                 ";
	setXY(x, y + 18); cout << "                -@@@-                %@@@@@.               :@@@=                ";
	setXY(x, y + 19); cout << "               =@@@-                 :#@@%=                 .%@@+               ";
	setXY(x, y + 20); cout << "              -@@@:                                           #@@*              ";
	setXY(x, y + 21); cout << "              =@@#.                                          .=@@%              ";
	setXY(x, y + 22); cout << "               #@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%.              ";
}

void BorrarWarning(int x, int y)
{
	setColor(9); // Establecer el color antes de dibujar
	setXY(x, y); cout << "                                                                                ";
	setXY(x, y + 1); cout << "                                                                                ";
	setXY(x, y + 2); cout << "                                                                                ";
	setXY(x, y + 3); cout << "                                                                                ";
	setXY(x, y + 4); cout << "                                                                                ";
	setXY(x, y + 5); cout << "                                                                                ";
	setXY(x, y + 6); cout << "                                                                                ";
	setXY(x, y + 7); cout << "                                                                                ";
	setXY(x, y + 8); cout << "                                                                                ";
	setXY(x, y + 9); cout << "                                                                                ";
	setXY(x, y + 10); cout << "                                                                                ";
	setXY(x, y + 11); cout << "                                                                                ";
	setXY(x, y + 12); cout << "                                                                                ";
	setXY(x, y + 13); cout << "                                                                                ";
	setXY(x, y + 14); cout << "                                                                                ";
	setXY(x, y + 15); cout << "                                                                                ";
	setXY(x, y + 16); cout << "                                                                                ";
	setXY(x, y + 17); cout << "                                                                                ";
	setXY(x, y + 18); cout << "                                                                                ";
	setXY(x, y + 19); cout << "                                                                                ";
	setXY(x, y + 20); cout << "                                                                                ";
	setXY(x, y + 21); cout << "                                                                                ";
	setXY(x, y + 22); cout << "                                                                                ";
}

void ParpadearWarning(int x, int y, int numParpadeos)
{
	for (int i = 0; i < numParpadeos; i++) {
		BorrarWarning(x, y);
		_sleep(500);

		Warning(x, y);
		_sleep(500);
	}
}

void AlertaMeteoritos(int x, int y)
{
	setColor(9); // Establecer el color antes de dibujar
	setXY(x + 30, y);     cout << " .d8b.  db      d88888b d8888b. d888888b  .d8b. ";
	setXY(x + 30, y + 1); cout << "d8' `8b 88      88'     88  `8D `~~88~~' d8' `8b";
	setXY(x + 30, y + 2); cout << "88ooo88 88      88ooooo 88oobY'    88    88ooo88";
	setXY(x + 30, y + 3); cout << "88~~~88 88      88~~~~~ 88`8b      88    88~~~88";
	setXY(x + 30, y + 4); cout << "88   88 88booo. 88.     88 `88.    88    88   88";
	setXY(x + 30, y + 5); cout << "YP   YP Y88888P Y88888P 88   YD    YP    YP   YP";

	setXY(x + 13, y + 9);     cout << ".88b  d88. d88888b d888888b d88888b  .d88b.  d8888b. d888888b d888888b .d88b.  .d8888.";
	setXY(x + 13, y + 10);	 cout << "88'YbdP`88 88'     `~~88~~' 88'     .8P  Y8. 88  `8D   `88'   `~~88~~'.8P  Y8. 88'  YP";
	setXY(x + 13, y + 11);	 cout << "88  88  88 88ooooo    88    88ooooo 88    88 88oobY'    88       88   88    88 `8bo.  ";
	setXY(x + 13, y + 12);	 cout << "88  88  88 88~~~~~    88    88~~~~~ 88    88 88`8b      88       88   88    88   `Y8b.";
	setXY(x + 13, y + 13);	 cout << "88  88  88 88.        88    88.     `8b  d8' 88 `88.   .88.      88   `8b  d8' db   8D";
	setXY(x + 13, y + 14);	 cout << "YP  YP  YP Y88888P    YP    Y88888P  `Y88P'  88   YD Y888888P    YP    `Y88P'  `8888Y'";
	setXY(x + 13, y + 15);	 cout << "";


}
void DesplazarH(int& x, int vx)
{
	x = x + vx;
}
void NaveH(int& x, int y, int vx)
{
	BorrarNave(x, y);
	DesplazarH(x, vx);
	DibujarNave(x, y);
}

void DibujarRover(int& x, int& y)
{
	setColor(7);
	setXY(x, y);      cout << "         ___ ";
	setXY(x, y + 1);  cout << "        [_0_]";
	setXY(x, y + 2);  cout << "/\______//___ ";
	setXY(x, y + 3);  cout << "[___________] ";
	setXY(x, y + 4);  cout << "    O---O---O ";
}
void BorrarRover(int x, int y)
{
	setXY(x, y);      cout << "                 ";
	setXY(x, y + 1);  cout << "                 ";
	setXY(x, y + 2);  cout << "                 ";
	setXY(x, y + 3);  cout << "                 ";
	setXY(x, y + 4);  cout << "                 ";
}
void DezplazarV(int& y, int vy)
{
	if (y < ALTO - 10)
		y = y + vy;


}
void RoverV(int& x, int& y, int vy)
{
	BorrarRover(x, y);
	DezplazarV(y, vy);
	DibujarRover(x, y);
}
void RoverH(int& x, int& y, int vx)
{
	BorrarRover(x, y);
	DesplazarH(x, vx);
	DibujarRover(x, y);
}
void BorrarMeteorito(int x1, int y1)
{
	setXY(x1, y1);     cout << "                       ";
	setXY(x1, y1 + 1); cout << "                       ";
	setXY(x1, y1 + 2); cout << "                       ";
	setXY(x1, y1 + 3); cout << "                       ";
	setXY(x1, y1 + 4); cout << "                       ";
	setXY(x1, y1 + 5); cout << "                       ";
	setXY(x1, y1 + 6); cout << "                       ";
	setXY(x1, y1 + 7); cout << "                       ";
	setXY(x1, y1 + 8); cout << "                       ";
}

void DibujarMeteorito(int x1, int y1, int color)
{
	setXY(x1, y1);
	setColor(color);
	setXY(x1, y1);     cout << "   .```^,  ````.     ";
	setXY(x1, y1 + 1); cout << "   :.    ^`    '``.  ";
	setXY(x1, y1 + 2); cout << "   I             '^  ";
	setXY(x1, y1 + 3); cout << ".^`              ?.  ";
	setXY(x1, y1 + 4); cout << "l        '``.    .I  ";
	setXY(x1, y1 + 5); cout << ",.      .;.''   . ^ '";
	setXY(x1, y1 + 6); cout << " ``,      ..   ;'    ";
	setXY(x1, y1 + 7); cout << "    !      '``^'     ";
	setXY(x1, y1 + 8); cout << "     ```'^^          ";
}
void GenerarMeteoros(int N, int* arrColor, float* arrX, float* arrY, float* arrVx, float* arrVy, float vel)
{

	for (int i = 0; i < N; i++)
	{
		arrColor[i] = Aleatorio(2, 15);
		arrX[i] = Aleatorio(2, ANCHO - 30);
		arrY[i] = Aleatorio(2, ALTO - 40);
		arrVx[i] = vel;
		arrVy[i] = vel;
	}
}

void DesplazarMeteoritos(float& x, float& y, float& Vx, float& Vy)
{

	if (x + Vx > ANCHO - 21 || x + Vx < 0)
		Vx = Vx * (-1);
	if (y + Vy > ALTO - 9 || y + Vy < 2)
		Vy = Vy * (-1);
	x = x + Vx;
	y = y + Vy;
}

void MoverMeteoritos(float& x, float& y, int color, float& Vx, float& Vy)
{

	BorrarMeteorito(x, y);
	DesplazarMeteoritos(x, y, Vx, Vy);
	DibujarMeteorito(x, y, color);
}
void Meteoritos(int N, int* arrColor, float* arrX, float* arrY, float* arrVx, float* arrVy)
{
	for (int i = 0; i < N; i++)
	{
		MoverMeteoritos(arrX[i], arrY[i], arrColor[i], arrVx[i], arrVy[i]);
	}
}

void DesplazarNave(int& x, int& y, int& vx, int& vy)
{
	if (x + vx < 0)
		vx = (-1) * vx;
	if (x + vx > ANCHO - 18)
		x = x;
	if (y + vy<0 || y + vy >ALTO - 6)
		vy = (-1) * vy;
	else
	{
		x = x + vx;
		y = y + vy;
	}

}

void MoverNave(int& x, int& y, int& vx, int& vy)
{
	BorrarNave(x, y);
	DesplazarNave(x, y, vx, vy);
	DibujarNave(x, y);

}
void DibujarEntorno(int x, int y)
{
	Console::ForegroundColor = ConsoleColor::DarkRed;
	setXY(x, y);     cout << "  __    +      *                         `'       `'|.    `:";
	setXY(x, y + 1); cout << "''  `---'''----....____,..^---`^``----.,.___          `.    `.  .    ____,.,-";
	setXY(x, y + 2); cout << "    ___,--''''`---''   ^  ^ ^        ^       ''''-- - , ..___ __, ..-- - '''";
	setXY(x, y + 3); cout << "'--''            ;                    ^                         ``--..,__";
}

void DibujarEntorno2(int x, int y)
{
	Console::ForegroundColor = ConsoleColor::DarkRed;
	setXY(x, y);     cout << "  __    +      *                        ";
	setXY(x, y + 1); cout << "''  `---'''----....____,..^---`^``----.,__";
	setXY(x, y + 2); cout << "    ___,--''''`---''   ^  ^ ^        ^  ";
	setXY(x, y + 3); cout << "'--''            ;                    ^ ";
}

void DesplazarRM(int& x, int& y, int& vx, int& vy)
{
	if (x + vx < 0 || x + vx >= ANCHO - 14) vx = 0;
	else x = x + vx;

	if (y + vy < 0 || y + vy >= ALTO - 4) vy = 0;
	else y = y + vy;

}

void MoverRoverManualmente(int& x, int& y, int& vx, int& vy)
{
	BorrarRover(x, y);
	DesplazarRM(x, y, vx, vy);
	DibujarRover(x, y);
}
bool VerificarColision(int x1, int y1, int ancho1, int alto1, int x2, int y2, int ancho2, int alto2)
{
	return(x1 < x2 + ancho2 &&
		x1 + ancho1 > x2 &&
		y1 < y2 + alto2 &&
		y1 + alto1 > y2);


}


void DibujarMuestras(int N, int x, int y, vector<pair<int, int>>& pxy)
{
	int cont = N;
	char caracter = '%';

	Console::ForegroundColor = ConsoleColor::White;
	for (int i = 0; i < cont; i++)
	{
		int x = Aleatorio(15, 110);
		int y = Aleatorio(25, 33);
		pxy.push_back({ x,y });
		setXY(x, y); cout << caracter;
	}

}

void BorrarCohete(int x, int y)
{
	cout << "            ";
	cout << "            ";
	cout << "            ";
	cout << "            ";
}

void BorrarCohete2(int x, int y)
{
	setXY(x, y);     cout << "            ";
	setXY(x, y + 1); cout << "            ";
	setXY(x, y + 2); cout << "            ";
	setXY(x, y + 3); cout << "            ";
}

void DibujarCohete(int x, int y)
{
	Console::ForegroundColor = ConsoleColor::DarkYellow;
	setXY(x, y);     cout << "   __";
	setXY(x, y + 1); cout << "   | |_____";
	setXY(x, y + 2); cout << "###[==_____>";
	setXY(x, y + 3); cout << "   /_/      ";

}

void Cohete(int& x, int y, int vx)
{
	BorrarCohete(x, y);
	DesplazarH(x, vx);
	DibujarCohete(x, y);
}

void DibujarSatelite(int x, int y)
{
	Console::ForegroundColor = ConsoleColor::DarkGray;
	setXY(x, y);     cout << "                             _______";
	setXY(x, y + 1); cout << "                            ////////";
	setXY(x, y + 2); cout << "     ________             ///////// ";
	setXY(x, y + 3); cout << "    |.____.  /%         /////////   ";
	setXY(x, y + 4); cout << "  .//      %/  |%     /////////     ";
	setXY(x, y + 5); cout << ".//          % |  % /////////       ";
	setXY(x, y + 6); cout << "||.    .    .| |  /////////         ";
	setXY(x, y + 7); cout << "||           | |//`,/////           ";
	setXY(x, y + 8); cout << " %%        ./ //  /  %/             ";
	setXY(x, y + 9); cout << "   %%.___./ //%` '   ,_%            ";
	setXY(x, y + 10); cout << "        % //////% , /   %          ";
	setXY(x, y + 11); cout << "        ///////// %|  '  |         ";
	setXY(x, y + 12); cout << "      /////////     % _ /          ";
	setXY(x, y + 13); cout << "    /////////                      ";
	setXY(x, y + 14); cout << " ./////////                        ";
	setXY(x, y + 15); cout << "  --------                         ";
}

void BorrarSatelite(int x, int y)
{
	setXY(x, y);     cout << "                                          ";
	setXY(x, y + 1); cout << "                                          ";
	setXY(x, y + 2); cout << "                                          ";
	setXY(x, y + 3); cout << "                                          ";
	setXY(x, y + 4); cout << "                                          ";
	setXY(x, y + 5); cout << "                                          ";
	setXY(x, y + 6); cout << "                                          ";
	setXY(x, y + 7); cout << "                                          ";
	setXY(x, y + 8); cout << "                                          ";
	setXY(x, y + 9); cout << "                                          ";
	setXY(x, y + 10); cout << "                                         ";
	setXY(x, y + 11); cout << "                                         ";
	setXY(x, y + 12); cout << "                                         ";
	setXY(x, y + 13); cout << "                                         ";
	setXY(x, y + 14); cout << "                                         ";
	setXY(x, y + 15); cout << "                                         ";
}

void Satelite(int& x, int y, int vx)
{
	BorrarSatelite(x, y);
	DesplazarH(x, vx);
	DibujarSatelite(x, y);
}

void BorrarTraces(int x, int y)
{
	setXY(x, y); cout << " ";
	setXY(x, y + 1); cout << " ";
	setXY(x, y + 2); cout << " ";
	setXY(x, y + 3); cout << " ";
}

void Traces(int& x, int y, int vx)
{
	BorrarTraces(x, y);
	DesplazarH(x, vx);
}

void DesplazarD(int& x, int& y, int vx, int vy)
{
	x += vx;
	y += vy;
}

void NaveD(int& x, int& y, int vx, int vy)
{
	BorrarNave(x, y);
	DesplazarD(x, y, vx, vy);
	DibujarNave(x, y);
}

void DibujarTierra(int x, int y)
{
	Console::ForegroundColor = ConsoleColor::DarkGreen;
	setXY(x, y);     cout << "              _-o#&&*''''?d:>b\_";
	setXY(x, y + 1); cout << "          _o/'`''  '', , dMF9MMMMMHo_";
	setXY(x, y + 2); cout << "       .o&#'        `'MbHMMMMMMMMMMMHo.";
	setXY(x, y + 3); cout << "     .o'' '         vodM*$&&HMMMMMMMMMM?.";
	setXY(x, y + 4); cout << "    ,'              $M&ood,~'`(&##MMMMMMH%";
	setXY(x, y + 5); cout << "   /               ,MMMMMMM#b?#bobMMMMHMMML";
	setXY(x, y + 6); cout << "  &              ?MMMMMMMMMMMMMMMMM7MMM$R*Hk";
	setXY(x, y + 7); cout << " ?$.            :MMMMMMMMMMMMMMMMMMM/HMMM|`*L";
	setXY(x, y + 8); cout << "|               |MMMMMMMMMMMMMMMMMMMMbMH'   T,";
	setXY(x, y + 9); cout << "$H#:            `*MMMMMMMMMMMMMMMMMMMMb#}'  `?";
	setXY(x, y + 10); cout << "]MMH#             ''*''''*#MMMMMMMMMMMMM'    -";
	setXY(x, y + 11); cout << "MMMMMb_                   |MMMMMMMMMMMP'     :";
}
void PresentacionJuego()
{
	int x = 25;
	int y = 2;

	setColor(11);
	setXY(x, y); cout << " .o88b.  .d88b.  d8b   db d888888b d88888b db    db d888888b  .d88b.";
	setColor(2);
	setXY(x, y + 1); cout << "d8P  Y8 .8P  Y8. 888o  88 `~~88~~' 88'     `8b  d8' `~~88~~' .8P  Y8.";
	setXY(x, y + 2); cout << "8P      88    88 88V8o 88    88    88ooooo  `8bd8'     88    88    88";
	setColor(3);
	setXY(x, y + 3); cout << "8b      88    88 88 V8o88    88    88~~~~~  .dPYb.     88    88    88";
	setXY(x, y + 4); cout << "Y8b  d8 `8b  d8' 88  V888    88    88.     .8P  Y8.    88    `8b  d8'";
	setXY(x, y + 5); cout << " `Y88P'  `Y88P'  VP   V8P    YP    Y88888P YP    YP    YP     `Y88P' ";

	y = y + 8;

	GeneraCuadro(x, y, 69);
	y = y + 1;
	x = x + 5;
	setColor(5);
	setXY(x, y + 2); cout << "Roversito tiene como mision llegar a Marte y enviar muestras";
	setXY(x, y + 3); cout << "de rocas a la Tierra.";
	setXY(x, y + 4); cout << "Para ello, su nave debe pasar por la lluvia de meteoritos.";
	setXY(x, y + 6); cout << "Una vez pasado el obstaculo, debe recolectar muestras antes";
	setXY(x, y + 7); cout << "de que se acabe el Tiempo y enviarlas.";

	int xT, yT;
	xT = ANCHO / 6 + 11;
	yT = ALTO - 13;
	DibujarNave(xT, yT);

	xT = xT + 7; yT = yT - 2;
	setColor(15); setXY(xT, yT); cout << "Nave";

	int xR, yR;
	xR = ANCHO / 6 + 50;
	yR = ALTO - 13;
	DibujarRover(xR, yR);

	xR = xR + 3; yR = yR - 2;
	setColor(15); setXY(xR, yR); cout << "Roversito";

	int xTexto = xT;
	setColor(3); setXY(xTexto, ALTO - 3); cout << "[Presiona Cualquier Tecla para Iniciar Mision]";

	_getch(); Console::Clear();





}
void TituloFinMision(int x, int y)
{

	setColor(15); setXY(x + 15, y);		cout << ".88b  d88. d888888b .d8888. d888888b  .d88b.  d8b   db";
	setColor(15); setXY(x + 15, y + 1);   cout << "88'YbdP`88   `88'   88'  YP   `88'   .8P  Y8. 888o  88";
	setColor(15); setXY(x + 15, y + 2);   cout << "88  88  88    88    `8bo.      88    88    88 88V8o 88";
	setColor(7); setXY(x + 15, y + 3);    cout << "88  88  88    88      `Y8b.    88    88    88 88 V8o88";
	setColor(7); setXY(x + 15, y + 4);    cout << "88  88  88   .88.   db   8D   .88.   `8b  d8' 88  V888";
	setColor(7); setXY(x + 15, y + 5);    cout << "YP  YP  YP Y888888P `8888Y' Y888888P  `Y88P'  VP   V8P";
	x = x + 7;
	setColor(15); setXY(x, y + 7);     cout << " .o88b. db    db .88b  d88. d8888b. db      d888888b d8888b.  .d8b. ";
	setColor(15); setXY(x, y + 8);	   cout << "d8P  Y8 88    88 88'YbdP`88 88  `8D 88        `88'   88  `8D d8' `8b";
	setColor(15); setXY(x, y + 9);	   cout << "8P      88    88 88  88  88 88oodD' 88         88    88   88 88ooo88";
	setColor(7); setXY(x, y + 10);	   cout << "8b      88    88 88  88  88 88~~~   88         88    88   88 88~~~88";
	setColor(7); setXY(x, y + 11);    cout << "Y8b  d8 88b  d88 88  88  88 88      88booo.   .88.   88  .8D 88   88";
	setColor(7); setXY(x, y + 12);    cout << " `Y88P' ~Y8888P' YP  YP  YP 88      Y88888P Y888888P Y8888D' YP   YP";


}

void PantallaFinMision()
{
	Console::Clear();

	int x = ANCHO - 100, y = 8;
	TituloFinMision(x, y); _sleep(1000);

	x = ANCHO / 6 - 15, y = ALTO / 10;
	setXY(x + 40, ALTO - 10); setColor(3); cout << "[Ingrese Cualquier Tecla para Salir]"; _getch(); exit(0);
}
void BorrarCoheteB(int x, int y)
{
	setXY(x, y);     cout << "            ";
	setXY(x, y + 1); cout << "            ";
	setXY(x, y + 2); cout << "            ";
	setXY(x, y + 3); cout << "            ";
	setXY(x, y + 4); cout << "            ";
}

void DibujarCoheteB(int x, int y)
{
	Console::ForegroundColor = ConsoleColor::DarkYellow;
	setXY(x, y);     cout << "      /%";
	setXY(x, y + 1); cout << "     (  )";
	setXY(x, y + 2); cout << "     (  )";
	setXY(x, y + 3); cout << "    /|/%|%";
	setXY(x, y + 4); cout << "   /_||||_%";
}


void DezplazarV2(int& y, int vy)
{
	if (y < ALTO - 10)
		y = y - vy;
}

void Cohete2(int x, int& y, int vy)
{
	BorrarCoheteB(x, y);
	DezplazarV2(y, vy);
	DibujarCoheteB(x, y);
}
void PantallaDepositandoMuestras(int num)
{
	Console::Clear();
	int xRm = ANCHO / 2, yRm = ALTO - 16, vxRm = 1;
	setXY(0, 2); setColor(3); cout << "Total Muestras: " << num;
	DibujarEntorno(0, 20);
	DibujarEntorno2(ANCHO - 42, 20);

	int xTm = ANCHO - 27, yTm = ALTO - 16;

	DibujarNave(xTm, yTm);

	while (true)
	{
		RoverH(xRm, yRm, vxRm);
		_sleep(100);
		if (xRm == ANCHO - 42)
		{
			setColor(15); setXY(50, 2); cout << "Depositando Muestras ...";
			_sleep(5000);
			break;
		}
	}

	setColor(15); setXY(50, 2); cout << "        Listo!          ";
	int xC = ANCHO - 22, yC = ALTO - 23, vyC = 1;
	while (true)
	{
		Cohete2(xC, yC, vyC);
		_sleep(100);
		if (yC == ALTO - 39)
		{
			Console::Clear();
			break;
		}
	}

}