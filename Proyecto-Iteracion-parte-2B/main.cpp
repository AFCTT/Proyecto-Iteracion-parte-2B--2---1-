

// EntradaMain.cpp

#include "Entrada.h"
#include <iostream>
using namespace std;
int main()
{
    Entrada entrada;
    string nombreArchivo;
    std::string comando;

      do                                   
    {

        std::cout << "Ingrese un comando ('ayuda' para obtener ayuda): $ ";
        std::getline(std::cin, comando);

        entrada.establecerComandoActual(comando);
        entrada.ejecutarComando();

    } while (comando != "salir");

    return 0;
}