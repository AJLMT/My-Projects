#include <iostream>
#include <vector>
/*
    Consideramos un mazo de n cartas, siendo n un numero triangular; esto es, n = 1+2+3+....+k. Se reparte la totalidad de las cartas 
    en un numero arbitrario m de montones. 

    El lote de montones se organiza así: se toma una carta de cada monton y con todas ellas se forma uno nuevo. Por ejemplo:+
    El monton [1 1 8 5] quedaria tal que [7 4 4]

    El desarrollo del juego consiste en llevar a cabo la reorganización descrita cuantas veces sea necesario hasta que haya un montón 
    de 1 carta, seguido de un monton de 2 cartas.... hasta k cartas. Por ejemplo, partiendo de la situacion [5 7 3]:
            [5 7 3]
            [4 6 2 3]
            [3 5 1 2 4]
            [2 4 1 3 5]
            [1 3 2 4 5]
            [2 1 3 4 5]
            [1 2 3 4 5]

    Una vez llega a la condicion final el juego termina sea cual fuera la distribucion inicial.
    Este ejercicio propone crear un programa que simule el juego anterior.

*/
using namespace std;

void Mostrar(vector<int>);

int main(void){
    vector<int> mazo;
    bool bandera = true;
    int salida, monton;

    while(bandera){
        cout << "Para anyadir un monton pulsa 1."<<endl;
        cout << "Para ver las reorganizaciones de los montones pulsa 2."<<endl;
        cin >> salida;

        switch(salida){
            case 1:
                cout << "Indica el numero de cartas del monton:";
                cin >> monton;
                mazo.push_back(monton);
                break;

            case 2:
                bandera = false;
                Mostrar(mazo);
                break;

            default:
                cout << "Eso no es una opcion valida, repite."<<endl;

        }
    }
    
    
    
    return 0;
}

void Mostrar(vector<int> mazo){
    bool bandera = true;

    if(mazo.size() > 0){
        cout <<"[";
        for(int i = 0; i < mazo.size() -1; i++){
            cout << mazo[i] << " ";
        }
        cout << mazo[mazo.size()-1] << "]"<<endl;

        while(bandera){
            int tam = mazo.size();
            for(int i = 0; i < mazo.size(); i++){
                while(mazo[i] <= 1)
                    mazo.erase(mazo.begin() + i);
                
                mazo[i]--;
            }
            mazo.push_back(tam);


            bandera = false;
            int i = 0;
            while(bandera == false && i < mazo.size()){
                if(mazo[i] != i + 1)
                    bandera = true;
                i++;
            }

            cout << "[ ";
            for(int i = 0; i < mazo.size() - 1; i++){
                cout << mazo[i] << " ";
            }
            cout << mazo[mazo.size()-1] << "]"<<endl;
        }
    }
    else{
        cout << "[]";
    }

    return;
}