#include "lista.h"

Lista::Lista(){
  act = NULL;
}

void Lista::insListaOrdenada(Elemento elem){
   Nodo* tmp;
   Nodo* otro;
   int flag1 = 0;
  if(vaciaLista()){
    Nodo* nuevo = new Nodo;
    nuevo->dato = elem;
    nuevo->sig = NULL;
    act = nuevo;
  }
  else if(elem < act->dato){
    Nodo* nuevo = new Nodo;
    nuevo->dato = elem;
    nuevo->sig = act;
    act = nuevo;
  }
  else{
    tmp = act;
    otro = tmp;
    while(tmp != NULL && flag1 == 0){
      if(tmp->dato >= elem){
        Nodo* actual = new Nodo;
        actual->dato = elem;
        otro-> sig = actual;
        actual->sig = tmp;
        flag1 = 1;
      }
      otro = tmp;
      tmp = tmp->sig;
    }
    if(tmp == NULL){
        Nodo* actual = new Nodo;
        actual->dato = elem;
        otro->sig = actual;
        actual->sig = NULL;
    }    
  }
}

void Lista::elimLista(int pos){
  Nodo *tmp, *elim;
  if(pos >= 1 && pos <= longLista()){
    if(pos == 1)
      act = act->sig;
    else{
      tmp = act;
      for(int i = 0; i < pos-2; i++)
	tmp = tmp->sig;
      elim = tmp->sig;
      tmp->sig = tmp->sig->sig;
      delete elim;
    }
  }
}

Elemento Lista::infoLista(int pos){
  Nodo* tmp = act;

  for(int i = 1; i < pos; i++)
    tmp = tmp->sig;

  return tmp->dato;
}

int Lista::longLista(){
  Nodo* tmp = act;
  int cont = 0;

  while(tmp != NULL){
    tmp = tmp->sig;
    cont++;
  }

  return cont;
}

bool Lista::vaciaLista(){
  return act == NULL;
}
