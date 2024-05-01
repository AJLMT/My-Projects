#include <iostream>
#include <cmath>

using namespace std;

int pasar_a_decimal(int);

int main(void){
    int binario, salida;

    cout << "Dime un numero en binario: " << endl;
    cin >> binario;

    salida = pasar_a_decimal(binario);

    cout << "El numero en binario " << binario << " en decimal es " << salida <<endl;

    return 0;
}

int pasar_a_decimal(int binario){
    int decimal = 0, x=10, y = binario, i=0, z;

    while(y > 0){
        z = y % 10;
        decimal += pow(2, i) * z;
        y /= 10;
        i++;
    }

    decimal += pow(2, i) * z;

    return decimal;
}