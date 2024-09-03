// Archivo Entrada.h

#ifndef ENTRADA_H
#define ENTRADA_H

#include <string>
#include <fstream>
#include <unordered_set>
class Entrada
{
private:
    std::string comando_actual;
    bool diccionarioInicializado;
    bool diccionarioInversoInicializado;
    bool arbolInicializado;
    bool arbolInversoInicializado;

public:
    Entrada();
    std::string obtenerComandoActual() const;
    void ejecutarComando();
    void establecerComandoActual(const std::string &comando);
    void inicializar();
};

#endif // ENTRADA_H
  