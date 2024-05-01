#include <iostream>

using namespace std;

int main(void){
    int num;

    cout << "Dame el nº y te digo si es negativo: " << endl;
    cin >> num;

    if(num < 0){
        cout << "Es negativo" <<endl;
    }
    else{
        cout << "No es negativo" <<endl;
    }

    return 0;
}