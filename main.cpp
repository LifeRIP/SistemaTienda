//Cabeceras
#include <iostream>
#include <vector>
#include "Utils.h" // Funciones globales

// Clases
#include "Persona.h"
#include "Trabajador.h"
#include "Administrador.h"
#include "Supervisor.h"
#include "Cajero.h"
#include "Proveedor.h"
#include "Cliente.h"
#include "Producto.h"
#include "Pedido.h"

using namespace std;

// Vectores
vector <Administrador> vecAdmins;
vector <Supervisor> vecSupervisores;
vector <Cajero> vecCajeros;
vector <Proveedor> vecProveedores;
vector <Cliente> vecClientes;
vector <Producto> vecInventario;
vector <Producto> vecVentas;
vector <Pedido> vecPedidos;
vector <Producto> vecFactura;

/*---------------------------------------------------------*/

/// Definición de funciones
// Menús
void menuAdmin();
void menuSupervisor();
void menuCajero();
void menuProveedor();
void menuCliente();

// SubMenús
void subMenuPersonaAdmin();
void subMenuPersonaSupervisor();
void subMenuPersonaCajero();

void subMenuProductoAdmin();
void subMenuProductoSupervisor();
void subMenuProductoCajero();
void subMenuProductoCliente();

void subMenuPedidoAdmin();
void subMenuPedidoSupervisor();
void subMenuPedidoProveedor();

void subMenuCierreAdmin();
void subMenuCierreSupervisor();

/*---------------------------------------------------------*/

// Funciones SubMenús
void listadoAdmin();
void listadoSupervisor();
void listadoCajero();
void listadoProveedor();
void listadoCliente();
void listadoProducto();
void listadoVentasDia();
void listadoCierreCaja();
void listadoPedido();

void consultarAdmin();
void consultarSupervisor();
void consultarCajero();
void consultarProveedor();
void consultarCliente();
void consultarProducto();
void consultarCierreCaja();
void consultarPedido();

void crearAdmin();
void crearSupervisor();
void crearCajero();
void crearProveedor();
void crearCliente();
void crearProducto();
void cierreCaja();
void crearPedido();

void devolverProducto();
void cambiarProducto();

void modificarAdmin();
void modificarSupervisor();
void modificarCajero();
void modificarProveedor();
void modificarCliente();
void modificarProducto();
void modificarCierreCaja();
void modificarPedido();

void desactivarAdmin();
void desactivarSupervisor();
void desactivarCajero();
void desactivarProveedor();
void desactivarCliente();
void desactivarProducto();
void desactivarCierreCaja();
void desactivarPedido();

void borrarAdmin();
void borrarSupervisor();
void borrarCajero();
void borrarProveedor();
void borrarCliente();
void borrarProducto();
void borrarCierreCaja();
void borrarPedido();

void venderProductos();
/*---------------------------------------------------------*/

// Funciones varias
void login();
void setUsuarios();
void setProductos();
void setPedidos();

/*---------------------------------------------------------*/

// Variables globales
string *tmpID = new string; // Puntero que almacena el ID del cliente que inicie sesion;

/*---------------------------------------------------------*/

// Función principal
int main()
{
    //setlocale(LC_ALL, "es_ES"); // Falla con los caracteres ASCII
    formatoConsola();
    setUsuarios();
    setProductos();
    setPedidos();
    login();


    return 0;
}

/*---------------------------------------------------------*/

// Implementación de funciones
void setUsuarios()
{
    Administrador adm = Administrador("123", "123"); // numID, contrasena
    vecAdmins.push_back(adm);
    Supervisor sup = Supervisor("123", "123"); // numID, contrasena
    vecSupervisores.push_back(sup);
    Cajero caj = Cajero("123", "123"); // numID, contrasena
    vecCajeros.push_back(caj);
    Proveedor pro = Proveedor("123", "123"); // numID, contrasena
    vecProveedores.push_back(pro);
    Cliente clt = Cliente("123", "123", 100, "Activa"); // numID, contrasena, puntos, membresia
    vecClientes.push_back(clt);
}

void setProductos()
{
    // INVENTARIO
    Producto prodInv = Producto("Monitor", "Asus", 5, 100000, 0, 0); // nombre, marca, cantidad, valor, descuento, productoID
    vecInventario.push_back(prodInv);
    Producto prodInv1 = Producto("Altavoces", "Logitech", 5, 30000, 0, 1); // nombre, marca, cantidad, valor, descuento, productoID
    vecInventario.push_back(prodInv1);
    Producto prodInv2 = Producto("Diademas", "Razer", 5, 50000, 0, 2); // nombre, marca, cantidad, valor, descuento, productoID
    vecInventario.push_back(prodInv2);
    Producto prodInv3 = Producto("Teclado", "VSG", 5, 90000, 0, 3); // nombre, marca, cantidad, valor, descuento, productoID
    vecInventario.push_back(prodInv3);
    Producto prodInv4 = Producto("Raton", "Redragon", 5, 70000, 0, 4); // nombre, marca, cantidad, valor, descuento, productoID
    vecInventario.push_back(prodInv4);
}

void setPedidos()
{
    // Pedido con producto existente
    Pedido ped1 = Pedido("Raton", "Redragon", 5, 70000, 0, 4, false); // nombre, marca, cantidad, valor, pedidoID, productoID, estado
    ped1.setTiempo();
    vecPedidos.push_back(ped1);
    // Pedido con producto nuevo
    Pedido ped2 = Pedido("Microfono", "HyperX", 5, 80000, 1, 5, false); // nombre, marca, cantidad, valor, pedidoID, productoID, estado
    ped2.setTiempo();
    vecPedidos.push_back(ped2);
}

void login()
{
    bool repite = true, existe = false;
    int opc;
    string usuarioBuscar;
    string contrasenaBuscar;
    do
    {
        marcoMenus("INICIO DE SESION");
        saltosLinea();
        cout << char(179);
        tituloLogin("\tTipo de usuario");
        cout << char(179) << "\t1. Administrador" << endl;
        cout << char(179) << "\t2. Supervisor" << endl;
        cout << char(179) << "\t3. Cajero" << endl;
        cout << char(179) << "\t4. Proveedor" << endl;
        cout << char(179) << "\t5. Cliente" << endl;
        cout << char(179) << "\t0. Salir" << endl << endl;
        cout << char(179) << "\tSeleccione una opcion: ";
        saltosLinea();
        saltosLinea();
        cout << "\n\n\n\n\n\n" << char(179) << "\t\t\t\t\t\t\t\t\t\t\t\t\t6. Acerca de...";
        gotoxy(31, 17);
        cin >> opc;
        limpiarPantalla();
        switch(opc)
        {
        case 0 :
            marcoMenus("INICIO DE SESION");
            saltosLinea();
            titulo("\tGracias por usar el programa");
            pausa();
            repite = false;
            break;
        case 1:
            marcoMenus("INICIO DE SESION");
            saltosLinea();
            titulo("\t1. Administrador");
            cout << "\tIngrese su usuario(ID): ";
            fflush(stdin);
            getline(cin, usuarioBuscar);
            cout << "\tIngrese su contrase" << enye() << "a: ";
            fflush(stdin);
            getline(cin, contrasenaBuscar);
            limpiarPantalla();
            if(vecAdmins.size() > 0)
            {
                Administrador tmp = Administrador();
                for(int i = 0; i < vecAdmins.size(); i++)
                {
                    tmp = vecAdmins.at(i);
                    if(tmp.getNumID() == usuarioBuscar && tmp.getContrasena() == contrasenaBuscar)
                    {
                        existe = true;
                        if(!tmp.getEstado())
                        {
                            marcoMenus("INICIO DE SESION");
                            saltosLinea();
                            titulo("\tUsuario inactivo");
                            pausa();
                        }
                        else
                        {
                            marcoMenus("INICIO DE SESION");
                            saltosLinea();
                            titulo("\tSesion iniciada correctamente");
                            pausa();
                            repite = false;
                            menuAdmin();
                        }
                    }
                    if(existe)
                        break;
                }
                if(!existe)
                {
                    marcoMenus("INICIO DE SESION");
                    saltosLinea();
                    titulo("\tDatos incorrectos, intente nuevamente");
                    pausa();
                }
            }
            else
            {
                marcoMenus("INICIO DE SESION");
                saltosLinea();
                titulo("\tNo hay administradores en el sistema");
                pausa();
            }
            break;
        case 2:
            marcoMenus("INICIO DE SESION");
            saltosLinea();
            titulo("\t2. Supervisor");
            cout << "\tIngrese su usuario(ID): ";
            cin >> usuarioBuscar;
            cout << "\tIngrese su contrase" << enye() << "a: ";
            fflush(stdin);
            getline(cin, contrasenaBuscar);
            limpiarPantalla();
            if(vecSupervisores.size() > 0)
            {
                Supervisor tmp = Supervisor();
                for(int i = 0; i < vecSupervisores.size(); i++)
                {
                    tmp = vecSupervisores.at(i);
                    if(tmp.getNumID() == usuarioBuscar && tmp.getContrasena() == contrasenaBuscar)
                    {
                        existe = true;
                        if(!tmp.getEstado())
                        {
                            marcoMenus("INICIO DE SESION");
                            saltosLinea();
                            titulo("\tUsuario inactivo");
                            pausa();
                        }
                        else
                        {
                            marcoMenus("INICIO DE SESION");
                            saltosLinea();
                            titulo("\tSesion iniciada correctamente");
                            pausa();
                            repite = false;
                            menuSupervisor();
                        }
                    }
                    if(existe)
                        break;
                }
                if(!existe)
                {
                    marcoMenus("INICIO DE SESION");
                    saltosLinea();
                    titulo("\tDatos incorrectos, intente nuevamente");
                    pausa();
                }
            }
            else
            {
                marcoMenus("INICIO DE SESION");
                saltosLinea();
                titulo("\tNo hay supervisores en el sistema");
                pausa();
            }
            break;
        case 3:
            marcoMenus("INICIO DE SESION");
            saltosLinea();
            titulo("\t3. Cajero");
            cout << "\tIngrese su usuario(ID): ";
            cin >> usuarioBuscar;
            cout << "\tIngrese su contrase" << enye() << "a: ";
            fflush(stdin);
            getline(cin, contrasenaBuscar);
            limpiarPantalla();
            if(vecCajeros.size() > 0)
            {
                Cajero tmp = Cajero();
                for(int i = 0; i < vecCajeros.size(); i++)
                {
                    tmp = vecCajeros.at(i);
                    if(tmp.getNumID() == usuarioBuscar && tmp.getContrasena() == contrasenaBuscar)
                    {
                        existe = true;
                        if(!tmp.getEstado())
                        {
                            marcoMenus("INICIO DE SESION");
                            saltosLinea();
                            titulo("\tUsuario inactivo");
                            pausa();
                        }
                        else
                        {
                            marcoMenus("INICIO DE SESION");
                            saltosLinea();
                            titulo("\tSesion iniciada correctamente");
                            pausa();
                            repite = false;
                            menuCajero();
                        }
                    }
                    if(existe)
                        break;
                }
                if(!existe)
                {
                    marcoMenus("INICIO DE SESION");
                    saltosLinea();
                    titulo("\tDatos incorrectos, intente nuevamente");
                    pausa();
                }
            }
            else
            {
                marcoMenus("INICIO DE SESION");
                saltosLinea();
                titulo("\tNo hay cajeros en el sistema");
                pausa();
            }
            break;
        case 4:
            marcoMenus("INICIO DE SESION");
            saltosLinea();
            titulo("\t4. Proveedor");
            cout << "\tIngrese su usuario(ID): ";
            cin >> usuarioBuscar;
            cout << "\tIngrese su contrase" << enye() << "a: ";
            fflush(stdin);
            getline(cin, contrasenaBuscar);
            limpiarPantalla();
            if(vecProveedores.size() > 0)
            {
                Proveedor tmp = Proveedor();
                for(int i = 0; i < vecProveedores.size(); i++)
                {
                    tmp = vecProveedores.at(i);
                    if(tmp.getNumID() == usuarioBuscar && tmp.getContrasena() == contrasenaBuscar)
                    {
                        existe = true;
                        if(!tmp.getEstado())
                        {
                            marcoMenus("INICIO DE SESION");
                            saltosLinea();
                            titulo("\tUsuario inactivo");
                            pausa();
                        }
                        else
                        {
                            marcoMenus("INICIO DE SESION");
                            saltosLinea();
                            titulo("\tSesion iniciada correctamente");
                            pausa();
                            repite = false;
                            menuProveedor();
                        }
                    }
                    if(existe)
                        break;
                }
                if(!existe)
                {
                    marcoMenus("INICIO DE SESION");
                    saltosLinea();
                    titulo("\tDatos incorrectos, intente nuevamente");
                    pausa();
                }
            }
            else
            {
                marcoMenus("INICIO DE SESION");
                saltosLinea();
                titulo("\tNo hay proveedores en el sistema");
                pausa();
            }
            break;
        case 5:
            marcoMenus("INICIO DE SESION");
            saltosLinea();
            titulo("\t5. Cliente");
            cout << "\tIngrese su usuario(ID): ";
            cin >> usuarioBuscar;
            cout << "\tIngrese su contrase" << enye() << "a: ";
            fflush(stdin);
            getline(cin, contrasenaBuscar);
            limpiarPantalla();
            if(vecClientes.size() > 0)
            {
                Cliente tmp = Cliente();
                for(int i = 0; i < vecClientes.size(); i++)
                {
                    tmp = vecClientes.at(i);
                    if(tmp.getNumID() == usuarioBuscar && tmp.getContrasena() == contrasenaBuscar)
                    {
                        existe = true;
                        if(!tmp.getEstado())
                        {
                            marcoMenus("INICIO DE SESION");
                            saltosLinea();
                            titulo("\tUsuario inactivo");
                            pausa();
                        }
                        else
                        {
                            marcoMenus("INICIO DE SESION");
                            saltosLinea();
                            titulo("\tSesion iniciada correctamente");
                            pausa();
                            repite = false;
                            *tmpID = tmp.getNumID();
                            menuCliente();
                        }
                    }
                    if(existe)
                        break;
                }
                if(!existe)
                {
                    marcoMenus("INICIO DE SESION");
                    saltosLinea();
                    titulo("\tDatos incorrectos, intente nuevamente");
                    pausa();
                }
            }
            else
            {
                marcoMenus("INICIO DE SESION");
                saltosLinea();
                titulo("\tNo hay Clientes en el sistema");
                pausa();
            }
            break;
        case 6:
            marcoMenus("INICIO DE SESION");
            saltosLinea();
            titulo("\t6. Acerca de...");
            cout << "\tDesarrollado por:" << endl;
            cout << "\tJoan Manuel Jaramillo Avila - 202159930" << endl;
            cout << "\tJuan Sebastian Marin Serna - 202160213" << endl;
            cout << "\tManuel Jesus Rosero Zu" << enye() << "iga - 202176007" << endl;
            cout << "\tLeider Santiago Cortes Hernandez - 202159879" << endl << endl;
            cout << "\tVersion:" << endl;
            cout << "\t1.0" << endl << endl;
            pausa();
            break;
        default:
            marcoMenus("INICIO DE SESION");
            saltosLinea();
            titulo("\tOpcion incorrecta");
            pausa();
            break;
        }
    }
    while(repite);
}

void menuAdmin()
{
    bool repite = true, repiteAdv = true;
    int opc, adv;
    do
    {
        marcoMenus("MENU ADMIN");
        saltosLinea();
        titulo("\tSubmenus");
        cout << "\t1. Personas" << endl;
        cout << "\t2. Productos" << endl;
        cout << "\t3. Pedidos" << endl;
        cout << "\t4. Cierre de Caja" << endl;
        cout << "\t0. Cerrar sesion" << endl << endl;
        cout << "\tSeleccione una opcion: ";
        cin >> opc;
        limpiarPantalla();
        switch(opc)
        {
        case 0:
            do
            {
                marcoMenus("MENU ADMIN");
                saltosLinea();
                cout << "\tEsta seguro que desea cerrar sesion? [1. SI - 0. NO]: ";
                cin >> adv;
                limpiarPantalla();
                switch(adv)
                {
                case 0:
                    repiteAdv = false;
                    break;
                case 1:
                    repite = false;
                    repiteAdv = false;
                    marcoMenus("MENU ADMIN");
                    saltosLinea();
                    titulo("\tSesion cerrada correctamente");
                    pausa();
                    login();
                    break;
                default:
                    marcoMenus("MENU ADMIN");
                    saltosLinea();
                    titulo("\tOpcion incorrecta");
                    pausa();
                    break;
                }
            }
            while(repiteAdv);
            break;
        case 1:
            repite = false;
            subMenuPersonaAdmin();
            break;
        case 2:
            repite = false;
            subMenuProductoAdmin();
            break;
        case 3:
            repite = false;
            subMenuPedidoAdmin();
            break;
        case 4:
            repite = false;
            cierreCaja();
            break;
        default:
            marcoMenus("MENU ADMIN");
            saltosLinea();
            titulo("\tOpcion incorrecta");
            pausa();
            break;
        }
    }
    while(repite);
}

void menuSupervisor()
{
    bool repite = true, repiteAdv = true;
    int opc, adv;
    do
    {
        marcoMenus("MENU SUPERVISOR");
        saltosLinea();
        titulo("\tSubmenus");
        cout << "\t1. Personas" << endl;
        cout << "\t2. Productos" << endl;
        cout << "\t3. Listado de Pedidos" << endl;
        cout << "\t4. Cierre de Caja" << endl;
        cout << "\t0. Cerrar sesion" << endl << endl;
        cout << "\tSeleccione una opcion: ";
        cin >> opc;
        limpiarPantalla();
        switch(opc)
        {
        case 0:
            do
            {
                marcoMenus("MENU SUPERVISOR");
                saltosLinea();
                cout << "\tEsta seguro que desea cerrar sesion? [1. SI - 0. NO]: ";
                cin >> adv;
                limpiarPantalla();
                switch(adv)
                {
                case 0:
                    repiteAdv = false;
                    break;
                case 1:
                    repite = false;
                    repiteAdv = false;
                    marcoMenus("MENU SUPERVISOR");
                    saltosLinea();
                    titulo("\tSesion cerrada correctamente");
                    pausa();
                    login();
                    break;
                default:
                    marcoMenus("MENU SUPERVISOR");
                    saltosLinea();
                    titulo("\tOpcion incorrecta");
                    pausa();
                    break;
                }
            }
            while(repiteAdv);
            break;
        case 1:
            subMenuPersonaSupervisor();
            break;
        case 2:
            subMenuProductoSupervisor();
            break;
        case 3:
            listadoPedido();
            break;
        case 4:
            cierreCaja();
            break;
        default:
            marcoMenus("MENU SUPERVISOR");
            saltosLinea();
            titulo("\tOpcion incorrecta");
            pausa();
            break;
        }
    }
    while(repite);
}

void menuCajero()
{
    bool repite = true, repiteAdv = true;
    int opc, adv;
    do
    {
        marcoMenus("MENU CAJERO");
        saltosLinea();
        titulo("\tSubmenus");
        cout << "\t1. Listado de clientes" << endl;
        cout << "\t2. Listado de productos" << endl;
        cout << "\t3. Vender Producto" << endl;
        cout << "\t0. Cerrar sesion" << endl << endl;
        cout << "\tSeleccione una opcion: ";
        cin >> opc;
        limpiarPantalla();
        switch(opc)
        {
        case 0:
            do
            {
                marcoMenus("MENU CAJERO");
                saltosLinea();
                cout << "\tEsta seguro que desea cerrar sesion? [1. SI - 0. NO]: ";
                cin >> adv;
                limpiarPantalla();
                switch(adv)
                {
                case 0:
                    repiteAdv = false;
                    break;
                case 1:
                    repite = false;
                    repiteAdv = false;
                    marcoMenus("MENU CAJERO");
                    saltosLinea();
                    titulo("\tSesion cerrada correctamente");
                    pausa();
                    login();
                    break;

                default:
                    marcoMenus("MENU CAJERO");
                    saltosLinea();
                    titulo("\tOpcion incorrecta");
                    pausa();
                    break;
                }
            }
            while(repiteAdv);
            break;
        case 1:
            listadoCliente();
            break;
        case 2:
            listadoProducto();
            break;
        case 3:
            venderProductos();
            break;
        default:
            marcoMenus("MENU CAJERO");
            saltosLinea();
            titulo("\tOpcion incorrecta");
            pausa();
            break;
        }
    }
    while(repite);
}

void menuProveedor()
{
    bool repite = true, repiteAdv = true;
    int opc, adv;
    do
    {
        marcoMenus("MENU PROVEEDOR");
        saltosLinea();
        titulo("\tSubmenus");
        cout << "\t1. Pedidos" << endl;
        cout << "\t0. Cerrar sesion" << endl << endl;
        cout << "\tSeleccione una opcion: ";
        cin >> opc;
        limpiarPantalla();
        switch(opc)
        {
        case 0:
            do
            {
                marcoMenus("MENU PROVEEDOR");
                saltosLinea();
                cout << "\tEsta seguro que desea cerrar sesion? [1. SI - 0. NO]: ";
                cin >> adv;
                limpiarPantalla();
                switch(adv)
                {
                case 0:
                    repiteAdv = false;
                    break;
                case 1:
                    repite = false;
                    repiteAdv = false;
                    marcoMenus("MENU PROVEEDOR");
                    saltosLinea();
                    titulo("\tSesion cerrada correctamente");
                    pausa();
                    login();
                    break;
                default:
                    marcoMenus("MENU PROVEEDOR");
                    saltosLinea();
                    titulo("\tOpcion incorrecta");
                    pausa();
                    break;
                }
            }
            while(repiteAdv);
            break;
        case 1:
            repite = false;
            subMenuPedidoProveedor();
            break;
        default:
            marcoMenus("MENU PROVEEDOR");
            saltosLinea();
            titulo("\tOpcion incorrecta");
            pausa();
            break;
        }
    }
    while(repite);
}

void menuCliente()
{
    bool repite = true, repiteAdv = true, existe = false;
    int opc, adv;
    do
    {
        marcoMenus("MENU CLIENTE");
        saltosLinea();
        titulo("\tSubmenus");
        cout << "\t1. Datos de la cuenta" << endl;
        cout << "\t2. Listado de productos" << endl;
        cout << "\t0. Cerrar sesion" << endl << endl;
        cout << "\tSeleccione una opcion: ";
        cin >> opc;
        limpiarPantalla();
        switch(opc)
        {
        case 0:
            do
            {
                marcoMenus("MENU CLIENTE");
                saltosLinea();
                cout << "\tEsta seguro que desea cerrar sesion? [1. SI - 0. NO]: ";
                cin >> adv;
                limpiarPantalla();
                switch(adv)
                {
                case 0:
                    repiteAdv = false;
                    break;
                case 1:
                    repite = false;
                    repiteAdv = false;
                    marcoMenus("MENU CLIENTE");
                    saltosLinea();
                    titulo("\tSesion cerrada correctamente");
                    pausa();
                    login();
                    break;
                default:
                    marcoMenus("MENU CLIENTE");
                    saltosLinea();
                    titulo("\tOpcion incorrecta");
                    pausa();
                    break;
                }
            }
            while(repiteAdv);
            break;
        case 1:
        {
            // <-- llave para evitar el error 'jump to case label' [-fpermissive]
            repite = false;
            marcoMenus("MENU CLIENTE");
            saltosLinea();
            titulo("\t1. Datos de la cuenta");
            Cliente tmp = Cliente();
            for(int i = 0; i < vecClientes.size(); i++)
            {
                tmp = vecClientes.at(i);
                if(tmp.getNumID() == *tmpID)
                {
                    existe = true;
                    do
                    {
                        marcoMenus("MENU CLIENTE");
                        saltosLinea();
                        titulo("\t1. Datos de la cuenta");
                        cout << tmp.getInfo() << endl << endl;
                        cout << "\t1. Mostrar contrase" << enye() << "a" << endl;
                        cout << "\t0. Volver al menu anterior" << endl << endl;
                        cout << "\tSeleccione una opcion: ";
                        cin >> opc;
                        limpiarPantalla();
                        switch(opc)
                        {
                        case 0:
                            repite = false;
                            break;
                        case 1:
                            repite = false;
                            marcoMenus("MENU CLIENTE");
                            saltosLinea();
                            titulo("\t1. Datos de la cuenta");
                            cout << tmp.getInfo();
                            gotoxy (20, 16);
                            cout << tmp.getContrasena() << "      ";
                            gotoxy (0, 20);
                            pausa();
                            menuCliente();
                            break;
                        default:
                            marcoMenus("MENU CLIENTE");
                            saltosLinea();
                            titulo("\tOpcion incorrecta");
                            pausa();
                            break;
                        }
                    }
                    while(repite);
                }
                if(existe)
                    break;
            }
        }   // <-- llave para evitar el error 'jump to case label' [-fpermissive]
        case 2:
            listadoProducto();
            break;

        default:
            marcoMenus("MENU CLIENTE");
            saltosLinea();
            titulo("\tOpcion incorrecta");
            pausa();
            break;
        }
    }
    while(repite);
}

void subMenuPersonaAdmin()
{
    bool repite = true;
    bool repiteListado = true;
    bool repiteCrear = true;
    bool repiteConsultar = true;
    bool repiteModificar = true;
    bool repiteDesactivar = true;
    bool repiteBorrar = true;
    int opc, opcListado, opcCrear, opcConsultar, opcModificar, opcDesactivar, opcBorrar;
    marcoMenus("SUBMENU PERSONAS");
    saltosLinea();
    titulo("\tOpciones");
    do
    {
        marcoMenus("SUBMENU PERSONAS");
        saltosLinea();
        titulo("\tOpciones");
        cout << "\t1. Listado general" << endl;
        cout << "\t2. Ingresar usuario" << endl;
        cout << "\t3. Consultar usuario" << endl;
        cout << "\t4. Modificar usuario" << endl;
        cout << "\t5. Desactivar usuario" << endl;
        cout << "\t6. Borrar usuario" << endl;
        cout << "\t0. Volver al menu anterior" << endl << endl;
        cout << "\tSeleccione una opcion: ";
        cin >> opc;
        limpiarPantalla();
        switch(opc)
        {
        case 0:
            repite = false;
            menuAdmin();
            break;
        case 1:
            repite = false;
            do
            {
                marcoMenus("LISTADO GENERAL");
                saltosLinea();
                tituloLogin("\tTipo de usuario");
                cout << "\t1. Administrador" << endl;
                cout << "\t2. Supervisor" << endl;
                cout << "\t3. Cajero" << endl;
                cout << "\t4. Proveedor" << endl;
                cout << "\t5. Cliente" << endl;
                cout << "\t0. Volver al menu anterior" << endl << endl;
                cout << "\tSeleccione una opcion: ";
                cin >> opcListado;
                limpiarPantalla();
                switch(opcListado)
                {
                case 0:
                    repiteListado = false;
                    subMenuPersonaAdmin();
                    break;
                case 1:
                    listadoAdmin();
                    break;
                case 2:
                    listadoSupervisor();
                    break;
                case 3:
                    listadoCajero();
                    break;
                case 4:
                    listadoProveedor();
                    break;
                case 5:
                    listadoCliente();
                    break;
                default:
                    marcoMenus("LISTADO GENERAL");
                    saltosLinea();
                    titulo("\tOpcion incorrecta");
                    pausa();
                    break;
                }
            }
            while(repiteListado);
            break;
        case 2:
            repite = false;
            do
            {
                marcoMenus("INGRESAR USUARIO");
                saltosLinea();
                tituloLogin("\tTipo de usuario");
                cout << "\t1. Administrador" << endl;
                cout << "\t2. Supervisor" << endl;
                cout << "\t3. Cajero" << endl;
                cout << "\t4. Proveedor" << endl;
                cout << "\t5. Cliente" << endl;
                cout << "\t0. Volver al menu anterior" << endl << endl;
                cout << "\tSeleccione una opcion: ";
                cin >> opcCrear;
                limpiarPantalla();
                switch(opcCrear)
                {
                case 0:
                    repiteCrear = false;
                    subMenuPersonaAdmin();
                    break;
                case 1:
                    crearAdmin();
                    break;
                case 2:
                    crearSupervisor();
                    break;
                case 3:
                    crearCajero();
                    break;
                case 4:
                    crearProveedor();
                    break;
                case 5:
                    crearCliente();
                    break;
                default:
                    marcoMenus("INGRESAR USUARIO");
                    saltosLinea();
                    titulo("\tOpcion incorrecta");
                    pausa();
                    break;
                }
            }
            while(repiteCrear);
            break;
        case 3:
            repite = false;
            do
            {
                marcoMenus("CONSULTAR USUARIO");
                saltosLinea();
                tituloLogin("\tTipo de usuario");
                cout << "\t1. Administrador" << endl;
                cout << "\t2. Supervisor" << endl;
                cout << "\t3. Cajero" << endl;
                cout << "\t4. Proveedor" << endl;
                cout << "\t5. Cliente" << endl;
                cout << "\t0. Volver al menu anterior" << endl << endl;
                cout << "\tSeleccione una opcion: ";
                cin >> opcConsultar;
                limpiarPantalla();
                switch(opcConsultar)
                {
                case 0:
                    repiteConsultar = false;
                    subMenuPersonaAdmin();
                    break;
                case 1:
                    consultarAdmin();
                    break;
                case 2:
                    consultarSupervisor();
                    break;
                case 3:
                    consultarCajero();
                    break;
                case 4:
                    consultarProveedor();
                    break;
                case 5:
                    consultarCliente();
                    break;
                default:
                    marcoMenus("CONSULTAR USUARIO");
                    saltosLinea();
                    titulo("\tOpcion incorrecta");
                    pausa();
                }
            }
            while(repiteConsultar);
            break;
        case 4:
            repite = false;
            do
            {
                marcoMenus("MODIFICAR USUARIO");
                saltosLinea();
                tituloLogin("\tTipo de usuario");
                cout << "\t1. Administrador" << endl;
                cout << "\t2. Supervisor" << endl;
                cout << "\t3. Cajero" << endl;
                cout << "\t4. Proveedor" << endl;
                cout << "\t5. Cliente" << endl;
                cout << "\t0. Volver al menu anterior" << endl << endl;
                cout << "\tSeleccione una opcion: ";
                cin >> opcModificar;
                limpiarPantalla();
                switch(opcModificar)
                {
                case 0:
                    repiteModificar = false;
                    subMenuPersonaAdmin();
                    break;
                case 1:
                    modificarAdmin();
                    break;
                case 2:
                    modificarSupervisor();
                    break;
                case 3:
                    modificarCajero();
                    break;
                case 4:
                    modificarProveedor();
                    break;
                case 5:
                    modificarCliente();
                    break;
                default:
                    marcoMenus("MODIFICAR USUARIO");
                    saltosLinea();
                    titulo("\tOpcion incorrecta");
                    pausa();
                }
            }
            while(repiteModificar);
            break;
        case 5:
            repite = false;
            do
            {
                marcoMenus("ACTIVAR/DESACTIVAR USUARIO");
                saltosLinea();
                tituloLogin("\tTipo de usuario");
                cout << "\t1. Administrador" << endl;
                cout << "\t2. Supervisor" << endl;
                cout << "\t3. Cajero" << endl;
                cout << "\t4. Proveedor" << endl;
                cout << "\t5. Cliente" << endl;
                cout << "\t0. Volver al menu anterior" << endl << endl;
                cout << "\tSeleccione una opcion: ";
                cin >> opcDesactivar;
                limpiarPantalla();
                switch(opcDesactivar)
                {
                case 0:
                    repiteDesactivar = false;
                    subMenuPersonaAdmin();
                    break;
                case 1:
                    desactivarAdmin();
                    break;
                case 2:
                    desactivarSupervisor();
                    break;
                case 3:
                    desactivarCajero();
                    break;
                case 4:
                    desactivarProveedor();
                    break;
                case 5:
                    desactivarCliente();
                    break;
                default:
                    marcoMenus("ACTIVAR/DESACTIVAR USUARIO");
                    saltosLinea();
                    titulo("\tOpcion incorrecta");
                    pausa();
                }
            }
            while(repiteDesactivar);
            break;
        case 6:
            repite = false;
            do
            {
                marcoMenus("BORRAR USUARIO");
                saltosLinea();
                tituloLogin("\tTipo de usuario");
                cout << "\t1. Administrador" << endl;
                cout << "\t2. Supervisor" << endl;
                cout << "\t3. Cajero" << endl;
                cout << "\t4. Proveedor" << endl;
                cout << "\t5. Cliente" << endl;
                cout << "\t0. Volver al menu anterior" << endl << endl;
                cout << "\tSeleccione una opcion: ";
                cin >> opcBorrar;
                limpiarPantalla();
                switch(opcBorrar)
                {
                case 0:
                    repiteBorrar = false;
                    subMenuPersonaAdmin();
                    break;
                case 1:
                    borrarAdmin();
                    break;
                case 2:
                    borrarSupervisor();
                    break;
                case 3:
                    borrarCajero();
                    break;
                case 4:
                    borrarProveedor();
                    break;
                case 5:
                    borrarCliente();
                    break;
                default:
                    marcoMenus("BORRAR USUARIO");
                    saltosLinea();
                    titulo("\tOpcion incorrecta");
                    pausa();
                }
            }
            while(repiteBorrar);
            break;
        default:
            marcoMenus("SUBMENU PERSONAS");
            saltosLinea();
            titulo("\tOpcion incorrecta");
            pausa();
            break;
        }
    }
    while(repite);
}

void subMenuPersonaSupervisor()
{
    bool repite = true;
    bool repiteListado = true;
    bool repiteConsultar = true;
    bool repiteDesactivar = true;
    int opc, opcListado, opcConsultar, opcDesactivar;
    marcoMenus("SUBMENU PERSONAS");
    saltosLinea();
    titulo("\tOpciones");
    do
    {
        marcoMenus("SUBMENU PERSONAS");
        saltosLinea();
        titulo("\tOpciones");
        cout << "\t1. Listado general" << endl;
        cout << "\t2. Consultar usuario" << endl;
        cout << "\t3. Desactivar usuario" << endl;
        cout << "\t4. Crear usuario" << endl;
        cout << "\t0. Volver al menu anterior" << endl << endl;
        cout << "\tSeleccione una opcion: ";
        cin >> opc;
        limpiarPantalla();
        switch(opc)
        {
        case 0:
            repite = false;
            menuSupervisor();
            break;
        case 1:
            repite = false;
            do
            {
                marcoMenus("LISTADO GENERAL");
                saltosLinea();
                tituloLogin("\tTipo de usuario");
                cout << "\t1. Administrador" << endl;
                cout << "\t2. Supervisor" << endl;
                cout << "\t3. Cajero" << endl;
                cout << "\t4. Proveedor" << endl;
                cout << "\t5. Cliente" << endl;
                cout << "\t0. Volver al menu anterior" << endl << endl;
                cout << "\tSeleccione una opcion: ";
                cin >> opcListado;
                limpiarPantalla();
                switch(opcListado)
                {
                case 0:
                    repiteListado = false;
                    subMenuPersonaSupervisor();
                    break;
                case 1:
                    listadoAdmin();
                    break;
                case 2:
                    listadoSupervisor();
                    break;
                case 3:
                    listadoCajero();
                    break;
                case 4:
                    listadoProveedor();
                    break;
                case 5:
                    listadoCliente();
                    break;
                default:
                    marcoMenus("LISTADO GENERAL");
                    saltosLinea();
                    titulo("\tOpcion incorrecta");
                    pausa();
                    break;
                }
            }
            while(repiteListado);
            break;

        case 2:
            repite = false;
            do
            {
                marcoMenus("CONSULTAR USUARIO");
                saltosLinea();
                tituloLogin("\tTipo de usuario");
                cout << "\t1. Administrador" << endl;
                cout << "\t2. Supervisor" << endl;
                cout << "\t3. Cajero" << endl;
                cout << "\t4. Proveedor" << endl;
                cout << "\t5. Cliente" << endl;
                cout << "\t0. Volver al menu anterior" << endl << endl;
                cout << "\tSeleccione una opcion: ";
                cin >> opcConsultar;
                limpiarPantalla();
                switch(opcConsultar)
                {
                case 0:
                    repiteConsultar = false;
                    subMenuPersonaSupervisor();
                    break;
                case 1:
                    consultarAdmin();
                    break;
                case 2:
                    consultarSupervisor();
                    break;
                case 3:
                    consultarCajero();
                    break;
                case 4:
                    consultarProveedor();
                    break;
                case 5:
                    consultarCliente();
                    break;
                default:
                    marcoMenus("CONSULTAR USUARIO");
                    saltosLinea();
                    titulo("\tOpcion incorrecta");
                    pausa();
                }
            }
            while(repiteConsultar);
            break;

        case 3:
            repite = false;
            do
            {
                marcoMenus("ACTIVAR/DESACTIVAR USUARIO");
                saltosLinea();
                tituloLogin("\tTipo de usuario");
                cout << "\t1. Supervisor" << endl;
                cout << "\t2. Cajero" << endl;
                cout << "\t3. Proveedor" << endl;
                cout << "\t4. Cliente" << endl;
                cout << "\t0. Volver al menu anterior" << endl << endl;
                cout << "\tSeleccione una opcion: ";
                cin >> opcDesactivar;
                limpiarPantalla();
                switch(opcDesactivar)
                {
                case 0:
                    repiteDesactivar = false;
                    subMenuPersonaSupervisor();
                    break;
                case 1:
                    desactivarSupervisor();
                    break;
                case 2:
                    desactivarCajero();
                    break;
                case 3:
                    desactivarProveedor();
                    break;
                case 4:
                    desactivarCliente();
                    break;
                default:
                    marcoMenus("ACTIVAR/DESACTIVAR USUARIO");
                    saltosLinea();
                    titulo("\tOpcion incorrecta");
                    pausa();
                }
            }
            while(repiteDesactivar);
            break;

        case 4:
            repite = false;
            do
            {
                marcoMenus("CREAR USUARIO");
                saltosLinea();
                tituloLogin("\tTipo de usuario");
                cout << "\t1. Cajero" << endl;
                cout << "\t2. Cliente" << endl;
                cout << "\t0. Volver al menu anterior" << endl << endl;
                cout << "\tSeleccione una opcion: ";
                cin >> opcDesactivar;
                limpiarPantalla();
                switch(opcDesactivar)
                {
                case 0:
                    repiteDesactivar = false;
                    subMenuPersonaSupervisor();
                    break;
                case 1:
                    crearCajero();
                    break;
                case 2:
                    crearCliente();
                    break;

                default:
                    marcoMenus("ACTIVAR/DESACTIVAR USUARIO");
                    saltosLinea();
                    titulo("\tOpcion incorrecta");
                    pausa();
                }
            }
            while(repiteDesactivar);
            break;

        default:
            marcoMenus("SUBMENU PERSONAS");
            saltosLinea();
            titulo("\tOpcion incorrecta");
            pausa();
            break;
        }
    }
    while(repite);

}

void subMenuProductoSupervisor()
{
    bool repite = true;
    bool repiteConsultar = true;

    int opc, opcConsultar;
    marcoMenus("SUBMENU PRODUCTOS");
    saltosLinea();
    titulo("\tOpciones");
    do
    {
        marcoMenus("SUBMENU PRODUCTOS");
        saltosLinea();
        titulo("\tOpciones");
        cout << "\t1. Listado de productos" << endl;
        cout << "\t2. Consultar producto" << endl;
        cout << "\t3. Modificar producto" << endl;
        cout << "\t4. Vender Producto" << endl;
        cout << "\t0. Volver al menu anterior" << endl << endl;
        cout << "\tSeleccione una opcion: ";
        cin >> opc;
        limpiarPantalla();
        switch(opc)
        {
        case 0:
            repite = false;
            menuSupervisor();
            break;
        case 1:
            listadoProducto();
            break;
        case 2:
            consultarProducto();
            break;
        case 3:
            modificarProducto();
            break;
        case 4:
            venderProductos();
            break;
        default:
            marcoMenus("SUBMENU PRODUCTOS");
            saltosLinea();
            titulo("\tOpcion incorrecta");
            pausa();
            break;
        }
    }
    while(repite);


}

void subMenuProductoAdmin()
{
    bool repite = true;
    bool repiteConsultar = true;

    int opc, opcConsultar;
    marcoMenus("SUBMENU PRODUCTOS");
    saltosLinea();
    titulo("\tOpciones");
    do
    {
        marcoMenus("SUBMENU PRODUCTOS");
        saltosLinea();
        titulo("\tOpciones");
        cout << "\t1. Crear producto" << endl;
        cout << "\t2. Listado de productos" << endl;
        cout << "\t3. Consultar producto" << endl;
        cout << "\t4. Modificar producto" << endl;
        cout << "\t5. Vender Productos" << endl;
        cout << "\t0. Volver al menu anterior" << endl << endl;
        cout << "\tSeleccione una opcion: ";
        cin >> opc;
        limpiarPantalla();
        switch(opc)
        {
        case 0:
            repite = false;
            menuAdmin();
            break;
        case 1:
            crearProducto();
            break;
        case 2:
            listadoProducto();
            break;
        case 3:
            consultarProducto();
            break;
        case 4:
            modificarProducto();
            break;
        case 5:
            venderProductos();
            break;
        default:
            marcoMenus("SUBMENU PRODUCTOS");
            saltosLinea();
            titulo("\tOpcion incorrecta");
            pausa();
            break;
        }
    }
    while(repite);
}

void subMenuPedidoAdmin()
{
    bool repite = true;
    bool repiteConsultar = true;

    int opc, opcConsultar;
    marcoMenus("SUBMENU PEDIDOS");
    saltosLinea();
    titulo("\tOpciones");
    do
    {
        marcoMenus("SUBMENU PEDIDOS");
        saltosLinea();
        titulo("\tOpciones");
        cout << "\t1. Crear pedido" << endl;
        cout << "\t2. Listado de pedidos" << endl;
        cout << "\t3. Consultar Pedidos" << endl;
        cout << "\t0. Volver al menu anterior" << endl << endl;
        cout << "\tSeleccione una opcion: ";
        cin >> opc;
        limpiarPantalla();
        switch(opc)
        {
        case 0:
            repite = false;
            menuAdmin();
            break;
        case 1:
            crearPedido();
            break;
        case 2:
            listadoPedido();
            break;
        case 3:
            consultarPedido();
            break;

        default:
            marcoMenus("SUBMENU PEDIDOS");
            saltosLinea();
            titulo("\tOpcion incorrecta");
            pausa();
            break;
        }
    }
    while(repite);
}

void subMenuPedidoProveedor()
{
    bool repite = true;
    bool repiteConsultar = true;

    int opc, opcConsultar;
    marcoMenus("SUBMENU PEDIDOS");
    saltosLinea();
    titulo("\tOpciones");
    do
    {
        marcoMenus("SUBMENU PEDIDOS");
        saltosLinea();
        titulo("\tOpciones");
        cout << "\t1. Enviar Pedido" << endl;
        cout << "\t2. Listado" << endl;
        cout << "\t3. Cosultar pedido" << endl;
        cout << "\t0. Volver al menu anterior" << endl << endl;
        cout << "\tSeleccione una opcion: ";
        cin >> opc;
        limpiarPantalla();
        switch(opc)
        {
        case 0:
            repite = false;
            menuProveedor();
            break;

        case 1:
            desactivarPedido();
            break;

        case 2:
            listadoPedido();
            break;

        case 3:
            consultarPedido();
            break;
        default:
            marcoMenus("LISTADO DE PEDIDOS");
            saltosLinea();
            titulo("\tOpcion incorrecta");
            pausa();
            break;
        }
    }
    while(repite);


}

void listadoAdmin()
{
    marcoMenuListado("LISTADO GENERAL");
    saltosLinea();
    titulo("\t1. Administrador");
    if(vecAdmins.size() > 0)
    {
        Administrador tmp = Administrador();
        for(int i = 0; i < vecAdmins.size(); i++)
        {
            tmp = vecAdmins.at(i);
            cout << tmp.getInfo() << endl << endl;
            separador();
        }
        pausa();
    }
    else
    {
        marcoMenuListado("LISTADO GENERAL");
        saltosLinea();
        titulo("\tNo hay administradores en el sistema");
        pausa();
    }
}

void listadoSupervisor()
{
    marcoMenuListado("LISTADO GENERAL");
    saltosLinea();
    titulo("\t2. Supervisor");
    if(vecSupervisores.size() > 0)
    {
        Supervisor tmp = Supervisor();
        for(int i = 0; i < vecSupervisores.size(); i++)
        {
            tmp = vecSupervisores.at(i);
            cout << tmp.getInfo() << endl << endl;
            separador();
        }
        pausa();
    }
    else
    {
        marcoMenuListado("LISTADO GENERAL");
        saltosLinea();
        titulo("\tNo hay supervisores en el sistema");
        pausa();
    }
}

void listadoCajero()
{
    marcoMenuListado("LISTADO GENERAL");
    saltosLinea();
    titulo("\t3. Cajero");
    if(vecCajeros.size() > 0)
    {
        Cajero tmp = Cajero();
        for(int i = 0; i < vecCajeros.size(); i++)
        {
            tmp = vecCajeros.at(i);
            cout << tmp.getInfo() << endl << endl;
            separador();
        }
        pausa();
    }
    else
    {
        marcoMenuListado("LISTADO GENERAL");
        saltosLinea();
        titulo("\tNo hay cajeros en el sistema");
        pausa();
    }
}

void listadoProveedor()
{
    marcoMenuListado("LISTADO GENERAL");
    saltosLinea();
    titulo("\t4. Proveedor");
    if(vecProveedores.size() > 0)
    {
        Proveedor tmp = Proveedor();
        for(int i = 0; i < vecProveedores.size(); i++)
        {
            tmp = vecProveedores.at(i);
            cout << tmp.getInfo() << endl << endl;
            separador();
        }
        pausa();
    }
    else
    {
        marcoMenuListado("LISTADO GENERAL");
        saltosLinea();
        titulo("\tNo hay proveedores en el sistema");
        pausa();
    }
}

void listadoCliente()
{
    marcoMenuListado("LISTADO GENERAL");
    saltosLinea();
    titulo("\t5. Cliente");
    if(vecClientes.size() > 0)
    {
        Cliente tmp = Cliente();
        for(int i = 0; i < vecClientes.size(); i++)
        {
            tmp = vecClientes.at(i);
            cout << tmp.getInfo() << endl << endl;
            separador();
        }
        pausa();
    }
    else
    {
        marcoMenuListado("LISTADO GENERAL");
        saltosLinea();
        titulo("\tNo hay Clientes en el sistema");
        pausa();
    }
}

void consultarAdmin()
{
    int opc;
    bool repite = true, existe = false;
    string idBuscar;
    marcoMenus("CONSULTAR USUARIO");
    saltosLinea();
    titulo("\t1. Administrador");
    cout << "\tIngrese el numero de identificacion: ";
    fflush(stdin);
    getline(cin, idBuscar);
    limpiarPantalla();
    if(vecAdmins.size() > 0)
    {
        Administrador tmp = Administrador();
        for(int i = 0; i < vecAdmins.size(); i++)
        {
            tmp = vecAdmins.at(i);
            if(tmp.getNumID() == idBuscar)
            {
                existe = true;
                do
                {
                    marcoMenus("CONSULTAR USUARIO");
                    saltosLinea();
                    titulo("\t1. Administrador");
                    cout << tmp.getInfo() << endl << endl;
                    separador();
                    cout << "\t1. Mostrar contrase" << enye() << "a" << endl;
                    cout << "\t0. Volver al menu anterior" << endl << endl;
                    cout << "\tSeleccione una opcion: ";
                    cin >> opc;
                    limpiarPantalla();
                    switch(opc)
                    {
                    case 0:
                        repite = false;
                        break;
                    case 1:
                        repite = false;
                        marcoMenus("CONSULTAR USUARIO");
                        saltosLinea();
                        titulo("\t1. Administrador");
                        cout << tmp.getInfo();
                        gotoxy (20, 16);
                        cout << tmp.getContrasena() << "      ";
                        gotoxy (0, 21);
                        pausa();
                        break;
                    default:
                        marcoMenus("CONSULTAR USUARIO");
                        saltosLinea();
                        titulo("\tOpcion incorrecta");
                        pausa();
                        break;
                    }
                }
                while(repite);
            }
            if(existe)
                break;
        }
        if(!existe)
        {
            marcoMenus("CONSULTAR USUARIO");
            saltosLinea();
            titulo("\tNo hay administradores con ese numero de identificacion en el sistema");
            pausa();
        }
    }
    else
    {
        marcoMenus("CONSULTAR USUARIO");
        saltosLinea();
        titulo("\tNo hay administradores en el sistema");
        pausa();
    }
}

void consultarSupervisor()
{
    int opc;
    bool repite = true, existe = false;
    string idBuscar;
    marcoMenus("CONSULTAR USUARIO");
    saltosLinea();
    titulo("\t2. Supervisor");
    cout << "\tIngrese el numero de identificacion: ";
    fflush(stdin);
    getline(cin, idBuscar);
    limpiarPantalla();
    if(vecSupervisores.size() > 0)
    {
        Supervisor tmp = Supervisor();
        for(int i = 0; i < vecSupervisores.size(); i++)
        {
            tmp = vecSupervisores.at(i);
            if(tmp.getNumID() == idBuscar)
            {
                existe = true;
                do
                {
                    marcoMenus("CONSULTAR USUARIO");
                    saltosLinea();
                    titulo("\t2. Supervisor");
                    cout << tmp.getInfo() << endl << endl;
                    separador();
                    cout << "\t1. Mostrar contrase" << enye() << "a" << endl;
                    cout << "\t0. Volver al menu anterior" << endl << endl;
                    cout << "\tSeleccione una opcion: ";
                    cin >> opc;
                    limpiarPantalla();
                    switch(opc)
                    {
                    case 0:
                        repite = false;
                        break;
                    case 1:
                        repite = false;
                        marcoMenus("CONSULTAR USUARIO");
                        saltosLinea();
                        titulo("\t2. Supervisor");
                        cout << tmp.getInfo();
                        gotoxy (20, 16);
                        cout << tmp.getContrasena() << "      ";
                        gotoxy (0, 21);
                        pausa();
                        break;
                    default:
                        marcoMenus("CONSULTAR USUARIO");
                        saltosLinea();
                        titulo("\tOpcion incorrecta");
                        pausa();
                        break;
                    }
                }
                while(repite);
            }
            if(existe)
                break;
        }
        if(!existe)
        {
            marcoMenus("CONSULTAR USUARIO");
            saltosLinea();
            titulo("\tNo hay supervisores con ese numero de identificacion en el sistema");
            pausa();
        }
    }
    else
    {
        marcoMenus("CONSULTAR USUARIO");
        saltosLinea();
        titulo("\tNo hay supervisores en el sistema");
        pausa();
    }
}

void listadoProducto()
{
    marcoMenuListado("LISTADO GENERAL");
    saltosLinea();
    titulo("\t1. Productos");
    if(vecInventario.size() > 0)
    {
        Producto tmp = Producto();
        for(int i = 0; i < vecInventario.size(); i++)
        {
            tmp = vecInventario.at(i);
            cout << tmp.getInfo() << endl << endl;
            separador();
        }
        pausa();
    }
    else
    {
        marcoMenuListado("LISTADO GENERAL");
        saltosLinea();
        titulo("\tNo hay Productos en el sistema");
        pausa();
    }

}

void listadoPedido()
{

    marcoMenuListado("LISTADO DE PEDIDOS");
    saltosLinea();
    titulo("\t1. Listado General");
    if(vecPedidos.size() > 0)
    {
        Pedido tmp = Pedido();
        for(int i = 0; i < vecPedidos.size(); i++)
        {
            tmp = vecPedidos.at(i);
            cout << tmp.getInfoP() << endl << endl;
            separador();
        }
        pausa();
    }
    else
    {
        marcoMenuListado("LISTADO DE PEDIDOS");
        saltosLinea();
        titulo("\tNo hay pedidos en el sistema");
        pausa();
    }
}

void consultarCajero()
{
    int opc;
    bool repite = true, existe = false;
    string idBuscar;
    marcoMenus("CONSULTAR USUARIO");
    saltosLinea();
    titulo("\t3. Cajero");
    cout << "\tIngrese el numero de identificacion: ";
    fflush(stdin);
    getline(cin, idBuscar);
    limpiarPantalla();
    if(vecCajeros.size() > 0)
    {
        Cajero tmp = Cajero();
        for(int i = 0; i < vecCajeros.size(); i++)
        {
            tmp = vecCajeros.at(i);
            if(tmp.getNumID() == idBuscar)
            {
                existe = true;
                do
                {
                    marcoMenus("CONSULTAR USUARIO");
                    saltosLinea();
                    titulo("\t3. Cajero");
                    cout << tmp.getInfo() << endl << endl;
                    cout << "\t1. Mostrar contrase" << enye() << "a" << endl;
                    cout << "\t0. Volver al menu anterior" << endl << endl;
                    cout << "\tSeleccione una opcion: ";
                    cin >> opc;
                    limpiarPantalla();
                    switch(opc)
                    {
                    case 0:
                        repite = false;
                        break;
                    case 1:
                        repite = false;
                        marcoMenus("CONSULTAR USUARIO");
                        saltosLinea();
                        titulo("\t3. Cajero");
                        cout << tmp.getInfo();
                        gotoxy (20, 16);
                        cout << tmp.getContrasena() << "      ";
                        gotoxy (0, 21);
                        pausa();
                        break;
                    default:
                        marcoMenus("CONSULTAR USUARIO");
                        saltosLinea();
                        titulo("\tOpcion incorrecta");
                        pausa();
                        break;
                    }
                }
                while(repite);
            }
            if(existe)
                break;
        }
        if(!existe)
        {
            marcoMenus("CONSULTAR USUARIO");
            saltosLinea();
            titulo("\tNo hay cajeros con ese numero de identificacion en el sistema");
            pausa();
        }
    }
    else
    {
        marcoMenus("CONSULTAR USUARIO");
        saltosLinea();
        titulo("\tNo hay cajeros en el sistema");
        pausa();
    }
}

void consultarProveedor()
{
    int opc;
    bool repite = true, existe = false;
    string idBuscar;
    marcoMenus("CONSULTAR USUARIO");
    saltosLinea();
    titulo("\t4. Proveedor");
    cout << "\tIngrese el numero de identificacion: ";
    fflush(stdin);
    getline(cin, idBuscar);
    limpiarPantalla();
    if(vecProveedores.size() > 0)
    {
        Proveedor tmp = Proveedor();
        for(int i = 0; i < vecProveedores.size(); i++)
        {
            tmp = vecProveedores.at(i);
            if(tmp.getNumID() == idBuscar)
            {
                existe = true;
                do
                {
                    marcoMenus("CONSULTAR USUARIO");
                    saltosLinea();
                    titulo("\t4. Proveedor");
                    cout << tmp.getInfo() << endl << endl;
                    cout << "\t1. Mostrar contrase" << enye() << "a" << endl;
                    cout << "\t0. Volver al menu anterior" << endl << endl;
                    cout << "\tSeleccione una opcion: ";
                    cin >> opc;
                    limpiarPantalla();
                    switch(opc)
                    {
                    case 0:
                        repite = false;
                        break;
                    case 1:
                        repite = false;
                        marcoMenus("CONSULTAR USUARIO");
                        saltosLinea();
                        titulo("\t4. Proveedor");
                        cout << tmp.getInfo();
                        gotoxy (20, 16);
                        cout << tmp.getContrasena() << "      ";
                        gotoxy (0, 19);
                        pausa();
                        break;
                    default:
                        marcoMenus("CONSULTAR USUARIO");
                        saltosLinea();
                        titulo("\tOpcion incorrecta");
                        pausa();
                        break;
                    }
                }
                while(repite);
            }
            if(existe)
                break;
        }
        if(!existe)
        {
            marcoMenus("CONSULTAR USUARIO");
            saltosLinea();
            titulo("\tNo hay proveedores con ese numero de identificacion en el sistema");
            pausa();
        }
    }
    else
    {
        marcoMenus("CONSULTAR USUARIO");
        saltosLinea();
        titulo("\tNo hay proveedores en el sistema");
        pausa();
    }
}

void consultarCliente()
{
    int opc;
    bool repite = true, existe = false;
    string idBuscar;
    marcoMenus("CONSULTAR USUARIO");
    saltosLinea();
    titulo("\t5. Cliente");
    cout << "\tIngrese el numero de identificacion: ";
    fflush(stdin);
    getline(cin, idBuscar);
    limpiarPantalla();
    if(vecClientes.size() > 0)
    {
        Cliente tmp = Cliente();
        for(int i = 0; i < vecClientes.size(); i++)
        {
            tmp = vecClientes.at(i);
            if(tmp.getNumID() == idBuscar)
            {
                existe = true;
                do
                {
                    marcoMenus("CONSULTAR USUARIO");
                    saltosLinea();
                    titulo("\t5. Cliente");
                    cout << tmp.getInfo() << endl << endl;
                    cout << "\t1. Mostrar contrase" << enye() << "a" << endl;
                    cout << "\t0. Volver al menu anterior" << endl << endl;
                    cout << "\tSeleccione una opcion: ";
                    cin >> opc;
                    limpiarPantalla();
                    switch(opc)
                    {
                    case 0:
                        repite = false;
                        break;
                    case 1:
                        repite = false;
                        marcoMenus("CONSULTAR USUARIO");
                        saltosLinea();
                        titulo("\t5. Cliente");
                        cout << tmp.getInfo();
                        gotoxy (20, 16);
                        cout << tmp.getContrasena() << "      ";
                        gotoxy (0, 20);
                        pausa();
                        break;
                    default:
                        marcoMenus("CONSULTAR USUARIO");
                        saltosLinea();
                        titulo("\tOpcion incorrecta");
                        pausa();
                        break;
                    }
                }
                while(repite);
            }
            if(existe)
                break;
        }
        if(!existe)
        {
            marcoMenus("CONSULTAR USUARIO");
            saltosLinea();
            titulo("\tNo hay clientes con ese numero de identificacion en el sistema");
            pausa();
        }
    }
    else
    {
        marcoMenus("CONSULTAR USUARIO");
        saltosLinea();
        titulo("\tNo hay clientes en el sistema");
        pausa();
    }
}

void consultarProducto()
{
    bool repite = true, existe = false;
    long idBuscar;
    marcoMenus("CONSULTAR PRODUCTO");
    saltosLinea();
    titulo("\tProducto");
    cout << "\tIngrese el numero de ID del producto: ";
    cin >> idBuscar;
    limpiarPantalla();
    if(vecInventario.size() > 0)
    {
        Producto tmp = Producto();
        for(int i = 0; i < vecInventario.size(); i++)
        {
            tmp = vecInventario.at(i);
            if(tmp.getProductoID() == idBuscar)
            {
                existe = true;
                do
                {
                    marcoMenus("CONSULTAR PRODUCTO");
                    saltosLinea();
                    titulo("\tProducto");
                    cout << tmp.getInfo() << endl << endl;
                    pausa();
                    repite = false;
                }
                while(repite);
            }
            if(existe)
                break;
        }
        if(!existe)
        {
            marcoMenus("CONSULTAR PRODUCTO");
            saltosLinea();
            titulo("\tNo hay producto con ese numero de ID en el sistema");
            pausa();
        }
    }
    else
    {
        marcoMenus("CONSULTAR PRODUCTO");
        saltosLinea();
        titulo("\tNo hay productos en el sistema");
        pausa();
    }
}

void consultarPedido()
{
    bool repite = true, existe = false;
    long idBuscar;
    marcoMenus("CONSULTAR PEDIDO");
    saltosLinea();
    titulo("\tPedido");
    cout << "\tIngrese el numero de ID del pedido: ";
    fflush(stdin);
    cin >> idBuscar;
    limpiarPantalla();
    if(vecPedidos.size() > 0)
    {
        Pedido tmp = Pedido();
        for(int i = 0; i < vecPedidos.size(); i++)
        {
            tmp = vecPedidos.at(i);
            if(tmp.getPedidoID() == idBuscar)
            {
                existe = true;
                do
                {
                    marcoMenus("CONSULTAR PEDIDO");
                    saltosLinea();
                    titulo("\tPedido");
                    cout << tmp.getInfoP() << endl;
                    separador();
                    pausa();
                    repite = false;
                }
                while(repite);
            }
            if(existe)
                break;
        }
        if(!existe)
        {
            marcoMenus("CONSULTAR PEDIDO");
            saltosLinea();
            titulo("\tNo hay pedidos con ese numero de ID en el sistema");
            pausa();
        }
    }
    else
    {
        marcoMenus("CONSULTAR PEDIDO");
        saltosLinea();
        titulo("\tNo hay pedidos en el sistema");
        pausa();
    }

}

void crearAdmin()
{
    bool repite = true;
    int opc;
    marcoMenus("INGRESAR USUARIO");
    saltosLinea();
    titulo("\t1. Administrador");
    Administrador tmp = Administrador();
    tmp.setEstado(true);
    tmp.setNombre();
    tmp.setApellido();
    tmp.setNumID();
    tmp.setEmail();
    tmp.setTelefono();
    tmp.setContrasena();
    tmp.setSalario(3000000);
    tmp.setJornada(16);
    tmp.setNumDepto(vecAdmins.size());
    vecAdmins.push_back(tmp);
    do
    {
        limpiarPantalla();
        marcoMenus("INGRESAR USUARIO");
        saltosLinea();
        titulo("\t1. Administrador");
        cout << tmp.getInfo() << endl << endl;
        separador();
        cout << "\t1. Mostrar contrase" << enye() << "a" << endl;
        cout << "\t0. Volver al menu anterior" << endl << endl;
        cout << "\tSeleccione una opcion: ";
        cin >> opc;
        limpiarPantalla();
        switch(opc)
        {
        case 0:
            repite = false;
            break;
        case 1:
        {
            repite = false;
            marcoMenus("INGRESAR USUARIO");
            saltosLinea();
            titulo("\t1. Administrador");
            cout << tmp.getInfo();
            gotoxy (20, 16);
            cout << tmp.getContrasena() << "      ";
            gotoxy (0, 21);
            pausa();
            break;
        }
        default:
            marcoMenus("INGRESAR USUARIO");
            saltosLinea();
            titulo("\tOpcion incorrecta");
            pausa();
            break;
        }
    }
    while(repite);
}

void crearSupervisor()
{
    bool repite = true;
    int opc;
    marcoMenus("INGRESAR USUARIO");
    saltosLinea();
    titulo("\t2. Supervisor");
    Supervisor tmp = Supervisor();
    tmp.setEstado(true);
    tmp.setNombre();
    tmp.setApellido();
    tmp.setNumID();
    tmp.setEmail();
    tmp.setTelefono();
    tmp.setContrasena();
    tmp.setSalario(2000000);
    tmp.setJornada(16);
    tmp.setNumOficina(vecSupervisores.size());
    vecSupervisores.push_back(tmp);
    do
    {
        limpiarPantalla();
        marcoMenus("INGRESAR USUARIO");
        saltosLinea();
        titulo("\t2. Supervisor");
        cout << tmp.getInfo() << endl << endl;
        cout << "\t1. Mostrar contrase" << enye() << "a" << endl;
        cout << "\t0. Volver al menu anterior" << endl << endl;
        cout << "\tSeleccione una opcion: ";
        cin >> opc;
        limpiarPantalla();
        switch(opc)
        {
        case 0:
            repite = false;
            break;
        case 1:
        {
            repite = false;
            marcoMenus("INGRESAR USUARIO");
            saltosLinea();
            titulo("\t2. Supervisor");
            cout << tmp.getInfo();
            gotoxy (20, 16);
            cout << tmp.getContrasena() << "      ";
            gotoxy (0, 21);
            pausa();
            break;
        }
        default:
            marcoMenus("INGRESAR USUARIO");
            saltosLinea();
            titulo("\tOpcion incorrecta");
            pausa();
            break;
        }
    }
    while(repite);
}

void crearCajero()
{
    bool repite = true;
    int opc;
    marcoMenus("INGRESAR USUARIO");
    saltosLinea();
    titulo("\t3. Cajero");
    Cajero tmp = Cajero();
    tmp.setEstado(true);
    tmp.setNombre();
    tmp.setApellido();
    tmp.setNumID();
    tmp.setEmail();
    tmp.setTelefono();
    tmp.setContrasena();
    tmp.setSalario(1000000);
    tmp.setJornada(16);
    tmp.setNumCaja(vecCajeros.size());
    vecCajeros.push_back(tmp);
    do
    {
        limpiarPantalla();
        marcoMenus("INGRESAR USUARIO");
        saltosLinea();
        titulo("\t3. Cajero");
        cout << tmp.getInfo() << endl << endl;
        cout << "\t1. Mostrar contrase" << enye() << "a" << endl;
        cout << "\t0. Volver al menu anterior" << endl << endl;
        cout << "\tSeleccione una opcion: ";
        cin >> opc;
        limpiarPantalla();
        switch(opc)
        {
        case 0:
            repite = false;
            break;
        case 1:
        {
            repite = false;
            marcoMenus("INGRESAR USUARIO");
            saltosLinea();
            titulo("\t3. Cajero");
            cout << tmp.getInfo();
            gotoxy (20, 16);
            cout << tmp.getContrasena() << "      ";
            gotoxy (0, 21);
            pausa();
            break;
        }
        default:
            marcoMenus("INGRESAR USUARIO");
            saltosLinea();
            titulo("\tOpcion incorrecta");
            pausa();
            break;
        }
    }
    while(repite);
}

void crearProveedor()
{
    bool repite = true;
    int opc;
    marcoMenus("INGRESAR USUARIO");
    saltosLinea();
    titulo("\t4. Proveedor");
    Proveedor tmp = Proveedor();
    tmp.setEstado(true);
    tmp.setNombre();
    tmp.setApellido();
    tmp.setNumID();
    tmp.setEmail();
    tmp.setTelefono();
    tmp.setContrasena();
    tmp.setNumCamiones();
    vecProveedores.push_back(tmp);
    do
    {
        limpiarPantalla();
        marcoMenus("INGRESAR USUARIO");
        saltosLinea();
        titulo("\t4. Proveedor");
        cout << tmp.getInfo() << endl << endl;
        cout << "\t1. Mostrar contrase" << enye() << "a" << endl;
        cout << "\t0. Volver al menu anterior" << endl << endl;
        cout << "\tSeleccione una opcion: ";
        cin >> opc;
        limpiarPantalla();
        switch(opc)
        {
        case 0:
            repite = false;
            break;
        case 1:
        {
            repite = false;
            marcoMenus("INGRESAR USUARIO");
            saltosLinea();
            titulo("\t4. Proveedor");
            cout << tmp.getInfo();
            gotoxy (20, 16);
            cout << tmp.getContrasena() << "      ";
            gotoxy (0, 19);
            pausa();
            break;
        }
        default:
            marcoMenus("INGRESAR USUARIO");
            saltosLinea();
            titulo("\tOpcion incorrecta");
            pausa();
            break;
        }
    }
    while(repite);
}

void crearCliente()
{
    bool repite = true;
    int opc;
    marcoMenus("INGRESAR USUARIO");
    saltosLinea();
    titulo("\t5. Cliente");
    Cliente tmp = Cliente();
    tmp.setEstado(true);
    tmp.setNombre();
    tmp.setApellido();
    tmp.setNumID();
    tmp.setEmail();
    tmp.setTelefono();
    tmp.setContrasena();
    tmp.setPuntos(0);
    tmp.setMembresia(16);
    vecClientes.push_back(tmp);
    do
    {
        limpiarPantalla();
        marcoMenus("INGRESAR USUARIO");
        saltosLinea();
        titulo("\t5. Cliente");
        cout << tmp.getInfo() << endl << endl;
        cout << "\t1. Mostrar contrase" << enye() << "a" << endl;
        cout << "\t0. Volver al menu anterior" << endl << endl;
        cout << "\tSeleccione una opcion: ";
        cin >> opc;
        limpiarPantalla();
        switch(opc)
        {
        case 0:
            repite = false;
            break;
        case 1:
        {
            repite = false;
            marcoMenus("INGRESAR USUARIO");
            saltosLinea();
            titulo("\t5. Cliente");
            cout << tmp.getInfo();
            gotoxy (20, 16);
            cout << tmp.getContrasena() << "      ";
            gotoxy (0, 20);
            pausa();
            break;
        }
        default:
            marcoMenus("INGRESAR USUARIO");
            saltosLinea();
            titulo("\tOpcion incorrecta");
            pausa();
            break;
        }
    }
    while(repite);
}

void crearProducto()
{
    marcoMenus("INGRESAR PRODUCTO");
    saltosLinea();
    titulo("\t Nuevo Producto");
    Producto tmp = Producto();
    tmp.setNombre();
    tmp.setProductoID();
    tmp.setMarca();
    tmp.setCantidad();
    tmp.setValor();
    tmp.setDescuento();
    tmp.setValorDesc();
    vecInventario.push_back(tmp);
    limpiarPantalla();
    marcoMenus("INGRESAR PRODUCTO");
    saltosLinea();
    cout<<tmp.getInfo();
    pausa();
}

void cierreCaja()
{
    bool repite = true;
    int opc;
    marcoMenus("CIERRE CAJA");
    saltosLinea();
    titulo("\tPRODUCTOS");
    int valorTotal = 0, cantidadProductos = 0;
    Producto vent = Producto();
    for(int i = 0; i < vecVentas.size(); i++)
    {
        vent = vecVentas.at(i);
        cout << vent.getInfo() << endl;
        separador();
        valorTotal += (vent.getValorDesc() * vent.getCantidad());
        cantidadProductos += vent.getCantidad();
    }
    cout << "\tGanancias registradas en el dia: " << valorTotal << endl;
    cout << "\tCantidad productos vendidos en el dia: " << cantidadProductos << endl << endl;
}

void crearPedido()
{
    bool repite = true, existe = false;
    long idBuscar;
    int opc;
    do
    {
        limpiarPantalla();
        marcoMenus("CREAR PEDIDO");
        saltosLinea();
        titulo("\tCrear pedido");
        cout << "\t1. Producto nuevo" << endl;
        cout << "\t2. Producto ya existente" << endl;
        cout << "\t0. Volver al menu anterior" << endl << endl;
        cout << "\tSeleccione una opcion: ";
        cin >> opc;
        limpiarPantalla();
        switch(opc)
        {
        case 0:
            repite = false;
            break;
        case 1:
        {
            marcoMenus("INGRESAR PEDIDOS");
            saltosLinea();
            titulo("\t1. Producto nuevo");
            Pedido tmpPed = Pedido();
            tmpPed.setTiempo();
            tmpPed.setPedidoID(vecPedidos.size());
            tmpPed.setNombreP();
            tmpPed.setProductoIDP();
            tmpPed.setMarcaP();
            tmpPed.setCantidadP();
            tmpPed.setValorP();
            tmpPed.setEstadoP(false);
            vecPedidos.push_back(tmpPed);
            limpiarPantalla();
            marcoMenus("INGRESAR PEDIDOS");
            saltosLinea();
            cout<<tmpPed.getInfoP()<<endl;
            pausa();
            repite = false;
            break;
        }
        case 2:
        {
            marcoMenus("INGRESAR PEDIDOS");
            saltosLinea();
            titulo("\t2. Producto ya existente");
            cout << "\tIngrese el numero de ID del producto: ";
            cin >> idBuscar;
            limpiarPantalla();
            if(vecInventario.size() > 0)
            {
                Producto tmp = Producto();
                for(int i = 0; i < vecInventario.size(); i++)
                {
                    tmp = vecInventario.at(i);
                    if(tmp.getProductoID() == idBuscar)
                    {
                        existe = true;
                        marcoMenus("INGRESAR PEDIDOS");
                        saltosLinea();
                        titulo("\t2. Producto ya existente");
                        Pedido tmpPed = Pedido(tmp.getNombre(), tmp.getMarca(), tmp.getCantidad(), tmp.getValor(), vecPedidos.size(), idBuscar, false);// nombre, marca, cantidad, valor, pedidoID, productoID, estado
                        tmpPed.setTiempo();
                        tmpPed.setCantidadP();
                        vecPedidos.push_back(tmpPed);
                        limpiarPantalla();
                        marcoMenus("INGRESAR PEDIDOS");
                        saltosLinea();
                        cout<<tmpPed.getInfoP()<<endl;
                        pausa();
                    }
                    if(existe)
                        break;
                }
                if(!existe)
                {
                    marcoMenus("INGRESAR PEDIDOS");
                    saltosLinea();
                    titulo("\tNo hay producto con ese numero de ID en el sistema");
                    pausa();
                }
            }
            else
            {
                marcoMenus("INGRESAR PEDIDOS");
                saltosLinea();
                titulo("\tNo hay productos en el sistema");
                pausa();
            }
            repite = false;
            break;
        }
        default:
            marcoMenus("INGRESAR USUARIO");
            saltosLinea();
            titulo("\tOpcion incorrecta");
            pausa();
            break;
        }
    }
    while(repite);
}

void modificarAdmin()
{
    int opc;
    bool repite = true, existe = false;
    string idBuscar;
    marcoMenus("MODIFICAR USUARIO");
    saltosLinea();
    titulo("\t1. Administrador");
    cout << "\tIngrese el numero de identificacion: ";
    fflush(stdin);
    getline(cin, idBuscar);
    limpiarPantalla();
    if(vecAdmins.size() > 0)
    {
        Administrador tmp = Administrador();
        for(int i = 0; i < vecAdmins.size(); i++)
        {
            tmp = vecAdmins.at(i);
            if(tmp.getNumID() == idBuscar)
            {
                existe = true;
                do
                {
                    marcoMenus("MODIFICAR USUARIO");
                    saltosLinea();
                    titulo("\t1. Administrador");
                    cout << tmp.getInfo() << endl << endl;
                    separador();
                    cout << "\t1. Estado" << endl;
                    cout << "\t2. Nombre" << endl;
                    cout << "\t3. Apellido" << endl;
                    cout << "\t4. Numero de identificacion" << endl;
                    cout << "\t5. Correo electronico" << endl;
                    cout << "\t6. Telefono" << endl;
                    cout << "\t7. Contrase" << enye() << "a" << endl;
                    cout << "\t8. Salario" << endl;
                    cout << "\t9. Jornada" << endl;
                    cout << "\t10. Numero de departamento" << endl;
                    cout << "\t0. Volver al menu anterior" << endl << endl;
                    cout << "\tSeleccione una opcion: ";
                    cin >> opc;
                    limpiarPantalla();
                    switch(opc)
                    {
                    case 0:
                        repite = false;
                        break;
                    case 1:
                        marcoMenus("MODIFICAR USUARIO");
                        saltosLinea();
                        titulo("\t1. Administrador");
                        cout << tmp.getInfo() << endl << endl;
                        separador();
                        tmp.setEstado(23);
                        limpiarPantalla();
                        break;
                    case 2:
                        marcoMenus("MODIFICAR USUARIO");
                        saltosLinea();
                        titulo("\t1. Administrador");
                        cout << tmp.getInfo() << endl << endl;
                        separador();
                        tmp.setNombre();
                        limpiarPantalla();
                        break;
                    case 3:
                        marcoMenus("MODIFICAR USUARIO");
                        saltosLinea();
                        titulo("\t1. Administrador");
                        cout << tmp.getInfo() << endl << endl;
                        separador();
                        tmp.setApellido();
                        limpiarPantalla();
                        break;
                    case 4:
                        marcoMenus("MODIFICAR USUARIO");
                        saltosLinea();
                        titulo("\t1. Administrador");
                        cout << tmp.getInfo() << endl << endl;
                        separador();
                        tmp.setNumID();
                        limpiarPantalla();
                        break;
                    case 5:
                        marcoMenus("MODIFICAR USUARIO");
                        saltosLinea();
                        titulo("\t1. Administrador");
                        cout << tmp.getInfo() << endl << endl;
                        separador();
                        tmp.setEmail();
                        limpiarPantalla();
                        break;
                    case 6:
                        marcoMenus("MODIFICAR USUARIO");
                        saltosLinea();
                        titulo("\t1. Administrador");
                        cout << tmp.getInfo() << endl << endl;
                        separador();
                        tmp.setTelefono();
                        limpiarPantalla();
                        break;
                    case 7:
                        marcoMenus("MODIFICAR USUARIO");
                        saltosLinea();
                        titulo("\t1. Administrador");
                        cout << tmp.getInfo() << endl << endl;
                        separador();
                        tmp.setContrasena();
                        limpiarPantalla();
                        break;
                    case 8:
                        marcoMenus("MODIFICAR USUARIO");
                        saltosLinea();
                        titulo("\t1. Administrador");
                        cout << tmp.getInfo() << endl << endl;
                        separador();
                        tmp.setSalario();
                        limpiarPantalla();
                        break;
                    case 9:
                        marcoMenus("MODIFICAR USUARIO");
                        saltosLinea();
                        titulo("\t1. Administrador");
                        cout << tmp.getInfo() << endl << endl;
                        separador();
                        tmp.setJornada(23);
                        limpiarPantalla();
                        break;
                    case 10:
                        marcoMenus("MODIFICAR USUARIO");
                        saltosLinea();
                        titulo("\t1. Administrador");
                        cout << tmp.getInfo() << endl << endl;
                        separador();
                        tmp.setNumDepto();
                        limpiarPantalla();
                        break;
                    default:
                        marcoMenus("MODIFICAR USUARIO");
                        saltosLinea();
                        titulo("\tOpcion incorrecta");
                        pausa();
                        break;
                    }
                }
                while(repite);
                vecAdmins.at(i) = tmp;
            }
            if(existe)
                break;
        }
        if(!existe)
        {
            marcoMenus("MODIFICAR USUARIO");
            saltosLinea();
            titulo("\tNo hay administradores con ese numero de identificacion en el sistema");
            pausa();
        }
    }
    else
    {
        marcoMenus("MODIFICAR USUARIO");
        saltosLinea();
        titulo("\tNo hay administradores en el sistema");
        pausa();
    }
}

void modificarSupervisor()
{
    int opc;
    bool repite = true, existe = false;
    string idBuscar;
    marcoMenus("MODIFICAR USUARIO");
    saltosLinea();
    titulo("\t2. Supervisor");
    cout << "\tIngrese el numero de identificacion: ";
    fflush(stdin);
    getline(cin, idBuscar);
    limpiarPantalla();
    if(vecSupervisores.size() > 0)
    {
        Supervisor tmp = Supervisor();
        for(int i = 0; i < vecSupervisores.size(); i++)
        {
            tmp = vecSupervisores.at(i);
            if(tmp.getNumID() == idBuscar)
            {
                existe = true;
                do
                {
                    marcoMenus("MODIFICAR USUARIO");
                    saltosLinea();
                    titulo("\t2. Supervisor");
                    cout << tmp.getInfo() << endl << endl;
                    separador();
                    cout << "\t1. Estado" << endl;
                    cout << "\t2. Nombre" << endl;
                    cout << "\t3. Apellido" << endl;
                    cout << "\t4. Numero de identificacion" << endl;
                    cout << "\t5. Correo electronico" << endl;
                    cout << "\t6. Telefono" << endl;
                    cout << "\t7. Contrase" << enye() << "a" << endl;
                    cout << "\t8. Salario" << endl;
                    cout << "\t9. Jornada" << endl;
                    cout << "\t10. Numero de oficina" << endl;
                    cout << "\t0. Volver al menu anterior" << endl << endl;
                    cout << "\tSeleccione una opcion: ";
                    cin >> opc;
                    limpiarPantalla();
                    switch(opc)
                    {
                    case 0:
                        repite = false;
                        break;
                    case 1:
                        marcoMenus("MODIFICAR USUARIO");
                        saltosLinea();
                        titulo("\t2. Supervisor");
                        cout << tmp.getInfo() << endl << endl;
                        separador();
                        tmp.setEstado(23);
                        limpiarPantalla();
                        break;
                    case 2:
                        marcoMenus("MODIFICAR USUARIO");
                        saltosLinea();
                        titulo("\t2. Supervisor");
                        cout << tmp.getInfo() << endl << endl;
                        separador();
                        tmp.setNombre();
                        limpiarPantalla();
                        break;
                    case 3:
                        marcoMenus("MODIFICAR USUARIO");
                        saltosLinea();
                        titulo("\t2. Supervisor");
                        cout << tmp.getInfo() << endl << endl;
                        separador();
                        tmp.setApellido();
                        limpiarPantalla();
                        break;
                    case 4:
                        marcoMenus("MODIFICAR USUARIO");
                        saltosLinea();
                        titulo("\t2. Supervisor");
                        cout << tmp.getInfo() << endl << endl;
                        separador();
                        tmp.setNumID();
                        limpiarPantalla();
                        break;
                    case 5:
                        marcoMenus("MODIFICAR USUARIO");
                        saltosLinea();
                        titulo("\t2. Supervisor");
                        cout << tmp.getInfo() << endl << endl;
                        separador();
                        tmp.setEmail();
                        limpiarPantalla();
                        break;
                    case 6:
                        marcoMenus("MODIFICAR USUARIO");
                        saltosLinea();
                        titulo("\t2. Supervisor");
                        cout << tmp.getInfo() << endl << endl;
                        separador();
                        tmp.setTelefono();
                        limpiarPantalla();
                        break;
                    case 7:
                        marcoMenus("MODIFICAR USUARIO");
                        saltosLinea();
                        titulo("\t2. Supervisor");
                        cout << tmp.getInfo() << endl << endl;
                        separador();
                        tmp.setContrasena();
                        limpiarPantalla();
                        break;
                    case 8:
                        marcoMenus("MODIFICAR USUARIO");
                        saltosLinea();
                        titulo("\t2. Supervisor");
                        cout << tmp.getInfo() << endl << endl;
                        separador();
                        tmp.setSalario();
                        limpiarPantalla();
                        break;
                    case 9:
                        marcoMenus("MODIFICAR USUARIO");
                        saltosLinea();
                        titulo("\t2. Supervisor");
                        cout << tmp.getInfo() << endl << endl;
                        separador();
                        tmp.setJornada(23);
                        limpiarPantalla();
                        break;
                    case 10:
                        marcoMenus("MODIFICAR USUARIO");
                        saltosLinea();
                        titulo("\t2. Supervisor");
                        cout << tmp.getInfo() << endl << endl;
                        separador();
                        tmp.setNumOficina();
                        limpiarPantalla();
                        break;
                    default:
                        marcoMenus("MODIFICAR USUARIO");
                        saltosLinea();
                        titulo("\tOpcion incorrecta");
                        pausa();
                        break;
                    }
                }
                while(repite);
                vecSupervisores.at(i) = tmp;
            }
            if(existe)
                break;
        }
        if(!existe)
        {
            marcoMenus("MODIFICAR USUARIO");
            saltosLinea();
            titulo("\tNo hay supervisores con ese numero de identificacion en el sistema");
            pausa();
        }
    }
    else
    {
        marcoMenus("MODIFICAR USUARIO");
        saltosLinea();
        titulo("\tNo hay supervisores en el sistema");
        pausa();
    }
}

void modificarCajero()
{
    int opc;
    bool repite = true, existe = false;
    string idBuscar;
    marcoMenus("MODIFICAR USUARIO");
    saltosLinea();
    titulo("\t3. Cajero");
    cout << "\tIngrese el numero de identificacion: ";
    fflush(stdin);
    getline(cin, idBuscar);
    limpiarPantalla();
    if(vecCajeros.size() > 0)
    {
        Cajero tmp = Cajero();
        for(int i = 0; i < vecCajeros.size(); i++)
        {
            tmp = vecCajeros.at(i);
            if(tmp.getNumID() == idBuscar)
            {
                existe = true;
                do
                {
                    marcoMenus("MODIFICAR USUARIO");
                    saltosLinea();
                    titulo("\t3. Cajero");
                    cout << tmp.getInfo() << endl << endl;
                    separador();
                    cout << "\t1. Estado" << endl;
                    cout << "\t2. Nombre" << endl;
                    cout << "\t3. Apellido" << endl;
                    cout << "\t4. Numero de identificacion" << endl;
                    cout << "\t5. Correo electronico" << endl;
                    cout << "\t6. Telefono" << endl;
                    cout << "\t7. Contrase" << enye() << "a" << endl;
                    cout << "\t8. Salario" << endl;
                    cout << "\t9. Jornada" << endl;
                    cout << "\t10. Numero de caja" << endl;
                    cout << "\t0. Volver al menu anterior" << endl << endl;
                    cout << "\tSeleccione una opcion: ";
                    cin >> opc;
                    limpiarPantalla();
                    switch(opc)
                    {
                    case 0:
                        repite = false;
                        break;
                    case 1:
                        marcoMenus("MODIFICAR USUARIO");
                        saltosLinea();
                        titulo("\t3. Cajero");
                        cout << tmp.getInfo() << endl << endl;
                        separador();
                        tmp.setEstado(23);
                        limpiarPantalla();
                        break;
                    case 2:
                        marcoMenus("MODIFICAR USUARIO");
                        saltosLinea();
                        titulo("\t3. Cajero");
                        cout << tmp.getInfo() << endl << endl;
                        separador();
                        tmp.setNombre();
                        limpiarPantalla();
                        break;
                    case 3:
                        marcoMenus("MODIFICAR USUARIO");
                        saltosLinea();
                        titulo("\t3. Cajero");
                        cout << tmp.getInfo() << endl << endl;
                        separador();
                        tmp.setApellido();
                        limpiarPantalla();
                        break;
                    case 4:
                        marcoMenus("MODIFICAR USUARIO");
                        saltosLinea();
                        titulo("\t3. Cajero");
                        cout << tmp.getInfo() << endl << endl;
                        separador();
                        tmp.setNumID();
                        limpiarPantalla();
                        break;
                    case 5:
                        marcoMenus("MODIFICAR USUARIO");
                        saltosLinea();
                        titulo("\t3. Cajero");
                        cout << tmp.getInfo() << endl << endl;
                        separador();
                        tmp.setEmail();
                        limpiarPantalla();
                        break;
                    case 6:
                        marcoMenus("MODIFICAR USUARIO");
                        saltosLinea();
                        titulo("\t3. Cajero");
                        cout << tmp.getInfo() << endl << endl;
                        separador();
                        tmp.setTelefono();
                        limpiarPantalla();
                        break;
                    case 7:
                        marcoMenus("MODIFICAR USUARIO");
                        saltosLinea();
                        titulo("\t3. Cajero");
                        cout << tmp.getInfo() << endl << endl;
                        separador();
                        tmp.setContrasena();
                        limpiarPantalla();
                        break;
                    case 8:
                        marcoMenus("MODIFICAR USUARIO");
                        saltosLinea();
                        titulo("\t3. Cajero");
                        cout << tmp.getInfo() << endl << endl;
                        separador();
                        tmp.setSalario();
                        limpiarPantalla();
                        break;
                    case 9:
                        marcoMenus("MODIFICAR USUARIO");
                        saltosLinea();
                        titulo("\t3. Cajero");
                        cout << tmp.getInfo() << endl << endl;
                        separador();
                        tmp.setJornada(23);
                        limpiarPantalla();
                        break;
                    case 10:
                        marcoMenus("MODIFICAR USUARIO");
                        saltosLinea();
                        titulo("\t3. Cajero");
                        cout << tmp.getInfo() << endl << endl;
                        separador();
                        tmp.setNumCaja();
                        limpiarPantalla();
                        break;
                    default:
                        marcoMenus("MODIFICAR USUARIO");
                        saltosLinea();
                        titulo("\tOpcion incorrecta");
                        pausa();
                        break;
                    }
                }
                while(repite);
                vecCajeros.at(i) = tmp;
            }
            if(existe)
                break;
        }
        if(!existe)
        {
            marcoMenus("MODIFICAR USUARIO");
            saltosLinea();
            titulo("\tNo hay cajeros con ese numero de identificacion en el sistema");
            pausa();
        }
    }
    else
    {
        marcoMenus("MODIFICAR USUARIO");
        saltosLinea();
        titulo("\tNo hay cajeros en el sistema");
        pausa();
    }
}

void modificarProveedor()
{
    int opc;
    bool repite = true, existe = false;
    string idBuscar;
    marcoMenus("MODIFICAR USUARIO");
    saltosLinea();
    titulo("\t4. Proveedor");
    cout << "\tIngrese el numero de identificacion: ";
    fflush(stdin);
    getline(cin, idBuscar);
    limpiarPantalla();
    if(vecProveedores.size() > 0)
    {
        Proveedor tmp = Proveedor();
        for(int i = 0; i < vecProveedores.size(); i++)
        {
            tmp = vecProveedores.at(i);
            if(tmp.getNumID() == idBuscar)
            {
                existe = true;
                do
                {
                    marcoMenus("MODIFICAR USUARIO");
                    saltosLinea();
                    titulo("\t4. Proveedor");
                    cout << tmp.getInfo() << endl << endl;
                    separador();
                    cout << "\t1. Estado" << endl;
                    cout << "\t2. Nombre" << endl;
                    cout << "\t3. Apellido" << endl;
                    cout << "\t4. Numero de identificacion" << endl;
                    cout << "\t5. Correo electronico" << endl;
                    cout << "\t6. Telefono" << endl;
                    cout << "\t7. Contrase" << enye() << "a" << endl;
                    cout << "\t8. Numero de camiones" << endl;
                    cout << "\t0. Volver al menu anterior" << endl << endl;
                    cout << "\tSeleccione una opcion: ";
                    cin >> opc;
                    limpiarPantalla();
                    switch(opc)
                    {
                    case 0:
                        repite = false;
                        break;
                    case 1:
                        marcoMenus("MODIFICAR USUARIO");
                        saltosLinea();
                        titulo("\t4. Proveedor");
                        cout << tmp.getInfo() << endl << endl;
                        separador();
                        tmp.setEstado(21);
                        limpiarPantalla();
                        break;
                    case 2:
                        marcoMenus("MODIFICAR USUARIO");
                        saltosLinea();
                        titulo("\t4. Proveedor");
                        cout << tmp.getInfo() << endl << endl;
                        separador();
                        tmp.setNombre();
                        limpiarPantalla();
                        break;
                    case 3:
                        marcoMenus("MODIFICAR USUARIO");
                        saltosLinea();
                        titulo("\t4. Proveedor");
                        cout << tmp.getInfo() << endl << endl;
                        separador();
                        tmp.setApellido();
                        limpiarPantalla();
                        break;
                    case 4:
                        marcoMenus("MODIFICAR USUARIO");
                        saltosLinea();
                        titulo("\t4. Proveedor");
                        cout << tmp.getInfo() << endl << endl;
                        separador();
                        tmp.setNumID();
                        limpiarPantalla();
                        break;
                    case 5:
                        marcoMenus("MODIFICAR USUARIO");
                        saltosLinea();
                        titulo("\t4. Proveedor");
                        cout << tmp.getInfo() << endl << endl;
                        separador();
                        tmp.setEmail();
                        limpiarPantalla();
                        break;
                    case 6:
                        marcoMenus("MODIFICAR USUARIO");
                        saltosLinea();
                        titulo("\t4. Proveedor");
                        cout << tmp.getInfo() << endl << endl;
                        separador();
                        tmp.setTelefono();
                        limpiarPantalla();
                        break;
                    case 7:
                        marcoMenus("MODIFICAR USUARIO");
                        saltosLinea();
                        titulo("\t4. Proveedor");
                        cout << tmp.getInfo() << endl << endl;
                        separador();
                        tmp.setContrasena();
                        limpiarPantalla();
                        break;
                    case 8:
                        marcoMenus("MODIFICAR USUARIO");
                        saltosLinea();
                        titulo("\t4. Proveedor");
                        cout << tmp.getInfo() << endl << endl;
                        separador();
                        tmp.setNumCamiones();
                        limpiarPantalla();
                        break;
                    default:
                        marcoMenus("MODIFICAR USUARIO");
                        saltosLinea();
                        titulo("\tOpcion incorrecta");
                        pausa();
                        break;
                    }
                }
                while(repite);
                vecProveedores.at(i) = tmp;
            }
            if(existe)
                break;
        }
        if(!existe)
        {
            marcoMenus("MODIFICAR USUARIO");
            saltosLinea();
            titulo("\tNo hay proveedores con ese numero de identificacion en el sistema");
            pausa();
        }
    }
    else
    {
        marcoMenus("MODIFICAR USUARIO");
        saltosLinea();
        titulo("\tNo hay proveedores en el sistema");
        pausa();
    }
}

void modificarCliente()
{
    int opc;
    bool repite = true, existe = false;
    string idBuscar;
    marcoMenus("MODIFICAR USUARIO");
    saltosLinea();
    titulo("\t5. Cliente");
    cout << "\tIngrese el numero de identificacion: ";
    fflush(stdin);
    getline(cin, idBuscar);
    limpiarPantalla();
    if(vecClientes.size() > 0)
    {
        Cliente tmp = Cliente();
        for(int i = 0; i < vecClientes.size(); i++)
        {
            tmp = vecClientes.at(i);
            if(tmp.getNumID() == idBuscar)
            {
                existe = true;
                do
                {
                    marcoMenus("MODIFICAR USUARIO");
                    saltosLinea();
                    titulo("\t5. Cliente");
                    cout << tmp.getInfo() << endl << endl;
                    separador();
                    cout << "\t1. Estado" << endl;
                    cout << "\t2. Nombre" << endl;
                    cout << "\t3. Apellido" << endl;
                    cout << "\t4. Numero de identificacion" << endl;
                    cout << "\t5. Correo electronico" << endl;
                    cout << "\t6. Telefono" << endl;
                    cout << "\t7. Contrase" << enye() << "a" << endl;
                    cout << "\t8. Puntos" << endl;
                    cout << "\t9. Membresia" << endl;
                    cout << "\t0. Volver al menu anterior" << endl << endl;
                    cout << "\tSeleccione una opcion: ";
                    cin >> opc;
                    limpiarPantalla();
                    switch(opc)
                    {
                    case 0:
                        repite = false;
                        break;
                    case 1:
                        marcoMenus("MODIFICAR USUARIO");
                        saltosLinea();
                        titulo("\t5. Cliente");
                        cout << tmp.getInfo() << endl << endl;
                        separador();
                        tmp.setEstado(22);
                        limpiarPantalla();
                        break;
                    case 2:
                        marcoMenus("MODIFICAR USUARIO");
                        saltosLinea();
                        titulo("\t5. Cliente");
                        cout << tmp.getInfo() << endl << endl;
                        separador();
                        tmp.setNombre();
                        limpiarPantalla();
                        break;
                    case 3:
                        marcoMenus("MODIFICAR USUARIO");
                        saltosLinea();
                        titulo("\t5. Cliente");
                        cout << tmp.getInfo() << endl << endl;
                        separador();
                        tmp.setApellido();
                        limpiarPantalla();
                        break;
                    case 4:
                        marcoMenus("MODIFICAR USUARIO");
                        saltosLinea();
                        titulo("\t5. Cliente");
                        cout << tmp.getInfo() << endl << endl;
                        separador();
                        tmp.setNumID();
                        limpiarPantalla();
                        break;
                    case 5:
                        marcoMenus("MODIFICAR USUARIO");
                        saltosLinea();
                        titulo("\t5. Cliente");
                        cout << tmp.getInfo() << endl << endl;
                        separador();
                        tmp.setEmail();
                        limpiarPantalla();
                        break;
                    case 6:
                        marcoMenus("MODIFICAR USUARIO");
                        saltosLinea();
                        titulo("\t5. Cliente");
                        cout << tmp.getInfo() << endl << endl;
                        separador();
                        tmp.setTelefono();
                        limpiarPantalla();
                        break;
                    case 7:
                        marcoMenus("MODIFICAR USUARIO");
                        saltosLinea();
                        titulo("\t5. Cliente");
                        cout << tmp.getInfo() << endl << endl;
                        separador();
                        tmp.setContrasena();
                        limpiarPantalla();
                        break;
                    case 8:
                        marcoMenus("MODIFICAR USUARIO");
                        saltosLinea();
                        titulo("\t5. Cliente");
                        cout << tmp.getInfo() << endl << endl;
                        separador();
                        tmp.setPuntos();
                        limpiarPantalla();
                        break;
                    case 9:
                        marcoMenus("MODIFICAR USUARIO");
                        saltosLinea();
                        titulo("\t5. Cliente");
                        cout << tmp.getInfo() << endl << endl;
                        separador();
                        tmp.setMembresia(22);
                        limpiarPantalla();
                        break;
                    default:
                        marcoMenus("MODIFICAR USUARIO");
                        saltosLinea();
                        titulo("\tOpcion incorrecta");
                        pausa();
                        break;
                    }
                }
                while(repite);
                vecClientes.at(i) = tmp;
            }
            if(existe)
                break;
        }
        if(!existe)
        {
            marcoMenus("MODIFICAR USUARIO");
            saltosLinea();
            titulo("\tNo hay clientes con ese numero de identificacion en el sistema");
            pausa();
        }
    }
    else
    {
        marcoMenus("MODIFICAR USUARIO");
        saltosLinea();
        titulo("\tNo hay clientes en el sistema");
        pausa();
    }
}

void modificarProducto()
{
    int opc;
    bool repite = true, existe = false;
    long idBuscar;
    marcoMenus("MODIFICAR PRODUCTO");
    saltosLinea();
    titulo("\t Producto");
    cout << "\tIngrese el numero de ID del producto: ";
    fflush(stdin);
    cin >> idBuscar;
    limpiarPantalla();
    if(vecInventario.size() > 0)
    {
        Producto tmp = Producto();
        for(int i = 0; i < vecInventario.size(); i++)
        {
            tmp = vecInventario.at(i);
            if(tmp.getProductoID() == idBuscar)
            {
                existe = true;
                do
                {
                    marcoMenus("MODIFICAR PRODUCTO");
                    saltosLinea();
                    titulo("\t Producto");
                    cout << tmp.getInfo() << endl << endl;
                    separador();
                    cout << "\t1. Nombre" << endl;
                    cout << "\t2. Numero de ID" << endl;
                    cout << "\t3. Marca" << endl;
                    cout << "\t4. Cantidad" << endl;
                    cout << "\t5. Valor" << endl;
                    cout << "\t6. Descuento" << endl;
                    cout << "\t0. Volver al menu anterior" << endl << endl;
                    cout << "\tSeleccione una opcion: ";
                    cin >> opc;
                    limpiarPantalla();
                    switch(opc)
                    {
                    case 0:
                        repite = false;
                        break;
                    case 1:
                        marcoMenus("MODIFICAR PRODUCTO");
                        saltosLinea();
                        titulo("\t5. Cliente");
                        cout << tmp.getInfo() << endl << endl;
                        separador();
                        tmp.setNombre();
                        limpiarPantalla();
                        break;
                    case 2:
                        marcoMenus("MODIFICAR PRODUCTO");
                        saltosLinea();
                        titulo("\t5Producto");
                        cout << tmp.getInfo() << endl << endl;
                        separador();
                        tmp.setProductoID();
                        limpiarPantalla();
                        break;
                    case 3:
                        marcoMenus("MODIFICAR PRODUCTO");
                        saltosLinea();
                        titulo("\t5Producto");
                        cout << tmp.getInfo() << endl << endl;
                        separador();
                        tmp.setMarca();
                        limpiarPantalla();
                        break;
                    case 4:
                        marcoMenus("MODIFICAR PRODUCTO");
                        saltosLinea();
                        titulo("\tProducto");
                        cout << tmp.getInfo() << endl << endl;
                        separador();
                        tmp.setCantidad();
                        limpiarPantalla();
                        break;
                    case 5:
                        marcoMenus("MODIFICAR PRODUCTO");
                        saltosLinea();
                        titulo("\tProducto");
                        cout << tmp.getInfo() << endl << endl;
                        separador();
                        tmp.setValor();
                        limpiarPantalla();
                        break;
                    case 6:
                        marcoMenus("MODIFICAR PRODUCTO");
                        saltosLinea();
                        titulo("\tProducto");
                        cout << tmp.getInfo() << endl << endl;
                        separador();
                        tmp.setDescuento();
                        limpiarPantalla();
                        break;
                    default:
                        marcoMenus("MODIFICAR PRODUCTO");
                        saltosLinea();
                        titulo("\tOpcion incorrecta");
                        pausa();
                        break;
                    }
                }
                while(repite);
                vecInventario.at(i) = tmp;
            }
            if(existe)
                break;
        }
        if(!existe)
        {
            marcoMenus("MODIFICAR PRODUCTO");
            saltosLinea();
            titulo("\tNo hay productos con ese numero de ID en el sistema");
            pausa();
        }
    }
    else
    {
        marcoMenus("MODIFICAR PRODUCTO");
        saltosLinea();
        titulo("\tNo hay productos en el sistema");
        pausa();
    }
}

void desactivarAdmin()
{
    bool existe = false;
    string idBuscar;
    marcoMenus("ACTIVAR/DESACTIVAR USUARIO");
    saltosLinea();
    titulo("\t1. Administrador");
    cout << "\tIngrese el numero de identificacion: ";
    fflush(stdin);
    getline(cin, idBuscar);
    limpiarPantalla();
    if(vecAdmins.size() > 0)
    {
        Administrador tmp = Administrador();
        for(int i = 0; i < vecAdmins.size(); i++)
        {
            tmp = vecAdmins.at(i);
            if(tmp.getNumID() == idBuscar)
            {
                existe = true;
                marcoMenus("ACTIVAR/DESACTIVAR USUARIO");
                saltosLinea();
                titulo("\t1. Administrador");
                cout << tmp.getInfo() << endl << endl;
                separador();
                tmp.setEstado(23);
                limpiarPantalla();
                marcoMenus("ACTIVAR/DESACTIVAR USUARIO");
                saltosLinea();
                titulo("\t1. Administrador");
                cout << tmp.getInfo() << endl << endl;
                pausa();
                vecAdmins.at(i) = tmp;
            }
            if(existe)
                break;
        }
        if(!existe)
        {
            marcoMenus("ACTIVAR/DESACTIVAR USUARIO");
            saltosLinea();
            titulo("\tNo hay administradores con ese numero de identificacion en el sistema");
            pausa();
        }
    }
    else
    {
        marcoMenus("ACTIVAR/DESACTIVAR USUARIO");
        saltosLinea();
        titulo("\tNo hay administradores en el sistema");
        pausa();
    }
}

void desactivarSupervisor()
{
    bool existe = false;
    string idBuscar;
    marcoMenus("ACTIVAR/DESACTIVAR USUARIO");
    saltosLinea();
    titulo("\t2. Supervisor");
    cout << "\tIngrese el numero de identificacion: ";
    fflush(stdin);
    getline(cin, idBuscar);
    limpiarPantalla();
    if(vecSupervisores.size() > 0)
    {
        Supervisor tmp = Supervisor();
        for(int i = 0; i < vecSupervisores.size(); i++)
        {
            tmp = vecSupervisores.at(i);
            if(tmp.getNumID() == idBuscar)
            {
                existe = true;
                marcoMenus("ACTIVAR/DESACTIVAR USUARIO");
                saltosLinea();
                titulo("\t2. Supervisor");
                cout << tmp.getInfo() << endl << endl;
                separador();
                tmp.setEstado(23);
                limpiarPantalla();
                marcoMenus("ACTIVAR/DESACTIVAR USUARIO");
                saltosLinea();
                titulo("\t2. Supervisor");
                cout << tmp.getInfo() << endl << endl;
                pausa();
                vecSupervisores.at(i) = tmp;
            }
            if(existe)
                break;
        }
        if(!existe)
        {
            marcoMenus("ACTIVAR/DESACTIVAR USUARIO");
            saltosLinea();
            titulo("\tNo hay supervisores con ese numero de identificacion en el sistema");
            pausa();
        }
    }
    else
    {
        marcoMenus("ACTIVAR/DESACTIVAR USUARIO");
        saltosLinea();
        titulo("\tNo hay supervisores en el sistema");
        pausa();
    }
}

void desactivarCajero()
{
    bool existe = false;
    string idBuscar;
    marcoMenus("ACTIVAR/DESACTIVAR USUARIO");
    saltosLinea();
    titulo("\t3. Cajero");
    cout << "\tIngrese el numero de identificacion: ";
    fflush(stdin);
    getline(cin, idBuscar);
    limpiarPantalla();
    if(vecCajeros.size() > 0)
    {
        Cajero tmp = Cajero();
        for(int i = 0; i < vecCajeros.size(); i++)
        {
            tmp = vecCajeros.at(i);
            if(tmp.getNumID() == idBuscar)
            {
                existe = true;
                marcoMenus("ACTIVAR/DESACTIVAR USUARIO");
                saltosLinea();
                titulo("\t3. Cajero");
                cout << tmp.getInfo() << endl << endl;
                separador();
                tmp.setEstado(23);
                limpiarPantalla();
                marcoMenus("ACTIVAR/DESACTIVAR USUARIO");
                saltosLinea();
                titulo("\t3. Cajero");
                cout << tmp.getInfo() << endl << endl;
                pausa();
                vecCajeros.at(i) = tmp;
            }
            if(existe)
                break;
        }
        if(!existe)
        {
            marcoMenus("ACTIVAR/DESACTIVAR USUARIO");
            saltosLinea();
            titulo("\tNo hay cajeros con ese numero de identificacion en el sistema");
            pausa();
        }
    }
    else
    {
        marcoMenus("ACTIVAR/DESACTIVAR USUARIO");
        saltosLinea();
        titulo("\tNo hay cajeros en el sistema");
        pausa();
    }
}

void desactivarProveedor()
{
    bool existe = false;
    string idBuscar;
    marcoMenus("ACTIVAR/DESACTIVAR USUARIO");
    saltosLinea();
    titulo("\t4. Proveedor");
    cout << "\tIngrese el numero de identificacion: ";
    fflush(stdin);
    getline(cin, idBuscar);
    limpiarPantalla();
    if(vecProveedores.size() > 0)
    {
        Proveedor tmp = Proveedor();
        for(int i = 0; i < vecProveedores.size(); i++)
        {
            tmp = vecProveedores.at(i);
            if(tmp.getNumID() == idBuscar)
            {
                existe = true;
                marcoMenus("ACTIVAR/DESACTIVAR USUARIO");
                saltosLinea();
                titulo("\t4. Proveedor");
                cout << tmp.getInfo() << endl << endl;
                separador();
                tmp.setEstado(21);
                limpiarPantalla();
                marcoMenus("ACTIVAR/DESACTIVAR USUARIO");
                saltosLinea();
                titulo("\t4. Proveedor");
                cout << tmp.getInfo() << endl << endl;
                pausa();
                vecProveedores.at(i) = tmp;
            }
            if(existe)
                break;
        }
        if(!existe)
        {
            marcoMenus("ACTIVAR/DESACTIVAR USUARIO");
            saltosLinea();
            titulo("\tNo hay proveedores con ese numero de identificacion en el sistema");
            pausa();
        }
    }
    else
    {
        marcoMenus("ACTIVAR/DESACTIVAR USUARIO");
        saltosLinea();
        titulo("\tNo hay proveedores en el sistema");
        pausa();
    }
}

void desactivarCliente()
{
    bool existe = false;
    string idBuscar;
    marcoMenus("ACTIVAR/DESACTIVAR USUARIO");
    saltosLinea();
    titulo("\t5. Cliente");
    cout << "\tIngrese el numero de identificacion: ";
    fflush(stdin);
    getline(cin, idBuscar);
    limpiarPantalla();
    if(vecClientes.size() > 0)
    {
        Cliente tmp = Cliente();
        for(int i = 0; i < vecClientes.size(); i++)
        {
            tmp = vecClientes.at(i);
            if(tmp.getNumID() == idBuscar)
            {
                existe = true;
                marcoMenus("ACTIVAR/DESACTIVAR USUARIO");
                saltosLinea();
                titulo("\t5. Cliente");
                cout << tmp.getInfo() << endl << endl;
                separador();
                tmp.setEstado(22);
                limpiarPantalla();
                marcoMenus("ACTIVAR/DESACTIVAR USUARIO");
                saltosLinea();
                titulo("\t5. Cliente");
                cout << tmp.getInfo() << endl << endl;
                pausa();
                vecClientes.at(i) = tmp;
            }
            if(existe)
                break;
        }
        if(!existe)
        {
            marcoMenus("ACTIVAR/DESACTIVAR USUARIO");
            saltosLinea();
            titulo("\tNo hay clientes con ese numero de identificacion en el sistema");
            pausa();
        }
    }
    else
    {
        marcoMenus("ACTIVAR/DESACTIVAR USUARIO");
        saltosLinea();
        titulo("\tNo hay clientes en el sistema");
        pausa();
    }
}

void desactivarPedido()
{
    bool existe = false, existeProd = false;
    long idBuscar;
    marcoMenus("ENVIAR PEDIDO");
    saltosLinea();
    titulo("\t1. Enviar pedido");
    cout << "\tIngrese el numero de identificacion del pedido: ";
    cin>>idBuscar;
    limpiarPantalla();
    if(vecPedidos.size() > 0)
    {
        Pedido tmp = Pedido();
        for(int i = 0; i < vecPedidos.size(); i++)
        {
            tmp = vecPedidos.at(i);
            if(tmp.getPedidoID() == idBuscar)
            {
                existe = true;
                //////////////////////////////////////////////////////////////////////////////
                if(vecInventario.size() > 0)
                {
                    Producto tmpP = Producto();
                    for(int i = 0; i < vecInventario.size(); i++)
                    {
                        tmpP = vecInventario.at(i);
                        if(tmpP.getProductoID() == tmp.getProductoIDP())
                        {
                            existeProd = true;
                            tmpP.setCantidad(tmpP.getCantidad() + tmp.getCantidadP());
                            vecInventario.at(i) = tmpP;
                        }
                        if(existeProd)
                            break;
                    }
                    if(!existeProd)
                    {
                        Producto tmpN = Producto(tmp.getNombreP(), tmp.getMarcaP(), tmp.getCantidadP(), tmp.getValorP(), 0, tmp.getProductoIDP());// nombre, marca, cantidad, valor, descuento, productoID
                        vecInventario.push_back(tmpN);
                    }
                }
                else
                {
                    Producto tmpN = Producto(tmp.getNombreP(), tmp.getMarcaP(), tmp.getCantidadP(), tmp.getValorP(), 0, tmp.getProductoIDP());// nombre, marca, cantidad, valor, descuento, productoID
                    vecInventario.push_back(tmpN);
                }
                ///////////////////////////////////////////////////////////////////////////////
                marcoMenus("ENVIAR PEDIDO");
                saltosLinea();
                titulo("\t1. Enviar pedido");
                tmp.setEstadoP(true);
                vecPedidos.at(i) = tmp;
                cout << tmp.getInfoP() << endl;
                separador();
                pausa();
            }
            if(existe)
                break;
        }
        if(!existe)
        {
            marcoMenus("ENVIAR PEDIDO");
            saltosLinea();
            titulo("\tNo hay pedidos con ese numero de identificacion en el sistema");
            pausa();
        }
    }
    else
    {
        marcoMenus("ENVIAR PEDIDO");
        saltosLinea();
        titulo("\tNo hay pedidos en el sistema");
        pausa();
    }


}

void borrarAdmin()
{
    int opc;
    bool repite = true, existe = false;
    string idBuscar;
    marcoMenus("BORRAR USUARIO");
    saltosLinea();
    titulo("\t1. Administrador");
    cout << "\tIngrese el numero de identificacion: ";
    fflush(stdin);
    getline(cin, idBuscar);
    limpiarPantalla();
    if(vecAdmins.size() > 0)
    {
        Administrador tmp = Administrador();
        for(int i = 0; i < vecAdmins.size(); i++)
        {
            tmp = vecAdmins.at(i);
            if(tmp.getNumID() == idBuscar)
            {
                existe = true;
                do
                {
                    marcoMenus("BORRAR USUARIO");
                    saltosLinea();
                    titulo("\t1. Administrador");
                    cout << tmp.getInfo() << endl << endl;
                    separador();
                    cout << "\tEsta accion es irreversible, seguro que desea borrar este usuario? [1. SI - 0. NO]: ";
                    cin >> opc;
                    limpiarPantalla();
                    switch(opc)
                    {
                    case 0:
                        repite = false;
                        break;
                    case 1:
                        repite = false;
                        vecAdmins.erase(vecAdmins.begin() + i);
                        marcoMenus("BORRAR USUARIO");
                        saltosLinea();
                        titulo("\tUsuario borrado correctamente");
                        pausa();
                        break;
                    default:
                        marcoMenus("BORRAR USUARIO");
                        saltosLinea();
                        titulo("\tOpcion incorrecta");
                        pausa();
                        break;
                    }
                }
                while(repite);
            }
            if(existe)
                break;
        }
        if(!existe)
        {
            marcoMenus("BORRAR USUARIO");
            saltosLinea();
            titulo("\tNo hay administradores con ese numero de identificacion en el sistema");
            pausa();
        }
    }
    else
    {
        marcoMenus("BORRAR USUARIO");
        saltosLinea();
        titulo("\tNo hay administradores en el sistema");
        pausa();
    }
}

void borrarSupervisor()
{
    int opc;
    bool repite = true, existe = false;
    string idBuscar;
    marcoMenus("BORRAR USUARIO");
    saltosLinea();
    titulo("\t2. Supervisor");
    cout << "\tIngrese el numero de identificacion: ";
    fflush(stdin);
    getline(cin, idBuscar);
    limpiarPantalla();
    if(vecSupervisores.size() > 0)
    {
        Supervisor tmp = Supervisor();
        for(int i = 0; i < vecSupervisores.size(); i++)
        {
            tmp = vecSupervisores.at(i);
            if(tmp.getNumID() == idBuscar)
            {
                existe = true;
                do
                {
                    marcoMenus("BORRAR USUARIO");
                    saltosLinea();
                    titulo("\t2. Supervisor");
                    cout << tmp.getInfo() << endl << endl;
                    separador();
                    cout << "\tEsta accion es irreversible, seguro que desea borrar este usuario? [1. SI - 0. NO]: ";
                    cin >> opc;
                    limpiarPantalla();
                    switch(opc)
                    {
                    case 0:
                        repite = false;
                        break;
                    case 1:
                        repite = false;
                        vecSupervisores.erase(vecSupervisores.begin() + i);
                        marcoMenus("BORRAR USUARIO");
                        saltosLinea();
                        titulo("\tUsuario borrado correctamente");
                        pausa();
                        break;
                    default:
                        marcoMenus("BORRAR USUARIO");
                        saltosLinea();
                        titulo("\tOpcion incorrecta");
                        pausa();
                        break;
                    }
                }
                while(repite);
            }
            if(existe)
                break;
        }
        if(!existe)
        {
            marcoMenus("BORRAR USUARIO");
            saltosLinea();
            titulo("\tNo hay supervisores con ese numero de identificacion en el sistema");
            pausa();
        }
    }
    else
    {
        marcoMenus("BORRAR USUARIO");
        saltosLinea();
        titulo("\tNo hay supervisores en el sistema");
        pausa();
    }
}

void borrarCajero()
{
    int opc;
    bool repite = true, existe = false;
    string idBuscar;
    marcoMenus("BORRAR USUARIO");
    saltosLinea();
    titulo("\t3. Cajero");
    cout << "\tIngrese el numero de identificacion: ";
    fflush(stdin);
    getline(cin, idBuscar);
    limpiarPantalla();
    if(vecCajeros.size() > 0)
    {
        Cajero tmp = Cajero();
        for(int i = 0; i < vecCajeros.size(); i++)
        {
            tmp = vecCajeros.at(i);
            if(tmp.getNumID() == idBuscar)
            {
                existe = true;
                do
                {
                    marcoMenus("BORRAR USUARIO");
                    saltosLinea();
                    titulo("\t3. Cajero");
                    cout << tmp.getInfo() << endl << endl;
                    separador();
                    cout << "\tEsta accion es irreversible, seguro que desea borrar este usuario? [1. SI - 0. NO]: ";
                    cin >> opc;
                    limpiarPantalla();
                    switch(opc)
                    {
                    case 0:
                        repite = false;
                        break;
                    case 1:
                        repite = false;
                        vecCajeros.erase(vecCajeros.begin() + i);
                        marcoMenus("BORRAR USUARIO");
                        saltosLinea();
                        titulo("\tUsuario borrado correctamente");
                        pausa();
                        break;
                    default:
                        marcoMenus("BORRAR USUARIO");
                        saltosLinea();
                        titulo("\tOpcion incorrecta");
                        pausa();
                        break;
                    }
                }
                while(repite);
            }
            if(existe)
                break;
        }
        if(!existe)
        {
            marcoMenus("BORRAR USUARIO");
            saltosLinea();
            titulo("\tNo hay cajeros con ese numero de identificacion en el sistema");
            pausa();
        }
    }
    else
    {
        marcoMenus("BORRAR USUARIO");
        saltosLinea();
        titulo("\tNo hay cajeros en el sistema");
        pausa();
    }
}

void borrarProveedor()
{
    int opc;
    bool repite = true, existe = false;
    string idBuscar;
    marcoMenus("BORRAR USUARIO");
    saltosLinea();
    titulo("\t4. Proveedor");
    cout << "\tIngrese el numero de identificacion: ";
    fflush(stdin);
    getline(cin, idBuscar);
    limpiarPantalla();
    if(vecProveedores.size() > 0)
    {
        Proveedor tmp = Proveedor();
        for(int i = 0; i < vecProveedores.size(); i++)
        {
            tmp = vecProveedores.at(i);
            if(tmp.getNumID() == idBuscar)
            {
                existe = true;
                do
                {
                    marcoMenus("BORRAR USUARIO");
                    saltosLinea();
                    titulo("\t4. Proveedor");
                    cout << tmp.getInfo() << endl << endl;
                    separador();
                    cout << "\tEsta accion es irreversible, seguro que desea borrar este usuario? [1. SI - 0. NO]: ";
                    cin >> opc;
                    limpiarPantalla();
                    switch(opc)
                    {
                    case 0:
                        repite = false;
                        break;
                    case 1:
                        repite = false;
                        vecProveedores.erase(vecProveedores.begin() + i);
                        marcoMenus("BORRAR USUARIO");
                        saltosLinea();
                        titulo("\tUsuario borrado correctamente");
                        pausa();
                        break;
                    default:
                        marcoMenus("BORRAR USUARIO");
                        saltosLinea();
                        titulo("\tOpcion incorrecta");
                        pausa();
                        break;
                    }
                }
                while(repite);
            }
            if(existe)
                break;
        }
        if(!existe)
        {
            marcoMenus("BORRAR USUARIO");
            saltosLinea();
            titulo("\tNo hay proveedores con ese numero de identificacion en el sistema");
            pausa();
        }
    }
    else
    {
        marcoMenus("BORRAR USUARIO");
        saltosLinea();
        titulo("\tNo hay proveedores en el sistema");
        pausa();
    }
}

void borrarCliente()
{
    int opc;
    bool repite = true, existe = false;
    string idBuscar;
    marcoMenus("BORRAR USUARIO");
    saltosLinea();
    titulo("\t5. Cliente");
    cout << "\tIngrese el numero de identificacion: ";
    fflush(stdin);
    getline(cin, idBuscar);
    limpiarPantalla();
    if(vecClientes.size() > 0)
    {
        Cliente tmp = Cliente();
        for(int i = 0; i < vecClientes.size(); i++)
        {
            tmp = vecClientes.at(i);
            if(tmp.getNumID() == idBuscar)
            {
                existe = true;
                do
                {
                    marcoMenus("BORRAR USUARIO");
                    saltosLinea();
                    titulo("\t5. Cliente");
                    cout << tmp.getInfo() << endl << endl;
                    separador();
                    cout << "\tEsta accion es irreversible, seguro que desea borrar este usuario? [1. SI - 0. NO]: ";
                    cin >> opc;
                    limpiarPantalla();
                    switch(opc)
                    {
                    case 0:
                        repite = false;
                        break;
                    case 1:
                        repite = false;
                        vecClientes.erase(vecClientes.begin() + i);
                        marcoMenus("BORRAR USUARIO");
                        saltosLinea();
                        titulo("\tUsuario borrado correctamente");
                        pausa();
                        break;
                    default:
                        marcoMenus("BORRAR USUARIO");
                        saltosLinea();
                        titulo("\tOpcion incorrecta");
                        pausa();
                        break;
                    }
                }
                while(repite);
            }
            if(existe)
                break;
        }
        if(!existe)
        {
            marcoMenus("BORRAR USUARIO");
            saltosLinea();
            titulo("\tNo hay clientes con ese numero de identificacion en el sistema");
            pausa();
        }
    }
    else
    {
        marcoMenus("BORRAR USUARIO");
        saltosLinea();
        titulo("\tNo hay clientes en el sistema");
        pausa();
    }
}

void venderProductos()
{
    bool repite = true, existe = false, adv = false, repiteAdv = false;
    long idBuscar, valorTotal = 0;
    int cantidadVender = 0, cantidadProductos = 0;
    //vector <Producto> vecFactura;
    marcoMenus("VENDER PRODUCTO");
    saltosLinea();
    titulo("\tProducto");
    cout << "\tIngrese el numero de ID del producto: ";
    fflush(stdin);
    cin >> idBuscar;
    limpiarPantalla();
    if(vecInventario.size() > 0)
    {
        Producto tmp = Producto();
        for(int i = 0; i < vecInventario.size(); i++)
        {
            tmp = vecInventario.at(i);
            if(tmp.getProductoID() == idBuscar)
            {
                existe = true;
                do
                {
                    marcoMenus("VENDER PRODUCTO");
                    saltosLinea();
                    titulo("\tProducto");
                    cout << tmp.getInfo() << endl;
                    cout << "\tCantidad a vender: " ;
                    cin >> cantidadVender;
                    tmp.setCantidad(tmp.getCantidad() - cantidadVender);
                    vecInventario.at(i) = tmp;
                    tmp.setCantidad(cantidadVender);
                    vecVentas.push_back(tmp);
                    vecFactura.push_back(tmp);


                    do
                    {
                        marcoMenus("VENDER PRODUCTO");
                        saltosLinea();
                        cout <<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\tDesea ingresar otro producto? [1. SI - 0. NO]: ";
                        cin >> adv;
                        limpiarPantalla();
                        switch(adv)
                        {
                        case 0:
                        {
                            repite = false;
                            repiteAdv = false;

                            int opc;
                            bool repiteU = true, existeU = false;
                            string idBuscar;
                            marcoMenus("VENDER PRODUCTO");
                            saltosLinea();
                            titulo("\tConsultar Cliente");
                            cout << "\tIngrese el numero de identificacion: ";
                            fflush(stdin);
                            getline(cin, idBuscar);
                            limpiarPantalla();

                            marcoMenuListado("VENDER PRODUCTO");
                            saltosLinea();
                            titulo("\tFactura");

                            Producto fact = Producto();
                            for(int i = 0; i < vecFactura.size(); i++)
                            {
                                fact = vecFactura.at(i);
                                cout << fact.getInfo() << endl;
                                separador();
                                valorTotal += (fact.getValorDesc() * fact.getCantidad());
                                cantidadProductos += fact.getCantidad();
                            }
                            cout << "\tValor total a pagar: " << valorTotal << endl <<endl;
                            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                            if(vecClientes.size() > 0)
                            {
                                Cliente tmpC = Cliente();
                                for(int i = 0; i < vecClientes.size(); i++)
                                {
                                    tmpC = vecClientes.at(i);
                                    if(tmpC.getNumID() == idBuscar)
                                    {
                                        existe = true;
                                        tmpC.setPuntos(tmpC.getPuntos() + (cantidadProductos * 100));
                                        vecClientes.at(i) = tmpC;
                                    }
                                    if(existe)
                                        break;
                                }
                                if(!existe)
                                {
                                    marcoMenus("CONSULTAR USUARIO");
                                    saltosLinea();
                                    titulo("\tNo hay clientes con ese numero de identificacion en el sistema");
                                    pausa();
                                }
                            }
                            else
                            {
                                marcoMenus("CONSULTAR USUARIO");
                                saltosLinea();
                                titulo("\tNo hay clientes en el sistema");
                                pausa();
                            }
                            /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                            pausa();
                            vecFactura.clear();

                            break;
                        }
                        case 1:
                            repite = false;
                            repiteAdv = false;
                            venderProductos();
                            break;

                        default:
                            marcoMenus("MENU ADMIN");
                            saltosLinea();
                            titulo("\tOpcion incorrecta");
                            pausa();
                            break;
                        }
                    }
                    while(repiteAdv);

                }
                while(repite);


            }
            if(existe)
                break;
        }
        if(!existe)
        {
            marcoMenus("VENDER PRODUCTO");
            saltosLinea();
            titulo("\tNo hay producto con ese numero de ID en el sistema");
            pausa();
        }
    }
    else
    {
        marcoMenus("VENDER PRODUCTO");
        saltosLinea();
        titulo("\tNo hay productos en el sistema");
        pausa();
    }


}






