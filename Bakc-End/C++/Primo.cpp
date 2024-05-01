#include <iostream>

using namespace std;

bool Primo(int);

int main(void){
    int primo;
    bool salida;

    cout << "Indica el numero del que quieres saber si es primo o no: " <<endl;
    cin >> primo;

    salida = Primo(primo);

    if(salida == true){
        cout << "El numero " << primo << " si que es primo" << endl;
    }
    else{
        cout << "El numero " << primo << " no es primo" << endl;
    }

    return 0;
}

bool Primo(int num){
    if(num <= 3){
        return true;
    }
    for(int i = 2; i < num; i++){
        if(num % i == 0){
            return false;
        }
    }

    return true;
}