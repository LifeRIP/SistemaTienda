#ifndef CAJERO_H
#define CAJERO_H
#include "Trabajador.h"

class Cajero: public Trabajador
{
    public:

        Cajero();
        virtual ~Cajero();

        // Sobrecarga de constructor
        Cajero(string, string); // numID, contrasena

        // Setters
        void setNumCaja();
        void setNumCaja(int);

        // Getters
        int getNumCaja();
        string getInfo();

    protected:

    private:
        int numCaja;
};

#endif // CAJERO_H
