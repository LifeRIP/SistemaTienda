#include "Proveedor.h"

Proveedor::Proveedor()
{
    //ctor
    numCamiones = 0;
}

Proveedor::Proveedor(string _numID, string _contrasena)
{
    // Sobrecarga de constructor
    numID = _numID;
    contrasena = _contrasena;
    estado = true;
    numCamiones = 0;
    apellido = nombre = email = telefono = "-";
}

Proveedor::~Proveedor()
{
    //dtor
}

// Setters
void Proveedor::setNumCamiones()
{
    cout << "\tIngrese el numero de camiones disponibles: ";
    cin >> numCamiones;
}

// Getters
int Proveedor::getNumCamiones()
{
    return numCamiones;
}

string Proveedor::getInfo()
{
    return Persona::getInfo() + "\n" +
           "\tNumero de camiones: " + to_string(numCamiones);
}
