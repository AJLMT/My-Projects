#include <iostream>

//Vamos a concatenar dos cadenas


using namespace std;

char* Concatenacion(char *, char *);

int main(void){
    char c[100];
    char c2[15];

    cout << "Indica la primera cadena: ";
    cin.getline(c, 80); //getline(cin, c) permite que entre un número arbitrario de carácteres, es decir, sin un tamaño fijo, pero solo para strings.

    cout << "Indica la segunda cadena: ";
    cin.getline(c2, 80);

    cout << "La concatenacion quedaria tal que: " << Concatenacion(c, c2);

    return 0;
}

//Al crear inicio estamos devolviendo un puntero que señala al principio de c, si no estuviera devolveríamos un puntero que señalaría al final de c.
char *Concatenacion(char *c, char *c2){
    char *inicio = c;

    while(*c){
        c++;
    }
    while(*c2){
        *c = *c2;
        c2++;
        c++;
    }
    *c = '\0';
    
    return inicio;
}