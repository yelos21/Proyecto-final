#include "rebelde.h"
#include <string>

rebelde::rebelde(){
    nombre = "Rebelde";
    faccion = "Sin faccion";
    estado = true;
}

rebelde::rebelde(string nombre,string faccion,bool estado){
    this -> nombre = nombre;
    this -> faccion = faccion;
    this -> estado = estado;
}

string rebelde::getFaccion(){
    return faccion;
}

bool rebelde::getEstado(){
    return estado;
}

void rebelde::setEstado(bool estado){
    this -> estado = estado;
}

bool rebelde::confianza(int desohonor){
    if(desohonor < 50){
        return true;
    }else{
        return false;
    }
}