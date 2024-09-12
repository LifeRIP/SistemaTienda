#include "Supervisor.h"
#include "Trabajador.h"

Supervisor::Supervisor()
{
    //ctor
    numOficina = 0;
}

Supervisor::Supervisor(string _numID, string _contrasena)
{
    // Sobrecarga de constructor
    numID = _numID;
    contrasena = _contrasena;
    estado = true;
    numOficina = salario = 0;
    apellido = nombre = email = telefono = jornada = "-";
}

Supervisor::~Supervisor()
{
    //dtor
}

// Setters
void Supervisor::setNumOficina()
{
    cout << "\tIngrese el numero de oficina: ";
    cin >> numOficina;
}

void Supervisor::setNumOficina(int _numOficina)
{
    numOficina = _numOficina;
}

// Getters
int Supervisor::getNumOficina()
{
    return numOficina;
}

string Supervisor::getInfo()
{
    return Trabajador::getInfo() + "\n" +
           "\tNumero de oficina: " + to_string(numOficina);
}
