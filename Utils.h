//*****************************************************//
//* Nota: todas las funciones aquí tienen que ser     *//
//*       estáticas, por ej: static void prueba()     *//
//*****************************************************//

#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED
#include <iostream>
#include <windows.h>
#include <time.h>
#include <vector>
#include <chrono>

using namespace std;

static string toLower(string str) // Convierte un texto en minusculas
{
    for(int i = 0; i < str.size(); i++)
        str[i] = tolower(str[i]);
    return str;
}

static string toUpperFirst(string str) // Convierte la primera letra de un texto en mayuscula
{
    str[0] = toupper(str[0]);
    return str;
}

static void saltosLinea() // Imprime 7 saltos de linea
{
    cout << "\n\n\n\n\n\n\n";
}

static char enye() // Retorna la 'ñ'
{
     return char(164);
}

static void titulo(string texto) // Da formato a los titulos
{
    int n = texto.size();
    cout << texto << endl;
    cout << "\t";
    for(int i = 0; i < n; i++)
        cout << char(196);
    cout << endl << endl;
}

static void tituloLogin(string texto) // Da formato al titulo del login
{
    int n = texto.size();
    cout << texto << endl;
    cout << char(179) <<  "\t";
    for(int i = 0; i < n; i++)
        cout << char(196);
    cout << endl << endl;
}

static void pausa() // Pausa y luego borra el contenido de la consola
{
    cout << "\t";
    system("pause");
    system("cls");
}

static void limpiarPantalla() // Borra el contenido de la consola
{
    system("cls");
}

static void gotoxy(int x, int y) // Mueve el puntero a una coordenada en la consola
{
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y= y;
    SetConsoleCursorPosition(hcon,dwPos);
}

static string fechaAct() // Retorna la fecha del sistema
{
    time_t now = time(0); // Fecha y hora actual basado en el sistema
    auto tinfo = localtime(&now); // Estructura donde obtengo el tiempo
    char fecha[11]; // Array para guardar la fecha
    strftime(fecha, 20, "%d/%m/%Y", tinfo);  // Formato para guardar la fecha obtenido en *tinfo como dd/mm/yyyy
    return fecha;
}

static string horaAct() // Retorna la hora del sistema
{
    time_t now = time(0); // Fecha y hora actual basado en el sistema
    auto tinfo = localtime(&now); // Estructura donde obtengo el tiempo
    char hora[9];  // Array para guardar la hora
    strftime(hora, 11, "%H:%M:%S", tinfo); // Formato para guardar la fecha obtenido en *tinfo como hh:mm:ss
    return hora;
}

static void formatoConsola() // Establece un formato la consola
{
    // Bloqueo de redimensionamiento de consola
    HWND consoleWindow = GetConsoleWindow();
    RECT ConsoleRect;
    GetWindowRect(consoleWindow, &ConsoleRect);
    MoveWindow(consoleWindow, ConsoleRect.left, ConsoleRect.top, 1000, 665, TRUE); // Establece el tamaño de la pantalla cmd en pixeles
    SetWindowLong(consoleWindow, GWL_STYLE, GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);
    /*HWND consoleWindow = GetConsoleWindow();
    RECT ConsoleRect;
    GetWindowRect(consoleWindow, &ConsoleRect);
    MoveWindow(consoleWindow, ConsoleRect.left, ConsoleRect.top, 1200, 300, TRUE); // Establece el tamaño de la pantalla cmd en pixeles*/
    /*system("mode 120,40"); // Establece el tamaño de ventana de la consola en con coordenadas*/

}

static int centrarPosXTexto(string texto) // Centra la coordenada X con base en el texto ingresado
{
    return 60 - (texto.size() / 2);
}

static void marcoMenus(string tipoMenu) // Imprime el marco de los menus
{
    /// TITULO
    string tituloMenu = "SISTEMA TIENDA TECNOLOGICA";
    gotoxy(centrarPosXTexto(tituloMenu), 1);
    cout << tituloMenu;
    gotoxy(centrarPosXTexto(tipoMenu), 3);
    cout << tipoMenu;

    /// MARCO GRANDE
    // Esquinas
    // izq arriba
    gotoxy(0, 4);
    cout << char(218);
    // der arriba
    gotoxy(119, 4);
    cout << char(191);
    // izq abajo
    gotoxy(0, 38);
    cout << char(192);
    // der abajo
    gotoxy(119, 38);
    cout << char(217);
    gotoxy(1, 1);
    // Lado arriba
    for(int i = 1; i < 119; i++)
    {
        gotoxy(i, 4);
        cout << char(196);
    }
    // Lado izquierdo
    for(int i = 5; i < 38; i++)
    {
        gotoxy(0, i);
        cout << char(179);
    }
    // Lado derecho
    for(int i = 5; i < 38; i++)
    {
        gotoxy(119, i);
        cout << char(179);
    }
    // Lado abajo
    for(int i = 1; i < 119; i++)
    {
        gotoxy(i, 38);
        cout << char(196);
    }

    /// MARCO FECHA
    // Esquinas
    // izq arriba
    gotoxy(1, 1);
    cout << char(218);
    // der arriba
    gotoxy(16, 1);
    cout << char(191);
    // izq abajo
    gotoxy(1, 3);
    cout << char(192);
    // der abajo
    gotoxy(16, 3);
    cout << char(217);
    // Lado arriba
    for(int i = 2; i < 16; i++)
    {
        gotoxy(i, 1);
        cout << char(196);
    }
    // Lado izq
    gotoxy(1, 2);
    cout << char(179);
    // Lado der
    gotoxy(16, 2);
    cout << char(179);
    // Lado abajo
    for(int i = 2; i < 16; i++)
    {
        gotoxy(i, 3);
        cout << char(196);
    }

    /// MARCO HORA
    // Esquinas
    // izq arriba
    gotoxy(105, 1);
    cout << char(218);
    // der arriba
    gotoxy(118, 1);
    cout << char(191);
    // izq abajo
    gotoxy(105, 3);
    cout << char(192);
    // der abajo
    gotoxy(118, 3);
    cout << char(217);
    // Lado arriba
    for(int i = 106; i < 118; i++)
    {
        gotoxy(i, 1);
        cout << char(196);
    }
    // Lado izq
    gotoxy(105, 2);
    cout << char(179);
    // Lado der
    gotoxy(118, 2);
    cout << char(179);
    // Lado abajo
    for(int i = 106; i < 118; i++)
    {
        gotoxy(i, 3);
        cout << char(196);
    }

    /// TIEMPO
    // Fecha
    gotoxy(4, 2);
    cout << fechaAct();
    // Hora
    gotoxy(108, 2);
    cout << horaAct();

    gotoxy(0, 0); // Establece el cursor en la posicion inicial
    //gotoxy(0, 29); // Establece el cursor abajo del marco
}

static void separador() // Imprime una linea para separar textos
{
    cout << "\t";
    for(int i = 0; i < 40; i++)
        cout << char(196);
    cout << endl << endl;
}

static void marcoMenuListado(string tipoMenu) // Imprime el marco de los menus
{
    /// TITULO
    gotoxy(4, 1);
    cout << "SISTEMA TIENDA TECNOLOGICA";
    gotoxy(9, 3);
    cout << tipoMenu;

    /// SEPARADOR GRANDE
    // Esquinas
    // izq arriba
    gotoxy(1, 0);
    cout << char(218);
    // der arriba
    gotoxy(118, 0);
    cout << char(191);
    // izq abajo
    gotoxy(1, 4);
    cout << char(192);
    // der abajo
    gotoxy(118, 4);
    cout << char(217);
    gotoxy(1, 1);
    // Lado arriba
    for(int i = 2; i < 118; i++)
    {
        gotoxy(i, 0);
        cout << char(196);
    }
    // Lado izquierdo
    for(int i = 1; i < 4; i++)
    {
        gotoxy(1, i);
        cout << char(179);
    }
    // Lado derecho
    for(int i = 1; i < 4; i++)
    {
        gotoxy(118, i);
        cout << char(179);
    }
    // Lado abajo
    for(int i = 2; i < 118; i++)
    {
        gotoxy(i, 4);
        cout << char(196);
    }

    /// SEPARADOR TITULO / SUBTITULO
    // Lado arriba
    for(int i = 3; i < 31; i++)
    {
        gotoxy(i, 2);
        cout << char(196);
    }

    /// SEPARADOR FECHA / HORA
    // Lado arriba
    for(int i = 105; i < 117; i++)
    {
        gotoxy(i, 2);
        cout << char(196);
    }

    /// TIEMPO
    // Fecha
    gotoxy(106, 1);
    cout << fechaAct();
    // Hora
    gotoxy(107, 3);
    cout << horaAct();

    gotoxy(0, 0); // Establece el cursor en la posicion inicial
    //gotoxy(0, 29); // Establece el cursor abajo del marco
}


#endif // UTILS_H_INCLUDED
