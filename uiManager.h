#ifndef UIMANAGER_H
#define UIMANAGER_H

#include "personaje.h"
#include <raylib.h>

#define COLOR_FONDO        (Color){15, 15, 20, 255}
#define COLOR_TEXTO        (Color){220, 210, 190, 255}
#define COLOR_OPCION       (Color){40, 40, 55, 255}
#define COLOR_OPCION_HOVER (Color){70, 60, 90, 255}
#define COLOR_BORDE        (Color){100, 80, 130, 255}

class UIManager {
private:
    int anchoVentana;
    int altoVentana;
    int opcionSeleccionada;
    Font fuente;
    Rectangle rectOpciones[4];
    void dibujarTextoEnvuelto(string texto, int x, int y, int ancho, int size, Color color);
public:
    UIManager(int ancho, int alto);
    void cargarFuente(string ruta);

    // Dibujado principal
    void dibujarEscena(string texto);
    void dibujarOpciones(string opciones[], NodoArista* hArista);
    void dibujarBarraDeshonor(float normalizado);  // 0.0 - 1.0

    // Input — devuelve 0,1,2,3 según la opción clickeada, -1 si ninguna
    int  obtenerEleccion();
    void dibujarPantallaFinal(string mensaje, int deshonor);
    void dibujarPantallaCarga(string mensaje);


};




#endif