#include "Persona.h"
#include<iostream>
Persona::Persona()
{
    estado = 0;
    apellido = nombre = email = contrasena = telefono = numID = "-";
}

Persona::~Persona()
{
    //dtor
}

void Persona::setApellido(){
    fflush(stdin);
    cout<<"\tIngrese el apellido: ";
    getline(cin, apellido);
    apellido = toUpperFirst(toLower(apellido));
}

void Persona::setNombre(){
    fflush(stdin);
    cout<<"\tIngrese el nombre: ";
    getline(cin, nombre);
    nombre = toUpperFirst(toLower(nombre));
}

void Persona::setEmail(){
    fflush(stdin);
    cout<<"\tIngrese el email: ";
    getline(cin, email);
}

void Persona::setTelefono(){
    cout<<"\tIngrese el numero de telefono: ";
    cin>>telefono;
}

void Persona::setNumID(){
    cout<<"\tIngrese el numero de identificacion: ";
    cin>>numID;
}

void Persona::setContrasena(){
    fflush(stdin);
    cout<<"\tIngrese la contrase" << enye() << "a: ";
    getline(cin, contrasena);
}

void Persona::setEstado(int posy){
    bool repite = true;
    int opc;
    do
    {
        cout << "\tIngrese el estado del usuario [1. Activo - 0. Inactivo]: "; // No borrar los espacios
        cin >> opc;
        switch(opc)
        {
        case 0:
            estado = false;
            repite = false;
            break;
        case 1:
            estado = true;
            repite = false;
            break;
        default:
            gotoxy(65, posy);
            cout << "      ";
            gotoxy(0, posy);
            break;
        }
    }
    while(repite);
}

void Persona::setEstado(bool _estado){
    estado = _estado;
}

string Persona::getApellido(){
    return apellido;
}

string Persona::getNombre(){
    return nombre;
}

string Persona::getEmail(){
    return email;
}

string Persona::getTelefono(){
    return telefono;
}

string Persona::getNumID(){
    return numID;
}

string Persona::getContrasena(){
    return contrasena;
}

bool Persona::getEstado(){
    return estado;
}

string Persona::getInfo()
{
    string tmpEstado = estado? "Activo" : "Inactivo";
    return "\tEstado: " + tmpEstado + "\n" +
           "\tNombre: " + nombre + "\n" +
           "\tApellido: " + apellido + "\n" +
           "\tNumero de identificacion: " + numID + "\n" +
           "\tCorreo electronico: " + email + "\n" +
           "\tTelefono: " + telefono + "\n" +
           "\tContrase" + enye() + "a: " + char(177) + char(177) + char(177) + char(177) + char(177) + char(177);
}
