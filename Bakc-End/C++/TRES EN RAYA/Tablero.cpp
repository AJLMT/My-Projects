/******* Tablero.cpp *************************************************/ /**
 *
 * @file Tablero.cpp
 *
 * Implementación de los métodos de la clase Cita
 *
 * @version 1.0
 * @author Antonio José López Martínez
 * @date 11/07/2021
 *  
 ***************************************************************************/

#include <iomanip>
#include <iostream>

#include "Tablero.h"

using namespace std;

void Tablero::CrearTablero()
{
    int i, j;
    
    tablero [0][0] = 8;
    tablero [0][1] = 5;
    tablero [0][2] = 5;
    tablero [0][3] = 5;
    tablero [0][4] = 5;
    tablero [0][5] = 5;
    
    tablero [1][0] = 6;
    tablero [2][0] = 6;
    tablero [3][0] = 6;
    tablero [4][0] = 6;
    tablero [5][0] = 6;
    
    for (j = 1; j < 6; j++)
    {
        tablero [2][j] = 4;
        tablero [4][j] = 4;
    }
    
    for (i = 1; i <6; i++)
    {
        for (j = 1; j < 6; j++)
        {
            if (i % 2 != 0)
            {
                tablero [i][1] = 0;
                tablero [i][3] = 0;
                tablero [i][5] = 0;
            }
            if (i % 2 != 0)
            {
                tablero [i][2] = 1;
                tablero [i][4] = 1;
            }
        }
    }
    return;
}


void Tablero::MostrarTablero()
{
    int i, j;
    int ver, hor;
    ver = hor = 1;
    
    for (i = 0; i < 6; i++)
    {
        for (j = 0; j < 6; j++)
        {
            if ((i == 0) && (j == 0))
            {
                cout << 0;
            }
            if (tablero [i][j] == 0)
            {
                cout << " ";
            }
            
            if (tablero [i][j] == 1)
            {
                cout << "|";
            }
            
            if (tablero [i][j] == 2)
            {
                cout << "X";
            }
            
            if (tablero [i][j] == 3)
            {
                cout << "O";
            }
            
            if (tablero [i][j] == 4)
            {
                cout << "-";
            }
            
            if (tablero [i][j] == 5)
            {
                cout << hor;
                hor ++;
            }
            
            if (tablero [i][j] == 6)
            {
                cout << ver;
                ver ++;
            }
        }
        cout << endl;
    }
    
    return;
}


// SI LA POSICIÓN ESTÁ OCUPADA O POR LA MAQUINA O POR EL JUGADOR SALE FALSE
void Tablero::RellenarTablero(int fil, int col, int jug)
{

    if(jug == 1)
    {
        tablero[fil][col] = 2;
    }
    else
        tablero[fil][col] = 3;
    
    return;
}


// SI LA POSICIÓN ESTÁ OCUPADA O POR LA MAQUINA O POR EL JUGADOR SALE FALSE
bool Tablero::CasillaOcupada(int fil, int col)
{
    bool ok = false;
    
    
    if (tablero [fil][col] == 0)
    {
        ok = true;
    }
    
    return ok;
}

// ganador = 0 -> nadie; ganador = 1 -> jugador; ganador = 2 -> maquina; ganador = 3 -> empate
int Tablero::TresenRaya()
{
    int ganador = 0;
    int i, j;
    int t = 0;
    
    for (i = 1; i < 6; i++)
    {
        for (j = 1; j < 6; j++)
        {
            if (ganador == 0)
            {
                if (( tablero [i][j] == 2) && (tablero [i][j+2] == 2) && 
                    (tablero [i][j+4] == 2))
                {
                    ganador = 1;
                }
                    
                if (( tablero [i][j] == 2) && (tablero [i+2][j] == 2) && 
                    (tablero [i+4][j] == 2))
                {
                    ganador = 1;
                }
                    
                if (( tablero [i][j] == 2) && (tablero [i+2][j-2] == 2) && 
                (tablero [i+4][j-4] == 2))
                {
                    ganador = 1;
                }
                
                if (( tablero [i][j] == 2) && (tablero [i+2][j+2] == 2) && 
                (tablero [i+4][j+4] == 2))
                {
                    ganador = 1;
                }
            }
            
            
            if(ganador == 0)
            {
                if (( tablero [i][j] == 3) && (tablero [i][j+2] == 3) && 
                    (tablero [i][j+4] == 2))
                {
                    ganador = 2;
                }
                    
                if (( tablero [i][j] == 3) && (tablero [i+2][j] == 3) && 
                    (tablero [i+4][j] == 3))
                {
                    ganador = 2;
                }
                    
                if (( tablero [i][j] == 3) && (tablero [i+2][j-2] == 3) && 
                (tablero [i+4][j-4] == 3))
                {
                    ganador = 2;
                }
                
                if (( tablero [i][j] == 3) && (tablero [i+2][j+2] == 3) && 
                (tablero [i+4][j+4] == 3))
                {
                    ganador = 2;
                }
            }
        }
    }
    
    if (ganador == 0)
    {
        for (i = 1; i < 6; i++)
        {
            for (j = 1; j < 6; j++)
            {
                if(tablero[i][j] == 0)
                {
                    t++;
                }
            }
        }
        
        if(t == 0)
        {
            ganador = 3;
        }
    }
        
    return ganador;
}

int Tablero::JugadaJugador(int & col)
{
    int fil;
    bool ok = true;
    
    do{
        if (ok == false)
        {
            cout << "Error, esa casilla esta ocupada ya." <<endl;
            cout << "Elige otra:" << endl;
        }
        
        cout << "Indica la fila en la que deseas colocar: ";
        cin >> fil;
        
        cout << "Indica la columna en la que deseas colocar: ";
        cin >> col;
        
        ok = CasillaOcupada(fil, col);
        
    }while(ok == false);
    
    
    return fil;
}

int Tablero::IAFacil(int & col)
{
    int fil;
    bool ok;
    
    do{
        fil =rand() % 6 + 0;
        col = rand() % 6 + 0;
        
        ok = CasillaOcupada(fil, col);
        
    }while(ok == false);
    
    
    return fil;
}


int Tablero::IADificil(int & col)
{
    int jug = 85;
    int fil;
    int i, j;
    bool mov = false;
    
    for (i = 1; i < 6; i++)
    {
        for (j = 1; j < 6; j++)
        {
            if (tablero[i][j] == 3)
            {
                mov = true;
            }
        }
    }
    
    for (i = 1; i < 6; i++)
    {
        for (j = 1; j < 6; j++)
        {
            if (mov == false)
            {
                fil = IAFacil(col);
            }
            else
            {
                cout << "g";
                if (( tablero [i][j] == 2) && (tablero [i][j+2] == 2) && 
                        (tablero [i][j+4] == 0))
                {
                    fil = i;
                    col = j+4;
                    jug = 84;
                    cout << "1";
                }
                
                if (( tablero [i][j] == 2) && (tablero [i+2][j] == 2) && 
                    (tablero [i+4][j] == 0))
                {
                    fil = i+4;
                    col = j;
                    jug = 84;
                    cout << "2";
                }
                    
                if (( tablero [i][j] == 2) && (tablero [i+2][j-2] == 2) && 
                    (tablero [i+4][j-4] == 0))
                {
                    fil = i+4;
                    col = j-4;
                    jug = 84;
                    cout << "3";
                }
                
                if (( tablero [i][j] == 2) && (tablero [i+2][j+2] == 2) && 
                    (tablero [i+4][j+4] == 0))
                {
                    fil = i+4;
                    col = j+4;
                    jug = 84;
                    cout << "3";
                }
                
                if(jug == 85)
                {
                    cout << "h";
                    if (( tablero [i][j] == 3) && (tablero [i][j+2] == 3) && 
                        (tablero [i][j+4] == 0))
                    {
                        fil = i;
                        col = j+4;
                        jug = 84;
                    }
                    
                    if (( tablero [i][j] == 3) && (tablero [i+2][j] == 3) && 
                        (tablero [i+4][j] == 0))
                    {
                        fil = i+4;
                        col = j;
                        jug = 84;
                    }
                        
                    if (( tablero [i][j] == 3) && (tablero [i+2][j-2] == 3) && 
                        (tablero [i+4][j-4] == 0))
                    {
                        fil = i+4;
                        col = j-4;
                        jug = 84;
                    }
                    if (( tablero [i][j] == 3) && (tablero [i+2][j+2] == 3) && 
                    (tablero [i+4][j+4] == 0))
                    {
                        fil = i+4;
                        col = j+4;
                        jug = 84;
                    }
                    
                    if(jug == 85)
                    {
                        cout << "u";
                        if (( tablero [i][j] == 3) && (tablero [i][j+2] == 0))
                        {
                            fil = i;
                            col = j+2;
                            jug = 84;
                        }
                        
                        if (( tablero [i][j] == 3) && (tablero [i+2][j] == 0)) 
                        {
                            fil = i+2;
                            col = j;
                            jug = 84;
                        }
                            
                        if (( tablero [i][j] == 3) && (tablero [i-2][j-2] == 0))
                        {
                            fil = i-2;
                            col = j-2;
                            jug = 84;
                        }
                        if (( tablero [i][j] == 3) && (tablero [i+2][j+2] == 0))
                        {
                            fil = i+2;
                            col = j+2;
                            jug = 84;
                        }
                    }
                }
            }
        }
    }
    
    return fil;
}





