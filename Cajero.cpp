#include "Cajero.h"
#include "Trabajador.h"

Cajero::Cajero()
{
    //ctor
    salario = numCaja = 0;
}

Cajero::Cajero(string _numID, string _contrasena)
{
    // Sobrecarga de constructor
    numID = _numID;
    contrasena = _contrasena;
    estado = true;
    numCaja = salario = 0;
    apellido = nombre = email = telefono = jornada = "-";
}

Cajero::~Cajero()
{
    //dtor
}

// Setters
void Cajero::setNumCaja()
{
    cout << "\tIngrese el numero de caja: ";
    cin >> numCaja;
}

void Cajero::setNumCaja(int _numCaja)
{
    numCaja = _numCaja;
}

int Cajero::getNumCaja()
{
    return numCaja;
}

// Getters
string Cajero::getInfo()
{
    return Trabajador::getInfo() + "\n" +
           "\tNumero de caja: " + to_string(numCaja);
}
