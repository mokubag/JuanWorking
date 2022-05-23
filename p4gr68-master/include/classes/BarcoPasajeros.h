#ifndef BARCO_PASAJEROS_H
#define BARCO_PASAJEROS_H

#include "../dataTypes/DtBarcoPasajeros.h"
#include "Barco.h"

class BarcoPasajeros : public Barco{
    private:
        int cantPasajeros;
        TipoTamanio tamanio;
    public:
        BarcoPasajeros();
        BarcoPasajeros(DtBarcoPasajeros);
        void setCantPasajeros(int);
        void setTamanio(TipoTamanio);
        int getCantPasajeros();
        TipoTamanio getTamanio();
        void arribar(float cargaDespacho);
};

#endif
