#ifndef DT_ARRIBO_H
#define DT_ARRIBO_H

#include "DtBarco.h"
#include "DtFecha.h"

class DtArribo{
    private:
        DtFecha fecha;
        float carga;
        DtBarco* barco;
    public:
        DtArribo();
        DtArribo(DtFecha fecha, float carga, DtBarco* barco);
        DtArribo(const DtArribo&);
        ~DtArribo();
        DtFecha getFecha();
        float getCarga();
        DtBarco* getBarco();
};

#endif
