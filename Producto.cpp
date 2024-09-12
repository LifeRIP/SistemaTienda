#include "Producto.h"

Producto::Producto()
{
    //ctor
    cantidad = valor = valorDesc = descuento = productoID = 0;
    nombre = marca = "-";
}

Producto::Producto(string _nombre, string _marca, int _cantidad, long _valor, int _descuento, long _productoID)
{
    // Sobrecarga de constructor
    nombre = _nombre;
    cantidad = _cantidad;
    valor = _valor;
    descuento = _descuento;
    setValorDesc();
    productoID = _productoID;
    marca = _marca;
}

Producto::~Producto()
{
    //dtor
}

// Setters
void Producto::setNombre()
{
    fflush(stdin);
    cout << "\tIngrese el nombre del producto: ";
    getline(cin, nombre);
}

void Producto::setProductoID()
{
    cout << "\tIngrese el id del producto: ";
    cin >> productoID;
}

void Producto::setProductoID(long _productoID)
{
    productoID = _productoID;
}

void Producto::setMarca()
{
    fflush(stdin);
    cout << "\tIngrese la marca del producto: ";
    getline(cin, marca);
}

void Producto::setCantidad()
{
    cout << "\tIngrese la cantidad de ejemplares del producto: ";
    cin >> cantidad;
}

void Producto::setCantidad(int _cantidad)
{
    cantidad = _cantidad;
}

void Producto::setValor()
{
    cout << "\tIngrese el valor unitario del producto: ";
    cin >> valor;
}

void Producto::setDescuento()
{
    bool repite = true;
    while(repite)
    {
        cout << "\tIngrese el descuento del producto en porcentaje: ";
        cin >> descuento;
        if(descuento < 0 || descuento > 100)
            cout << "\tIngrese un valor entre [0 - 100]";
        else
            repite = false;
    }
}

void Producto::setValorDesc()
{
    if(descuento != 0)
        valorDesc = round(valor - (valor * (double(descuento) / 100)));
    else
        valorDesc = valor;
}

// Getters
string Producto::getNombre()
{
    return nombre;
}

long Producto::getProductoID()
{
    return productoID;
}

string Producto::getMarca()
{
    return marca;
}

int Producto::getCantidad()
{
    return cantidad;
}

long Producto::getValor()
{
    return valor;
}

int Producto::getDescuento()
{
    return descuento;
}

long Producto::getValorDesc()
{
    return valorDesc;
}

string Producto::getInfo()
{
    return "\tNombre: " + nombre + "\n" +
           "\tProducto ID: " + to_string(productoID) + "\n" +
           "\tMarca: " + marca + "\n" +
           "\tCantidad: " + to_string(cantidad) + "\n" +
           "\tValor c/u: $" + to_string(valor) + "\n" +
           "\tDescuento: " + to_string(descuento) + "%\n" +
           "\tValor c/u + Descuento: $" + to_string(valorDesc) + "\n";
}
