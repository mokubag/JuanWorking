#include "../include/dataTypes/DtArribo.h"
#include "../include/dataTypes/DtBarcoPasajeros.h"
#include "../include/dataTypes/DtBarcoPesquero.h"

DtArribo::DtArribo(){}

DtArribo::DtArribo(DtFecha fecha, float carga, DtBarco* barco) : fecha(fecha), carga(carga), barco(new DtBarco(*barco)){}

DtArribo::DtArribo(const DtArribo& a) : fecha(a.fecha), carga(a.carga), barco(new DtBarco(*(a.barco))){}

DtArribo::~DtArribo(){
    delete barco;
}

DtFecha DtArribo::getFecha(){
    return fecha;
}

float DtArribo::getCarga(){
    return carga;
}

DtBarco* DtArribo::getBarco(){
    return barco;
}
