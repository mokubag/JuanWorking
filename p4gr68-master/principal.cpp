#include "include/classes/Sistema.h"
#include "include/classes/Arribo.h"
#include "include/classes/Barco.h"
#include "include/classes/BarcoPasajeros.h"
#include "include/classes/BarcoPesquero.h"
#include "include/classes/Puerto.h"
#include "include/classes/Colecciones.h"

#include "include/dataTypes/DtArribo.h"
#include "include/dataTypes/DtBarco.h"
#include "include/dataTypes/DtBarcoPasajeros.h"
#include "include/dataTypes/DtBarcoPesquero.h"
#include "include/dataTypes/DtFecha.h"
#include "include/dataTypes/DtPuerto.h"
#include "include/dataTypes/TipoTamanio.h"

#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>

#define MAX_BARCOS 30
#define MAX_PUERTOS 10

using std::cin;
using std::cout;
using std::endl;

float abs(float x){
    return (x >= 0) ? x : -x;
}

std::ostream & operator<<(std::ostream &out, TipoTamanio t){
    switch (t){
        case 0 :
            cout << "Bote";
            break;
        case 1 :
            cout << "Crucero";
            break;
        case 2 :
            cout << "Galeón";
            break;
        case 3 :
            cout << "Transatlántico";
            break;
    }
    return out;
}

std::ostream & operator<<(std::ostream &out, DtBarco &b){
    cout << "\nID: " << b.getId()
    << "\nNombre: " << b.getNombre()
    << "\nTipo de barco: ";
    DtBarco* pb = &b;
    DtBarcoPasajeros* pas = dynamic_cast<DtBarcoPasajeros*>(pb);
    DtBarcoPesquero* pes = dynamic_cast<DtBarcoPesquero*>(pb);
    if (pas != NULL){
        cout << "Pasajeros.\n"
        << "    Cantidad de pasajeros: " << pas->getCantPasajeros()
        << "\n    Tamaño: " << pas->getTamanio() << ".\n";
    } else if (pes != NULL){
        cout << "Pesquero.\n"
        << "    Capacidad: " << pes->getCapacidad()
        << "\n    Carga: " << pes->getCarga() << "\n";
    }
    return out;
}

std::ostream & operator<<(std::ostream &out, DtFecha f){
    cout << std::setfill('0') << std::setw(2) << f.getDia() << "/" 
    << std::setfill('0') << std::setw(2) << f.getMes() << "/"
    << f.getAnio();
    return out;
}

std::ostream & operator<<(std::ostream &out, DtPuerto p){
    cout << "\nNombre: " << p.getNombre()
    << "\nID: " << p.getId()
    << "\nFecha de creación: " << p.getFechaCreacion()
    << "\nCantidad de arribos: " << p.getCantArribos() << "\n";
    return out;
}


std::ostream & operator<<(std::ostream &out, DtArribo a){
    cout << "\n" << a.getFecha() << "\n"
    << a.getBarco()->getNombre() << "(Id: " << a.getBarco()->getId() << ") ";
    if (a.getCarga() == 0){
         cout << "no realizó carga/descarga.\n";
    } else if (a.getCarga() < 0){
        cout << "cargó " << -1 * a.getCarga() << " unidades.\n";
    } else {
        cout << "descargó " << a.getCarga() << " unidades.\n";
    }
    return out;
}

TipoTamanio str2tam(string str){
    if ((str == "Bote")||(str == "bote")){
        return bote;
    } else if ((str == "Crucero")||(str == "crucero")){
        return crucero;
    } else if ((str == "Galeón")||(str == "galeón")||(str == "Galeon")||(str == "galeon")){
        return galeon;
    } else if ((str == "Transatlántico")||(str == "transatlántico")||(str == "Transatlantico")||(str == "transatlantico")){
        return transatlantico;
    } else {
        throw std::invalid_argument("errorTamanio");
    }
}

int main(){
    Sistema sys(MAX_BARCOS, MAX_PUERTOS);
    cout << "\nBienvenido. Elija la opción.\n";
    cout << "\t1) Agregar puerto.\n\t2) Agregar barco.\n\t3) Listar puertos.\n";
    cout << "\t4) Agregar arribo.\n\t5) Obtener información de arribos.\n\t6) Eliminar arribos.\n";
    cout << "\t7) Listar barcos.\n\t0) Salir.\n";
    int entrada;
    cin >> entrada;
    
    int cantPuertos = sys.getPuertos().getTope();
    int cantBarcos = sys.getBarcos().getTope();
    while (entrada != 0){
        switch (entrada){
            case 1 :{
                if (cantPuertos < MAX_PUERTOS){
                    cout << "\nIntroduzca información del puerto en el siguiente formato:\n";
                    cout << "ID Nombre Fecha_de_creación (dia mes año)\n";
                    string nuevoPId;
                    string nuevoPNombre;
                    string nuevoPDia;
                    string nuevoPMes;
                    string nuevoPAnio;
                    cin >> nuevoPId >> nuevoPNombre >> nuevoPDia >> nuevoPMes >> nuevoPAnio;
                    try{
                        DtFecha nuevoPFecha(std::stoi(nuevoPDia), std::stoi(nuevoPMes), std::stoi(nuevoPAnio));
                        try {
                            sys.agregarPuerto(nuevoPId, nuevoPNombre, nuevoPFecha);
                            cantPuertos++;
                            cout << "\nPuerto agregado con éxito.\n";
                        } catch (std::invalid_argument &err){
                            std::cerr << "\nError: Esa id ya está registrada en el sistema.\n";
                        }
                    } catch (std::invalid_argument &err){
                        std::cerr << "\nError: Fecha inválida.\n";
                    }
                } else {
                    std::cerr << "\nNo se pueden agregar más puertos.\n";
                }
                break;
            } case 2 :{
                if (cantBarcos < MAX_BARCOS){
                    DtBarco* nuevoDtB;  //Tipo estático
                    cout << "\nIntoruzca información del barco en el siguiente formato:\n";
                    cout << "Nombre ID Tipo (Pasajeros/Pesquero)\n";
                    string nuevoBNombre;
                    string nuevoBId;
                    string nuevoBTipo;
                    cin >> nuevoBNombre >> nuevoBId >> nuevoBTipo;
                    if ((nuevoBTipo == "Pasajeros") || (nuevoBTipo == "pasajeros")){
                        cout << "Introduzca el resto de información.\n";
                        cout << "Cantidad_de_pasajeros Tamaño (bote/crucero/galeón/transatlántico)\n";
                        string nuevoBCantPas;
                        string nuevoBTam;
                        cin >> nuevoBCantPas >> nuevoBTam;
                        try {
                            nuevoDtB = new DtBarcoPasajeros(nuevoBNombre, nuevoBId, std::stoi(nuevoBCantPas), str2tam(nuevoBTam));
                            try {
                                sys.agregarBarco(*nuevoDtB);
                                cantBarcos++;
                                cout << "\nBarco agregado con éxito.\n";
                            } catch (std::invalid_argument &err){
                                std::cerr << "\nError: Esa id ya está registrada en el sistema.\n";
                            }
                            delete nuevoDtB;
                        } catch (std::invalid_argument &err){
                            std::cerr << "\nError: Tamaño de barco o cantidad de carga inválidos.\n";
                        }
                    } else if ((nuevoBTipo == "Pesquero") || (nuevoBTipo == "pesquero")){
                        cout << "Introduzca el resto de información.\n";
                        cout << "Capacidad Carga\n";
                        string nuevoBCapacidad;
                        string nuevoBCarga;
                        cin >> nuevoBCapacidad >> nuevoBCarga;
                        if (std::stoi(nuevoBCarga) > std::stoi(nuevoBCapacidad) ){
                            std::cerr << "\nError: La carga no puede ser mayor a la capacidad.\n";
                            break;
                        }
                        try {
                            nuevoDtB = new DtBarcoPesquero(nuevoBNombre, nuevoBId, std::stoi(nuevoBCapacidad), std::stoi(nuevoBCarga));
                            try {
                                sys.agregarBarco(*nuevoDtB);
                                cantBarcos++;
                                cout << "\nBarco agregado con éxito.\n";
                            } catch (std::invalid_argument &err){
                                std::cerr << "Error: Esa id ya estaba registrada en el sistema.\n";
                            }
                            delete nuevoDtB;
                        } catch (std::invalid_argument &err){
                            std::cerr << "Error: Capacidad o carga inválidas.\n";
                        }
                    } else {
                        std::cerr << "\nError: Tipo no válido.\n";
                    }
                }
                else {
                    std::cerr << "\nNo se pueden agregar más Barcos.\n";
                }
                break;
            } case 3 : {
                if (cantPuertos == 0){
                    cout << "\nNo hay puertos en el sistema.\n";
                } else {
                    listaDtPuertos losDtPuertos = sys.listarPuertos();
                    for (int i = 1; i <= cantPuertos; ++i){
                        cout << losDtPuertos.getArray()[i];
                    }
                }
                break;
            } case 4 : {
                cout << "\nIngrese información sobre el arribo, en el siguiente formato:";
                cout << "\nID(puerto) ID(barco) motivo(cargar/descargar) cantidad(de carga)\n";
                string idb;
                string idp;
                string motivo;
                string strCarga;
                cin >> idp >> idb >> motivo >> strCarga;
                float carga;
                if (std::isdigit(strCarga.front() )){
                    if ((motivo == "cargar") || (motivo == "Cargar")){
                        carga = -1 * abs(std::stof(strCarga));
                        try{
                            sys.agregarArribo(idp, idb, carga);
                            cout << "\nArribo agregado con éxito.\n";
                        } catch (std::invalid_argument &err){
                            std::cerr << err.what();
                        }
                    } else if ((motivo == "descargar") || (motivo == "Descargar")){
                        carga = abs(std::stof(strCarga));
                        try{
                            sys.agregarArribo(idp, idb, carga);
                            cout << "\nArribo agregado con éxito.\n";
                        } catch (std::invalid_argument &err){
                            std::cerr << err.what();
                        }
                    } else {
                        std::cerr << "\nError: Motivo no válido, solo cargar/descargar (uso indistinto para barcos de pasajeros).\n";
                    }
                } else {
                    std::cerr << "\nError: Carga inválida, debe ser un número (sin signos).\n";
                }
                break;
            } case 5 : {
                string idPuerto;		
		cout << "\nIngrese la id del puerto:\n";
		cin >> idPuerto;
		try {
			listaDtArribos ListDeArribos =sys.obtenerInfoArribosEnPuerto(idPuerto);
			for (int i = 1; i <= ListDeArribos.getTope(); ++i){
                        cout << ListDeArribos.getArray()[i];
                    	}
                     } 
		catch (std::invalid_argument &err){
                            std::cerr << "\nError: Esa id no está registrada en el sistema.\n";
                     }		
                break;
            } case 6 : {
                cout << "\nEliminados.\n";
                break;
            } case 7 : {
                if (cantBarcos == 0){
                    cout << "\nNo hay barcos en el sistema.\n";
                } else {
                    listaDtBarcos losDtBarcos(sys.listarBarcos() );
                    for (int k = 1; k <= cantBarcos; ++k){
                        cout << *(losDtBarcos.getArray()[k]);
                    }
                }
                break;
            }
        }
               
        cout << "\nElija la opción.\n";
        cout << "\t1) Agregar puerto.\n\t2) Agregar barco.\n\t3) Listar puertos.\n";
        cout << "\t4) Agregar arribo.\n\t5) Obtener información de arribos.\n\t6) Eliminar arribos.\n";
        cout << "\t7) Listar barcos.\n\t0) Salir.\n";            
        cin >> entrada;
    }
    return 0;
}
