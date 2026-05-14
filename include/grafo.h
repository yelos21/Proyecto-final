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
    NodoVertice *buscarVertice(string);    
    void eliminarVertice(string);
    void eliminarArista(string, string);
    void dijkstra(string origen, string destino);


};




#endif