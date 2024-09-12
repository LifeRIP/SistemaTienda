#ifndef TRABAJADOR_H
#define TRABAJADOR_H
#include "Persona.h"

class Trabajador: public Persona
{
    public:
        Trabajador();
        virtual ~Trabajador();

        // Setters
        void setSalario();
        void setSalario(long);
        void setJornada(int);

        // Getters
        long getSalario();
        string getJornada();
        string getInfo();

    protected:
        // Atributos
        long salario;
        string jornada;

    private:
};

#endif // TRABAJADOR_H
