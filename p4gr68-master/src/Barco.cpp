#include "../include/classes/Barco.h"
#include <string>

Barco::Barco(){}

Barco::Barco(DtBarco b) : nombre(b.getNombre() ), id(b.getId() ) {}

Barco::~Barco(){}

void Barco::setNombre(string nuevo_nombre){
    nombre = nuevo_nombre;
}

void Barco::setId(string nueva_id){
    id = nueva_id;
}

string Barco::getNombre(){
    return nombre;
}

string Barco::getId(){
    return id;
}

void Barco::arribar(float cargaDespacho){}
