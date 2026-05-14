#ifndef ENEMIGO_H
#define ENEMIGO_H

#include "Nodo.h"
#include "personaje.h"
#include <string>


class enemigo:public personaje {
private: 
    bool estado;
    string rango;

    public:
    enemigo();
    enemigo(string,bool,string);
    void setRango(string rango);
    string getRango();


};




#endif