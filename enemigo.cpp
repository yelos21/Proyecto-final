#include "enemigo.h"

enemigo::enemigo(){
    nombre = "Enemigo";
    estado = true;
    rango = "Sin rango";
}

enemigo::enemigo(string nombre,bool estado,string rango){
    this -> nombre = nombre;
    this -> estado = estado;
    this -> rango = rango;
}

void enemigo::setRango(string rango){
    this -> rango = rango;
}

string enemigo::getRango(){
    return rango;
}
