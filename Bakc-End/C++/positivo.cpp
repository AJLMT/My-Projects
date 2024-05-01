#include <iostream>

using namespace std;

int main(void){
    int num;

    cout << "Dame el nº y te digo si es positivo: " << endl;
    cin >> num;

    if(num > 0){
        cout << "Es positivo" <<endl;
    }
    else{
        cout << "No es positivo" <<endl;
    }

    return 0;
}