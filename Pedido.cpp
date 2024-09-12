#include<iostream>
using namespace std;

#include "Pedido.h"

Pedido::Pedido()
{
    //ctor
    cantidadP= valorP = productoIDP = 0;
    nombreP = marcaP = "-";
    estadoP = 0;
}

Pedido::Pedido(string _nombreP, string _marcaP, int _cantidadP, long _valorP, long _pedidoID, long _productoIDP, bool _estadoP)
{
    // Sobrecarga de constructor
    nombreP = _nombreP;
    cantidadP = _cantidadP;
    valorP = _valorP;
    productoIDP = _productoIDP;
    marcaP = _marcaP;
    estadoP = _estadoP;
    pedidoID = _pedidoID;
}

Pedido::~Pedido()
{
    //dtor
}

//Setter

void Pedido::setTiempo()
{
    objTiempo.setFecha();
    objTiempo.setHora();
}

void Pedido::setPedidoID()
{
    cout << "\tIngrese el id del pedido: ";
    cin >> pedidoID;

}

void Pedido::setPedidoID(long _pedidoID)
{
    pedidoID = _pedidoID;
}

void Pedido::setNombreP()
{
    fflush(stdin);
    cout << "\tIngrese el nombre del producto a pedir: ";
    getline(cin, nombreP);
}

void Pedido::setProductoIDP()
{
    cout << "\tIngrese el id del producto a pedir: ";
    cin >> productoIDP;

}

void Pedido::setProductoIDP(long _productoIDP)
{
    productoIDP = _productoIDP;
}

void Pedido::setMarcaP()
{
    fflush(stdin);
    cout << "\tIngrese la marca del producto a pedir: ";
    getline(cin, marcaP);
}

void Pedido::setCantidadP()
{
    cout << "\tIngrese la cantidad de ejemplares del producto a pedir: ";
    cin >> cantidadP;
}

void Pedido::setCantidadP(int _cantidadP)
{
    cantidadP = _cantidadP;
}

void Pedido::setValorP()
{
    cout << "\tIngrese el valor unitario del producto a pedir: ";
    cin >> valorP;
}

void Pedido::setEstadoP(bool _estadoP){
    estadoP = _estadoP;
}

// Getters
string Pedido::getNombreP()
{
    return nombreP;

}

long Pedido::getPedidoID()
{
    return pedidoID;
}

long Pedido::getProductoIDP()
{
    return productoIDP;
}

string Pedido::getMarcaP()
{
    return marcaP;
}

int Pedido::getCantidadP()
{
    return cantidadP;
}

long Pedido::getValorP()
{
    return valorP;
}

bool Pedido::getEstadoP()
{
    return estadoP;
}

string Pedido::getInfoP()
{
    string tmpEstadoP = estadoP? "Enviado" : "En Espera";
    return "\tFecha: " + objTiempo.getFecha() + "\n" +
           "\tHora: " + objTiempo.getHora() + "\n" +
           "\tPedido ID: " + to_string(pedidoID) + "\n" +
           "\tEstado: " + tmpEstadoP + "\n" +
           "\tNombre: " + nombreP + "\n" +
           "\tProducto ID: " + to_string(productoIDP) + "\n" +
           "\tMarca: " + marcaP + "\n" +
           "\tCantidad: " + to_string(cantidadP) + "\n" +
           "\tValor c/u: $" + to_string(valorP) + "\n";
}
