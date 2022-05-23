#include "../include/dataTypes/DtBarco.h"
#include "../include/dataTypes/DtBarcoPasajeros.h"
#include "../include/dataTypes/DtBarcoPesquero.h"

using std::string;

DtBarco::DtBarco(){}

DtBarco::DtBarco(string nombre, string id) : nombre(nombre), id(id){}

DtBarco::~DtBarco(){}

string DtBarco::getNombre(){
    return nombre;
}

string DtBarco::getId(){
    return id;
}
