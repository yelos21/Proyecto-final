#ifndef ESCENA_H
#define ESCENA_H

#include <iostream>
#include "string.h"
#include "vector.h"
#include "uiManager.h"
#include "assert.h"
#include "Nodo.h"

using namespace std;

class Escena
{
    private:
        string texto;
        vector <string> opciones[4];
        int eleccion;
        bool esfinal;
        int tipo_final; //0:normal, 1:bueno, 2:malo, 3:egoista, 4:secreto

    public:
        Escena();
        Escena(int,int);
        Escena(string,vector <string>);

        string get_texto();
        void set_texto(string);

        vector <string> get_opciones();
        void set_opciones(vector <string>)

        int get_eleccion();
        void set_eleccion(int);

        bool get_esfinal();
        void set_esfinal(bool);

        int get_tipo_final();
        void set_tipo_final(int);

        string cargar_narrativa(string archivo);
        void prepararInterfaz(UIManager& ui, string archivo);
        bool puedeElegirOpcion(int indice, int deshonorActual);
        //void reproducirAmbiente(assetMa& audio);
        //bool esNodoTerminal();
};

#endif // ESCENA_H
