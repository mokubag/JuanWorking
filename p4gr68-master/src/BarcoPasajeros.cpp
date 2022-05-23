#include "../include/classes/BarcoPasajeros.h"
#include "../include/dataTypes/DtBarcoPasajeros.h"

#include <string>

BarcoPasajeros::BarcoPasajeros(){}

BarcoPasajeros::BarcoPasajeros(DtBarcoPasajeros b) : cantPasajeros(b.getCantPasajeros()), tamanio(b.getTamanio() ){
    setNombre(b.getNombre() );
    setId(b.getId() );
}

void BarcoPasajeros::setCantPasajeros(int cant){
    cantPasajeros = cant;
}

void BarcoPasajeros::setTamanio(TipoTamanio size){
    tamanio = size;
}

int BarcoPasajeros::getCantPasajeros(){
    return cantPasajeros;
}

TipoTamanio BarcoPasajeros::getTamanio(){
    return tamanio;
}

void BarcoPasajeros::arribar(float cargaDespacho){}        //NO hace nada, los barcos de pasajeros no tienen carga.
