#include <iostream>

using namespace std;
//Ejercicio de prueba para hacer una repeticion hasta que el cliente decida parar.

int main (){
    bool bandera = true;
    int entrada;

    while(bandera){
        cout << "Indique una de las dos siguientes opciones:"<<endl;
        cout << "Clique 1 para continuar digitando las notas." <<endl;
        cout << "Clique 0 para salir del programa." <<endl;
        cin >> entrada;

        switch(entrada){
            case 1:
                setlocale(LC_CTYPE,"Spanish");
                int x;
                float n1, n2, n3, n4, prom;
                
                cout<<"Ingrese la primer nota:";
                cin >> n1;
                cout<<"Ingrese la segunda nota:";
                cin >> n2;
                cout<<"Ingrese la tercera nota:";
                cin >> n3;
                cout<<"Ingrese la cuarta nota:";
                cin >> n4;

                prom=(n1+n2+n3+n4)/4;
                
                cout<<"\nSu nota final es: " << prom <<endl;

                if(prom < 3){
                    x = 1;
                }
                else if(prom < 5 && prom > 3){
                    x = 2;
                }
                else{
                    x = 3;
                }

                switch(x){
                    case 1: 
                        cout<<endl<<"No aprobado."<<endl; 
                        break;
                    
                    case 2: 
                        cout<<endl<<"En este momento no tiene aprobada la materia de tecnologia, pero tiene la oportunidad de recuperarla."<<endl; 
                        break;
                    
                    case 3: 
                        cout<<endl<<"Aprobado."<<endl; 
                        break;
                    
                    default:
                        cout<<"Opcion NO VALIDA."<<endl;
                }

                cout<<endl<<"Codigo desarrollado por: Juan Guevara."<<endl<<endl;
                cout << "\n";
                break;    

            case 0:
                bandera = false;
                break;

            default:
                cout << "Esa opcion es incorrecta, vuelva a probar:" << endl;
                cout << "\n\n\n";
        }
    }
       return 0;
}