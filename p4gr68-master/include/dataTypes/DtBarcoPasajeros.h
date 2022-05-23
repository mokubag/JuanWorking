#ifndef DT_BARCO_PASAJEROS_H
#define DT_BARCO_PASAJEROS_H

#include "DtBarco.h"
#include "TipoTamanio.h"

class DtBarcoPasajeros : public DtBarco{
    private:
        int cantPasajeros;
        TipoTamanio tamanio;
    public:
        DtBarcoPasajeros();
        DtBarcoPasajeros(string, string, int, TipoTamanio);
        int getCantPasajeros();
        TipoTamanio getTamanio();
};

#endif
