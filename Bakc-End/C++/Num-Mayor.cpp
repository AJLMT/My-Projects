#include <iostream>

using namespace std;

//Devuelve el mayor de un vector
int Mayor(float *);

int main(void){
    float vect[10];

    for(int i = 0; i < 10; i++){
        cout << "Inserta un numero: ";
        cin >> vect[i];
        cout << endl;
    }


    cout << "El numero mayor del vector pasado es el: " << Mayor(vect);


    return 0;
}

int Mayor(float *element){
    float mayor = 0;

    while(*element){
        if(*element > mayor){
            mayor = *element;
        }
        element++;
    }

    return mayor;
}