#ifndef PEDIDO_H
#define PEDIDO_H
#include "Producto.h"
#include "Tiempo.h"


class Pedido
{
    public:
        Pedido();
        virtual ~Pedido();

        // Objeto tiempo
        Tiempo objTiempo = Tiempo();

        // Sobrecarga de constructor
        Pedido(string, string, int, long, long, long, bool); // nombre, marca, cantidad, valor, pedidoID, productoID, estado

        // Setters
        void setTiempo();
        void setNombreP();
        void setPedidoID();
        void setPedidoID(long);
        void setProductoIDP();
        void setProductoIDP(long);
        void setMarcaP();
        void setCantidadP();
        void setCantidadP(int);
        void setValorP();
        void setEstadoP(bool);

        //Getters
        string getNombreP();
        long getPedidoID();
        long getProductoIDP();
        string getMarcaP();
        int getCantidadP();
        long getValorP();
        bool getEstadoP();
        string getInfoP();

    protected:
        bool estadoP;

    private:
         // Atributos
        string nombreP, marcaP;
        int cantidadP;
        long valorP, productoIDP, pedidoID;


};

#endif // PEDIDO_H
