#ifndef PRODUCTO_H
#define PRODUCTO_H
#include <iostream>
#include <math.h> // round
#include "Utils.h"

using namespace std;


class Producto
{
    public:
        Producto();
        virtual ~Producto();

        // Sobrecarga de constructor
        Producto(string, string, int, long, int, long); // nombre, marca, cantidad, valor, descuento, productoID

        // Setters
        void setNombre();
        void setProductoID();
        void setProductoID(long);
        void setMarca();
        void setCantidad();
        void setCantidad(int);
        void setValor();
        void setDescuento();
        void setValorDesc();

        // Getters
        string getNombre();
        long getProductoID();
        string getMarca();
        int getCantidad();
        long getValor();
        int getDescuento();
        long getValorDesc();
        string getInfo();

    protected:

    private:
        // Atributos
        string nombre, marca;
        int cantidad, descuento;
        long valor, productoID;
        long valorDesc;
};

#endif // PRODUCTO_H
