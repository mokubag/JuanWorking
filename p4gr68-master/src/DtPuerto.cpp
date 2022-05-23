#include "../include/dataTypes/DtPuerto.h"
#include "../include/dataTypes/DtFecha.h"

using std::string;

DtPuerto::DtPuerto(){}

DtPuerto::DtPuerto(string id, string nombre, DtFecha fechaCreacion, int cantArribos) :
    id(id), nombre(nombre), fechaCreacion(fechaCreacion), cantArribos(cantArribos){}

string DtPuerto::getId(){
    return id;
}

string DtPuerto::getNombre(){
    return nombre;
}

DtFecha DtPuerto::getFechaCreacion(){
    return fechaCreacion;
}

int DtPuerto::getCantArribos(){
    return cantArribos;
}
