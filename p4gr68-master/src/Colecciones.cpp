#include "../include/classes/Colecciones.h"
#include "../include/classes/BarcoPasajeros.h"
#include "../include/classes/BarcoPesquero.h"
#include "../include/dataTypes/DtBarcoPasajeros.h"
#include "../include/dataTypes/DtBarcoPesquero.h"
#include "../include/dataTypes/TipoTamanio.h"

#include <string>
#include <iostream>

/* listaDtArribos */

listaDtArribos::listaDtArribos(){}

listaDtArribos::listaDtArribos(int size) : array(new DtArribo*[size + 1]), tope(0){}

listaDtArribos::listaDtArribos(const listaDtArribos &lsta) : array(new DtArribo*[30 + 1]), tope(lsta.tope){
    for (int i = 1; i <= tope; ++i){
        DtFecha fechaI = lsta.array[i]->getFecha();
        float cargaI = lsta.array[i]->getCarga();
        DtBarco* barcoI = lsta.array[i]->getBarco();
        array[i] = new DtArribo(fechaI, cargaI, barcoI);
    }
}

listaDtArribos::~listaDtArribos(){
    for (int i = 1; i <= tope; ++i){
        delete array[i];
    }
    delete[] array;
}

DtArribo** listaDtArribos::getArray(){
    return array;
}

int listaDtArribos::getTope(){
    return tope;
}

void listaDtArribos::agregar(DtArribo &dato){ //Prec. tope < size
    tope++;
    array[tope] = &dato;
}
void listaDtArribos::SubirTope(){
	tope++;	
}

void listaDtArribos::eliminar(int pos){     //Prec. tope > pos
    tope--;
    for (int i = pos; i <= tope; ++i){
        array[i] = array[i + 1];
    }
}

/* listaDtBarcos */

listaDtBarcos::listaDtBarcos(){}

listaDtBarcos::listaDtBarcos(int size) : array(new DtBarco*[size + 1]), tope(0){}


listaDtBarcos::listaDtBarcos(const listaDtBarcos &lstb) : array(new DtBarco*[lstb.tope + 2]), tope(lstb.tope){
    for (int i = 1; i <= tope; ++i){
        DtBarcoPasajeros* bPas = dynamic_cast<DtBarcoPasajeros*>(lstb.array[i]);
        DtBarcoPesquero* bPes = dynamic_cast<DtBarcoPesquero*>(lstb.array[i]);
        if (bPas != NULL){
            array[i] = new DtBarcoPasajeros(*bPas);
        } else if (bPes != NULL){
            array[i] = new DtBarcoPesquero(*bPes);
        }
    }
}

listaDtBarcos::~listaDtBarcos(){
    for (int i = 1; i <= tope; ++i){
        delete array[i];
    }
    delete[] array;
}

DtBarco** listaDtBarcos::getArray(){
    return array;
}

int listaDtBarcos::getTope(){
    return tope;
}

void listaDtBarcos::agregar(DtBarco &dato){ //Prec. tope < size
    tope++;
    array[tope] = &dato;
}

void listaDtBarcos::eliminar(int pos){     //Prec. tope > pos
    tope--;
    for (int i = pos; i <= tope; ++i){
        array[i] = array[i + 1];
    }
}

/* listaDtPuertos */

listaDtPuertos::listaDtPuertos(){}

listaDtPuertos::listaDtPuertos(int size) : array(new DtPuerto[size + 1]), tope(0){}

listaDtPuertos::listaDtPuertos(const listaDtPuertos &lstp) : array(new DtPuerto[lstp.tope + 1]), tope(lstp.tope){
    for (int i = 1; i <= tope; ++i){
        string idI = lstp.array[i].getId();
        string nombreI = lstp.array[i].getNombre();
        DtFecha fechaI = lstp.array[i].getFechaCreacion();
        int cantArribosI = lstp.array[i].getCantArribos();
        array[i] = DtPuerto(idI, nombreI, fechaI, cantArribosI);
    }
}

listaDtPuertos::~listaDtPuertos(){
    delete[] array;
}

DtPuerto* listaDtPuertos::getArray(){
    return array;
}

int listaDtPuertos::getTope(){
    return tope;
}

void listaDtPuertos::agregar(DtPuerto &dato){ //Prec. tope < size
    tope++;
    array[tope] = dato;
}

void listaDtPuertos::eliminar(int pos){     //Prec. tope > pos
    tope--;
    for (int i = pos; i <= tope; ++i){
        array[i] = array[i + 1];
    }
}

/* listaArribos */

listaArribos::listaArribos(){}

listaArribos::listaArribos(int size) : array(new Arribo*[size + 1]), tope(0){}

listaArribos::listaArribos(const listaArribos& lsta) : array(new Arribo*[30 + 1]), tope(lsta.tope){ //Hack, el máximo es 30 en este ejemplo.
    for (int i = 1; i <= tope; ++i){
        DtFecha fechaI = lsta.array[i]->getFecha();
        float cargaI = lsta.array[i]->getCarga();
        DtBarco* barcoI = lsta.array[i]->getDtBarco();
        array[i] = new Arribo(DtArribo(fechaI, cargaI, barcoI));
        array[i]->setBarco(*(lsta.array[i]->getBarco() ));
    }
}

listaArribos::~listaArribos(){
    for (int i = 1; i <= tope; ++i){
        delete array[i];
    }
    delete[] array;
}

Arribo** listaArribos::getArray(){
    return array;
}

int listaArribos::getTope(){
    return tope;
}

void listaArribos::agregar(Arribo &dato){ //Prec. tope < size
    tope++;
    array[tope] = &dato;
}

void listaArribos::eliminar(int pos){     //Prec. tope > pos
    delete array[pos];
    tope--;
    for (int i = pos; i <= tope; ++i){
        array[i] = array[i + 1];
    }
}

/* listaBarcos */

listaBarcos::listaBarcos(){}

listaBarcos::listaBarcos(int size) : array(new Barco*[size + 1]), tope(0){}

listaBarcos::listaBarcos(const listaBarcos &lstb) : array(new Barco*[lstb.tope + 1]), tope(lstb.tope){
    for (int i = 1; i <= tope; ++i){
        Barco* barcoI = lstb.array[i];
        BarcoPasajeros* bPas = dynamic_cast<BarcoPasajeros*>(barcoI);
        BarcoPesquero* bPes = dynamic_cast<BarcoPesquero*>(barcoI);
        if (bPas != NULL){
            array[i] = new BarcoPasajeros(*bPas);
        } else if (bPes != NULL){
            array[i] = new BarcoPesquero(*bPes);
        }
    }
}

listaBarcos::~listaBarcos(){
    for (int i = 1; i <= tope; ++i){
        delete array[i];
    }
    delete[] array;
}

Barco** listaBarcos::getArray(){
    return array;
}

int listaBarcos::getTope(){
    return tope;
}

void listaBarcos::agregar(Barco &dato){ //Prec. tope < size
    tope++;
    array[tope] = &dato;
}

void listaBarcos::eliminar(int pos){     //Prec. tope > pos
    delete array[pos];
    tope--;
    for (int i = pos; i <= tope; ++i){
        array[i] = array[i + 1];
    }
}

/* listaPuertos */

listaPuertos::listaPuertos(){}

listaPuertos::listaPuertos(int size) : array(new Puerto*[size + 1]), tope(0){}

listaPuertos::listaPuertos(const listaPuertos &lstp) : array(new Puerto*[lstp.tope + 1]), tope(lstp.tope){
    for (int i = 1; i <= tope; ++i){
        string idI = lstp.array[i]->getId();
        string nombreI = lstp.array[i]->getNombre();
        DtFecha fechaI = lstp.array[i]->getFechaCreacion();
        int cantArribosI = lstp.array[i]->getArribos().getTope();
        array[i] = new Puerto(DtPuerto(idI, nombreI, fechaI, cantArribosI));
    }
}

listaPuertos::~listaPuertos(){
    for (int i = 1; i <= tope; ++i){
        delete array[i];
    }
    delete[] array;
}

Puerto** listaPuertos::getArray(){
    return array;
}

int listaPuertos::getTope(){
    return tope;
}

void listaPuertos::agregar(Puerto &dato){ //Prec. tope < size
    tope++;
    array[tope] = &dato;
}

void listaPuertos::eliminar(int pos){     //Prec. tope > pos
    delete array[pos];
    tope--;
    for (int i = pos; i <= tope; ++i){
        array[i] = array[i + 1];
    }
}
