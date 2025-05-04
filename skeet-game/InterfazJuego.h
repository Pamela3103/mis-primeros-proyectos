#pragma once

using namespace std;
using namespace System;


#include<iostream>
#include<conio.h>
#define ANCHO 140
#define ALTO 40
#define UP 72
#define DOWN 80
#define RIGHT 77
#define LEFT 75
#define SPACE 32

#define ACTIVO true
#define INACTIVO false

bool estado = INACTIVO;
bool estadoObjetivo = INACTIVO;
bool estadoObjetivo2 = INACTIVO;

float AleatorioDec()
{
    return ((float)rand() / RAND_MAX);
}
void BorrarTexto2(int x, int y)
{
    setXY(x, y); cout << "                                                     ";
}
struct Jugadores {
    int puntaje;
    string Pais;
};
void GenerarPaises(string* Paises, int* N)
{
    string* Paises_en_competencia = new string[*N];
    Paises_en_competencia[0] = "Argentina";
    Paises_en_competencia[1] = "Peru";
    Paises_en_competencia[2] = "Colombia";
    Paises_en_competencia[3] = "Chile";
    Paises_en_competencia[4] = "Brasil";
    Paises_en_competencia[5] = "Mexico";
    Paises_en_competencia[6] = "Nicaragua";
    Paises_en_competencia[7] = "Bolivia";
    Paises_en_competencia[8] = "Francia";
    Paises_en_competencia[9] = "Venezuela";

    for (int i = 0; i < *N; i++)
    {
        Paises[i] = Paises_en_competencia[i];

    }
}
void MostrarPaises(string* Paises, int* N)
{
    int x = 50;
    int y = 16;
    int y2 = 16;
    int y3 = 16;

    for (int i = 0; i < *N; i++)
    {
        if (*N > 5)
        {
            if (i < 5)
            {
                setXY(x, y); setBGcolor(10); setColor(15);
                cout << " " << i + 1 << " ";
                setBGcolor(4);
                setXY(x + 5, y); cout << Paises[i];
                y = y + 2;
            }
            else
            {
                setXY(x + 25, y2); setBGcolor(10); setColor(15);
                cout << " " << i + 1 << " ";
                setBGcolor(4);
                setXY(x + 25 + 5, y2); cout << Paises[i];
                y2 = y2 + 2;
            }
        }
        else
        {
            setXY(x, y3); setBGcolor(10); setColor(15);
            cout << " " << i + 1 << " ";
            setBGcolor(4);
            setXY(x + 5, y3); cout << Paises[i];
            y3 = y3 + 2;
        }
    }
}
string* eliminarPosicion(string* Paises, int* N, int pos)
{
    string* Temporal = new string[*N - 1];

    for (int i = 0; i < pos; i++)
    {
        Temporal[i] = Paises[i];
    }
    for (int i = pos + 1; i < *N; i++)
    {
        Temporal[i - 1] = Paises[i];
    }
    if (Paises != NULL)delete[]Paises;
    *N = *N - 1;
    return Temporal;

}
string* EliminarPais(string* Paises, int* N, int pais)
{

    return Paises = eliminarPosicion(Paises, N, pais - 1);

}
void FondoListaPaises()
{
    int x = 57;
    int y = 12;
    Fondo_1();
    GeneraCuadroMenu(40, 12, 60, 15, 4);
    GeneraCuadroMenu(50, 11, 42, 3, 16);
    setColor(1);
    setXY(x, y); cout << "LISTA DE PAISES PARTICIPANTES";
}
void AlmacenaParticipante(string* Paises, Jugadores*& participante, int indice, int pos)
{
    participante[pos].Pais = Paises[indice - 1];

}
void ListaPaises(int*& N, string*& Paises, Jugadores*& participante, int pos)
{
    int pais;
    bool fin = false;
    while (!fin) //Modificado
    {
        FondoListaPaises();
        MostrarPaises(Paises, N);
        do {
            setXY(ANCHO / 2 - 20, ALTO - 7); setBGcolor(3); setColor(13);
            cout << "Elija un pais (Ingrese su numero respectivo): "; cin >> pais;
            BorrarTexto2(ANCHO / 2 - 20, ALTO - 7);
        } while (!(pais > 0 && pais <= *N));

        setBGcolor(3); Console::Clear();
        AlmacenaParticipante(Paises, participante, pais, pos);
        Paises = EliminarPais(Paises, N, pais);
        fin = true;
    }

}
void dibujaCieloPantallaContador(int x, int y, int color)
{
    setBGcolor(1);
    Console::Clear();
    int contador = 0;
    while (contador < 40)
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

void dibujaContadorFondo(int x, int y)
{
    char block = char(219);

    setColor(6);
    for (int f = 1; f <= 30; f++)
    {
        setXY(x, y);
        for (int c = 1; c <= 90; c++)
        {
            cout << block;
        }
        cout << endl;
        y++;
    }
}

void dibujaContador(int x, int y)
{
    char block = char(219);

    setColor(1);
    for (int f = 1; f <= 26; f++)
    {
        setXY(x, y);
        for (int c = 1; c <= 82; c++)
        {
            cout << block;
        }
        cout << endl;
        y++;
    }
}

void borraNumeros(int x, int y)
{
    setBGcolor(1);
    setXY(x, y);     cout << "                    ";
    setXY(x, y + 1); cout << "                    ";
    setXY(x, y + 2); cout << "                    ";
    setXY(x, y + 3); cout << "                    ";
    setXY(x, y + 4); cout << "                    ";
    setXY(x, y + 5); cout << "                    ";
    setXY(x, y + 6); cout << "                    ";
    setXY(x, y + 7); cout << "                    ";
    setXY(x, y + 8); cout << "                    ";
    setXY(x, y + 9); cout << "                    ";
    setXY(x, y + 10); cout << "                    ";
    setXY(x, y + 11); cout << "                    ";
    setXY(x, y + 12); cout << "                    ";
    setXY(x, y + 13); cout << "                    ";
    setXY(x, y + 14); cout << "                    ";
    setXY(x, y + 15); cout << "                    ";
}

void dibuja3(int x, int y)
{
    setColor(12); setBGcolor(1);
    setXY(x, y);     cout << " 333333333333333   ";
    setXY(x, y + 1); cout << "3:::::::::::::::33 ";
    setXY(x, y + 2); cout << "3::::::33333::::::3";
    setXY(x, y + 3); cout << "3333333     3:::::3";
    setXY(x, y + 4); cout << "            3:::::3";
    setXY(x, y + 5); cout << "            3:::::3";
    setXY(x, y + 6); cout << "    33333333:::::3 ";
    setXY(x, y + 7); cout << "    3:::::::::::3  ";
    setXY(x, y + 8); cout << "    33333333:::::3 ";
    setXY(x, y + 9); cout << "            3:::::3";
    setXY(x, y + 10); cout << "            3:::::3";
    setXY(x, y + 11); cout << "            3:::::3";
    setXY(x, y + 12); cout << "3333333     3:::::3";
    setXY(x, y + 13); cout << "3::::::33333::::::3";
    setXY(x, y + 14); cout << "3:::::::::::::::33 ";
    setXY(x, y + 15); cout << " 333333333333333   ";
}

void dibuja2(int x, int y)
{
    setColor(12); setBGcolor(1);
    setXY(x, y); cout << " 222222222222222    ";
    setXY(x, y + 1); cout << "2:::::::::::::::22  ";
    setXY(x, y + 2); cout << "2::::::222222:::::2 ";
    setXY(x, y + 3); cout << "2222222     2:::::2 ";
    setXY(x, y + 4); cout << "            2:::::2 ";
    setXY(x, y + 5); cout << "            2:::::2 ";
    setXY(x, y + 6); cout << "         2222::::2  ";
    setXY(x, y + 7); cout << "    22222::::::22   ";
    setXY(x, y + 8); cout << "  22::::::::222     ";
    setXY(x, y + 9); cout << " 2:::::22222        ";
    setXY(x, y + 10); cout << "2:::::2             ";
    setXY(x, y + 11); cout << "2:::::2             ";
    setXY(x, y + 12); cout << "2:::::2       222222";
    setXY(x, y + 13); cout << "2::::::2222222:::::2";
    setXY(x, y + 14); cout << "2::::::::::::::::::2";
    setXY(x, y + 15); cout << "22222222222222222222";
}

void dibuja1(int x, int y)
{
    setColor(12); setBGcolor(1);
    setXY(x, y);     cout << "  1111111   ";
    setXY(x, y + 1); cout << " 1::::::1   ";
    setXY(x, y + 2); cout << "1:::::::1   ";
    setXY(x, y + 3); cout << "111:::::1   ";
    setXY(x, y + 4); cout << "   1::::1   ";
    setXY(x, y + 5); cout << "   1::::1   ";
    setXY(x, y + 6); cout << "   1::::1   ";
    setXY(x, y + 7); cout << "   1::::l   ";
    setXY(x, y + 8); cout << "   1::::l   ";
    setXY(x, y + 9); cout << "   1::::l   ";
    setXY(x, y + 10); cout << "   1::::l   ";
    setXY(x, y + 11); cout << "   1::::l   ";
    setXY(x, y + 12); cout << "111::::::111";
    setXY(x, y + 13); cout << "1::::::::::1";
    setXY(x, y + 14); cout << "1::::::::::1";
    setXY(x, y + 15); cout << "111111111111";
}

void dibujaGO(int x, int y)
{
    setColor(12); setBGcolor(1);
    setXY(x, y); cout << "        GGGGGGGGGGGGG       OOOOOOOOO           !!! ";
    setXY(x, y + 1); cout << "     GGG::::::::::::G     OO:::::::::OO        !!:!!";
    setXY(x, y + 2); cout << "   GG:::::::::::::::G   OO:::::::::::::OO      !:::!";
    setXY(x, y + 3); cout << "  G:::::GGGGGGGG::::G  O:::::::OOO:::::::O     !:::!";
    setXY(x, y + 4); cout << " G:::::G       GGGGGG  O::::::O   O::::::O     !:::!";
    setXY(x, y + 5); cout << "G:::::G                O:::::O     O:::::O     !:::!";
    setXY(x, y + 6); cout << "G:::::G                O:::::O     O:::::O     !:::!";
    setXY(x, y + 7); cout << "G:::::G    GGGGGGGGGG  O:::::O     O:::::O     !:::!";
    setXY(x, y + 8); cout << "G:::::G    G::::::::G  O:::::O     O:::::O     !:::!";
    setXY(x, y + 9); cout << "G:::::G    GGGGG::::G  O:::::O     O:::::O     !:::!";
    setXY(x, y + 10); cout << "G:::::G        G::::G  O:::::O     O:::::O     !!:!!";
    setXY(x, y + 11); cout << " G:::::G       G::::G  O::::::O   O::::::O      !!! ";
    setXY(x, y + 12); cout << "  G:::::GGGGGGGG::::G  O:::::::OOO:::::::O          ";
    setXY(x, y + 13); cout << "   GG:::::::::::::::G   OO:::::::::::::OO       !!! ";
    setXY(x, y + 14); cout << "     GGG::::::GGG:::G     OO:::::::::OO        !!:!!";
    setXY(x, y + 15); cout << "        GGGGGG   GGGG       OOOOOOOOO           !!! ";
}

void Contador()
{
    dibujaCieloPantallaContador(0, 0, 3);
    dibujaContadorFondo(22, 5);
    dibujaContador(26, 7);
    dibuja3(58, 12);
    _sleep(1000);
    borraNumeros(58, 12);
    dibuja2(58, 12);
    _sleep(1000);
    borraNumeros(58, 12);
    dibuja1(62, 12);
    _sleep(1000);
    borraNumeros(58, 12);
    dibujaGO(42, 12);
    _sleep(1000);
}


//PARTE LUDICA
struct Persona
{
    int x;
    int y;
    int vX;
    int vY;
};

void dibujaJuezPuntaje(int& x, int& y)
{
    char block = char(219);

    setColor(4); setXY(x, y); cout << " " << block << block << block << block << block << block << block;
    setColor(15); setXY(x, y + 1); cout << "  " << block << block << block << block << block;
    setColor(2); setXY(x, y + 2); cout << "   " << block << block << block;
    setColor(4); setXY(x, y + 3); cout << block << block << block << block << block << block << block << block << block << block << block << block;
    setXY(x, y + 4); cout << block << " " << block << block << block << block << block;
    setXY(x, y + 5); cout << block << " " << block << block << block << block << block;
    setXY(x, y + 6); cout << "  " << block << block << " " << block << block;
    setXY(x, y + 7); cout << "  " << block << block << " " << block << block;
    setColor(1); setXY(x, y + 8); cout << "  " << block << block << " " << block << block;
}

void dibujaJuez(int& x, int& y)
{
    char block = char(219);

    setColor(4); setXY(x, y); cout << " " << block << block << block << block << block << block << block;
    setColor(15); setXY(x, y + 1); cout << "  " << block << block << block << block << block;
    setColor(2); setXY(x, y + 2); cout << "   " << block << block << block;
    setColor(4); setXY(x, y + 3); cout << block << block << block << block << block << block << block << block << block;
    setXY(x, y + 4); cout << block << " " << block << block << block << block << block << " " << block;
    setXY(x, y + 5); cout << block << " " << block << block << block << block << block << " " << block;
    setXY(x, y + 6); cout << "  " << block << block << " " << block << block;
    setXY(x, y + 7); cout << "  " << block << block << " " << block << block;
    setColor(1); setXY(x, y + 8); cout << "  " << block << block << " " << block << block;
}

void borrarJuez(int x, int y)
{
    setXY(x, y); cout << "          ";
    setXY(x, y + 1); cout << "          ";
    setXY(x, y + 2); cout << "          ";
    setXY(x, y + 3); cout << "          ";
    setXY(x, y + 4); cout << "          ";
    setXY(x, y + 5); cout << "          ";
    setXY(x, y + 6); cout << "          ";
    setXY(x, y + 7); cout << "          ";
    setXY(x, y + 8); cout << "          ";
}

void moverJuez(int& x, int& vX)
{
    x += vX;
}

void desplazarJuez(int& x, int& y, int& vX)
{
    borrarJuez(x, y);
    moverJuez(x, vX);
    dibujaJuez(x, y);
}

void dibujarCuadroTexto(int x, int y)
{
    char block = char(219);

    setColor(1);
    setXY(x, y); cout << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block;
    setXY(x, y + 1); cout << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block;
    setXY(x, y + 2); cout << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block;
}

void dibujarCuadroTexto2(int x, int y)
{
    char block = char(219);

    setColor(1);
    setXY(x, y); cout << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block;
    setXY(x, y + 1); cout << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block;
    setXY(x, y + 2); cout << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block << block;
}

void dibujarCartel(int x, int y)
{
    char block = char(219);

    setColor(1);
    setXY(x, y);     cout << block << block << block << block << block;
    setXY(x, y + 1); cout << block << block << block << block << block;
    setXY(x, y + 2); cout << block << block << block << block << block;
    setXY(x, y + 3); cout << "  " << block << "  ";
    setXY(x, y + 4); cout << "  " << block << "  ";
}

void CieloPantallaEscopetas()
{

    setBGcolor(11);
    Console::Clear();

    GeneraCuadroMenu(0, 14, ANCHO, 1, 6);
    GeneraCuadroMenu(0, 27, ANCHO, 1, 6);
}

void Cartel_1()
{
    dibujarCuadroTexto(7, 25);
    setColor(15); setBGcolor(1); setXY(9, 26); cout << "ESTAS LISTO?";
    setColor(1); setBGcolor(12); setXY(60, 38); cout << "[El juego empezara a su se" << char(164) << "al]"; _getch();
    setBGcolor(12); setXY(50, 38); cout << "                                         ";
    setColor(15); setBGcolor(1); setXY(9, 26); cout << "COMENCEMOS !";
    _sleep(1000);
    setColor(1); setBGcolor(12); setXY(60, 38); cout << "Pasando a vista de jugador ..."; _sleep(1000);
}
void Entrada_Jueces()
{
    Persona juez1;
    Persona juez2;

    juez1.x = 0;
    juez1.y = 29;
    juez1.vX = 1;

    juez2.x = 0;
    juez2.y = 29;
    juez2.vX = 1;

    while (true)
    {
        if (juez1.x < 20)
        {
            desplazarJuez(juez1.x, juez1.y, juez1.vX);
        }
        if (juez1.x >= 11 && juez2.x < 10)
        {
            desplazarJuez(juez2.x, juez2.y, juez2.vX);
        }
        if (juez1.x == 20 && juez2.x == 10)
        {
            break;
        }
        _sleep(100);
    }
    _sleep(1000);

}
void dibujaJugador(int& x1, int y1, int num_jugador)
{

    if (num_jugador == 1)
    {//Argentina
        dibujaJugadorargentina(x1, y1);
    }
    if (num_jugador == 2)
    {//Peru
        dibujaJugadorPeru(x1, y1);
    }
    if (num_jugador == 3)
    {//Colombia
        dibujaJugadorColombia(x1, y1);
    }
    if (num_jugador == 4)
    {//Chile
        dibujaJugadorChile(x1, y1);
    }
    if (num_jugador == 5)
    {//Brasil
        dibujaJugadorBrazil(x1, y1);
    }
    if (num_jugador == 6)
    {//Mexico
        dibujaJugadormexico(x1, y1);
    }
    if (num_jugador == 7)
    {//Nicaragua
        dibujaJugadorNicaragua(x1, y1);
    }
    if (num_jugador == 8)
    {//Bolivia
        dibujaJugadorBolivia(x1, y1);
    }
    if (num_jugador == 9)
    {//Francia
        dibujaJugadorfrancia(x1, y1);
    }
    if (num_jugador == 10)
    {//Venezuela
        dibujaJugadorvenezuela(x1, y1);
    }
}
void BorrarJugador(int& x1, int y1)
{
    setColor(12); setXY(x1, y1);  cout << " " << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219); setBGcolor(12);
    setColor(12); setXY(x1, y1 + 1);  cout << "  " << char(219) << char(219) << char(219) << char(219) << char(219);
    setColor(12); setXY(x1, y1 + 2);  cout << "   " << char(219) << char(219) << char(219);
    setColor(12); setXY(x1, y1 + 3); cout << char(219) << char(219); setColor(12); setXY(x1 + 2, y1 + 3); cout << char(219); setColor(12); setXY(x1 + 3, y1 + 3); cout << char(219); setColor(12); setXY(x1 + 2, y1 + 3); cout << char(219); setColor(7); setXY(x1 + 3, y1 + 3); cout << char(219); setColor(12); setXY(x1 + 4, y1 + 3); cout << char(219); setColor(12); setXY(x1 + 5, y1 + 3); cout << char(219); setColor(12); setXY(x1 + 6, y1 + 3); cout << char(219); setColor(12); setXY(x1 + 7, y1 + 3); cout << char(219) << char(219);
    setColor(12); setXY(x1, y1 + 4); cout << char(219) << " "; setColor(12); setXY(x1 + 2, y1 + 4); cout << char(219); setColor(12); setXY(x1 + 3, y1 + 4); cout << char(219); setColor(12); setXY(x1 + 2, y1 + 4); cout << char(219); setColor(7); setXY(x1 + 3, y1 + 4); cout << char(219); setColor(12); setXY(x1 + 4, y1 + 4); cout << char(219); setColor(12); setXY(x1 + 5, y1 + 4); cout << char(219); setColor(12); setXY(x1 + 6, y1 + 4); cout << char(219); setColor(12); setXY(x1 + 7, y1 + 4); cout << " " << char(219);
    setColor(12); setXY(x1, y1 + 5); cout << char(219) << " "; setColor(12); setXY(x1 + 2, y1 + 5); cout << char(219); setColor(12); setXY(x1 + 3, y1 + 5); cout << char(219); setColor(12); setXY(x1 + 2, y1 + 5); cout << char(219); setColor(7); setXY(x1 + 3, y1 + 5); cout << char(219); setColor(12); setXY(x1 + 4, y1 + 5); cout << char(219); setColor(12); setXY(x1 + 5, y1 + 5); cout << char(219); setColor(12); setXY(x1 + 6, y1 + 5); cout << char(219); setColor(12); setXY(x1 + 7, y1 + 5); cout << " " << char(219);
    setColor(12); setXY(x1, y1 + 6); cout << "  " << char(219) << char(219) << " " << char(219) << char(219);
    setColor(12); setXY(x1, y1 + 7); cout << "  " << char(219) << char(219) << " " << char(219) << char(219);
    setColor(12); setXY(x1, y1 + 8); cout << "  " << char(219) << char(219) << " " << char(219) << char(219);
}
void MoverJugador(int& x, int y, int vX, int num_jugador)
{
    BorrarJugador(x, y);
    moverJuez(x, vX);
    dibujaJugador(x, y, num_jugador);

}
void Entrada_Jugador(int num_jugador)
{
    Persona jugador;

    jugador.x = 0;
    jugador.y = 19;
    jugador.vX = 1;


    _sleep(1000);

    while (true)
    {
        if (jugador.x < 34)
        {
            MoverJugador(jugador.x, jugador.y, jugador.vX, num_jugador);
        }

        if (jugador.x == 34)
        {
            break;
        }
        _sleep(100);
    }
    _sleep(1000);
}
void PantallaEscopeta(short& opcEscopeta)
{
    CieloPantallaEscopetas();
    setBGcolor(5);
    setColor(15); setXY(56, 1); cout << " E S C O G E   T U   E S C O P E T A  ! ";

    setColor(1); setBGcolor(3); setXY(5, 4); cout << "E S C O P E T A   1";
    Escopeta(5, 4, 13);

    setColor(1); setBGcolor(3); setXY(5, 16); cout << "E S C O P E T A   2";
    Escopeta(5, 16, 10);

    setColor(1); setBGcolor(3); setXY(5, 29); cout << "E S C O P E T A   3";
    Escopeta(5, 30, 5);

    do
    {
        setColor(1); setBGcolor(3); setXY(100, 20); cout << "                      ";
        setColor(1); setBGcolor(3); setXY(100, 20); cout << "Opcion elegida: "; cin >> opcEscopeta;
    } while (!(opcEscopeta > 0 && opcEscopeta <= 3));

    _sleep(100);
    setBGcolor(1);
    Console::Clear();
}
void CasetaJuego1()
{
    int x = 20;
    int y = 20;
    setBGcolor(10);
    setXY(x, y); cout << "     ";
    setXY(x, y + 1); cout << "     ";
    setXY(x, y + 2); cout << "     ";

    x = x + 95;
    setBGcolor(10);
    setXY(x, y); cout << "     ";
    setXY(x, y + 1); cout << "     ";
    setXY(x, y + 2); cout << "     ";
}
int ColorEscopeta(short& escopeta)
{
    if (escopeta == 1)
        return 13;
    if (escopeta == 2)
        return 10;
    if (escopeta == 3)
        return  5;

}
void Grass_2(int x, int y, int altura)
{
    for (int j = 0; j < altura; j++)
    {
        for (int i = 0; i < ANCHO; i++)
        {

            setXY(x + i, y);
            setBGcolor(12);
            cout << " ";
        }
        y = y - 1;
    }
    y = ALTO - altura;
    for (int i = 0; i < ANCHO; i++)
    {

        setXY(x + i, y); setBGcolor(7); cout << " ";

    }

}
void Fondo_Jugador()
{
    Cielo_1();
    int contador = 0;
    int x = 0;
    int y = 0;
    Grass_2(0, ALTO, 25);
    dibujaGrass2(70, ANCHO - 1, ALTO - 1);

    CasetaJuego1();

}

void BorrarBala(char bala, float& x, float& y)
{
    setXY(x, y);
    setBGcolor(12); cout << " ";
}
void DibujarBala(char bala, float& x, float& y, int color)
{
    setXY(x, y);
    setBGcolor(12); setColor(color); cout << bala;
}
void DesplazarBala(char bala, float& x, float& y, float& vx, float& vy)
{
    if (y + vy < 16)
        estado = INACTIVO;
    else
        y = y + vy;
}
void MoverBala(char bala, float& x, float& y, int color, float& vx, float& vy)
{
    if (estado == ACTIVO)
    {
        BorrarBala(bala, x, y);
        DesplazarBala(bala, x, y, vx, vy);
        DibujarBala(bala, x, y, color);
    }
    else
        BorrarBala(bala, x, y);
}
void dibujarEscopeta(float x, int y, int color)
{
    setBGcolor(1);
    setXY(x, y); cout << "  "; setBGcolor(color); cout << "   "; setBGcolor(1); cout << "  ";
    setXY(x, y - 1); cout << "  "; setBGcolor(color); cout << "   "; setBGcolor(1); cout << "  ";
    setXY(x, y - 2); cout << "  "; setBGcolor(color); cout << "   "; setBGcolor(1); cout << "  ";
    setXY(x, y - 3); cout << "  "; setBGcolor(color); cout << "   "; setBGcolor(1); cout << "  ";
    setXY(x, y - 4); ; cout << "       ";
    setXY(x + 2, y - 5); ; cout << "   ";
}
void borrarEscopeta(float x, int y, int color)
{
    setBGcolor(12);
    setXY(x, y); cout << "  "; setBGcolor(12); cout << "   "; setBGcolor(12); cout << "  ";
    setXY(x, y - 1); cout << "  "; setBGcolor(12); cout << "   "; setBGcolor(12); cout << "  ";
    setXY(x, y - 2); cout << "  "; setBGcolor(12); cout << "   "; setBGcolor(12); cout << "  ";
    setXY(x, y - 3); cout << "  "; setBGcolor(12); cout << "   "; setBGcolor(12); cout << "  ";
    setXY(x, y - 4); ; cout << "       ";
    setXY(x + 2, y - 5); ; cout << "   ";
}
void DesplazarEscopeta(float& x, int vx)
{
    if (x + vx > 110 || x + vx < 22)
        x = x;
    else
        x = x + vx;
}
void MoverEscopeta(float& x, int y, int vx, int color)
{
    borrarEscopeta(x, y, color);
    DesplazarEscopeta(x, vx);
    dibujarEscopeta(x, y, color);
}
void Velocidad_Fase(float& vel, int num_fase)
{
    if (num_fase == 1)
    {
        do {
            vel = AleatorioDec();
        } while (!(vel >= 0.5 && vel < 0.7));
    }
    if (num_fase == 2)
    {
        do {
            vel = AleatorioDec();
        } while (!(vel >= 0.7 && vel < 0.9));
    }
    if (num_fase == 3)
    {
        do {
            vel = AleatorioDec();
        } while (!(vel >= 0.9 && vel < 1.2));
    }
}
struct Objetivo
{
    float x;
    float y;
    float vx;
    int color;
    int tipo;
    float posi;
};
void BorrarObjetivo(Objetivo vObj)
{
    setXY(vObj.x, vObj.y);
    setBGcolor(12); cout << " ";
}
void DibujarObjetivo(Objetivo vObj)
{
    setXY(vObj.x, vObj.y);
    setColor(vObj.color); cout << char(vObj.tipo);
}
void DesplazarObjetivo(Objetivo& vObj)
{

    if (vObj.x + vObj.vx < 25 || vObj.x + vObj.vx >115)
    {
        estadoObjetivo = INACTIVO;
    }
    else
        vObj.x = vObj.x + vObj.vx;

}
void MoverObjetivo(Objetivo* vObj, int pos)
{
    if (estadoObjetivo == ACTIVO)
    {
        BorrarObjetivo(vObj[pos]);
        DesplazarObjetivo(vObj[pos]);
        DibujarObjetivo(vObj[pos]);
    }

}
void BorrarObjetivo2(Objetivo vObj)
{
    setXY(vObj.x, vObj.y);
    setBGcolor(12); cout << " ";
}
void DibujarObjetivo2(Objetivo vObj)
{
    setXY(vObj.x, vObj.y);
    setColor(vObj.color); cout << char(vObj.tipo);
}
void DesplazarObjetivo2(Objetivo& vObj)
{

    if (vObj.x + vObj.vx < 25 || vObj.x + vObj.vx >115)
    {
        estadoObjetivo2 = INACTIVO;
    }
    else
        vObj.x = vObj.x + vObj.vx;

}
void MoverObjetivo2(Objetivo* vObj, int pos)
{
    if (estadoObjetivo2 == ACTIVO)
    {
        BorrarObjetivo2(vObj[pos]);
        DesplazarObjetivo2(vObj[pos]);
        DibujarObjetivo2(vObj[pos]);
    }

}
void GenerarObjetivos1(Objetivo* vObj, int N, float vel)
{
    int contador;
    for (int i = 0; i < N; i++)
    {
        contador = Aleatorio(1, 2);

        if (contador == 1)
        {
            vObj[i].vx = vel;
            vObj[i].x = 26;
            vObj[i].color = Aleatorio(2, 8);
            vObj[i].y = 21;
            vObj[i].tipo = 254;
        }
        if (contador == 2)
        {
            vObj[i].vx = (-1) * vel;
            vObj[i].x = 114;
            vObj[i].color = Aleatorio(2, 8);
            vObj[i].y = 21;
            vObj[i].tipo = 254;
        }
    }
}
void Informacion(float vel, int puntaje, int aciertos, int Mpuntaje, int descuento, int contadordisparos, int contadorObj, int cantidad)
{
    setBGcolor(2);
    setXY(40, 5); setColor(15); cout << "Velocidad: " << vel;
    if (contadorObj >= cantidad - 1)
    {
        setXY(40, 7); setColor(14); cout << "Total de Objetivos: " << cantidad - contadorObj;
    }
    else
    {
        setXY(40, 7); cout << "Total de Objetivos: " << cantidad - contadorObj;
    }
    setColor(15);
    setXY(40, 9); cout << "Disparos Permitidos: " << cantidad + 3;

    if (contadordisparos >= cantidad + 2)
    {
        setXY(40, 11); setColor(14); cout << "Disparos Hechos: " << contadordisparos;
    }
    else
    {
        setXY(40, 11); cout << "Disparos Hechos: " << contadordisparos;
    }
    setColor(15);
    setXY(78, 5); cout << "Puntaje Actual: " << puntaje;
    setXY(78, 7); cout << "Mejor Puntaje: " << Mpuntaje;
    setXY(78, 9); cout << "Disparos Acertados: " << aciertos;
    if (descuento > 0)
    {
        setColor(14); setXY(78, 11); cout << "Descuentos: " << descuento;
    }
}
void VentanaInformativa(float vel, int puntaje, int aciertos, int Mpuntaje, int descuento, int contadordisparos, int contadorObj, int cantidad)
{
    GeneraCuadroMenu(25, 2, 90, 12, 2);
    GeneraCuadroMenu(50, 1, 40, 3, 16);
    setXY(60, 2); setBGcolor(16); setColor(1); cout << "I N F O R M A C I O N";
    setBGcolor(2);

    Informacion(vel, puntaje, aciertos, Mpuntaje, descuento, contadordisparos, contadorObj, cantidad);

}
void Informacion2(float vel, int puntaje, int aciertos, int Mpuntaje, int descuento, int contadordisparos, int contadorObj, int cantidad)
{
    setBGcolor(2);
    setXY(40, 5); setColor(15); cout << "Velocidad: " << vel;
    if (contadorObj >= cantidad - 1)
    {
        setXY(40, 7); setColor(14); cout << "Total de Objetivos: " << cantidad - contadorObj;
    }
    else
    {
        setXY(40, 7); cout << "Total de Objetivos: " << cantidad - contadorObj;
    }
    setColor(15);
    setXY(40, 9); cout << "Disparos Permitidos: " << cantidad + 1;

    if (contadordisparos >= cantidad + 2)
    {
        setXY(40, 11); setColor(14); cout << "Disparos Hechos: " << contadordisparos;
    }
    else
    {
        setXY(40, 11); cout << "Disparos Hechos: " << contadordisparos;
    }
    setColor(15);
    setXY(78, 5); cout << "Puntaje Actual: " << puntaje;
    setXY(78, 7); cout << "Mejor Puntaje: " << Mpuntaje;
    setXY(78, 9); cout << "Disparos Acertados: " << aciertos;
    if (descuento > 0)
    {
        setColor(14); setXY(78, 11); cout << "Descuentos: " << descuento;
    }
}
void VentanaInformativa2(float vel, int puntaje, int aciertos, int Mpuntaje, int descuento, int contadordisparos, int contadorObj, int cantidad)
{
    GeneraCuadroMenu(25, 2, 90, 12, 2);
    GeneraCuadroMenu(50, 1, 40, 3, 16);
    setXY(60, 2); setBGcolor(16); setColor(1); cout << "I N F O R M A C I O N";
    setBGcolor(2);

    Informacion2(vel, puntaje, aciertos, Mpuntaje, descuento, contadordisparos, contadorObj, cantidad);

}
void dibujaFlechaDerecha()
{
    setColor(9);
    setBGcolor(12);
    setXY(20, 18); cout << "----->"; _sleep(500);
    setXY(20, 18); cout << "      ";
}
void dibujaFlechaIzquierda()
{
    setColor(9);
    setBGcolor(12);
    setXY(115, 18); cout << "<-----"; _sleep(500);
    setXY(115, 18); cout << "      ";
}
void dibuja_2_Flechas()
{
    setColor(9);
    setBGcolor(12);
    setXY(20, 18); cout << "----->";
    setXY(115, 18); cout << "<-----"; _sleep(500);
    setXY(20, 18); cout << "      ";
    setXY(115, 18); cout << "      ";

}
void AgregarPuntaje(Jugadores*& participante, int indice, int puntaje)
{
    participante[indice].puntaje = puntaje;
}
void Cartel_2(int puntaje)
{
    dibujarCuadroTexto(16, 25);
    setColor(15); setBGcolor(1); setXY(18, 26); cout << "PUNTAJE: " << puntaje;
    setColor(1); setBGcolor(12); setXY(65, 38); cout << "[Presione cualquier tecla]";

}
void VentanaPuntaje(int puntaje)
{
    Escenario_Deportivo();

    Persona juez1;
    Persona juez2;

    juez1.x = 0;
    juez1.y = 29;
    juez1.vX = 1;

    juez2.x = 0;
    juez2.y = 29;
    juez2.vX = 1;

    while (true)
    {
        if (juez1.x < 20)
        {
            desplazarJuez(juez1.x, juez1.y, juez1.vX);
        }
        if (juez1.x >= 11 && juez2.x < 10)
        {
            desplazarJuez(juez2.x, juez2.y, juez2.vX);
        }
        if (juez1.x == 20 && juez2.x == 10)
        {
            Cartel_2(puntaje);
            _getch();
            break;

        }
        _sleep(100);
    }
    setBGcolor(3);
    Console::Clear();
}
void VistaJugador(short escopeta, float vel, int mayorPuntaje, Jugadores*& participante, int indice)
{
    setBGcolor(1);
    Console::Clear();
    Fondo_Jugador();

    int cantidad = 7;
    //Escopeta
    int color;
    float xE = 65;
    float yE = ALTO;
    float vxE = 1;

    //Bala
    char bala = '*';
    float xB = xE + 3;
    float yB = yE - 6;
    int colorBala = 1; //9
    float vxB = 0;
    float vyB = -1;

    int contadorDisparos;
    contadorDisparos = 0;

    int contadorObj = 0;
    //Dibujar escopeta
    color = ColorEscopeta(escopeta);
    dibujarEscopeta(xE, yE, color);

    bool FinJuego = false;
    char tecla;

    //Objetivos en Movimiento

    Objetivo* vObj;
    vObj = new Objetivo[7];
    GenerarObjetivos1(vObj, 7, vel);
    int pos = 0;

    //Ventana de Informacion
    int puntaje = 0;
    int aciertos = 0;
    int descuento = 0;
    VentanaInformativa(vel, puntaje, aciertos, mayorPuntaje, descuento, contadorDisparos, contadorObj, cantidad);
    bool colision = false;
    bool borrar = false;

    while (true)//cont<objetivos
    {
        if (vObj[pos].vx < 0 && borrar == false && pos < 7)
        {
            dibujaFlechaIzquierda();
            borrar = true;
        }
        if (vObj[pos].vx > 0 && borrar == false && pos < 7)
        {
            dibujaFlechaDerecha();
            borrar = true;
        }
        if (pos == 0)
            estadoObjetivo = ACTIVO;

        if (kbhit() && contadorDisparos < 10)
        {
            tecla = _getch();
            switch (tecla)
            {
            case LEFT: vxE = -1; break;
            case RIGHT:vxE = 1; break;
            case SPACE:
                if (estado == INACTIVO)
                {
                    //Reiniciamos valores
                    xB = xE + 3;
                    yB = yE - 4;
                    vyB = -1;
                    estado = ACTIVO;
                    contadorDisparos++;
                }break;
            }
        }
        else
        {
            vxE = 0;
        }

        MoverBala(bala, xB, yB, colorBala, vxB, vyB);

        if (contadorDisparos <= 10)
            MoverEscopeta(xE, yE, vxE, color);

        if (pos < 7)
            MoverObjetivo(vObj, pos);

        int limite = 1;
        if (xB - vObj[pos].x <= limite && vObj[pos].x - xB <= limite && yB - vObj[pos].y <= limite && vObj[pos].y - yB <= limite)
        {
            puntaje = puntaje + 20;
            aciertos++;
            estadoObjetivo = INACTIVO;
        }
        if (xE + vxE < 22 || xE + vxE>110)
        {
            descuento = descuento + 5;
        }
        if (estadoObjetivo == INACTIVO)
        {
            borrar = false;
            BorrarObjetivo(vObj[pos]);
            estadoObjetivo = ACTIVO;
            contadorObj++;
            pos++;
        }
        Informacion(vel, puntaje, aciertos, mayorPuntaje, descuento, contadorDisparos, contadorObj, cantidad);
        if ((contadorObj == 7 || contadorDisparos == 10) && estado == INACTIVO)
            break;


        _sleep(75);
    }
    _sleep(1000);
    puntaje = puntaje - descuento;
    setBGcolor(1);
    Console::Clear();
    VentanaPuntaje(puntaje);
    AgregarPuntaje(participante, indice, puntaje);

}

int Mayor(Jugadores* participante, int pos)
{
    int mayor = participante[0].puntaje;
    if (pos == 0)
    {
        mayor = 0;
    }
    else
    {
        for (int i = 0; i < pos + 1; i++)
        {
            if (participante[i].puntaje > mayor)
            {
                mayor = participante[i].puntaje;
            }
        }
    }

    return mayor;
}
int AsignarNumJugador(Jugadores*& participante, int pos)
{
    if (participante[pos].Pais == "Argentina")
        return  1;
    if (participante[pos].Pais == "Peru")
        return  2;
    if (participante[pos].Pais == "Colombia")
        return  3;
    if (participante[pos].Pais == "Chile")
        return  4;
    if (participante[pos].Pais == "Brasil")
        return  5;
    if (participante[pos].Pais == "Mexico")
        return  6;
    if (participante[pos].Pais == "Nicaragua")
        return  7;
    if (participante[pos].Pais == "Bolivia")
        return  8;
    if (participante[pos].Pais == "Francia")
        return  9;
    if (participante[pos].Pais == "Venezuela")
        return  10;

}
void VistaLateralJugador(int num, short escopeta)
{
    int x = 34;
    BorrarJugador(x, 19);
    int color;

    if (escopeta == 1)
        color = 13;
    if (escopeta == 2)
        color = 10;
    if (escopeta == 3)
        color = 5;

    switch (num)
    {
    case 1: dibujaJugadorargentinaPerfil(x, 19, color); break;
    case 2: dibujaJugadorperuPerfil(x, 19, color); break;
    case 3: dibujaJugadorcolombiaPerfil(x, 19, color); break;
    case 4: dibujaJugadorchilePerfil(x, 19, color); break;
    case 5: dibujaJugadorbrazilPerfil(x, 19, color); break;
    case 6: dibujaJugadormexicoPerfil(x, 19, color); break;
    case 7: dibujaJugadornicaraguaPerfil(x, 19, color); break;
    case 8: dibujaJugadorboliviaPerfil(x, 19, color); break;
    case 9: dibujaJugadorfranciaPerfil(x, 19, color); break;
    case 10: dibujaJugadorvenezuelaPerfil(x, 19, color); break;

    }


}
void Fase1(string*& Paises, int*& N, Jugadores*& participante, int* Nj)
{
    short escopeta = 0;
    int num;
    int Mayorpuntaje = 0;
    float vel1;
    int contador = 0;
    Velocidad_Fase(vel1, 1);

    int pos = 0;

    while (contador < 10)
    {
        ListaPaises(N, Paises, participante, pos);
        num = AsignarNumJugador(participante, pos);
        PantallaEscopeta(escopeta);
        Escenario_Deportivo();
        Entrada_Jueces();
        Entrada_Jugador(num);
        VistaLateralJugador(num, escopeta);
        Cartel_1();
        Mayorpuntaje = Mayor(participante, pos);
        Contador();
        VistaJugador(escopeta, vel1, Mayorpuntaje, participante, pos);
        contador++;
        pos++;
    }

}
string* OrdenaDescendente(Jugadores* participante, int* Nj, int num, int*& N)
{
    int aux;
    string aux2;
    string* Temporal = new string[*Nj];

    for (int i = 0; i < *Nj - 1; i++)
    {
        for (int j = i + 1; j < *Nj; j++)
        {
            if (participante[i].puntaje < participante[j].puntaje)
            {
                //Ordena puntaje
                aux = participante[i].puntaje;
                participante[i].puntaje = participante[j].puntaje;
                participante[j].puntaje = aux;

                //Ordena pais
                aux2 = participante[i].Pais;
                participante[i].Pais = participante[j].Pais;
                participante[j].Pais = aux2;

            }
        }
    }
    for (int i = 0; i < num; i++)
    {
        Temporal[i] = participante[i].Pais;
    }
    *N = num;
    return Temporal;
}
void VentanaEstadistica(Jugadores* participante, int* Num, int fase)
{
    Fondo_1();
    GeneraCuadroMenu(40, 12, 60, 15, 4);
    GeneraCuadroMenu(50, 11, 42, 3, 16);
    setColor(1);
    setXY(61, 12); cout << "ESTADISTICA DEL JUEGO";

    int x = 50;
    int y = 16;
    int y2 = 16;
    int y3 = 16;

    for (int i = 0; i < *Num; i++)
    {
        if (*Num > 5)
        {
            if (i < 5)
            {
                setXY(x, y); setBGcolor(10); setColor(15);
                cout << " " << i + 1 << " ";
                setBGcolor(4);
                setXY(x + 5, y); cout << participante[i].Pais << ": " << participante[i].puntaje;
                y = y + 2;
            }
            else
            {
                setXY(x + 25, y2); setBGcolor(10); setColor(15);
                cout << " " << i + 1 << " ";
                setBGcolor(4);
                setXY(x + 25 + 5, y2); cout << participante[i].Pais << ": " << participante[i].puntaje;
                y2 = y2 + 2;
            }
        }
        else
        {
            setXY(x, y3); setBGcolor(10); setColor(15);
            cout << " " << i + 1 << " ";
            setBGcolor(4);
            setXY(x + 5, y3); cout << participante[i].Pais << ": " << participante[i].puntaje;
            y3 = y3 + 2;
        }
    }
    setXY(ANCHO / 2 - 21, ALTO - 7); setBGcolor(3); setColor(13);
    cout << "[Presione cualquier tecla para iniciar Fase " << fase << "]"; _getch();
    setBGcolor(3); Console::Clear();
}

void VistaJugador2(short escopeta, float vel, int mayorPuntaje, Jugadores*& participante, int indice)
{
    setBGcolor(1);
    Console::Clear();
    Fondo_Jugador();

    int cantidad = 5;
    //Escopeta
    int color;
    float xE = 65;
    float yE = ALTO;
    float vxE = 1.3;

    //Bala
    char bala = '*';
    float xB = xE + 3;
    float yB = yE - 6;
    int colorBala = 1; //9
    float vxB = 0;
    float vyB = -1;

    int contadorDisparos;
    contadorDisparos = 0;

    int contadorObj = 0;
    //Dibujar escopeta
    color = ColorEscopeta(escopeta);
    dibujarEscopeta(xE, yE, color);

    bool FinJuego = false;
    char tecla;

    //Objetivos en Movimiento

    Objetivo* vObj;
    vObj = new Objetivo[5];
    GenerarObjetivos1(vObj, 5, vel);
    int pos = 0;

    //Objetivo en Simultaneo
    Objetivo* vObj2;
    vObj2 = new Objetivo[2];

    vObj2[0].color = 9;
    vObj2[1].color = 9;

    vObj2[0].tipo = 254;
    vObj2[1].tipo = 254;

    vObj2[0].vx = vel;
    vObj2[1].vx = (-1) * vel;

    vObj2[0].x = 26;
    vObj2[1].x = 114;

    vObj2[0].y = 21;
    vObj2[1].y = 21;

    vObj2[0].posi = 26;
    vObj2[1].posi = 114;

    int indice1_2_objetivos = Aleatorio(0, cantidad - 1);
    int indice2_2_objetivos;
    do {
        indice2_2_objetivos = Aleatorio(0, cantidad - 1);
    } while (indice1_2_objetivos == indice2_2_objetivos);

    //Ventana de Informacion
    int puntaje = 0;
    int aciertos = 0;
    int descuento = 0;
    VentanaInformativa(vel, puntaje, aciertos, mayorPuntaje, descuento, contadorDisparos, contadorObj, cantidad);
    bool colision = false;
    bool borrar = false;

    bool activo2 = false;
    bool activo1 = false;

    bool entrada = true;

    while (true)
    {
        if ((pos == 0) || (pos > 0 && estadoObjetivo == ACTIVO) && pos < 5)
        {
            if (!(pos == indice1_2_objetivos || pos == indice2_2_objetivos))
            {
                if (vObj[pos].vx < 0 && borrar == false && pos < 5)
                {
                    dibujaFlechaIzquierda();
                    borrar = true;
                }
                if (vObj[pos].vx > 0 && borrar == false && pos < 5)
                {
                    dibujaFlechaDerecha();
                    borrar = true;
                }
            }
            if ((pos == indice1_2_objetivos || pos == indice2_2_objetivos) && borrar == false)
            {
                dibuja_2_Flechas();
                borrar = true;
            }
        }
        if (estadoObjetivo2 == ACTIVO && borrar == false && pos < 5)
        {
            dibuja_2_Flechas();
            borrar = true;
        }
        if (pos == 0)
        {
            if ((pos == indice1_2_objetivos || pos == indice2_2_objetivos) && activo2 == false && activo1 == false)
            {
                estadoObjetivo2 = ACTIVO;
                estadoObjetivo = ACTIVO;
                activo2 = true;
                activo1 = true;
            }
            if (activo1 == false)
            {
                estadoObjetivo = ACTIVO;
                activo1 = true;
            }
        }

        //Informacion(vel, puntaje, aciertos, mayorPuntaje, descuento, contadorDisparos, contadorObj, cantidad);
        if (kbhit() && contadorDisparos < 8)
        {
            tecla = _getch();
            switch (tecla)
            {
            case LEFT: vxE = -1; break;
            case RIGHT:vxE = 1; break;
            case SPACE:
                if (estado == INACTIVO)
                {
                    //Reiniciamos valores de la bala
                    xB = xE + 3;
                    yB = yE - 4;
                    vyB = -1;
                    estado = ACTIVO;
                    contadorDisparos++;
                }break;
            }
        }
        else
        {
            vxE = 0;
        }

        MoverBala(bala, xB, yB, colorBala, vxB, vyB);
        int pos2;
        if (vObj[pos].vx > 0) //Si el pbj va a la derecha el otro obj va a la izq
            pos2 = 1;

        if (vObj[pos].vx < 0)
            pos2 = 0;

        if (contadorDisparos <= 8)
            MoverEscopeta(xE, yE, vxE, color);
        if (indice1_2_objetivos == pos || indice2_2_objetivos == pos)
            MoverObjetivo2(vObj2, pos2);
        if (pos < 5)
            MoverObjetivo(vObj, pos);

        int limite = 1;


        //Si colisiona con el objetivo normal o si colisiona con el segundo objetivo
        if (estadoObjetivo2 == ACTIVO)
        {
            if (xB - vObj[pos].x <= limite && vObj[pos].x - xB <= limite && yB - vObj[pos].y <= limite && vObj[pos].y - yB <= limite || (xB - vObj2[pos2].x <= limite && vObj2[pos2].x - xB <= limite && yB - vObj2[pos2].y <= limite && vObj2[pos2].y - yB <= limite)) //ANADIR COLISION DOBLE
            {
                //DOBLE COLISION
                if (xB - vObj2[pos2].x <= limite && vObj2[pos2].x - xB <= limite && yB - vObj2[pos2].y <= limite && vObj2[pos2].y - yB <= limite && (xB - vObj[pos].x <= limite && vObj[pos].x - xB <= limite && yB - vObj[pos].y <= limite && vObj[pos].y - yB <= limite) && entrada == true)
                {
                    BorrarObjetivo2(vObj2[pos2]);
                    BorrarObjetivo(vObj[pos]);
                    puntaje = puntaje + 40;
                    aciertos++;
                    estadoObjetivo = INACTIVO;
                    estadoObjetivo2 = INACTIVO;
                    entrada = false;
                }
                //Si solo el segundo objetivo colisiona 
                else if (xB - vObj2[pos2].x <= limite && vObj2[pos2].x - xB <= limite && yB - vObj2[pos2].y <= limite && vObj2[pos2].y - yB <= limite && (!(xB - vObj[pos].x <= limite && vObj[pos].x - xB <= limite && yB - vObj[pos].y <= limite && vObj[pos].y - yB <= limite)) && entrada == true)
                {
                    BorrarObjetivo2(vObj2[pos2]);
                    puntaje = puntaje + 20;
                    aciertos++;
                    estadoObjetivo2 = INACTIVO;
                    entrada = false;
                }
                //Si solo el objetivo normal colisiona 
                else if (xB - vObj[pos].x <= limite && vObj[pos].x - xB <= limite && yB - vObj[pos].y <= limite && vObj[pos].y - yB <= limite && (!(xB - vObj2[pos2].x <= limite && vObj2[pos2].x - xB <= limite && yB - vObj2[pos2].y <= limite && vObj2[pos2].y - yB <= limite)) && entrada == true)
                {
                    BorrarObjetivo(vObj[pos]);
                    puntaje = puntaje + 20;
                    aciertos++;
                    estadoObjetivo = INACTIVO;
                    entrada = false;
                }

            }
        }
        else
        {
            if (xB - vObj[pos].x <= limite && vObj[pos].x - xB <= limite && yB - vObj[pos].y <= limite && vObj[pos].y - yB <= limite)
            {
                puntaje = puntaje + 20;
                aciertos++;
                estadoObjetivo = INACTIVO;
            }
        }
        if (xE + vxE < 22 || xE + vxE>110) //Poner tipo obstaculo para inmovilizar con Matriz
        {
            descuento = descuento + 5;
        }
        if (estadoObjetivo2 == INACTIVO && activo2 == true && estadoObjetivo == ACTIVO)
        {
            BorrarObjetivo2(vObj2[pos2]);
            vObj2[pos2].x = vObj2[pos2].posi; //Reiniciamos posicion
            if (!(pos == 0))
                activo2 = false;
        }
        if (estadoObjetivo == INACTIVO)
        {
            BorrarObjetivo(vObj[pos]);

            if (estadoObjetivo2 == ACTIVO && (!(pos == 0)))
            {
                activo2 = true;
            }
            if (activo2 = true && estadoObjetivo2 == INACTIVO)
            {
                BorrarObjetivo2(vObj2[pos2]);
                vObj2[pos2].x = vObj2[pos2].posi;
                activo2 = false;
                //estadoObjetivo = ACTIVO;
            }
            if (estadoObjetivo2 == INACTIVO) // y estado Objetivo tmb INACTIVO
            {
                pos++;
                contadorObj++;
                borrar = false;
                entrada = true;
                if (pos == indice1_2_objetivos || pos == indice2_2_objetivos) //Al tiempo q aumenta el contador verificamos
                {
                    estadoObjetivo2 = ACTIVO;
                    estadoObjetivo = ACTIVO;
                }
                if (!(pos == indice1_2_objetivos || pos == indice2_2_objetivos))
                {
                    estadoObjetivo = ACTIVO;
                }

            }
        }
        Informacion(vel, puntaje, aciertos, mayorPuntaje, descuento, contadorDisparos, contadorObj, cantidad);
        if ((contadorObj == 5 || contadorDisparos == 8) && estado == INACTIVO)
            break;


        _sleep(75);
    }
    _sleep(1000);
    puntaje = puntaje - descuento;
    setBGcolor(1);
    Console::Clear();
    VentanaPuntaje(puntaje);
    AgregarPuntaje(participante, indice, puntaje);

}
void Fase2(string*& Paises, int*& N, Jugadores*& participante, int* Nj, int fase)
{
    short escopeta = 0;
    int num;
    int Mayorpuntaje = 0;
    float vel;
    int contador = 0;
    Velocidad_Fase(vel, fase);
    int pos = 0;

    while (contador < 5)
    {
        ListaPaises(N, Paises, participante, pos);
        num = AsignarNumJugador(participante, pos);
        PantallaEscopeta(escopeta);
        Escenario_Deportivo();
        Entrada_Jueces();
        Entrada_Jugador(num);
        VistaLateralJugador(num, escopeta);
        Cartel_1();
        Mayorpuntaje = Mayor(participante, pos);
        Contador();
        VistaJugador2(escopeta, vel, Mayorpuntaje, participante, pos);
        contador++;
        pos++;
    }

}
void VistaJugador3(short escopeta, float vel, int mayorPuntaje, Jugadores*& participante, int indice)
{
    setBGcolor(1);
    Console::Clear();
    Fondo_Jugador();

    int cantidad = 3;
    //Escopeta
    int color;
    float xE = 65;
    float yE = ALTO;
    float vxE = 1.6;

    //Bala
    char bala = '*';
    float xB = xE + 3;
    float yB = yE - 6;
    int colorBala = 1; //9
    float vxB = 0;
    float vyB = -1;

    int contadorDisparos;
    contadorDisparos = 0;

    int contadorObj = 0;
    //Dibujar escopeta
    color = ColorEscopeta(escopeta);
    dibujarEscopeta(xE, yE, color);

    bool FinJuego = false;
    char tecla;

    //Objetivos en Movimiento

    Objetivo* vObj;
    vObj = new Objetivo[3];
    GenerarObjetivos1(vObj, 3, vel);
    int pos = 0;

    //Objetivo en Simultaneo
    Objetivo* vObj2;
    vObj2 = new Objetivo[2];

    vObj2[0].color = 9;
    vObj2[1].color = 9;

    vObj2[0].tipo = 254;
    vObj2[1].tipo = 254;

    vObj2[0].vx = vel;
    vObj2[1].vx = (-1) * vel;

    vObj2[0].x = 26;
    vObj2[1].x = 114;

    vObj2[0].y = 21;
    vObj2[1].y = 21;

    vObj2[0].posi = 26;
    vObj2[1].posi = 114;

    int indice1_2_objetivos = Aleatorio(0, cantidad - 1);
    int indice2_2_objetivos;
    do {
        indice2_2_objetivos = Aleatorio(0, cantidad - 1);
    } while (indice1_2_objetivos == indice2_2_objetivos);

    //Ventana de Informacion
    int puntaje = 0;
    int aciertos = 0;
    int descuento = 0;
    VentanaInformativa2(vel, puntaje, aciertos, mayorPuntaje, descuento, contadorDisparos, contadorObj, cantidad);
    bool colision = false;
    bool borrar = false;

    bool activo2 = false;
    bool activo1 = false;

    bool entrada = true;

    while (true)
    {
        if ((pos == 0) || (pos > 0 && estadoObjetivo == ACTIVO) && pos < 3)
        {
            if (!(pos == indice1_2_objetivos || pos == indice2_2_objetivos))
            {
                if (vObj[pos].vx < 0 && borrar == false && pos < 3)
                {
                    dibujaFlechaIzquierda();
                    borrar = true;
                }
                if (vObj[pos].vx > 0 && borrar == false && pos < 3)
                {
                    dibujaFlechaDerecha();
                    borrar = true;
                }
            }
            if ((pos == indice1_2_objetivos || pos == indice2_2_objetivos) && borrar == false)
            {
                dibuja_2_Flechas();
                borrar = true;
            }
        }
        if (estadoObjetivo2 == ACTIVO && borrar == false && pos < 3)
        {
            dibuja_2_Flechas();
            borrar = true;
        }
        if (pos == 0)
        {
            if ((pos == indice1_2_objetivos || pos == indice2_2_objetivos) && activo2 == false && activo1 == false)
            {
                estadoObjetivo2 = ACTIVO;
                estadoObjetivo = ACTIVO;
                activo2 = true;
                activo1 = true;
            }
            if (activo1 == false)
            {
                estadoObjetivo = ACTIVO;
                activo1 = true;
            }
        }

        if (kbhit() && contadorDisparos < 4)
        {
            tecla = _getch();
            switch (tecla)
            {
            case LEFT: vxE = -1; break;
            case RIGHT:vxE = 1; break;
            case SPACE:
                if (estado == INACTIVO)
                {
                    //Reiniciamos valores de la bala
                    xB = xE + 3;
                    yB = yE - 4;
                    vyB = -1;
                    estado = ACTIVO;
                    contadorDisparos++;
                }break;
            }
        }
        else
        {
            vxE = 0;
        }

        MoverBala(bala, xB, yB, colorBala, vxB, vyB);
        MoverEscopeta(xE, yE, vxE, color);
        int pos2;
        if (vObj[pos].vx > 0) //Si el pbj va a la derecha el otro obj va a la izq
            pos2 = 1;

        if (vObj[pos].vx < 0)
            pos2 = 0;

        if (indice1_2_objetivos == pos || indice2_2_objetivos == pos)
            MoverObjetivo2(vObj2, pos2);
        if (pos < 3)
            MoverObjetivo(vObj, pos);

        int limite = 1;


        //Si colisiona con el objetivo normal o si colisiona con el segundo objetivo
        if (estadoObjetivo2 == ACTIVO)
        {
            if (xB - vObj[pos].x <= limite && vObj[pos].x - xB <= limite && yB - vObj[pos].y <= limite && vObj[pos].y - yB <= limite || (xB - vObj2[pos2].x <= limite && vObj2[pos2].x - xB <= limite && yB - vObj2[pos2].y <= limite && vObj2[pos2].y - yB <= limite)) //ANADIR COLISION DOBLE
            {
                //DOBLE COLISION
                if (xB - vObj2[pos2].x <= limite && vObj2[pos2].x - xB <= limite && yB - vObj2[pos2].y <= limite && vObj2[pos2].y - yB <= limite && (xB - vObj[pos].x <= limite && vObj[pos].x - xB <= limite && yB - vObj[pos].y <= limite && vObj[pos].y - yB <= limite) && entrada == true)
                {
                    BorrarObjetivo2(vObj2[pos2]);
                    BorrarObjetivo(vObj[pos]);
                    puntaje = puntaje + 40;
                    aciertos++;
                    estadoObjetivo = INACTIVO;
                    estadoObjetivo2 = INACTIVO;
                    entrada = false;
                }
                //Si solo el segundo objetivo colisiona 
                else if (xB - vObj2[pos2].x <= limite && vObj2[pos2].x - xB <= limite && yB - vObj2[pos2].y <= limite && vObj2[pos2].y - yB <= limite && (!(xB - vObj[pos].x <= limite && vObj[pos].x - xB <= limite && yB - vObj[pos].y <= limite && vObj[pos].y - yB <= limite)) && entrada == true)
                {
                    BorrarObjetivo2(vObj2[pos2]);
                    puntaje = puntaje + 20;
                    aciertos++;
                    estadoObjetivo2 = INACTIVO;
                    entrada = false;
                }
                //Si solo el objetivo normal colisiona 
                else if (xB - vObj[pos].x <= limite && vObj[pos].x - xB <= limite && yB - vObj[pos].y <= limite && vObj[pos].y - yB <= limite && (!(xB - vObj2[pos2].x <= limite && vObj2[pos2].x - xB <= limite && yB - vObj2[pos2].y <= limite && vObj2[pos2].y - yB <= limite)) && entrada == true)
                {
                    BorrarObjetivo(vObj[pos]);
                    puntaje = puntaje + 20;
                    aciertos++;
                    estadoObjetivo = INACTIVO;
                    entrada = false;
                }

            }
        }
        else
        {
            if (xB - vObj[pos].x <= limite && vObj[pos].x - xB <= limite && yB - vObj[pos].y <= limite && vObj[pos].y - yB <= limite)
            {
                puntaje = puntaje + 20;
                aciertos++;
                estadoObjetivo = INACTIVO;
            }
        }
        if (xE + vxE < 22 || xE + vxE>110) //Poner tipo obstaculo para inmovilizar con Matriz
        {
            descuento = descuento + 5;
        }
        if (estadoObjetivo2 == INACTIVO && activo2 == true && estadoObjetivo == ACTIVO)
        {
            BorrarObjetivo2(vObj2[pos2]);
            vObj2[pos2].x = vObj2[pos2].posi; //Reiniciamos posicion
            if (!(pos == 0))
                activo2 = false;
        }
        if (estadoObjetivo == INACTIVO)
        {
            BorrarObjetivo(vObj[pos]);

            if (estadoObjetivo2 == ACTIVO && (!(pos == 0)))
            {
                activo2 = true;
            }
            if (activo2 = true && estadoObjetivo2 == INACTIVO)
            {
                BorrarObjetivo2(vObj2[pos2]);
                vObj2[pos2].x = vObj2[pos2].posi;
                activo2 = false;
                //estadoObjetivo = ACTIVO;
            }
            if (estadoObjetivo2 == INACTIVO) // y estado Objetivo tmb INACTIVO
            {
                pos++;
                contadorObj++;
                borrar = false;
                entrada = true;
                if (pos == indice1_2_objetivos || pos == indice2_2_objetivos) //Al tiempo q aumenta el contador verificamos
                {
                    estadoObjetivo2 = ACTIVO;
                    estadoObjetivo = ACTIVO;
                }
                if (!(pos == indice1_2_objetivos || pos == indice2_2_objetivos))
                {
                    estadoObjetivo = ACTIVO;
                }

            }
        }
        Informacion2(vel, puntaje, aciertos, mayorPuntaje, descuento, contadorDisparos, contadorObj, cantidad);
        if ((contadorObj == 3 || contadorDisparos == 4) && estado == INACTIVO)
            break;


        _sleep(75);
    }
    _sleep(1000);
    puntaje = puntaje - descuento;
    setBGcolor(1);
    Console::Clear();
    VentanaPuntaje(puntaje);
    AgregarPuntaje(participante, indice, puntaje);
}
void Fase3(string*& Paises, int*& N, Jugadores*& participante, int* Nj, int fase)
{
    short escopeta = 0;
    int num;
    int Mayorpuntaje = 0;
    float vel;
    int contador = 0;
    Velocidad_Fase(vel, fase);
    int pos = 0;

    while (contador < 3)
    {
        ListaPaises(N, Paises, participante, pos);
        num = AsignarNumJugador(participante, pos);
        PantallaEscopeta(escopeta);
        Escenario_Deportivo();
        Entrada_Jueces();
        Entrada_Jugador(num);
        VistaLateralJugador(num, escopeta);
        Cartel_1();
        Mayorpuntaje = Mayor(participante, pos);
        Contador();
        VistaJugador3(escopeta, vel, Mayorpuntaje, participante, pos);
        contador++;
        pos++;
    }

}

void VentanaResultados(Jugadores*& participante, int* Nj, int Num)
{
    Fondo_1();
    GeneraCuadroMenu(40, 12, 60, 15, 4);
    GeneraCuadroMenu(50, 11, 42, 3, 16);
    setColor(1);
    setXY(61, 12); cout << "ESTADISTICA DEL JUEGO";

    int x = 50;
    int y = 16;
    int y2 = 16;
    int y3 = 16;

    for (int i = 0; i < Num; i++)
    {
        if (Num > 5)
        {
            if (i < 5)
            {
                setXY(x, y); setBGcolor(10); setColor(15);
                cout << " " << i + 1 << " ";
                setBGcolor(4);
                setXY(x + 5, y); cout << participante[i].Pais << ": " << participante[i].puntaje;
                y = y + 2;
            }
            else
            {
                setXY(x + 25, y2); setBGcolor(10); setColor(15);
                cout << " " << i + 1 << " ";
                setBGcolor(4);
                setXY(x + 25 + 5, y2); cout << participante[i].Pais << ": " << participante[i].puntaje;
                y2 = y2 + 2;
            }
        }
        else
        {
            setXY(x, y3); setBGcolor(10); setColor(15);
            cout << " " << i + 1 << " ";
            setBGcolor(4);
            setXY(x + 5, y3); cout << participante[i].Pais << ": " << participante[i].puntaje;
            y3 = y3 + 2;
        }
    }
    setXY(ANCHO / 2 - 21, ALTO - 7); setBGcolor(3); setColor(13);
    cout << "[Presione cualquier para pasar a la Premiacion]"; _getch();
    setBGcolor(3); Console::Clear();
}
void ActualizacionNj(string*& Paises, int*& N, Jugadores*& participante, int*& Nj)
{
    if (participante != NULL) delete[]participante;

    *Nj = *N;
    participante = new Jugadores[*Nj];

    for (int i = 0; i < *N; i++)
    {
        participante[i].Pais = Paises[i];
    }

}
void IniciarJuego(string*& Paises, int*& N, Jugadores*& participante, int*& Nj)
{

    //Inaguracion();

    //FASE1 
    /*
    Fase1(Paises, N, participante, Nj);

    //Ordenando Descendentemente
    Paises = OrdenaDescendente(participante, Nj, 5, N);
    VentanaEstadistica(participante, Nj, 2);

    ActualizacionNj(Paises, N, participante, Nj);
    */
    //FASE 2
    Fase2(Paises, N, participante, Nj, 2);

    Paises = OrdenaDescendente(participante, Nj, 3, N);
    VentanaEstadistica(participante, Nj, 3);
    ActualizacionNj(Paises, N, participante, Nj);

    //FASE 3
    Fase3(Paises, N, participante, Nj, 3);

    Paises = OrdenaDescendente(participante, Nj, 3, N);
    VentanaResultados(participante, Nj, 3);

}
