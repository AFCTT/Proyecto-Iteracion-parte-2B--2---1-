// ArbolTrie.cpp
#include "ArbolTrie.h"

ArbolTrie::ArbolTrie() : raiz(new NodoTrie()) {}

ArbolTrie::~ArbolTrie()
{
    delete raiz;
}

void ArbolTrie::insertarPalabra(const std::string &palabra)
{
    NodoTrie *nodoActual = raiz;
    for (char letra : palabra)
    {
        nodoActual = nodoActual->insertarHijo(letra);
    }
    nodoActual->marcarComoPalabra();
}

bool ArbolTrie::buscarPalabra(const std::string &palabra)
{
    NodoTrie *nodoActual = raiz;
    for (char letra : palabra)
    {
        nodoActual = nodoActual->obtenerHijo(letra);
        if (nodoActual == nullptr)
        {
            return false;
        }
    }
    return nodoActual->esPalabra();
}

void ArbolTrie::imprimirRecursivo(NodoTrie *nodo, std::string prefijo)
{
    if (nodo == nullptr)
    {
        return;
    }
    if (nodo->esPalabra())
    {
        std::cout << prefijo << std::endl;
    }
    for (auto &par : nodo->hijos)
    {
        imprimirRecursivo(par.second, prefijo + par.first);
    }
}

void ArbolTrie::imprimir()
{
    imprimirRecursivo(raiz, "");
}

void ArbolTrie::palabrasPorPrefijoRecursivo(NodoTrie *nodo, std::string prefijo, std::vector<std::string> &palabras)
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

void ArbolTrie::palabrasPorPrefijo(const std::string &prefijo)
{
    std::vector<std::string> palabras;
    NodoTrie *nodoActual = raiz;
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

void ArbolTrie::imprimirContenidoAux(NodoTrie *nodo, std::string palabraActual) const
{
    if (nodo == nullptr)
    {
        return;
    }
    if (nodo->esPalabra())
    {
        std::cout << palabraActual << std::endl;
    }
    for (auto &par : nodo->hijos)
    {
        imprimirContenidoAux(par.second, palabraActual + par.first);
    }
}

void ArbolTrie::imprimirContenido() const
{
    imprimirContenidoAux(raiz, "");
}
