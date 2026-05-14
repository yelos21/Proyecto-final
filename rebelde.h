#ifndef  REBELDE_H
#define REBELDE_H

#include "personaje.h"
#include <string>

class rebelde:public personaje{
private:
    string faccion;  

public:
    rebelde();
    rebelde(string,string);
    string getFaccion();

};



#endif