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

NodoArista* Grafo::buscarArista(string _origen,string _destino,int _peso)
{
    NodoVertice* vOrigen = buscarVertice(_origen);
    NodoVertice* vDestino = buscarVertice(_destino);

    if(vOrigen and vDestino)
    {
     NodoArista* auxArista = vOrigen -> hArista;
            while (auxArista)
            {
                if((auxArista->destino->id==_destino)and(auxArista->peso==_peso))
                {
                    return auxArista;
                }
                auxArista = auxArista -> sigArista;
            }
    }
    cout<<"No se encontr"<<char(162)<<" la arista"<<endl;
    return nullptr;
    }

NodoArista* Grafo::buscarArista(string _origen,string _destino)
{
    NodoVertice* vOrigen = buscarVertice(_origen);
    NodoVertice* vDestino = buscarVertice(_destino);

    if(vOrigen and vDestino)
    {
     NodoArista* auxArista = vOrigen -> hArista;
            while (auxArista)
            {
                if((auxArista->destino->id==_destino))
                {
                    return auxArista;
                }
                auxArista = auxArista -> sigArista;
            }
    }
    cout<<"No se encontr"<<char(162)<<" la arista"<<endl;
    return nullptr;
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

void Grafo::insertarVertice(string id,Sucursal*dato){

        if(hGrafo == nullptr){
        NodoVertice * tmp = new NodoVertice(id ,dato);
        hGrafo = tmp;
    }else{
        NodoVertice * tmp = new NodoVertice(id,dato);
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

  if(auxArista){
    while(auxArista){
        if(auxArista -> destino == destino){

            if(auxAristaAnt == nullptr){
                origen -> hArista = auxArista -> sigArista;
            }else{
                auxAristaAnt -> sigArista = auxArista ->  sigArista;
            }

            delete auxArista;
            cout<< "Arista " << _origen  << "-> " << _destino << " eliminado"<<endl;
            return;
        }
        auxAristaAnt = auxArista;
        auxArista = auxArista -> sigArista;
    }
     }
     else{
    cout<<"Arista no encontrada";
     }
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
                        if(auxAristaAnt == nullptr){
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

void Grafo::dijkstra(string origen_, string destino_){

    NodoVertice* origen = buscarVertice(origen_);
    NodoVertice* destino = buscarVertice(destino_);

    if(!origen){
        cout << "No se encontro el vertice origen" << endl;
        return;
     }else if (!destino) {
        cout << "No se encontro el vertice destino" << endl;
        return;
     }

    map<string, int> distancias;
    map<string, bool> visitado;
    map<string, string> anterior;

    NodoVertice* aux = hGrafo;

    while (aux) {
        distancias[aux->id] = INT_MAX;
        visitado[aux->id] = false;
        anterior[aux->id] = "";
        aux=aux->sigVertice;
    }

    distancias[origen->id] = 0;
    int total = distancias.size();
    for (int i = 0; i < total; i++){

        string verticeAct = "";
        int minDis = INT_MAX;

        for (auto& par : distancias) {
            if (!visitado[par.first] && par.second < minDis) {
                verticeAct = par.first;
                minDis = par.second;
            }
        }

        if(verticeAct == "") break;
        visitado[verticeAct] = true;
        NodoVertice* Nodoact = buscarVertice(verticeAct);
        NodoArista* arista = Nodoact->hArista;

        while(arista){
            string sig = arista->destino->id;
            int newDist = distancias[verticeAct] + arista->peso;
            if(newDist < distancias[sig]){
                distancias[sig] = newDist;
                anterior[sig] = verticeAct;
            }

            arista = arista->sigArista;

        }

        if(distancias[destino->id] == INT_MAX){
            cout << "No existe ruta de " << origen->id << " a " << destino->id << endl;
            return;
        }

    }
    vector<string> ruta;
    string paso = destino -> id;
    while(paso != ""){
        ruta.push_back(paso);
        paso = anterior[paso];
    }
    reverse(ruta.begin(), ruta.end());

    cout << "\nRuta mas corta de " << origen->id << " a " << destino->id << ":" << endl;
    for(int i = 0; i < ruta.size(); i++){
        cout << ruta[i];
        if(i < ruta.size() - 1) cout << " -> ";
    }
    cout << "\nDistancia total: " << distancias[destino->id] << " km" << endl;
}
