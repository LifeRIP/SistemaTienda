#include "Administrador.h"

Administrador::Administrador()
{
    //ctor
    numDepto = 0;
}

Administrador::Administrador(string _numID, string _contrasena)
{
    // Sobrecarga de constructor
    numID = _numID;
    contrasena = _contrasena;
    estado = true;
    numDepto = salario = 0;
    apellido = nombre = email = telefono = jornada = "-";
}

Administrador::~Administrador()
{
    //dtor
}

// Setters
void Administrador::setNumDepto()
{
    cout << "\tIngrese el numero de departamento: ";
    cin >> numDepto;
}

void Administrador::setNumDepto(int _numDepto)
{
    numDepto = _numDepto;
}

// Getters
int Administrador::getNumDepto()
{
    return numDepto;
}

string Administrador::getInfo()
{
    return Trabajador::getInfo() + "\n" +
           "\tNumero de departamento: " + to_string(numDepto);
}
