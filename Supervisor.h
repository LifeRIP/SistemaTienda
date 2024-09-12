#ifndef SUPERVISOR_H
#define SUPERVISOR_H
#include "Trabajador.h"

class Supervisor: public Trabajador //Herencia
{
    public:
        Supervisor();
        virtual ~Supervisor();

        // Sobrecarga de constructor
        Supervisor(string, string); // numID, contrasena

        // Setters
        void setNumOficina();
        void setNumOficina(int);

        // Getters
        int getNumOficina();
        string getInfo();

    protected:

    private:
        int numOficina;
};

#endif // SUPERVISOR_H
