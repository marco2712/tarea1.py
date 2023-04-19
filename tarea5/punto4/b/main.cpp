#include "lista.h"
#include <iostream>


// Marco Riascos Saluguero
// codigo 8952273
// Ejercicio 4b


// La complegidad delcontacaner listas es O(n**2), ya que recorre las listas agregandolos a una nueva lista pero lo hace dentro de ciclos
// lo que hace que su complegidad sea cuadratica

int main(){
  Lista l1;
  Lista l2;
  l1.anxLista(2);
  l1.anxLista(4);
  l1.anxLista(6);
  l1.anxLista(8);
  l1.anxLista(12);
  l1.anxLista(14);
  l2.anxLista(3);
  l2.anxLista(34);
  l2.anxLista(28);
  Lista l3 = l1 + l2;
  int i;
  for(int i = 1; i < l3.longLista(); i++){
		cout << l3.infoLista(i) << endl;
	}
  return 0;
}