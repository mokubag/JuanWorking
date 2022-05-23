#ifndef DT_BARCO_H
#define DT_BARCO_H

#include <string>

using std::string;

class DtBarco{
    private:
        string nombre;
        string id;
    public:
        DtBarco();
        DtBarco(string nombre, string id);
        virtual ~DtBarco();    //Destructor abstracto.
        string getNombre();
        string getId();
};

#endif
