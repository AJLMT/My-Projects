#include <iostream>

using namespace std;

bool amigos(int, int);

int main(void){
    int n1, n2;
    bool salida;

    cout << "Dame el primero numero: " <<endl;
    cin >> n1;
    cout << "Dame el segundo numero: " <<endl;
    cin >> n2;
    
    if(n1 == 0 || n2 == 0){
        cout << "No se puede hacer";
    }
    else{
        salida = amigos(n1, n2);

        if(salida == true){
            cout << "Los numeros " << n1 << " y " << n2 << " si son amigos";
        }
        else{
            cout << "Los numeros " << n1 << " y " << n2 << " no son amigos";
        }
    }
    return 0;
}

bool amigos(int n1, int n2){
    int suma1 = 0, suma2 = 0;

    for(int i=1; i < n1; i++){
        if(n1 % i == 0){
            suma1 += i;
        }
    }
    if(suma1 == n2){
        for(int i=1; i< n2; i++){
            if(n2 % i == 0){
                suma2 += i;
            }
        }
    }

    if(suma2 == n1){
        return true;
    }
    else{
        return false;
    }
    
}