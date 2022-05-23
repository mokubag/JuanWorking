#ifndef DT_PUERTO_H
#define DT_PUERTO_H

#include <string>

#include "DtFecha.h"

using std::string;

class DtPuerto{
    private:
        string id;
        string nombre;
        DtFecha fechaCreacion;
        int cantArribos;
    public:
        DtPuerto();
        DtPuerto(string id, string nombre, DtFecha fechaCreacion, int cantArribos);
        string getId();
        string getNombre();
        DtFecha getFechaCreacion();
        int getCantArribos();
};

#endif
