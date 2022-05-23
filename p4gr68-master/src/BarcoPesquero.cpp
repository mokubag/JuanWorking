#include "../include/classes/BarcoPesquero.h"
#include "../include/dataTypes/DtBarcoPesquero.h"

BarcoPesquero::BarcoPesquero(){}

BarcoPesquero::BarcoPesquero(DtBarcoPesquero b) : capacidad(b.getCapacidad()), carga(b.getCarga()){
        setNombre(b.getNombre() );
        setId(b.getId() );
    }

void BarcoPesquero::setCapacidad(int cant){
    capacidad = cant;
}

void BarcoPesquero::setCarga(int cant){
    carga = cant;
}

int BarcoPesquero::getCapacidad(){
    return capacidad;
}

int BarcoPesquero::getCarga(){
    return carga;
}

void BarcoPesquero::arribar(float cargaDespacho){
    carga -= cargaDespacho;
}
