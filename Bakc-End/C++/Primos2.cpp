#include <iostream>

using namespace std;

void Primo(int);

int main(void){
    int primo;
    bool salida;

    cout << "Indica un numero y te dire cuantos primos hay desde el 2 hasta el: " <<endl;
    cin >> primo;

    cout << "Los numeros primos desde el 2 al " << primo << " son: " <<endl;
    Primo(primo);

    return 0;
}

void Primo(int num){
    for(int j = 2; j < num; j++){
        bool salida = true;
        for(int i = 2; i < j; i++){
            if(j % i == 0){
                salida = false;
            }
        }
        if(salida == true){
            cout << j << " ";
        }
    }

    return;
}