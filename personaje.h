#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <iostream>
#include "Nodo.h"
#include "raylib.h"
#include <string>
using namespace std;


class personaje{
protected:
    int desohonor;
    string nombre;
    NodoVertice* ubicacion;

public:
    personaje();
    personaje(NodoVertice*);
    string getNombre();
    int getDeshonor();
    NodoVertice* getUbicacion();
    void aumentarDeshonor(int);
    void mover(NodoVertice* destino);
    float getDeshonorNormalizado();

};




#endif