#include "lista.h"

//Marco Antonio Riascos Salguero
// codigo 8952273
//Ejercico 3a

// La complegidad de insertarEnListaOrdenada es O(n), lo que significa que es lineal ya que recorre la lista una sola vez hasta
// que encuntra una posicion donde insertarlo

void insertarEnListaOrdenada(Lista* lista, int v){
    int contador;
    if(lista->vaciaLista()){
        lista->anxLista(v); // Agrega el primer elemento de la lista
    }
    else{
        int k = lista->longLista();
        int flag = 0;
        for(contador = 1; contador <= k; ++ contador){ // recorre la lista hasta encontrar la posicion donde debe insertar
            if(lista->infoLista(contador) > v && flag == 0){
                lista->insLista(v, contador);
                flag = 1;
            }
        }
    }
}


int main(){
  Lista l1;
  l1.anxLista(2);
  l1.anxLista(4);
  l1.anxLista(6);
  l1.anxLista(8);
  l1.anxLista(12);
  l1.anxLista(14);
  insertarEnListaOrdenada(&l1, 10);
  return 0;
}