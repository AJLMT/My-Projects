/******* Tablero.h **************************************************/ /**
 *
 * @file Tablero.h
 *
 * Fichero de cabecera de la clase Cita
 *
 * @version 1.0
 * @author Antonio José López Martínez
 * @date 11/07/2021
 *  
 ***************************************************************************/
#ifndef _TABLERO_H_
#define _TABLERO_H_

#include <iostream>

using namespace std;


class Tablero
{
public:
	
	void CrearTablero();
	void MostrarTablero();
	void RellenarTablero(int, int, int);
	bool CasillaOcupada(int, int);
	int TresenRaya();
	int JugadaJugador(int & col);
	int IAFacil(int & col);
	int IADificil(int & col);

private:
    
	typedef int Matriz [6][6];
    Matriz tablero;
    
    
    
};

#endif
