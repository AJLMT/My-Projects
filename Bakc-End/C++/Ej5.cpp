#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

/*
    Hemos quedado este fin de semana en escalar un monte. Para ello tenemos que hacer los preparativos repartiendo las tareas entre cada
    uno de los que vamos a ir. Alicia piensa en crear una lista con los miembros de la pandilla. Cada elemento de esa lista apuntará a su
    vez a la lista de compras o tareas que tiene asignada dicha persona. Por lo tanto hablamos de dos elementos. Elemento montañero y elemento
    tarea o compra, que estarán relacionados. 

    Escribe subprogramas que permitan añadir montañeros y borrarlos de la lista. También habrá que crear subprogramas que añadan tareas y le liberen
    de las mismas a montañeros. Ten en cuenta que antes de borrar a un montañero hay que repartir sus tareas entre todos los montañeros restantes.

    Escribe un subprograma que muestre todas las tareas que tiene asignadas cada montañero.

    Este programa sería inservible en el caso de que no se guarden los datos y hubiera que volver a rellenarlo todo cada vez que se ejecutará,
    por lo tanto, deberás almacenar la informacion de la estructura de datos en un fichero de disco. De esta manera se podrá reutilizar la 
    información borrando y añadiendo lo que convenga. En el fichero habrá dos tipos de lineas, las que empiezen por * y las que no. Aquellas que
    empiecen por * indicarán el nombre del montañero, y las demás sus tareas o compras a realizar.

            * Alicia
            pan
            chorizo
            * Manolo
            arroz
            hornillo
            revisar tienda
            * Bego
            .....

    Escribe un subprograma que, siguiendo la convención descrita. vuelque a un fichero la información de la estructura de datos en la memoria. 
    Así mismo escribe otro que reconstruya la estructura de datos a partir de la información del fichero

    Para finalizar, escribe un programa que integre los subprogramas de los apartados anteriores
*/

struct Montañero{
    string Nombre;
    vector<string> tareas;
};

Montañero Añadir_Montañero(void);
vector<Montañero> Eliminar_Montañero(vector<Montañero>, string);
Montañero Eliminar_Tarea(Montañero, string);
void Mostrar_Tareas_Montañeros(vector<Montañero>);
void Mostrar_Tareas_Montañero(Montañero);
vector<Montañero> Leer_Fichero(void);
void Escribir_Fichero(vector<Montañero>);

int main(void){
    vector<Montañero> montañeros;
    bool bandera = true, bander = true, z = true, fallo = true;
    int salida, x;
    string nombre, tarea, name;
    ofstream escribir;
    ifstream leer;

    montañeros = Leer_Fichero();

    while(bandera){
        cout << "*****************************************************"<<endl;
        cout << "BIENVENIDOS A LA APLICACION DE MONATANYEROS" <<endl;
        cout << "Indique que desea realizar:"<<endl;
        cout << "Pulse 1 para Anyadir un nuevo montanyero" <<endl;
        cout << "Pulse 2 para Eliminar un montanyero existente" <<endl;
        cout << "Pulsa 3 para Anyadirle una tarea a un montanyero existente" <<endl;
        cout << "Pulsa 4 para Eliminar una tarea a uno de los montanyeros existentes" <<endl;
        cout << "Pulsa 5 para Ver todas las tareas de cada uno de los montanyeros" <<endl;
        cout << "Pulsa 6 para Guardar en el fichero todos los datos de los montanyeros, asi como sus tareas" <<endl;
        cout << "Pulsa 7 para Salir." <<endl;
        cout << "*****************************************************"<<endl;
        cin >> salida;
        switch(salida){
            case 1:
                montañeros.push_back(Añadir_Montañero());
                break;

            case 2:
                cout << "Indica el nombre del montanyero que desea eliminar: ";
                cin >> nombre;
                montañeros = Eliminar_Montañero(montañeros, nombre);
                break;

            case 3:
                cout << "Indica el nombre del montanyero: ";
                cin >> nombre;
                for(int i = 0; i < montañeros.size(); i++){
                    if(montañeros[i].Nombre == nombre){
                        string tarea;
                        int x;
                        bool bander = true;
                        z = false;

                        while(bander){
                            cout << "Pulsa 1 si quieres anyadirle una nueva tarea."<<endl;
                            cout << "Pulsa 2 si no quieres anyadirle tarea." <<endl;
                            cin >> x;

                            switch(x){
                                case 1:
                                    cout << "Indica la tarea: ";
                                    cin >> tarea;
                                    montañeros[i].tareas.push_back(tarea);
                                    break;

                                case 2:
                                    bander = false;
                                    break;

                                default:
                                    cout << "Esa no es una opcion correcta, vuelve a intentarlo:" <<endl;
                            }
                        }
                    }
                }
                if(z == false){
                    cout << "Ese montanyero no existe.";
                    z = true;
                }
                break;

            case 4:
                bander = true;
                while(bander){
                    cout << "Pulsa 1 si quieres eliminar una tarea."<<endl;
                    cout << "Pulsa 2 si no quieres eliminar ninguna tarea." <<endl;
                    cin >> x;

                    switch(x){
                        case 1:
                        cout << "Indica el nombre del montanyero: ";
                        cin >> name;
                        for(int i = 0; i < montañeros.size(); i++){
                            if(montañeros[i].Nombre == name){
                                Mostrar_Tareas_Montañero(montañeros[i]); //Para mostrar las tareas del montañero que quieres eliminarle
                                cout << "Indica la tarea a eliminar: ";
                                cin >> tarea;
                                montañeros[i] = Eliminar_Tarea(montañeros[i], tarea);
                                z = false;
                            }
                        }
                        if(z == false){
                                cout << "Ese montanyero no existe.";
                                z = true;
                        }
                        
                        case 2:
                            bander = false;
                            break;

                        default:
                            cout << "Esa no es una opción valida, vuelve a intentarlo.";
                    }
                }
                break;

            case 5:
                Mostrar_Tareas_Montañeros(montañeros);
                break;

            case 6:
                Escribir_Fichero(montañeros);
                break;

            case 7:
                Escribir_Fichero(montañeros);
                bandera = false;
                break;

            default:
                cout << "Esa no es una opcion correcta, vuelve a intentarlo:" <<endl;
                break;
        }
    }

    return 0;
}

Montañero Añadir_Montañero(void){
    Montañero montañero;
    string tarea;
    int x;
    bool bandera = true;

    cout << "Indica el nombre del nuevo montanyero: ";
    cin >> montañero.Nombre;

    while(bandera){
        cout << "Pulsa 1 si quieres anyadirle ya una nueva tarea."<<endl;
        cout << "Pulsa 2 si no quieres anyadirle tarea." <<endl;
        cin >> x;

        switch(x){
            case 1:
                cout << "Indica la tarea: ";
                cin >> tarea;
                montañero.tareas.push_back(tarea);
                break;

            case 2:
                bandera = false;
                break;

            default:
                cout << "Esa no es una opcion correcta, vuelve a intentarlo:" <<endl;
        }
    }

    cout << "Montanyero anyadido correctamente." <<endl;

    return montañero;
}

vector<Montañero> Eliminar_Montañero(vector<Montañero> montañero, string nombre){
    int x = 0;
    bool comprobar = true;

    for(int i = 0; i < montañero.size(); i++){
        if(montañero[i].Nombre == nombre){
            while(montañero[i].tareas.size() > 0){
                montañero[x].tareas.push_back(montañero[i].tareas[montañero[i].tareas.size() - 1]);
                montañero[i].tareas.pop_back();

                if(x == montañero.size() - 1){
                    x = 0;
                }
                else if(x == i){
                    x += 2;
                }
                else{
                    x++;
                }
            }

            comprobar = false;
            montañero.erase(montañero.begin() + i);
        }
    }

    if(comprobar == false){
        cout << "Montanyero eliminado correctamente" <<endl;
    }
    else{
        cout << "Ese montanyero no existe." <<endl;
    }

    return montañero;
}

Montañero Eliminar_Tarea(Montañero montañero, string tarea){
    for(int i = 0; i < montañero.tareas.size(); i++){
        if(montañero.tareas[i] == tarea){
            montañero.tareas.erase(montañero.tareas.begin() + i);
        }
    }

    cout << "Tarea eliminada correctamente" <<endl;

    return montañero;
}

void Mostrar_Tareas_Montañeros(vector<Montañero> montañero){
    cout << "\n***************************************************"<<endl;
    cout << "Las tareas de los montanyeros son:"<<endl;
    for(int i = 0; i < montañero.size(); i++){
        cout<<"Nombre: " << montañero[i].Nombre <<endl;
        cout << "Tareas: "<<endl;
        for(int j = 0; j < montañero[i].tareas.size(); j++){
            cout << j + 1 << ". " << montañero[i].tareas[j] <<endl;
        }
    }
    cout << "***************************************************\n\n\n\n";

    return;
}

void Mostrar_Tareas_Montañero(Montañero montañero){
    cout << "\n***************************************************"<<endl;
    cout << "Las tareas del montanero " << montañero.Nombre << " son:" <<endl;
    for(int i = 0; i < montañero.tareas.size(); i++){
        cout << i + 1 << ". " << montañero.tareas[i] <<endl;
    }
    cout << "***************************************************\n\n\n\n";

    return;
}

vector<Montañero> Leer_Fichero(void){
    ifstream leer;
    vector<Montañero> montañeros;
    string linea;
    int i = -1;
    char primero;

    leer.open("montanyeros.txt", ios::binary);

    //para leer también se puede usar leer >> linea; que eso en linea escribe lo que haya en el fichero
    while(getline(leer, linea)){
        primero = linea[0];
        if(primero == '*'){
            i++;
            Montañero nuevo;
            linea.erase(0, 2);
            nuevo.Nombre = linea;
            montañeros.push_back(nuevo);
        }
        else{
            montañeros[i].tareas.push_back(linea);
        }
    }

    leer.close();

    return montañeros;
}

void Escribir_Fichero(vector<Montañero> montañero){
    ofstream salida;

    salida.open("montanyeros.txt", ios::binary);
    
    for(int i = 0; i < montañero.size(); i++){
        //salida.write("* ", 2);
        salida << "* ";
        salida << montañero[i].Nombre;
        salida << "\n";
        for(int j =0; j < montañero[i].tareas.size(); j++){
            salida << montañero[i].tareas[j];
            salida << "\n";
        }
    }    
    
    salida.close();

    cout << "Escritura realizada correctamente." <<endl;

    return;
}