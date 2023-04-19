#include "lista.h"

// Marco Antonio Riascos Salguero
// codigo 8952273
//Ejercicio 1 y 2

// La complegidad contarOcurrencias es O(n), es lineal ya que solo recorre la lista y retorna un valor. 

int contarOcurrencias(Lista lista, int v){  // Esta funcion permite verificar si un numero se repite en una lista
    int contador = 0;
    int cont = lista.longLista();
    if(cont == 0){
        printf("La lista esta vacia, agregue a un Node\n");
    }
    else{
        int check;
        for(check = 0; check <= lista.longLista(); ++check){
            if(lista.infoLista(check) == v){
                ++ contador;
            }
        }
    }
    return contador; // Retorna ls variable con el numero de ocurrencias
}


// La complegidad obtenerMenores de O(n**2), ya tiene un for, y dentro usa una funcion que es lienal, se combina la complgidad

Lista obtenerMenores(Lista lista, int v){ // Esta funcion permite verificar los numeros menores a un valor v, proporcionado
    Lista menores;
    int cont = lista.longLista();
    if(cont == 0){
        printf("La lsita esta vacia");
    }
    else{
        int check;
        int numeroMenor;
        for(check = 0; check <= lista.longLista(); ++check){
            numeroMenor = lista.infoLista(check);
            if(numeroMenor <= v){
                menores.anxLista(numeroMenor);
            }
        }
    }
    return menores; // Retorna la lista de valores menores
}


int main(){
  Lista l1;
  l1.anxLista(4);
  l1.anxLista(12);
  l1.anxLista(1);
  l1.anxLista(7);
  l1.anxLista(14);
  l1.anxLista(3);
  l1.anxLista(8);
  l1.anxLista(9);
  int ocurrencias = contarOcurrencias(l1,4);
  Lista l2 = obtenerMenores(l1,10);
  return 0;
}
