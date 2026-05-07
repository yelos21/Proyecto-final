#include "Nodo.h"

NodoVertice::NodoVertice(){
    id = "";
    sigVertice = nullptr;
    hArista = nullptr; 
}


NodoVertice::NodoVertice(string id){
    this -> id = id; 
    sigVertice = nullptr;
    hArista = nullptr; 
}


NodoVertice::NodoVertice(string id,NodoArista* hArista ,NodoVertice* sigVertice){
    this -> id = id; 
    this -> hArista = hArista;
    this -> sigVertice = sigVertice; 
}


NodoArista::NodoArista(){
    peso = 0; 
    sigArista = nullptr; 
    destino = nullptr; 
}


NodoArista::NodoArista(int peso){
    this -> peso = peso; 
    sigArista = nullptr; 
    destino = nullptr;     
}


NodoArista::NodoArista(int peso, NodoArista* sigArista, NodoVertice* destino){
    this -> peso = peso; 
    this -> sigArista = sigArista; 
    this -> destino = destino;
}
