#include <iostream>
#include <vector>

using namespace std;
/*
    En una ciudad colombiana se organiza un carnaval donde existen las siguientes categorías: 1. Carrozas, 2. Colectivos coreográficos y 3. Disfraces individuales.

    En cada categoría se otorga un premio de $80.000.000, $40.000.000 y 15.000.000 para las categorías 1, 2 y 3 respectivamente.

    Se requiere una aplicación para registrar a N participantes, con el siguiente menú:

    Registrar participantes (identificación, nombre, categoría)

    Registrar categorías (nombre categoría, valor premio)

    Imprimir lista de participantes

    Imprimir Lista de categorías

    Salir
*/

struct Categorias{
    string nombre_categoria;
    int valor_premio;
};

struct Participantes{
    int identificador;
    string nombre;
    string categoria;
};

vector<Categorias> RegistrarCategoriasExistentes(vector<Categorias>);
vector<Participantes> RegistrarParticipantesExistentes(vector<Participantes>);
vector<Participantes> RegistrarParticipante(vector<Participantes>, int);
vector<Categorias> RegistrarNuevaCategoria(vector<Categorias>);
void ImprimirParticipante(vector<Participantes>);
void ImprimirCategoria(vector<Categorias>);

int main(void){
    bool bandera = true;
    int decision, num_participantes = 0;
    vector<Categorias> categoria;
    vector<Participantes> participante;

    participante = RegistrarParticipantesExistentes(participante);
    categoria = RegistrarCategoriasExistentes(categoria);

    while(bandera){
        cout << "Bienvenido a nuestra aplicacion:" <<endl;
        cout << "Pulse 1 para registrar un nuevo participante" <<endl;
        cout << "Pulse 2 para registrar una nueva categoria" <<endl;
        cout << "Pulse 3 para imprimir lista de participantes" <<endl;
        cout << "Pulse 4 para imprimir lista de categorias" <<endl;
        cout << "Pulse 5 para salir" <<endl;
        cin >> decision;

        switch (decision){
            case 1:
                participante = RegistrarParticipante(participante, num_participantes);
                num_participantes++;
                break;

            case 2:
                categoria = RegistrarNuevaCategoria(categoria);
                break;

            case 3:
                ImprimirParticipante(participante);
                break;

            case 4:
                ImprimirCategoria(categoria);
                break;

            case 5:
                bandera = false;
                break;
            default:
                cout << "Esa opcion no corresponde a ninguna decision, vuelva a intentarlo." <<endl;
        }
    }

    return 0;
}

vector<Categorias> RegistrarCategoriasExistentes(vector<Categorias> categorias){
    Categorias categoria;
    
    categoria.nombre_categoria = "Carrozas";
    categoria.valor_premio = 80000000;
    categorias.push_back(categoria);

    categoria.nombre_categoria = "Colectivos coreograficos";
    categoria.valor_premio = 40000000;
    categorias.push_back(categoria);

    categoria.nombre_categoria = "Disfraces individuales";
    categoria.valor_premio = 15000000;
    categorias.push_back(categoria);

    return categorias;
}

vector<Participantes> RegistrarParticipantesExistentes(vector<Participantes> participante){
    Participantes participantes;

    participantes.identificador = 0;
    participantes.nombre = "-";
    participantes.categoria = "-";
    participante.push_back(participantes);

    return participante;
}


vector<Participantes> RegistrarParticipante(vector<Participantes> participantes, int tam){
    int categoria;
    bool bandera = true;
    Participantes participante;

    if(tam == 0){
        participantes.pop_back();
    }

    participante.identificador = tam;
    
    cout << "Indica el nombre del nuevo participante: ";
    cin >> participante.nombre;

    while(bandera){
        cout << "Indica la categoria." <<endl;
        cout << "1. para Carrozas." <<endl;
        cout << "2. para Colectivos coreograficos." <<endl;
        cout << "3. para Disfraces individuales." <<endl;
        cin >> categoria;
        
        switch(categoria){
            case 1:
                participante.categoria = "Carrozas";
                bandera = false;
                break;

            case 2:
                participante.categoria = "Colectivos coreograficos";
                bandera = false;
                break;

            case 3:
                participante.categoria = "Disfraces individuales";
                bandera = false;
                break;

            default:
                cout << "Ese no es un valor adecuado, repita." <<endl;
        }
    }

    participantes.push_back(participante);

    cout << "\n\n\n\n\n\n\n";

    return participantes;
}

vector<Categorias> RegistrarNuevaCategoria(vector<Categorias> categorias){
    Categorias categoria;

    cout << "Indica el nombre de la nueva categoria: ";
    cin >> categoria.nombre_categoria;

    cout << "Indica el valor del premio de la nueva categoria: ";
    cin >> categoria.valor_premio;

    categorias.push_back(categoria);

    cout << "\n\n\n\n\n\n\n";

    return categorias;
}

void ImprimirParticipante(vector<Participantes> participantes){
    cout << "\n\n\n\n\n\n\n";
    cout << "PARTICIPANTES:"<<endl;
    for(int i = 0; i < participantes.size(); i++){
        cout << "*****************************************************************************" <<endl;
        cout << "Participante " << participantes[i].identificador <<endl;
        cout << "Nombre: " << participantes[i].nombre << endl;
        cout << "Categoria en la que participa: " << participantes[i].categoria <<endl;
        cout << "*****************************************************************************" <<endl;
        cout << "\n";
    }
    cout << "\n\n\n\n\n\n\n";
    
    return;
}

void ImprimirCategoria(vector<Categorias> categorias){
    cout << "\n\n\n\n\n\n\n";
    cout << "CATEGORIAS:"<<endl;
    for(int i = 0; i < categorias.size(); i++){
        cout << "*****************************************************************************" <<endl;
        cout << "Nombre categoria : " << categorias[i].nombre_categoria <<endl;
        cout << "Valor economico de la categoria: " << categorias[i].valor_premio << "$." <<endl;
        cout << "*****************************************************************************" <<endl;
        cout << "\n";
    }
    cout << "\n\n\n\n\n\n\n";
}