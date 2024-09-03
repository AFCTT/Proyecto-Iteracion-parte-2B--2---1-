#ifndef DICCIONARIO_INVERSO_H
#define DICCIONARIO_INVERSO_H

#include <iostream>
#include <list>

template<typename T>
class DiccionarioInverso {
public:
    DiccionarioInverso();
    void agregarPalabra(const T& palabra);
    bool obtenerPalabra(const T& palabra);
    bool inicializar(const std::string& nombreArchivo);

private:
    std::list<T> Ldiccionario;
    bool inicializado;
};

#endif // DICCIONARIO_INVERSO_H