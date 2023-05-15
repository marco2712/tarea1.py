/*
Autor: Marco Antonio Riascos Salguero
codigo: 8952273
Fecha: 14 de Mayo
keyboard
*/

#include <iostream>
#include <list>
#include <string>
using namespace std;

/*
La complegidad de este algoritmo es lineal, osea O(n), ya que tiene un ciclo que recorre toda la linea de carcateres;
asi va agregando en la lista en la posicion indicada, en la lista, lo que depende del tamaño del caracter para saber cuanto
tarda en ejecutar
*/

int main() {
  string character;
  while (getline(cin, character)) {
    list<char> lista;
    list<char>::iterator it = lista.begin();
    for (int i = 0; i < character.size(); ++i) {
      if (character[i] == '[') { // si necesita agreagar al inicio
        it = lista.begin(); 
      }
      else if (character[i] == ']') { // si necesita agregar al final de la linea
        it = lista.end();
      } 
      else{
        lista.insert(it, character[i]); //  este permite agregar en una posicion arbitaria
      }
    }
    list<char>::iterator printLista;
    for(printLista = lista.begin(); printLista != lista.end(); ++printLista) {
      printf("%c",*printLista);
    }
    printf("\n");
  }
    return 0;
}