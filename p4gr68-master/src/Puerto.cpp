#include "../include/classes/Puerto.h"
#include "../include/dataTypes/DtPuerto.h"

Puerto::Puerto(){}

Puerto::Puerto(DtPuerto p) : 
    id(p.getId() ), nombre(p.getNombre() ), fechaCreacion(p.getFechaCreacion() ), arribos(listaArribos(30) ){}

void Puerto::setId(string nueva_id){
    id = nueva_id;
}

void Puerto::setNombre(string nuevo_nombre){
    nombre = nuevo_nombre;
}

void Puerto::setFechaCreacion(DtFecha fecha){
    fechaCreacion = fecha;
}

string Puerto::getId(){
    return id;
}

string Puerto::getNombre(){
    return nombre;
}

DtFecha Puerto::getFechaCreacion(){
    return fechaCreacion;
}

listaArribos& Puerto::getArribos(){
    return arribos;
}
