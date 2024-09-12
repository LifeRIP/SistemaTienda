#include "Tiempo.h"

Tiempo::Tiempo()
{
    //ctor
    fecha = hora = "-";
}

Tiempo::~Tiempo()
{
    //dtor
}

// Setters
void Tiempo::setFecha()
{
    fecha = fechaAct();
}

void Tiempo::setHora()
{
    hora = horaAct();
}

// Getters
string Tiempo::getFecha()
{
    return fecha;
}

string Tiempo::getHora()
{
    return hora;
}
