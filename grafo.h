#ifndef GRAFO_H
#define GRAFO_H

#include "Nodo.h"

class Grafo{
public:

    NodoVertice* hGrafo; 

    Grafo();
    Grafo(NodoVertice*);

    void insertarVertice(string);
    void mostraGrafo();
    void insertarArista(string,string,int);
    NodoVertice *  buscarVertice(string);    

};




#endif