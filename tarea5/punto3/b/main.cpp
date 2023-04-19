#include "lista.h"
#include <iostream>

// Marco Antonio Riascos Salguero
//  codigo 8952273
// Ejercicio 3b

// La complegidad del insListaOrdenada es O(N**2), ya que necesita recorrer la lista cada vez que va a agregar un nuevo dono en 
// cada posicion.

int main(){
  Lista l1;
  l1.insListaOrdenada(6);
  l1.insListaOrdenada(4);
  l1.insListaOrdenada(2);
  l1.insListaOrdenada(8);
  l1.insListaOrdenada(12);
  for(int i = 1; i <= l1.longLista(); i++){
		cout << l1.infoLista(i) << endl;
	}
  return 0;
}