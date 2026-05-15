#ifndef SUCURSAL_H
#define SUCURSAL_H

#include <iostream>
#include <string.h>
#include "Nodo.h"
using namespace std;

class NodoArista;

class Sucursal
{
 private:
    string nombre;
    string direccion;
    string telefono;
    string horario;
    int mercancia;

     public:
        Sucursal();
        Sucursal(string nombre, string direccion);
        Sucursal(string telefono, string horario,int mercancia);
        Sucursal(string nombre,string direccion,string telefono,string horario,int mercancia);
        ~Sucursal();

        string get_nombre();
        void set_nombre(string);

        string get_direccion();
        void set_direccion(string);

        string get_telefono();
        void set_telefono(string);

        string get_horario();
        void set_horario(string);

        int get_mercancia();
        void set_mercancia(int);

        void mostrar_datos();
        void distribuir(NodoArista*);
};

#endif // SUCURSAL_A_H
