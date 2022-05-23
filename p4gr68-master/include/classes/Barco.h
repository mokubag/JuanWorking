#ifndef __BARCO_H__
#define  __BARCO_H__

#include "../dataTypes/DtBarco.h"

#include <string>

class Barco{
    private:
        string nombre;
        string id;
    public:
        Barco();
        Barco(DtBarco);
        virtual ~Barco();   //Destructor abstracto.
        void setNombre(string nombre);
        void setId(string id);
        string getNombre();
        string getId();
        virtual void arribar(float cargaDespacho); //Operacion abstracta
};

#endif
