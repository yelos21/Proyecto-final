#include "grafo.h"
#include "Nodo.h"


Grafo::Grafo(){
    hGrafo = nullptr;
}


Grafo::Grafo(NodoVertice* hGrafo){
    this -> hGrafo = hGrafo;
}



