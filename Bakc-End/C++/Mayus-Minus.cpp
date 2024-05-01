#include <iostream>

using namespace std;

//Funcion que devuelve una cadena pasada a MAYUSCULAS
char *Mayusc(char *);

//Funcion que devuelve una cadena pasada a MINUSCULAS
char *Minusc(char *);

int main(void){
    char cadena[89];

    cout << "Indica la cadena que quieras pasar: ";
    cin.getline(cadena, 89);

    cout << "La cadena '" << cadena << "' en mayusculas es: '" << Mayusc(cadena) <<endl;
    cout << "La cadena '" << cadena << "' en minusculas es: '" << Minusc(cadena) <<endl;


    return 0;
}

char *Mayusc(char *cadena){
    char *salida = cadena;

    while(*cadena){
        *cadena = toupper(*cadena);
        cadena++;
    }

    return salida;
}


char *Minusc(char *cadena){
    char *salida = cadena;

    while(*cadena){
        *cadena = tolower(*cadena);
        cadena++;
    }

    return salida;
}