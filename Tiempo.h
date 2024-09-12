#ifndef TIEMPO_H
#define TIEMPO_H
#include <iostream>
#include "Utils.h" // Funciones globales

using namespace std;


class Tiempo
{
    public:
        Tiempo();
        virtual ~Tiempo();

        // Setters
        void setFecha();
        void setHora();

        // Getters
        string getFecha();
        string getHora();

    protected:

    private:
        // Atributos
        string fecha, hora;
};

#endif // TIEMPO_H
