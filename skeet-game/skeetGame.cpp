
#include<iostream>
#include<conio.h>


#include "Menu.h"
#include "Inauguracion.h"
#include "EscenarioJuego.h"
#include "Jugadores.h"
#include "InterfazJuego.h"
#include "EscenarioPremiacion.h"


using namespace std;
using namespace System;

#define ANCHO 140
#define ALTO 40
void GenerarPaisesPrueba(string*& Paises, int* N)
{
    string* Paises_en_competencia = new string[*N];
    Paises_en_competencia[0] = "Argentina";
    Paises_en_competencia[1] = "Peru";
    Paises_en_competencia[2] = "Colombia";
    Paises_en_competencia[3] = "Chile";
    Paises_en_competencia[4] = "Brasil";
    /*
    Paises_en_competencia[5] = "Mexico";
    Paises_en_competencia[6] = "Nicaragua";
    Paises_en_competencia[7] = "Bolivia";
    Paises_en_competencia[8] = "Francia";
    Paises_en_competencia[9] = "Venezuela";
    */

    for (int i = 0; i < *N; i++)
    {
        Paises[i] = Paises_en_competencia[i];

    }
}

int main()
{
    srand(time(NULL));
    Console::CursorVisible = false;
    Console::SetWindowSize(ANCHO, ALTO);

    //Arreglo de Paises Particpantes

    int* N = new int;
    *N = 5; //10
    string* Paises = new string[*N];

    GenerarPaisesPrueba(Paises, N);

    //Arreglo de Jugadores que van participando
    int* Nj = new int;
    *Nj = 5; //10
    Jugadores* participante = NULL;

    participante = new Jugadores[*Nj];

    Presentacion();
    IniciarJuego(Paises, N, participante, Nj);
    Premiacion(Paises, participante);



    _getch();
    return 0;
}