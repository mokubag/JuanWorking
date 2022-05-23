#include <stdexcept>

#include "../include/dataTypes/DtFecha.h"

DtFecha::DtFecha(){};

DtFecha::DtFecha(int dia, int mes, int anio) : dia(dia), mes(mes), anio(anio){
    bool diaValido = (dia > 0) && (dia <= 31);
    bool mesValido = (mes > 0) && (mes <= 12);
    bool anioValido = (anio >= 1900);
    if (!(diaValido && mesValido && anioValido)){
        throw std::invalid_argument("ErrorFecha");
    }
}

int DtFecha::getDia(){
    return dia;
}

int DtFecha::getMes(){
    return mes;
}

int DtFecha::getAnio(){
    return anio;
}
