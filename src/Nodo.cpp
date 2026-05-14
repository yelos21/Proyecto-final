#include "Nodo.h"

NodoVertice::NodoVertice(){
    id = "";
    sigVertice = nullptr;
    hArista = nullptr;
    dato = nullptr;
}

NodoVertice::NodoVertice(string id,Sucursal*dato){
    this -> id = id;
    sigVertice = nullptr;
    hArista = nullptr;
    this->dato = dato;
}


NodoVertice::NodoVertice(string id,NodoArista* hArista ,NodoVertice* sigVertice,Sucursal*dato){
    this -> id = id;
    this -> hArista = hArista;
    this -> sigVertice = sigVertice;
    this->dato = dato;
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

NodoArista::NodoArista(int peso, NodoArista* sigArista){
    this -> peso = peso;
    this -> sigArista = sigArista;
    destino = nullptr;
}


NodoArista::NodoArista(int peso, NodoArista* sigArista, NodoVertice* destino){
    this -> peso = peso;
    this -> sigArista = sigArista;
    this -> destino = destino;
}
