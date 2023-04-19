//lista.h
/*
 * Autor: Carlos Ramirez
 * Fecha de creacion: 30 de Octubre
 * Fecha ultima modificacion: 30 de Octubre
 * Version: 1.0
 * 
 * Archivo encabezado libreria TAD Lista
 * Representacion Estructuras Circulares Dobles
 */

#ifndef __LISTA_H
#define __LISTA_H

#include <iostream>

using namespace std;

/************************
* ESTRUCTURAS DE DATOS *
************************/
typedef int Elemento;

class Nodo{
   public:
     Elemento dato;
     Nodo* sig;
     Nodo* ant;

     ~Nodo();
};

class Lista{
  private:
    Nodo* act;

  public:
    /************************
    * OPERACIONES DEL TAD *
    ************************/

    /* Constructoras */
    Lista();

    /* Modificadoras */
    void anxLista(Elemento elem);
    void insLista(Elemento elem, int pos);
    void elimLista(int pos);

    /* Analizadoras */
    Elemento infoLista(int pos);
    int longLista();
    bool vaciaLista();
};

#endif