#include "Nodo.h"
#include "Grafo.h"

Grafo*crear_grafo()
{
    //Creación de las 8 sucursales
    Sucursal *sucursal1 = new Sucursal("Sur","Av. Lopez Mateos","3352342444","7:00am-19:00pm",500);
    Sucursal *sucursal2 = new Sucursal("Norte","Periferico Norte","3389328844","7:00am-19:00pm",1000);
    Sucursal *sucursal3 = new Sucursal("Centro","Colonia Centro","3354367404","7:00am-19:00pm",3000);
    Sucursal *sucursal4 = new Sucursal("Centro2","Calle Miguel Hidalgo","3389673432","7:00am-19:00pm",3500);
    Sucursal *sucursal5 = new Sucursal("Oeste","Colonia Chapalita","3300983234","8:00am-18:00pm",700);
    Sucursal *sucursal6 = new Sucursal("Este","San Joaquin","3300993222","8:00am-18:00pm",1000);
    Sucursal *sucursal7 = new Sucursal("Foranea1","Tequila","3399921231","9:00am-20:00pm",900);
    Sucursal *sucursal8 = new Sucursal("Foranea2","Ciudad Guzman","3334239843","9:00am-20:00pm",800);

    //Creación del Grafo
    Grafo *migrafo = new Grafo();

    migrafo->insertarVertice("Sur",sucursal1);
    migrafo->insertarVertice("Norte",sucursal2);
    migrafo->insertarVertice("Centro",sucursal3);
    migrafo->insertarVertice("Centro2",sucursal4);
    migrafo->insertarVertice("Oeste",sucursal5);
    migrafo->insertarVertice("Este",sucursal6);
    migrafo->insertarVertice("Foranea1",sucursal7);
    migrafo->insertarVertice("Foranea2",sucursal8);

    //4 Aristas por cada vértice
    //Vertice Sur
    migrafo->insertarArista("Sur","Norte",20);
    migrafo->insertarArista("Sur","Centro",10);
    migrafo->insertarArista("Sur","Centro2",10);
    migrafo->insertarArista("Sur","Oeste",15);

    //Vertice Norte
    migrafo->insertarArista("Norte","Centro",10);
    migrafo->insertarArista("Norte","Centro2",10);
    migrafo->insertarArista("Norte","Oeste",15);
    migrafo->insertarArista("Norte","Este",10);

    //Vertice Centro
    migrafo->insertarArista("Centro","Centro2",12);
    migrafo->insertarArista("Centro","Oeste",11);
    migrafo->insertarArista("Centro","Este",12);
    migrafo->insertarArista("Centro","Foranea1",15);

    //Vertice Centro 2
    migrafo->insertarArista("Centro2","Este",10);
    migrafo->insertarArista("Centro2","Oeste",10);
    migrafo->insertarArista("Centro2","Foranea1",20);
    migrafo->insertarArista("Centro2","Foranea2",21);

    //Vertice Oeste
    migrafo->insertarArista("Oeste","Sur",15);
    migrafo->insertarArista("Oeste","Norte",15);
    migrafo->insertarArista("Oeste","Este",18);
    migrafo->insertarArista("Oeste","Foranea2",22);

    //Vertice Este
    migrafo->insertarArista("Este","Centro",12);
    migrafo->insertarArista("Este","Centro2",10);
    migrafo->insertarArista("Este","Oeste",18);
    migrafo->insertarArista("Este","Foranea1",19);

    //Vertice Foranea 1
    migrafo->insertarArista("Foranea1","Foranea2",8);
    migrafo->insertarArista("Foranea1","Centro",15);
    migrafo->insertarArista("Foranea1","Oeste",9);
    migrafo->insertarArista("Foranea1","Este",19);

    //Vertices Foranea 2
    migrafo->insertarArista("Foranea2","Foranea1",8);
    migrafo->insertarArista("Foranea2","Norte",20);
    migrafo->insertarArista("Foranea2","Sur",17);
    migrafo->insertarArista("Foranea2","Centro2",21);

    return migrafo;
}

void Menu(Grafo*grafo)
{
    bool band = true,band2 = true;

    int opc,opc2,distancia,merc_aux;
    string tel_aux;

    Sucursal *sucursal;

    string org,des,nom,direccion_aux,horario_aux;

    NodoVertice *suc_aux;

    while(band)
    {
        cout<<"---Bienvenido al Centro de Distribuci"<<char(162)<<"n---"<<endl;
        cout<<char(168)<<"Qu"<<char(130)<<" operaci"<<char(162)<<"n"<<
        " desea realizar para la red de paqueter"<<char(161)<<"a"<<char(63)<<endl;

        cout<<"1.Insertar Sucursal\n2.Insertar Ruta\n3.Eliminar Sucursal\n"<<
        "4.Eliminar Ruta\n5.Imprimir Listado Sucursales/Rutas\n"<<
        "6.Encontrar ruta m"<<char(160)<<"s optima\n"<<"7.Men"<<char(163)<<
        " de sucursales\n"<<"8.Salir del programa"<<endl;

        cout<<"Eleccion:";
        cin>>opc;

        system("pause");
        system("cls");

        switch(opc)
        {
            case 1:
                    cin.ignore();
                    sucursal = new Sucursal();
                    cout<<"\nIngrese los datos de la nueva Sucursal:"<<endl;

                    cout<<"Nombre:";
                    getline(cin,nom);
                    sucursal->set_nombre(nom);

                    cout<<"\nDirecci"<<char(162)<<"n:";
                    getline(cin,direccion_aux);
                    sucursal->set_direccion(direccion_aux);

                    cout<<"\nHorario:";
                    getline(cin,horario_aux);
                    sucursal->set_horario(horario_aux);

                    cout<<"\nTelefono:";
                    getline(cin,tel_aux);
                    sucursal->set_telefono(tel_aux);

                    cout<<"\nCantidad de Mercancia:";
                    cin>>merc_aux;
                    sucursal->set_mercancia(merc_aux);

                    grafo->insertarVertice(sucursal->get_nombre(),sucursal);
                    system("pause");
                    system("cls");
                    break;
            case 2:
                   cin.ignore();
                   cout<<"\nIngrese el nombre de la sucursal de origen:";
                   getline(cin,org);

                   cout<<"\nIngrese el nombre de la sucursal destino:";
                   getline(cin,des);

                   cout<<"\nIngrese la distancia de la ruta:";
                   cin>>distancia;

                   grafo->insertarArista(org,des,distancia);
                   system("pause");
                   system("cls");
                   break;
            case 3:
                   cin.ignore();
                   cout<<"\nIngrese el nombre de la sucursal a eliminar:";
                   getline(cin,nom);

                   grafo->eliminarVertice(nom);
                   system("pause");
                   system("cls");
                   break;

            case 4:
                    cin.ignore();
                    grafo->mostraGrafo();
                    cout<<"\nIngrese el origen de la ruta a eliminar:";
                    getline(cin,org);

                    cout<<"\nIngrese el destino de la ruta a eliminar:";
                    getline(cin,des);

                    if(grafo->buscarArista(org,des)and grafo->buscarArista(des,org))
                    {
                        grafo->eliminarArista(org,des);
                        grafo->eliminarArista(des,org);
                    }
                    else
                    {
                        grafo->eliminarArista(org,des);
                    }
                    system("pause");
                    system("cls");
                    break;
            case 5:
                   cout<<"A continuaci"<<char(162)<<"n se muestra el listado de"<<
                   " todas las sucursales/rutas actuales"<<endl;

                   grafo->mostraGrafo();
                   system("pause");
                   system("cls");
                   break;

            case 6:
                   cin.ignore();
                   cout<<"\nIngrese el nombre de la sucursal de origen:";
                   getline(cin,org);

                   cout<<"\nIngrese el nombre de la sucursal destino:";
                   getline(cin,des);

                   grafo->dijkstra(org,des);
                   system("pause");
                   system("cls");
                   break;
            case 7:
                   cin.ignore();
                   grafo->mostraGrafo();
                   cout<<"\nIngrese el Nombre de la sucursal a gestionar:"<<endl;
                   getline(cin,nom);

                   band2 = true;
                   suc_aux = grafo->buscarVertice(nom);

                   system("pause");
                   system("cls");

                   while(band2)
                   {
                       cout<<"Bienvenido al Men"<<char(163)<<" de "<<
                       "sucursales, elija una opci"<<char(162)<<"n:"<<endl;

                       cout<<"1.Mostrar datos de sucursal\n2.Distribuir\n"<<
                       "3.Volver al Men"<<char(163)<<" principal"<<endl;

                       cout<<"Elecci"<<char(162)<<"n:";
                       cin>>opc2;

                       system("pause");
                       system("cls");

                       switch(opc2)
                       {
                        case 1:
                                suc_aux->dato->mostrar_datos();
                                system("pause");
                                system("cls");
                                break;
                        case 2:
                               cin.ignore();

                               grafo->mostraGrafo();

                               cout<<"\nIngrese el nombre de la sucursal destino:";
                               getline(cin,des);

                               cout<<"\nIngrese la distancia:";
                               cin>>distancia;

                               suc_aux->dato->distribuir(grafo->buscarArista(suc_aux->dato->get_nombre(),des,distancia));
                               system("pause");
                               system("cls");
                               break;
                        case 3:
                                system("pause");
                                system("cls");
                                band2 = false;
                                break;
                        default:
                                cout<<"Opci"<<char(162)<<"n no valida"<<endl;
                                system("pause");
                                system("cls");
                                break;
                       }
                         }
                         break;
                    case 8:
                            cout<<"\nSaliendo del programa..."<<endl;
                            system("pause");
                            system("cls");
                            band = false;
                            break;
                    default:
                            cout<<"Opci"<<char(162)<<"n no valida"<<endl;
                            system("pause");
                            system("cls");
                            break;
                           }
    }

}
