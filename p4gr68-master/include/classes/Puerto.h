#ifndef PUERTO_H
#define PUERTO_H

#include <string>

#include "../dataTypes/DtPuerto.h"
#include "../dataTypes/DtFecha.h"
#include "Colecciones.h"
#include "Arribo.h"

class Puerto{
    private:
        string id;
        string nombre;
        DtFecha fechaCreacion;
        listaArribos arribos;
    public:
        Puerto();
        Puerto(DtPuerto);
        void setId(string);
        void setNombre(string);
        void setFechaCreacion(DtFecha);
        string getId();
        string getNombre();
        DtFecha getFechaCreacion();
        listaArribos& getArribos();
};

#endif
