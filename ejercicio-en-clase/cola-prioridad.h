/*

Benjamin Ortiz Morales

Marco Antonio Riascos

Estructura de datos

*/


#include "lista.h"
#include <iostream>

using namespace std;


#ifndef __cola_prioridad_H
#define __cola_prioridad_H

typedef int Elemento;

class Cola{
   public:
      Lista l;
      Cola(); // crearCola
      Elemento front();
      void deque();
      void enqueue(Elemento);
      bool empty();
};

#endif