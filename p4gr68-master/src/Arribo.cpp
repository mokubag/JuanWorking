#include "../include/classes/Arribo.h"
#include "../include/classes/BarcoPasajeros.h"
#include "../include/classes/BarcoPesquero.h"
#include "../include/classes/Sistema.h"
#include "../include/dataTypes/DtArribo.h"
#include "../include/dataTypes/DtBarcoPasajeros.h"
#include "../include/dataTypes/DtBarcoPesquero.h"

Arribo::Arribo(){}

Arribo::Arribo(DtArribo a) : fecha(a.getFecha() ), carga(a.getCarga() ){}

void Arribo::setFecha(DtFecha nueva_fecha){
    fecha = nueva_fecha;
}

void Arribo::setCarga(float cant){
    carga = cant;
}

void Arribo::setBarco(Barco &b){
    barco = &b;
}

DtFecha Arribo::getFecha(){
    return fecha;
}

float Arribo::getCarga(){
    return carga;
}

Barco* Arribo::getBarco(){
    return barco;
}

DtBarco* Arribo::getDtBarco(){
    BarcoPasajeros* bPas = dynamic_cast<BarcoPasajeros*>(barco);
    BarcoPesquero* bPes = dynamic_cast<BarcoPesquero*>(barco);
    if (bPas != NULL){
        DtBarcoPasajeros* pas = new DtBarcoPasajeros(bPas->getNombre(),bPas->getId(),bPas->getCantPasajeros(),bPas->getTamanio() );
        return pas;
    } else if (bPes != NULL){
        DtBarcoPesquero* pes = new DtBarcoPesquero(bPes->getNombre(),bPes->getId(),bPes->getCapacidad(),bPes->getCarga() );
        return pes;
    }
    return NULL; //Para eliminar warning (nunca se llega a este punto).
}
