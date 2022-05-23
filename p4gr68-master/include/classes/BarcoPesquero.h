#ifndef __BARCO_PESCA_H__
#define __BARCO_PESCA_H__

#include "../dataTypes/DtBarcoPesquero.h"
#include "Barco.h"

class BarcoPesquero : public Barco{
    private:
        int capacidad;
        int carga;
    public:
        BarcoPesquero();
        BarcoPesquero(DtBarcoPesquero);
        void setCapacidad(int);
        void setCarga(int);
        int getCapacidad();
        int getCarga();
        void arribar(float cargaDespacho);
};

#endif
