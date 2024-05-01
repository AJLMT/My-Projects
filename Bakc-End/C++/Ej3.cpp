#include <iostream>
#include <vector>

/*
Consideramos un historiograma entero no decreciente representado mediante una lista en que se refieren las alturas de sus columnas:
                            *
                            *
                            *
                        *   *
                *   *   *   *
                *   *   *   *
                *   *   *   *
            *   *   *   *   *
            *   *   *   *   *
        *   *   *   *   *   *
*   *   *   *   *   *   *   *
------------------------------
1   1   2   4   7   7   8   11

Si hacemos que las columnas pasen a ser filas y viceversa, se obtienen el historiograma y la lista representativa siguientes:
                                        *
                                        *
                                    *   *
                            *   *   *   *
                *   *   *   *   *   *   *
                *   *   *   *   *   *   *
            *   *   *   *   *   *   *   *
*   *   *   *   *   *   *   *   *   *   *
-----------------------------------------
1   1   1   2   4   4   4   5   5   6   8

Se propone desarrollar un procedimiento que construya la listatranspuesta a partir de la primera; esto es:
                    [1 1 2 4 7 7 8 11]   ~  [1 1 1 2 4 4 4 5 5 6 8]
*/

using namespace std;

vector<int> Inicializar(void);

int main(void){
    vector<int> historiograma;
    vector<int> lista_representativa ;
    int x, y = 0;

    historiograma = Inicializar();
    lista_representativa.resize(historiograma[historiograma.size() -1]);
    lista_representativa[0] = 1;

    for(int i = historiograma.size()-1; i > 0; i--){
        x = historiograma[i];
        x -= 1;
        while(x >= 0){
            lista_representativa[x] += 1;
            x--;
        }
    }

    cout << "Lista representativa: [";
    for(int i = lista_representativa.size() -1; i > 0; i--){
        cout << lista_representativa[i] << ", ";
    }
    cout << lista_representativa[0] << "].";

    return 0;
}

vector<int> Inicializar(void){
    vector<int> historiograma;

    historiograma.push_back(1);
    historiograma.push_back(1);
    historiograma.push_back(2);
    historiograma.push_back(4);
    historiograma.push_back(7);
    historiograma.push_back(7);
    historiograma.push_back(8);
    historiograma.push_back(11);

    cout << "Lista historiograma: [";
    for(int i = 0; i < historiograma.size() - 1; i++){
        cout << historiograma[i] << ", ";
    }
    cout << historiograma[historiograma.size() - 1] << "]."<<endl;

    return historiograma;
}