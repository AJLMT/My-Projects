#include <iostream>

using namespace std;

int Fibonacci(int);

int main(void){
    int salida, fib;

    cout << "Indica cuantas iteraciones de Fibonnacci quieres: " << endl;
    cin >> fib;

    salida = Fibonacci(fib);

    cout << "El numero de fibonacci con " << fib << " iteraciones es: " << salida << endl;

    return 0;
}

int Fibonacci(int iter){
    int salida = 0;

    if(iter == 0){
        return iter;
    }
    if(iter == 1){
        return iter;
    }
    else{
        salida = Fibonacci(iter - 1) + Fibonacci(iter - 2);
    }

    return salida;
}