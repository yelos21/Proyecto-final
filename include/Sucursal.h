#ifndef SUCURSAL_H
#define SUCURSAL_H

#include <iostream>
#include <string.h>
#include "Nodo.h"
using namespace std;

class NodoArista;

class Sucursal
{
 protected:
    string nombre;
    string direccion;
    int telefono;
    string horario;
    int mercancia;

     public:
        Sucursal();
        Sucursal(string nombre, string direccion);
        Sucursal(int telefono, string horario);
        ~Sucursal();

        string get_nombre();
        void set_nombre(string);

        string get_direccion();
        void set_direccion(string);

        int get_telefono();
        void set_telefono(int);

        string get_horario();
        void set_horario(string);

        int get_mercancia();
        void set_mercancia(int);

        void mostrar_datos();
        void distribuir(NodoArista*)
};

#endif // SUCURSAL_A_H
