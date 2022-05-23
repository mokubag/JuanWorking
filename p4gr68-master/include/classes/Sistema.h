/*
 * Clase Sistema, consiste en una colección de puertos y barcos.
 * Las operaciones a ejecutarse en principal serán miembros de una instancia
 * de sistema.
 */

#ifndef SISTEMA_H
#define SISTEMA_H

#include "Barco.h"
#include "Puerto.h"

#include "Colecciones.h"

#include <string>

class Sistema{
    private:
        listaBarcos barcos;
        listaPuertos puertos;
    public:
        Sistema();
        Sistema(int, int);
        listaBarcos getBarcos();
        listaPuertos& getPuertos();
        /* Funciones auxiliares */
        bool existeIdPuerto(string);
        bool existeIdBarco(string);
        Puerto* getPuerto(string);
        Barco* getBarco(string);
        /* Operaciones pedidas en la tarea */
        void agregarPuerto(string id, string nombre, const DtFecha &fechaCreacion);
        void agregarBarco(DtBarco &barco);
        listaDtPuertos listarPuertos();
        void agregarArribo(string idPuerto, string idBarco, float cargaDespacho);
        listaDtArribos obtenerInfoArribosEnPuerto(string idPuerto);
        void eliminarArribos(string idPuerto, const DtFecha& fecha);
        listaDtBarcos listarBarcos();
};

#endif
