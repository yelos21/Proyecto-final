#include "personaje.h"

personaje::personaje(){
    nombre = "Elias";
    vida = 0;
    ataque = 0;
    defensa = 0;
    velocidad = 0;
    desohonor = 0;
}


personaje::personaje(string nombre, int vida, int ataque, int defensa, int velocidad){
    this -> nombre = "ELias";
    this -> vida = vida;
    this -> ataque = ataque;
    this -> defensa = defensa;
    this -> velocidad = velocidad;
    desohonor = 0;
}

string personaje::getNombre() { return nombre; }
int personaje::getVida() { return vida; }
int personaje::getAtaque() { return ataque; }
int personaje::getDefensa() { return defensa; }
int personaje::getVelocidad() { return velocidad; }

void personaje::setNombre(string _nombre) { nombre = _nombre; }
void personaje::setVida(int _vida) { vida = _vida; }
void personaje::setAtaque(int _ataque) { ataque = _ataque; }
void personaje::setDefensa(int _defensa) { defensa = _defensa; }/