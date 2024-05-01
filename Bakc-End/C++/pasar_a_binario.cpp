#include <iostream>
#include <cmath>

using namespace std;

string pasar_a_binario(int);

int main (void){
    string salida;
    int num;

    cout << "Dame el numero en binario" << endl;
    cin >> num;

    salida = pasar_a_binario(num);

    cout << "El numero " << num << " en binario es " << salida << endl;

    return 0;
}

string pasar_a_binario(int num){
    int i = 0;
    string salida = "";

    if(num < 2){
        if(num == 0){
            salida += "0";
        }
        else{
            salida += "1";
        }
    }
    
    while(pow(2, i) < num){
        i++;
    }
    
    for(int j = i; j > 0; j--){
        if(pow(2, j) < num){
            salida += "1";
        }
        else{
            salida += "0";
        }
    }

    return salida;
}