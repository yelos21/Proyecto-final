#include <iostream>
#include "grafo.h"
#include "personaje.h"

using namespace std;

int main() {
    cout << "==========================================" << endl;
    cout << "       INICIANDO PRUEBA DEL SISTEMA       " << endl;
    cout << "==========================================\n" << endl;

    // 1. Probando la creación de personajes
    cout << "[1] Creando personaje..." << endl;
    // Asumiendo el orden: nombre, vida, ataque, defensa, velocidad
    personaje clement("Clement", 100, 45, 20, 30); 
    cout << "-> Personaje listo: " << clement.getNombre() 
         << " | HP: " << clement.getVida() 
         << " | ATQ: " << clement.getAtaque() << "\n" << endl;

    // 2. Creando el Grafo (Mapa)
    cout << "[2] Construyendo el mapa (Vertices)..." << endl;
    Grafo mapa;
    mapa.insertarVertice("Taverna");
    mapa.insertarVertice("Bosque");
    mapa.insertarVertice("Pantano");
    mapa.insertarVertice("Castillo");
    cout << "-> Vertices insertados.\n" << endl;

    // 3. Conectando las rutas (Aristas)
    cout << "[3] Creando rutas (Aristas)..." << endl;
    mapa.insertarArista("Taverna", "Bosque", 5);
    mapa.insertarArista("Taverna", "Pantano", 12);
    mapa.insertarArista("Bosque", "Castillo", 20);
    mapa.insertarArista("Pantano", "Castillo", 8);
    // Agregamos una ruta de regreso solo para probar
    mapa.insertarArista("Castillo", "Taverna", 25); 
    
    cout << "\n--- MAPA ORIGINAL ---" << endl;
    mapa.mostraGrafo();
    cout << "---------------------\n" << endl;

    // 4. Probando eliminación de arista
    cout << "[4] Probando eliminarArista()" << endl;
    cout << "-> Un arbol cayo en el camino de la Taverna al Bosque." << endl;
    mapa.eliminarArista("Taverna", "Bosque");
    
    cout << "\n--- MAPA DESPUES DE PERDER UNA RUTA ---" << endl;
    mapa.mostraGrafo();
    cout << "---------------------------------------\n" << endl;

    // 5. Probando eliminación de vértice
    cout << "[5] Probando eliminarVertice()" << endl;
    cout << "-> El Pantano ha sido purgado y desaparecio del mapa." << endl;
    mapa.eliminarVertice("Pantano");

    cout << "\n--- MAPA DESPUES DE DESTRUIR EL PANTANO ---" << endl;
    mapa.mostraGrafo();
    cout << "-------------------------------------------\n" << endl;

    // 6. Probando llamada a Dijkstra
    cout << "[6] Probando llamada a Dijkstra()" << endl;
    cout << "-> Buscando ruta de Taverna a Castillo..." << endl;
    // Nota: Si Dijkstra aun esta vacio en tu grafo.cpp, esto no hara nada malo, 
    // solo no imprimira la ruta, pero comprobara que compila bien.
    mapa.dijkstra("Taverna", "Castillo");

    cout << "\n==========================================" << endl;
    cout << "           PRUEBA FINALIZADA              " << endl;
    cout << "==========================================" << endl;

    return 0;
}