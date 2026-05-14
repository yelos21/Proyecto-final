#include "Escena.h"
#include <fstream>
#include <sstream>

Escena::Escena()
{
    texto = "";
    opciones ={""}
    eleccion = 0;
    esfinal = 0;
    tipo_final = 0;
}

Escena::Escena(int eleccion,int tipo_final)
{
    this->eleccion = eleccion;
    this->tipo_final = tipo_final;
    esfinal = 0;
    texto = "";
    opciones = {""};
}

Escena::Escena(string texto,vector <string> opciones)
{
    this->texto = texto;
    this->opciones = opciones;
    eleccion = 0;
    esfinal = 0;
    tipo_final = 0;

}

Escena::~Escena()
{
    //dtor
}

string Escena::get_texto()
{
    return texto;
}

void Escena::set_texto(string texto)
{
    this->texto = texto;
}

vector <string> Escena::get_opciones()
{
    return opciones;
}

void Escena::set_opciones(vector <string> opciones)
{
    this->opciones = opciones;
}

int Escena::get_eleccion()
{
    return eleccion;
}

void Escena::set_eleccion(int eleccion)
{
    this->eleccion = eleccion;
}

bool Escena::get_esfinal()
{
    return esfinal;
}
void Escena::set_esfinal(bool esfinal)
{
    this->esfinal = esfinal;
}

int Escena::get_tipo_final()
{
    return tipo_final;
}

void Escena::set_tipo_final(int tipo_final)
{
    this->tipo_final = tipo_final;
}

string Escena::cargar_narrativa(string archivo)
{
    // 1. Abrimos el flujo de entrada para el archivo .txt
    ifstream file(archivo);

    // 2. Verificamos si el archivo se abrió correctamente
    if (!file.is_open()) {
        // Retornamos un mensaje de error que Raylib pueda mostrar
        return "Error: No se encontro la cronica en " + archivo;
    }

    // 3. Usamos un stringstream para leer todo el buffer del archivo
    stringstream buffer;
    buffer << file.rdbuf();

    // 4. Cerramos el archivo y guardamos el contenido en el atributo 'texto'
    file.close();
    this->texto = buffer.str();

    // 5. Retornamos el string por si necesitas usarlo fuera
    return this->texto;
}

void Escena::prepararInterfaz(uiManager & ui, string archivo)
{
    texto = cargar_narrativa(archivo);
    ui.dibujarEscena(this->texto);
    ui.dibujarOpciones(this->opciones, Nodo*hArista);
}

bool puedeElegirOpcion(int indice, int deshonor)
{
    // Si el índice no es válido (recuerda que el requisito son 4 aristas)
    if (indice < 0 || indice >= (int)opciones.size()) return false;

    // Lógica narrativa: Ciertas acciones "heroicas" (baja ponderación)
    // podrían bloquearse si el deshonor es demasiado alto (Ruta del Tirano)
    // O si es el Final Secreto, solo se activa bajo ciertas condiciones
    if (this->tipo_final == 4) return true; // El final secreto suele ser ineludible si llegas ahí

    return true; // Por defecto permitimos la elección para que el grafo fluya
}
