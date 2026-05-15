#include <iostream>
#include "Nodo.h"
#include "grafo.h"
#include "Funciones.h"

using namespace std;

int main()
{
    Grafo* nuevo_grafo;
    nuevo_grafo = crear_grafo();
    Menu(nuevo_grafo);

    return 0;
}
