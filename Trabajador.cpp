#include "Trabajador.h"

Trabajador::Trabajador()
{
    //ctor
    salario = 0;
    jornada = "-";
}

Trabajador::~Trabajador()
{
    //dtor
}

void Trabajador::setSalario()
{
    cout << "\tIngrese el salario: ";
    cin.ignore();
    cin >> salario;
}

void Trabajador::setSalario(long _salario)
{
    salario = _salario;
}

void Trabajador::setJornada(int posy)
{
    /*fflush(stdin);
    cout << "\tIngrese la jornada laboral [1. Ma" << enye() << "ana - 0. Tarde]: ";
    getline(cin, jornada);
    jornada = toUpperFirst(jornada);*/
    bool repite = true;
    int opc;
    do
    {
        cout << "\tIngrese la jornada laboral [1. Ma" << enye() << "ana - 0. Tarde]: ";
        cin >> opc;
        switch(opc)
        {
        case 0:
            jornada = "Tarde";
            repite = false;
            break;
        case 1:
            jornada = "Mañana";
            repite = false;
            break;
        default:
            gotoxy(59, posy);
            cout << "      ";
            gotoxy(0, posy);
            break;
        }
    }
    while(repite);
}

long Trabajador::getSalario()
{
    return salario;
}

string Trabajador::getJornada()
{
    return jornada;
}

string Trabajador::getInfo()
{
    string tmpJornada1, tmpJornada2;
    if(jornada == "Mañana")
    {
        tmpJornada1 = "Ma";
        tmpJornada2 = "ana";
        return Persona::getInfo() + "\n" +
               "\tSalario: " + to_string(salario) + "\n" +
               "\tJornada laboral: " + tmpJornada1 + enye() + tmpJornada2;
    }
    else
        return Persona::getInfo() + "\n" +
               "\tSalario: " + to_string(salario) + "\n" +
               "\tJornada laboral: " + jornada;
}
