/****** TresenRaya **********************************************************/ /**
 *
 * @file TresenRaya
 *
 * @brief Prácticas de Programación.
 *
 * Programa final para gestionar los pacientes de una unidad médica y las pruebas 
 * realizadas a los mismos.
 *
 * @version 0.9
 * @author Miguel Angel Gamón
 *
 * @date 11/07/2021
 *
 * @version 1.0
 * @author Antonio José López Martínez
 * @author id_grupo                                                   
 *                                                                         
 */ /***************************************************************************/

#include <iostream>
#include <string>

#include "Tablero.h"

using namespace std;

void MostrarMenu (string);

/*
 * Programa principal
 */
int main ()
{
    Tablero tablero;
    string nom;
    int fil, col, dificultad;
    int ganador = 0;
    
    cout << "BIENVENIDO JUGADOR" << endl;
    
    cout << "Porfavor indique su nombre a continuacion: ";
    cin >> nom;
    
    cout << "Creando tablero ... " << endl;
    tablero.CrearTablero();
    
    
    cout << "Tablero creado correctamente." <<endl;
    cout << endl;
    
    cout << "Mostrando tablero: " <<endl;
    tablero.MostrarTablero();
    cout << endl;
    
    cout << "Muy bien jugador " << nom << ", empezemos la partida de tu vida.";
    cout << endl;
    cout << endl;
    
    do{
        cout << "Primero que todo elige la dificultad de la IA (1 facil, 2 hardcore): ";
        cin >> dificultad;
        cout << endl;
    }while((dificultad != 1) && (dificultad != 2));

    cout << "Una vez elegida la dificultad vamos a empezar el juego." << endl;
    cout << endl;
    
    do{
        if (dificultad == 1)
        {
            fil = tablero.JugadaJugador(col);
            tablero.RellenarTablero(fil, col, 1);
            tablero.MostrarTablero();
            
            ganador = tablero.TresenRaya();
            if (ganador == 0)
            {
                cout <<endl;
                cout << "Ahora movera la maquina." <<endl;
                cout << endl;
                
                fil = tablero.IAFacil(col);
                tablero.RellenarTablero(fil, col, 2);
                tablero.MostrarTablero();

                ganador = tablero.TresenRaya();
                if (ganador == 0)
                {
                    cout << endl;
                    cout << "Tu turno jugador." << endl;
                    cout << endl;
                }
            }
        }
        else
        {
            fil = tablero.JugadaJugador(col);
            tablero.RellenarTablero(fil, col, 1);
            tablero.MostrarTablero();
            
            ganador = tablero.TresenRaya();
            if (ganador == 0)
            {
                cout <<endl;
                cout << "Ahora movera la maquina." <<endl;
                cout << endl;
                
                fil = tablero.IADificil(col);
                cout << endl;
                cout << "-------------------"<<endl;
                cout << " POSICION IA:"<<endl;
                cout << fil << "-" <<col;
                cout << endl;
                tablero.RellenarTablero(fil, col, 2);
                tablero.MostrarTablero();
                
                ganador = tablero.TresenRaya();
                if (ganador == 0)
                {
                    cout << endl;
                    cout << "Tu turno jugador." << endl;
                    cout << endl;
                }
            }
        }
    }while (ganador == 0);
    
    if (dificultad == 1)
    {
        if(ganador == 1)
        {
            cout << "Felicidades por ganarle a la maquina " << nom;
            cout << " en modalidad facil (no es tan dificil pero bueno), nos volveremos a ver." << endl;
        }
        else
            if(ganador == 2)
            {
                cout << "Una pena que no le hayas ganado a la computadora ";
                cout << nom << "en modalidad facil (eres muy malo), otra vez sera." << endl;        
            }
            else
            {
                cout << "Curioso, has empatado con la maquina en dificultad",
                cout << " facil, eres un manta."<<endl;
                cout << "Bueno " << nom << ", otra vez sera." << endl;
            }
    }
    
    if (dificultad == 2)
    {
        if(ganador == 1)
        {
            cout << "Felicidades por ganarle a la maquina " << nom;
            cout << " en modalidad hardcore, nos volveremos a ver." << endl;
        }
        else
            if(ganador == 2)
            {
                cout << "Una pena que no le hayas ganado a la computadora ";
                cout << nom << "en modalidad hardcore, otra vez sera." << endl;        
            }
            else
            {
                cout << "Curioso, has empatado con la maquina en dificultad",
                cout << " hardcore, no esta nada pero que nada mal."<<endl;
                cout << "Bueno" << nom << ", otra vez sera." << endl;
            }
    }
    cout << "CERRANDO JUEGO";
    
    
    return 0;
}
