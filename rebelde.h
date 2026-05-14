#ifndef  REBELDE_H
#define REBELDE_H

#include "personaje.h"
#include <string>

class rebelde:public personaje{
private:
    string faccion;  
    bool estado;
public:
    rebelde();
    rebelde(string,string,bool);
    string getFaccion();
    bool getEstado();
    void setEstado(bool);
    bool confianza(int desohonor);

};



#endif