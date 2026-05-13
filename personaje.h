#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <iostream>
#include "raylib.h"
using namespace std;


class personaje{
private:
    //aun no terminado 
    int honor;
    string nombre;
    int vida;
    int ataque;
    int defensa;
    int velocidad;
public:
    personaje();
    personaje(string, int, int, int, int);
    string getNombre();
    int getVida();
    int getAtaque();
    int getDefensa();
    int getVelocidad();    
    void setNombre(string);
    void setVida(int);
    void setAtaque(int);
    void setDefensa(int);
    
};




#endif