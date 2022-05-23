/* Declaración de arreglos con tope de DtArribo, DtBarco, DtPuerto y
 * de punteros a Arribo, Barco y Puerto
 */

#ifndef COLLECTIONS_H
#define COLLECTIONS_H

#include "../dataTypes/DtArribo.h"

/* Declaración de los arreglos. */

class listaDtArribos{
    private:
        DtArribo** array;
        int tope;
    public:
        listaDtArribos();
        listaDtArribos(int);
        listaDtArribos(const listaDtArribos&);
        ~listaDtArribos();
        DtArribo** getArray();
        int getTope();
        void agregar(DtArribo&);
        void eliminar(int pos);
	void SubirTope();
};

#include "../dataTypes/DtBarco.h"

class listaDtBarcos{
    private:
        DtBarco** array;
        int tope;
    public:
        listaDtBarcos();
        listaDtBarcos(int);
        listaDtBarcos(const listaDtBarcos&);
        ~listaDtBarcos();
        DtBarco** getArray();
        int getTope();
        void agregar(DtBarco&);
        void eliminar(int pos);
};

#include "../dataTypes/DtPuerto.h"

class listaDtPuertos{
    private:
        DtPuerto* array;
        int tope;
    public:
        listaDtPuertos();
        listaDtPuertos(int);
        listaDtPuertos(const listaDtPuertos&);
        ~listaDtPuertos();
        DtPuerto* getArray();
        int getTope();
        void agregar(DtPuerto&);
        void eliminar(int pos);
};

#include "Arribo.h"

class listaArribos{
    private:
        Arribo** array;
        int tope;
    public:
        listaArribos();
        listaArribos(int);
        listaArribos(const listaArribos&);
        ~listaArribos();
        Arribo** getArray();
        int getTope();
        void agregar(Arribo&);
        void eliminar(int pos);
};

#include "Barco.h"

class listaBarcos{
    private:
        Barco** array;
        int tope;
    public:
        listaBarcos();
        listaBarcos(int);
        listaBarcos(const listaBarcos&);
        ~listaBarcos();
        Barco** getArray();
        int getTope();
        void agregar(Barco&);
        void eliminar(int pos);
};

#include "Puerto.h"

class Puerto;

class listaPuertos{
    private:
        Puerto** array;
        int tope;
    public:
        listaPuertos();
        listaPuertos(int);
        listaPuertos(const listaPuertos&);
        ~listaPuertos();
        Puerto** getArray();
        int getTope();
        void agregar(Puerto&);
        void eliminar(int pos);
};

#endif
