/*

Benjamin Ortiz Morales

Marco Antonio Riascos

Estructura de datos

*/

#include "cola-prioridad.h"
#include "lista.h"
#include <iostream>


int main(){
    Cola col;

    col.enqueue(7);
    col.enqueue(8);
    col.enqueue(2);
    col.enqueue(5);
    col.enqueue(10);
    col.enqueue(6);
    col.enqueue(1);
    col.enqueue(3);
    col.enqueue(4);

    int elem = col.front();

    cout << elem << " Elemento mayor" << endl;

    for(int i = 1; i < col.l.longLista(); i++){
        cout << col.l.infoLista(i) << " ";
    }
    cout << endl;

    cout << "Eliminamos el elemento mayor" << endl;

    col.deque();

    for(int i = 1; i < col.l.longLista(); i++){
        cout << col.l.infoLista(i) << " ";
    }
    cout << endl;


    cout << "Elemento mayor eliminado" << endl;

    cout << "La cola esta vacia? " << col.empty() << endl;



    return 0;
}