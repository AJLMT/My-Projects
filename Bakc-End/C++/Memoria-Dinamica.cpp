#include <iostream>
#include <iomanip>

using namespace std;

struct TClientes{
       string codigo;
       string nombre;
};

struct TProveedores{
       string codigo;
       string nombre;
};  

void reserva1(TClientes *&); 
void reserva2(TClientes **&);
void destruye1(TClientes *&);
void destruye2(TProveedores **&);

int main(){
    int x;
   
    // 1. Declara los siguientes punteros: un puntero a un double,
    // un puntero a un int y un puntero a las estructuras TClientes y 
    // TProveedores
   
    double *d; int *i; TClientes *tc; TProveedores *tp;
   
    // 2. Reserva memoria dinámica para los anteriores punteros.
   
    d = new double;
    i = new int;
    tc = new TClientes;
    tp = new TProveedores;
   
    // 3. Reserva memoria dinámica para un array de 100 TClientes.
   
    tc = new TClientes[100];
   
    // 4. Reserva  memoria   dinámica   para   un   array   de   100   TClientes
    // mediante   una función a la que se le pasa el puntero
    // declarado previamente.
   
    reserva1(tc);
   
    // 5. Reserva  memoria   dinámica   para   un   array   de   100   punteros
    // a  TClientes e inicializarlo con NULL.
   
    TClientes **tc1;
    tc1 = new TClientes *[100];
    for(x = 0; x < 100; x++)
        tc1[x] = NULL;
       
    // 6. Reserva  memoria   dinámica   para   un   array   de   100   punteros
    // a  TClientes e inicializarlo  con NULL  mediante una  función a  la
    // que  se  le pasa  el  puntero declarado previamente.
   
    reserva2(tc1);
   
    // 7. Reserva memoria dinámica para un array de 120 punteros
    // a TProveedores y además reservar memoria para
    // las 120 estructuras TProveedores.
   
    TProveedores **tp1;
    tp1 = new TProveedores *[120];
    for(x=0; x<120; x++)
        tp1[x] = new TProveedores;
       
    // 8. Destruye el array del ejercicio 4.
   
    delete [] tc;
   
    // 9. Destruye el array del ejercicio 4 mediante
    // una función a la que se le pasa dicho array
   
    reserva1(tc); //volvemos a reservar memoria para que se pueda liberar
    destruye1(tc);
   
    // 10. Destruye el array del ejercicio 7.
   
    for(x=0; x<120; x++)
        delete tp1[x];
    delete [] tp1;
   
    // 11. Destruye el array del ejercicio 7 mediante
    // una función a la que se le pasa dicho array
   
    //volvemos a reservar memoria para que se pueda liberar
    tp1 = new TProveedores *[120];   
    for(x=0; x<120; x++)
         tp1[x] = new TProveedores;
    destruye2(tp1);
   
    return 0;
}

void reserva1(TClientes *&p){
     p = new TClientes[100];
}

void reserva2(TClientes **&p){
     p = new TClientes *[100];
     for(int x = 0; x < 100; x++)
          p[x] = NULL;
}

void destruye1(TClientes *&p){
     delete [] p;
}

void destruye2(TProveedores **&p){
     for(int x=0; x<120; x++)
         delete p[x];
     delete [] p;
}