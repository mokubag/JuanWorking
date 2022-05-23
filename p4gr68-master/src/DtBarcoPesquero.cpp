#include "../include/dataTypes/DtBarcoPesquero.h"

DtBarcoPesquero::DtBarcoPesquero(){}

DtBarcoPesquero::DtBarcoPesquero(string nombre, string id, int capacidad, int carga) : 
DtBarco(nombre, id), capacidad(capacidad), carga(carga){}

int DtBarcoPesquero::getCapacidad(){
    return capacidad;
}

int DtBarcoPesquero::getCarga(){
    return carga;
}
