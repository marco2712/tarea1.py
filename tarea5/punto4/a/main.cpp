#include "lista.h"
#include <iostream>

//Marco Antonio Riascos Salguero
// codigo 8952273
// Ejercicio 4a

//La complegidad concatenar listas es O(n**2), debido a que esta en un ciclo que recorre un funcion que es lineal,
// convirtiendo en cuadratica.

void concatenarLista(Lista &lista, Lista &lista2){
    int check;
    for(check = 1; check<= lista2.longLista(); ++check){
        lista.anxLista(lista2.infoLista(check));
    }
}

int main(){
  Lista l1;
  Lista l2;
  l1.anxLista(6);
  l1.anxLista(4);
  l1.anxLista(2);
  l1.anxLista(8);
  l2.anxLista(12);
  l2.anxLista(6);
  l2.anxLista(4);
  l2.anxLista(2);
  l2.anxLista(8);
  l2.anxLista(12);

  concatenarLista(l1, l2);
  for(int i = 1; i <= l1.longLista(); i++){
		cout << l1.infoLista(i) << endl;
	}
  return 0;
}