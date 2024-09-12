#include "Cliente.h"

Cliente::Cliente()
{
    //ctor
    puntos = 0;
    membresia = "-";
}

Cliente::Cliente(string _numID, string _contrasena, long _puntos, string _membresia)
{
    // Sobrecarga de constructor
    numID = _numID;
    contrasena = _contrasena;
    puntos = _puntos;
    membresia = _membresia;
    estado = true;
    apellido = nombre = email = telefono = "-";
}

Cliente::~Cliente()
{
    //dtor
}

// Setters
void Cliente::setPuntos()
{
    cout << "\tIngrese el numero de puntos: ";
    cin >> puntos;
}

void Cliente::setPuntos(long _puntos)
{
    puntos = _puntos;
}

void Cliente::setMembresia(int posy)
{
    /*fflush(stdin);
    cout << "\tIngrese el estado de la membresia [1. Activa - 0. Inactiva]: ";
    getline(cin, membresia);
    membresia = toUpperFirst(membresia);*/
    bool repite = true;
    int opc;
    do
    {
        cout << "\tIngrese el estado de la membresia [1. Activa - 0. Inactiva]: ";
        cin >> opc;
        switch(opc)
        {
        case 0:
            membresia = "Inactiva";
            repite = false;
            break;
        case 1:
            membresia = "Activa";
            repite = false;
            break;
        default:
            gotoxy(69, posy);
            cout << "      ";
            gotoxy(0, posy);
            break;
        }
    }
    while(repite);
}

// Getters
long Cliente::getPuntos()
{
    return puntos;
}

string Cliente::getMembresia()
{
    return membresia;
}

string Cliente::getInfo()
{
    return Persona::getInfo() + "\n" +
           "\tNumero de puntos: " + to_string(puntos) + "\n" +
           "\tMembresia: " + membresia;
}
