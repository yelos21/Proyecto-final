#include "raylib.h"
#include "grafo.h"
#include "personaje.h"
#include "uiManager.h"

int main(){
    const int ANCHO = 900;
    const int ALTO  = 600;

    InitWindow(ANCHO, ALTO, "Nueva Chapalica");
    SetTargetFPS(60);

    UIManager ui(ANCHO, ALTO);
    ui.cargarFuente("assets/fuente.ttf");

    // Construir grafo
    Grafo grafo;
    // ... insertarVertice, insertarArista, etc.

    personaje jugador(grafo.buscarVertice("inicio"));
    NodoVertice* actual = jugador.getUbicacion();

    while(!WindowShouldClose()){
        BeginDrawing();

            if(actual->esFinal){
                ui.dibujarPantallaFinal(actual->escena.texto, jugador.getDeshonor());
            } else {
                ui.dibujarEscena(actual->escena.texto);
                ui.dibujarOpciones(actual->escena.opciones, actual->hArista);
                ui.dibujarBarraDeshonor(jugador.getDeshonorNormalizado());

                int eleccion = ui.obtenerEleccion();
                if(eleccion != -1){
                    NodoArista* arista = actual->hArista;
                    for(int i = 0; i < eleccion; i++) arista = arista->sigArista;

                    jugador.aumentarDeshonor(arista->peso);
                    jugador.mover(arista->destino);
                    actual = arista->destino;
                }
            }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}