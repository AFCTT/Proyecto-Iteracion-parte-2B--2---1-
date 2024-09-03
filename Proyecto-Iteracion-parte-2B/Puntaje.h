#ifndef PUNTAJE_H
#define PUNTAJE_H

#include <string>
#include <list>

class Puntaje {
private:
    int valor;
    std::string palabra;

public:
    Puntaje(const std::string& palabra, const std::list<char>& letras);
    int obtenerValor() const;
};

#endif // PUNTAJE_H