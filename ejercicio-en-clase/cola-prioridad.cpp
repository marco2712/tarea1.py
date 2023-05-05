/*

Benjamin Ortiz Morales

Marco Antonio Riascos

Estructura de datos

*/


#include "cola-prioridad.h"
#include "lista.h"

typedef int Elemento;

Cola::Cola(){
}

Elemento Cola::front(){
    int mayor = l.infoLista(1);
    for(int i = 2; i <= l.longLista(); i++){
        if(mayor < l.infoLista(i)){
            mayor = l.infoLista(i);
        }
    }
   Elemento ans = mayor;
   return ans;
}

void Cola::enqueue(Elemento e){
   l.anxLista(e);
}

void Cola::deque(){
    Elemento mayor = front(); 
    int i = 1;
    int flag = 0;
    while(i <= l.longLista() && flag == 0){
        if(l.infoLista(i) == mayor){
            l.elimLista(i);
            flag = 1;
        }
        i++;
    }
}

bool Cola::empty(){
  bool ans;
  if(l.vaciaLista())
     ans = true;
  else
     ans = false;
  return ans;
}
