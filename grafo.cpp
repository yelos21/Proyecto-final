#include "grafo.h"
#include "Nodo.h"


Grafo::Grafo(){
    hGrafo = nullptr;
}


Grafo::Grafo(NodoVertice* hGrafo){
    this -> hGrafo = hGrafo;
}


NodoVertice* Grafo::buscarVertice(string id){
    NodoVertice* aux = hGrafo; 
    bool band = true; 

    while (aux and band){
        if (aux -> id == id){
            band = false; 
        }else{ 
            aux = aux -> sigVertice; 
        }

    }
    return aux;
}

void Grafo::insertarArista(string _origen, string _destino, int peso){
    NodoVertice* origen = buscarVertice(_origen);
    NodoVertice* destino = buscarVertice(_destino);

    if(origen and destino){
        NodoArista* aux =  origen -> hArista;
        NodoArista* tmp = new NodoArista(peso, nullptr, destino);

        tmp -> sigArista = aux;
        origen -> hArista = tmp;
    }
    else{
        cout << "No se encontro el vertice origen o destino" << endl;
    }
}

void Grafo::insertarVertice(string id){

        if(hGrafo == nullptr){
        NodoVertice * tmp = new NodoVertice(id , nullptr, nullptr);
        hGrafo = tmp;
    }else{
        NodoVertice * tmp = new NodoVertice(id,nullptr,nullptr);
        tmp ->sigVertice = hGrafo;
        hGrafo = tmp;
    }


}



void Grafo::mostraGrafo(){
    NodoVertice* aux = hGrafo; 

    while (aux){ 
        cout << aux -> id << " -> ";
        {
            NodoArista* auxArista = aux -> hArista; 
            while (auxArista){
               cout<<"("<<aux -> id<<","<< auxArista -> destino -> id<< ", "<<auxArista -> peso <<"), ";
                auxArista = auxArista -> sigArista;
            }

        }
        cout << endl;
        aux = aux -> sigVertice;
    }


}

