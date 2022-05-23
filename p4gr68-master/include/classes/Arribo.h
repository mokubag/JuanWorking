#ifndef ARRIBO_H
#define ARRIBO_H

#include "../dataTypes/DtArribo.h"
#include "../dataTypes/DtFecha.h"
#include "Barco.h"

class Arribo{
    private:
        DtFecha fecha;
        float carga;
        Barco* barco;
    public:
        Arribo();
        Arribo(DtArribo);
        void setFecha(DtFecha);
        void setCarga(float);
        void setBarco(Barco&);
        DtFecha getFecha();
        float getCarga();
        Barco* getBarco();
        DtBarco* getDtBarco();
};

#endif
