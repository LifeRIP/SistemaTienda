#ifndef CLIENTE_H
#define CLIENTE_H
#include "Persona.h"


class Cliente: public Persona
{
    public:
        Cliente();
        virtual ~Cliente();

        // Sobrecarga de constructor
        Cliente(string, string, long, string); // numID, contrasena, puntos, membresia

        // Setters
        void setPuntos();
        void setPuntos(long);
        void setMembresia(int);

        // Getters
        long getPuntos();
        string getMembresia();
        string getInfo();

    protected:

    private:
        // Atributos
        long puntos;
        string membresia;
};

#endif // CLIENTE_H
