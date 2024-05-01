#include <iostream>

using namespace std;

int CuentaVocales(char *);

int main(void){

    char cadena[80];

    cout << "Indica la cadena: ";
    cin.getline(cadena, 80);

    cout << "El numero de vocales en la cadena pasada es un total de: " << CuentaVocales(cadena) << " vocales.";

    return 0;
}

int CuentaVocales(char *c){
    int total = 0;

    while(*c){
        switch(toupper(*c)){
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                total ++;
                break;
        }
        c++;
    }

    return total;
}