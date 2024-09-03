// Prefijo.cpp
#include "Prefijo.h"

void Prefijo::palabrasPorPrefijo(const std::string &prefijo, const NodoTrie *raiz)
{ // Cambio de parámetro
    std::vector<std::string> palabras;
    const NodoTrie *nodoActual = raiz; // Cambio de acceso
    for (char letra : prefijo)
    {
        nodoActual = nodoActual->obtenerHijo(letra);
        if (nodoActual == nullptr)
        {
            std::cout << "No hay palabras con el prefijo dado." << std::endl;
            return;
        }
    }
    palabrasPorPrefijoRecursivo(nodoActual, prefijo, palabras);
    std::cout << "Palabras con prefijo '" << prefijo << "':" << std::endl;
    for (const std::string &palabra : palabras)
    {
        std::cout << palabra << std::endl;
    }
}

void Prefijo::palabrasPorPrefijoRecursivo(const NodoTrie *nodo, std::string prefijo, std::vector<std::string> &palabras)
{
    if (nodo == nullptr)
    {
        return;
    }
    if (nodo->esPalabra())
    {
        palabras.push_back(prefijo);
    }
    for (auto &par : nodo->hijos)
    {
        palabrasPorPrefijoRecursivo(par.second, prefijo + par.first, palabras);
    }
}
