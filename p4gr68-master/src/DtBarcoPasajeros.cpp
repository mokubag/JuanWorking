#include "../include/dataTypes/DtBarcoPasajeros.h"
#include "../include/dataTypes/TipoTamanio.h"

#include <string>

DtBarcoPasajeros::DtBarcoPasajeros(){}

DtBarcoPasajeros::DtBarcoPasajeros(string nombre, string id, int cantPasajeros, TipoTamanio tamanio) :
DtBarco(nombre, id), cantPasajeros(cantPasajeros), tamanio(tamanio){}

int DtBarcoPasajeros::getCantPasajeros(){
    return cantPasajeros;
}

TipoTamanio DtBarcoPasajeros::getTamanio(){
    return tamanio;
}
