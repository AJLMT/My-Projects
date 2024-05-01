#include <iostream>

using namespace std;

int Media(int *);

int main(void){
    int media[10];

    for(int i = 0; i < 10; i++){
        cout << "Indica el numero " << i + 1 << ": ";
        cin >> media[i];
    }
    

    cout << "La media de los numeros que has pasado es de: " << Media(media);

    return 0;
}

int Media(int *media){
    int m = 0, x = 0;

    for(int i = 0; i < 10; i++){
        x += *media;
        media++; 
    }
    
    m = x / 10;

    return m;
}