#ifndef NODO_H
#define NODO_H

#include <iostream>
#include "Sucursal.h"
using namespace std;

class NodoArista;
class Sucursal;

class NodoVertice{
public:

    string id;
    Sucursal*dato;
    NodoArista * hArista;
    NodoVertice * sigVertice;

    NodoVertice();
    NodoVertice(string,Sucursal*);
    NodoVertice(string, NodoArista *, NodoVertice *,Sucursal*);

};

class NodoArista{
public:

    int peso;
    NodoArista* sigArista;
    NodoVertice* destino;

    NodoArista();
    NodoArista(int);
    NodoArista(int, NodoArista*);
    NodoArista(int, NodoArista*, NodoVertice*);

};

#endif
