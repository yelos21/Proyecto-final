#include "personaje.h"
#include "Nodo.h"

personaje::personaje(){
    desohonor = 0;
    nombre = "Elias Emmanuel";
    ubicacion = nullptr;
}


personaje::personaje(NodoVertice* ubicacion){
    nombre = "Elias Emmanuel";
    desohonor = 0;
    this -> ubicacion = ubicacion; 
}

string personaje::getNombre(){
    return nombre;
}

int personaje::getDeshonor(){
    return desohonor;
}

NodoVertice* personaje::getUbicacion(){
    return ubicacion;
}

void personaje::aumentarDeshonor(int peso){
    desohonor += peso;
}

void personaje::mover(NodoVertice* destino){
    ubicacion = destino;
}

void personaje::getDeshonorNormalizado(){
    return desohonor / 100.0f;
}
