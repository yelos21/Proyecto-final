#ifndef NODO_H
#define NODO_H

#include <iostream>
#include "raylib.h"
using namespace std;

class NodoArista;

class NodoVertice{
public: 

    string id; 
    NodoArista * hArista;
    NodoVertice * sigVertice;

    NodoVertice();
    NodoVertice(string);
    NodoVertice(string, NodoArista *, NodoVertice *);

};

class NodoArista{
public:

    int peso; 
    NodoArista* sigArista;
    NodoVertice* destino;

    NodoArista();
    NodoArista(int);
    NodoArista(int, NodoArista*, NodoVertice*);
    
};

#endif