#include <iostream>

using namespace std;

//Función que devuelve la primera posición de un carácter dentro de una cadena
int Pos(char *, char);

//Función que devuelve todas las posiciones de un carácter dentro de una cadena
int *Pos2(char *, char, int *, int &);

int main(void){
    char cadena[80];
    char car;
    int *pos, *posiciones, salida, tam = 1;

    cout << "Indica la cadena: ";
    cin.getline(cadena, 80);

    cout << "Indica el caracter a buscar: ";
    cin >> car;

    salida = Pos(cadena, car);
    
    if(salida == -1){
        cout << "El caracter '" << car << "' en la cadena '" << cadena << "' no ocupa ninguna posicion." <<endl;
    }
    else{
        cout << "El caracter '" << car << "' en la cadena '" << cadena << "' ocupa la posicion: " << salida << "." <<endl;
    }

    cout << "Por otra parte, dicho caracter '" << car << "' en la cadena '" << cadena << "' tambien sale en las posiciones: ";
    pos = Pos2(cadena, car, posiciones, tam);

    for(int i = 0; i < tam-1; i++){
        cout << pos[i] << ", ";
    }

    return 0;
}

int Pos(char *cadena, char caracter){
    int posicion = 1, entrada = -1;
    bool bandera = true;

    while(*cadena){
        if(*cadena == caracter){
            bandera = false;
            entrada++;
        }
        if(bandera == true){
            posicion++;
        }
        cadena++;
    }
    if(entrada == -1)
        posicion = -1;

    return posicion;
}

int *Pos2(char *cadena, char caracter, int *posiciones, int & tam){
    int *salida = posiciones, i= 0, posicion = 0;
    bool bandera = true;

    while(*cadena){
        if(*cadena == caracter){
            *posiciones = posicion;
            posiciones++;
            tam++;
            posicion++;
        }
        else{
            posicion++;
        }
        cadena++;
    }

    return salida;
}