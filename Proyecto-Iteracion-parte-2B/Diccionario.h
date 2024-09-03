#ifndef DICCIONARIO_H
#define DICCIONARIO_H

#include <iostream>
#include <list>

template<typename T>
class Diccionario {
public:
    Diccionario();
    void agregarPalabra(const T& palabra);
    bool obtenerPalabra(const T& palabra);
    bool inicializar(const std::string& nombreArchivo);

private:
    std::list<T> Ldiccionario;
    bool inicializado;
};

#endif // DICCIONARIO_H