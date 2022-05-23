#ifndef DT_BARCO_PESQUERO_H
#define DT_BARCO_PESQUERO_H

#include "DtBarco.h"

class DtBarcoPesquero : public DtBarco{
    private:
        int capacidad;
        int carga;
    public:
        DtBarcoPesquero();
        DtBarcoPesquero(string, string, int, int);
        int getCapacidad();
        int getCarga();
};

#endif
