#include "Sucursal.h"

Sucursal::Sucursal()
{
    nombre = "";
    direccion = "";
    telefono = 0;
    horario = "";
    mercancia = 0;
}

Sucursal::Sucursal(string nombre, string direccion)
{
    this->nombre = nombre;
    this->direccion = direccion;
    telefono = 0;
    horario = "";
    mercancia = 0;
}

Sucursal::Sucursal(int telefono,string horario)
{
    nombre = "";
    direccion = "";
    this->telefono = telefono;
    this->horario = horario;
    mercancia = 0;
}

Sucursal::~Sucursal()
{

}

string Sucursal::get_nombre()
{
    return nombre;
}

void Sucursal::set_nombre(string nombre)
{
    this->nombre = nombre;
}

string Sucursal::get_direccion()
{
    return direccion;
}

void Sucursal::set_direccion(string direccion)
{
    this->direccion = direccion;
}

int Sucursal::get_telefono()
{
    return telefono;
}

void Sucursal::set_telefono(int telefono)
{
    this->telefono = telefono;
}

string Sucursal::get_horario()
{
    return horario;
}

void Sucursal::set_horario(string horario)
{
    this->horario = horario;
}

int Sucursal::get_mercancia()
{
    return mercancia;
}

void Sucursal::set_mercancia(int mercancia)
{
    this->mercancia = mercancia;
}

void Sucursal::mostrar_datos()
{
    cout<<"Datos de la sucursal:"<<nombre<<endl;
    cout<<"Direcci"<<char(162)<<"n:"<<direccion<<endl;
    cout<<"Telefono:"<<telefono<<endl;
    cout<<"Horario:"<<horario<<endl;
}

void Sucursal::distribuir(NodoArista*arista)
{
    if (arista == nullptr || arista->destino == nullptr || arista->destino->dato == nullptr)
    {
        cout << "Error: Ruta de distribución no válida." << endl;
        return;
    }

    cout<<"\nDistribuyendo "<<mercancia<<" paquetes de la sucursal "<<
    nombre<<" a la sucursal "<<arista->destino->dato->nombre<<"\n"<<
    " por la ruta de "<<arista->peso<<" kilometros"<<endl;
}
