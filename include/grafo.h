#ifndef GRAFO_H
#define GRAFO_H

#include "Nodo.h"
#include <map>
#include <vector>
#include <algorithm>
class Grafo{
public:

    NodoVertice* hGrafo;

    Grafo();
    Grafo(NodoVertice*);

    void insertarVertice(string,Sucursal*);
    void mostraGrafo();
    void insertarArista(string,string,int);
    NodoVertice *buscarVertice(string);
    NodoArista *buscarArista(string,string,int);
    NodoArista *buscarArista(string,string);
    void eliminarVertice(string);
    void eliminarArista(string, string);
    void dijkstra(string origen, string destino);
};

#endif
