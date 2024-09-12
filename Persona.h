#ifndef PERSONA_H
#define PERSONA_H
#include <iostream>
#include "Utils.h" // Funciones globales

using namespace std;

class Persona
{
    public:
        Persona();
        virtual ~Persona();

        // Setters
        void setApellido();
        void setNombre();
        void setEmail();
        void setTelefono();
        void setNumID();
        void setContrasena();
        void setEstado(int);
        void setEstado(bool);

        // Getters
        string getApellido();
        string getNombre();
        string getEmail();
        string getTelefono();
        string getNumID();
        string getContrasena();
        bool getEstado();

        // Metodos
        virtual string getInfo();

    protected:
        // Atributos
        string apellido, nombre, email, contrasena, telefono, numID;
        bool estado;

    private:
};

#endif // PERSONA_H
