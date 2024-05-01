#include <iostream>

using namespace std;

int main (void){
    int num;

    cout << "Num: " << endl;
    cin >> num;

    if(num % 2 == 0){
        cout << "El numero es par";
    }
    else{
        cout << "El numero es impar";
    }

    return 0;
}