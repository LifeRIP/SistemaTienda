#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H
#include "Trabajador.h"


class Administrador: public Trabajador
{
    public:
        Administrador();
        virtual ~Administrador();

        // Sobrecarga de constructor
        Administrador(string, string); // numID, contrasena

        // Setters
        void setNumDepto();
        void setNumDepto(int);

        // Getters
        int getNumDepto();
        string getInfo();

    protected:

    private:
        int numDepto;
};

#endif // ADMINISTRADOR_H
