#include "../include/classes/Sistema.h"
#include "../include/classes/Barco.h"
#include "../include/classes/BarcoPasajeros.h"
#include "../include/classes/BarcoPesquero.h"
#include "../include/dataTypes/DtBarco.h"
#include "../include/dataTypes/DtBarcoPasajeros.h"
#include "../include/dataTypes/DtBarcoPesquero.h"

#include <iostream>
#include <ctime>

Sistema::Sistema(){}

Sistema::Sistema(int maxBarcos, int maxPuertos) : barcos(listaBarcos(maxBarcos)), puertos(listaPuertos(maxPuertos)){}

listaBarcos Sistema::getBarcos(){
    return barcos;
}

listaPuertos& Sistema::getPuertos(){
    return puertos;
}

/* Funciones auxliares */

bool Sistema::existeIdPuerto(string idP){
    int i = 1;
    while ((i <= puertos.getTope() ) && (puertos.getArray()[i]->getId() != idP)){
        ++i;
    }
    if (i <= puertos.getTope() ){
        return true;
    } else {
        return false;
    }
}

bool Sistema::existeIdBarco(string idB){
    int i = 1;
    while ((i <= barcos.getTope() ) && (barcos.getArray()[i]->getId() != idB)){
        ++i;
    }
    if (i <= barcos.getTope() ){
        return true;
    } else {
        return false;
    }
}

Puerto* Sistema::getPuerto(string idP){                          //prec: existeIdPuerto(idP)
    int i = 1;
    while ((i <= puertos.getTope() ) && (puertos.getArray()[i]->getId() != idP)){
        ++i;
    }
    if (puertos.getArray()[i]->getId() == idP){
        return (puertos.getArray()[i]);
    } else {
        throw std::invalid_argument("El puerto no está en el sistema.");
    }
}

Barco* Sistema::getBarco(string idB){                            //prec: existeIdBarco(idB)
    int i = 1;
    while ((i <= barcos.getTope() ) && (barcos.getArray()[i]->getId() != idB)){
        ++i;
    }
    if (barcos.getArray()[i]->getId() == idB){
        return (barcos.getArray()[i]);
    } else {
        throw std::invalid_argument("El barco no está en el sistema.");
    }
}

static DtFecha getFechaActual(){
    time_t t0 = time(0);
    tm *tLocal = localtime(&t0);
    DtFecha fechaActual(tLocal->tm_mday, 1 + tLocal->tm_mon, 1900 + tLocal->tm_year);
    return fechaActual;
}

/* Métodos pedidos en la tarea */

void Sistema::agregarPuerto(string id, string nombre, const DtFecha &fechaCreacion){ //Prec: tope < size
      if (!existeIdPuerto(id)){
          DtPuerto dtP(id, nombre, fechaCreacion, 0);
          Puerto* nuevoPuerto = new Puerto(dtP);
          puertos.agregar(*nuevoPuerto);
      } else {
          throw std::invalid_argument("Error: Ese puerto ya está en el sistema.");
      }
}

void Sistema::agregarBarco(DtBarco& barco){
    DtBarco* nuevoBarco = &barco;
    if (!existeIdBarco(barco.getId() )){
        DtBarcoPasajeros* opcion1 = dynamic_cast<DtBarcoPasajeros*>(nuevoBarco);
        DtBarcoPesquero* opcion2 = dynamic_cast<DtBarcoPesquero*>(nuevoBarco);
        if (opcion1 != NULL){
            BarcoPasajeros* nuevoBPas = new BarcoPasajeros(*opcion1);
            barcos.agregar(*nuevoBPas);
        } else if (opcion2 != NULL){
            BarcoPesquero* nuevoBPes = new BarcoPesquero(*opcion2);
            barcos.agregar(*nuevoBPes);
        }
    } else {
        throw std::invalid_argument("Ese barco ya está en el sistema");
    }
}

listaDtPuertos Sistema::listarPuertos(){
    Puerto** losPuertos = puertos.getArray();
    listaDtPuertos res(puertos.getTope() );
    for (int i = 1; i <= puertos.getTope(); ++i){
        string resId = losPuertos[i]->getId();
        string resNombre = losPuertos[i]->getNombre();
        DtFecha resFecha = losPuertos[i]->getFechaCreacion();
        int resCantArribos = losPuertos[i]->getArribos().getTope();
        DtPuerto puertoI(resId, resNombre, resFecha, resCantArribos);
        res.getArray()[i] = puertoI;
    }
    return res;
}

void Sistema::agregarArribo(string idPuerto, string idBarco, float cargaDespacho){
    if (!existeIdPuerto(idPuerto)){
        throw std::invalid_argument("\nError: Ese puerto no existe en el sistema.\n");
    }
    if (!existeIdBarco(idBarco)){
        throw std::invalid_argument("\nError: Ese barco no existe en el sistema.\n");
    }
    Puerto* elPuerto = getPuerto(idPuerto);
    if (elPuerto->getArribos().getTope() == 30){
        throw std::invalid_argument("\nError: No se pueden agregar más arribos en este puerto.\n");
    }
    Barco* elBarco = getBarco(idBarco);
    DtFecha fechaActual = getFechaActual();
    Arribo* nuevoArribo;
    /* Downcast de elBarco */
    BarcoPasajeros* bPas = dynamic_cast<BarcoPasajeros*>(elBarco);
    BarcoPesquero* bPes = dynamic_cast<BarcoPesquero*>(elBarco);
    if (bPas != NULL){
        if (cargaDespacho != 0){
            throw std::invalid_argument("\nError: Los barcos de pasajeros no tienen carga. Usar carga = 0.\n");
        }
        DtBarcoPasajeros* dtBpas = new DtBarcoPasajeros(bPas->getNombre(), bPas->getId(), bPas->getCantPasajeros(), bPas->getTamanio() );
        DtArribo DtA = DtArribo(fechaActual, cargaDespacho, dtBpas);
        nuevoArribo = new Arribo(DtA);
        nuevoArribo->setBarco(*elBarco);
        delete dtBpas;
    } else if (bPes != NULL){
        if ((bPes->getCarga() - cargaDespacho < 0) || (bPes->getCarga() - cargaDespacho > bPes->getCapacidad() )){
            throw std::invalid_argument("\nError: No se puede cargar/descargar esa cantidad.\n");
        }
        elBarco->arribar(cargaDespacho);
        DtBarcoPesquero* dtBpes = new DtBarcoPesquero(bPes->getNombre(), bPes->getId(), bPes->getCapacidad(), bPes->getCarga() );
        DtArribo DtA = DtArribo(fechaActual, cargaDespacho, dtBpes);
        nuevoArribo = new Arribo(DtA);
        nuevoArribo->setBarco(*elBarco);
        delete dtBpes;
    }
    elPuerto->getArribos().agregar(*nuevoArribo);
}

listaDtArribos Sistema::obtenerInfoArribosEnPuerto(string idPuerto){
	if (existeIdPuerto(idPuerto)){	
	//cout << "\nHola.\n";
	int i=1;	
	Puerto** losPuertos = puertos.getArray();
// 	std::cout << "\nHola.\n";
// 	std::cout << losPuertos[i]->getArribos().getTope() << std::endl;
		while((puertos.getTope() >= i)&&(puertos.getArray()[i]->getId() != idPuerto)){
			i++;
// 			std::cout<< i;
		}
	
	int resCantArribos = losPuertos[i]->getArribos().getTope();
// 	std::cout<< resCantArribos;
	listaDtArribos res(resCantArribos);	
	listaArribos& L1=losPuertos[i]->getArribos();
	
		for(int j=1;j<=L1.getTope();j++){
		DtArribo Arribo1(L1.getArray()[j]->getFecha(),L1.getArray()[j]->getCarga(),L1.getArray()[j]->getDtBarco());
		DtArribo* Arribo2;
		Arribo2 =new DtArribo(Arribo1);
		res.agregar(*Arribo2);
		}		
	return res;
      } else {
          throw std::invalid_argument("\nError: Ese puerto no está en el sistema.");
      }
}

void Sistema::eliminarArribos(string idPuerto, const DtFecha& fecha){
}

listaDtBarcos Sistema::listarBarcos(){
    listaDtBarcos res(barcos.getTope() );
    for (int i = 1; i <= barcos.getTope(); ++i){
        Barco* barcoI = barcos.getArray()[i];
        string nombreI = barcoI->getNombre();
        string idI = barcoI->getId();
        BarcoPasajeros* bPas = dynamic_cast<BarcoPasajeros*>(barcoI);
        BarcoPesquero* bPes = dynamic_cast<BarcoPesquero*>(barcoI);
        if (bPas != NULL){
            int cantPasI = bPas->getCantPasajeros();
            TipoTamanio tamI = bPas->getTamanio();
            DtBarcoPasajeros* nuevoBpas = new DtBarcoPasajeros(nombreI,idI,cantPasI,tamI);
            res.agregar(*nuevoBpas);
        } else if (bPes != NULL){
            int capI = bPes->getCapacidad();
            int cargaI = bPes->getCarga();
            DtBarcoPesquero* nuevoBpes = new DtBarcoPesquero(nombreI,idI,capI,cargaI);
            res.agregar(*nuevoBpes);
        }
    }
    return res;
}
