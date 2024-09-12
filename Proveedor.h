#ifndef PROVEEDOR_H
#define PROVEEDOR_H
#include "Persona.h"


class Proveedor: public Persona
{
    public:
        Proveedor();
        virtual ~Proveedor();

        // Sobrecarga de constructor
        Proveedor(string, string); // numID, contrasena

        // Setters
        void setNumCamiones();

        // Getters
        int getNumCamiones();
        string getInfo();

    protected:

    private:
        int numCamiones;
};

#endif // PROVEEDOR_H
