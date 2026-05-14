#include "rebelde.h"
#include <string>

rebelde::rebelde(){
    nombre = "Rebelde";
    faccion = "Sin faccion";
}

rebelde::rebelde(string nombre,string faccion){
    this -> nombre = nombre;
    this -> faccion = faccion;
}

string rebelde::getFaccion(){
    return faccion;
}
