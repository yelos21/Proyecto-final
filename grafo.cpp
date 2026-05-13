#include "grafo.h"
#include "Nodo.h"
#include <iostream>


Grafo::Grafo(){
    hGrafo = nullptr;
}


Grafo::Grafo(NodoVertice* hGrafo){
    this -> hGrafo = hGrafo;
}


NodoVertice* Grafo::buscarVertice(string id){
    NodoVertice* aux = hGrafo; 
    bool band = true; 

    while (aux and band){
        if (aux -> id == id){
            band = false; 
        }else{ 
            aux = aux -> sigVertice; 
        }

    }
    return aux;
}

void Grafo::insertarArista(string _origen, string _destino, int peso){
    NodoVertice* origen = buscarVertice(_origen);
    NodoVertice* destino = buscarVertice(_destino);

    if(origen and destino){
        NodoArista* aux =  origen -> hArista;
        NodoArista* tmp = new NodoArista(peso, nullptr, destino);

        tmp -> sigArista = aux;
        origen -> hArista = tmp;
    }
    else{
        cout << "No se encontro el vertice origen o destino" << endl;
    }
}

void Grafo::insertarVertice(string id){

        if(hGrafo == nullptr){
        NodoVertice * tmp = new NodoVertice(id , nullptr, nullptr);
        hGrafo = tmp;
    }else{
        NodoVertice * tmp = new NodoVertice(id,nullptr,nullptr);
        tmp ->sigVertice = hGrafo;
        hGrafo = tmp;
    }


}



void Grafo::mostraGrafo(){
    NodoVertice* aux = hGrafo; 

    while (aux){ 
        cout << aux -> id << " -> ";
        {
            NodoArista* auxArista = aux -> hArista; 
            while (auxArista){
               cout<<"("<<aux -> id<<","<< auxArista -> destino -> id<< ", "<<auxArista -> peso <<"), ";
                auxArista = auxArista -> sigArista;
            }

        }
        cout << endl;
        aux = aux -> sigVertice;
    }


}


void Grafo::eliminarArista(string _origen, string _destino){
    NodoVertice* origen = buscarVertice(_origen);
    NodoVertice* destino = buscarVertice(_destino);

    if(!destino or !origen){
        cout << "No se encontro el vertice origen o destino" << endl;
    }

    NodoArista* auxArista = origen -> hArista;
    NodoArista* auxAristaAnt = nullptr;
    
    while(auxArista){
        if(auxArista -> destino == destino){

            if(auxAristaAnt == nullptr){
                origen -> hArista = auxArista -> sigArista;
            }else{ 
                auxAristaAnt -> sigArista = auxArista ->  sigArista;
            }

            delete auxArista;
            cout<< "Arista " << origen << "-> " << destino<< "eliminado"<<endl;
            return;
        }
        auxAristaAnt = auxArista;
        auxArista = auxArista -> sigArista;
    }
    
    cout<<"Arista no encontrada";
}


void Grafo::eliminarVertice(string id){
    NodoVertice* aux = hGrafo; 
    NodoVertice* auxant = nullptr;
    bool band = true; 

    while (aux and band){
        if(aux -> id == id){
            band = false; 
        }else{
            auxant = aux; 
            aux = aux -> sigVertice;
        }
    }

    if(aux){
        NodoVertice* tmpVertice = hGrafo;
        
        while(tmpVertice){
            if(tmpVertice != aux){
                NodoArista* auxArista = tmpVertice -> hArista;
                NodoArista* auxAristaAnt = nullptr;

                while(auxArista){
                    if(auxArista -> destino == aux){
                        if(auxAristaAnt){
                            tmpVertice -> hArista = auxArista -> sigArista;
                            delete auxArista;
                            auxArista = tmpVertice -> hArista;
                        }else{
                            auxAristaAnt -> sigArista = auxArista -> sigArista;
                            delete auxArista; 
                            auxArista = auxAristaAnt ->sigArista;
                        }

                    }else{
                        auxAristaAnt = auxArista;
                        auxArista = auxArista -> sigArista;
                    }
                }

            }
            tmpVertice = tmpVertice -> sigVertice;
        }

        NodoArista* deleteArista = aux->hArista;
        
        while(deleteArista){
            NodoArista* sig = deleteArista->sigArista;
            delete deleteArista;
            deleteArista = sig;
        }

        if(auxant == nullptr){
              hGrafo = aux -> sigVertice;
            }else{
                auxant -> sigVertice = aux ->sigVertice;
            }
                delete aux; 
                cout << "Vertice eliminado" << endl;
    }else{
        cout << "Vertice no encontrado" << endl;
    }
}


void Grafo::dijkstra(string origen, string destino){
 
    
}
