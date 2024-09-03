// ArbolTrie.cpp
#include "ArbolTrieInverso.h"

ArbolTrieInverso::ArbolTrieInverso() : raiz(new NodoTrie()) {}

ArbolTrieInverso::~ArbolTrieInverso()
{
    delete raiz;
}

void ArbolTrieInverso::insertarPalabra(const std::string &palabra)
{
    NodoTrie *nodoActual = raiz;
    for (char letra : palabra)
    {
        nodoActual = nodoActual->insertarHijo(letra);
    }
    nodoActual->marcarComoPalabra();
}

bool ArbolTrieInverso::buscarPalabraSufijo(const std::string &sufijo)
{
    NodoTrie *nodoActual = raiz;
    for (auto it = sufijo.rbegin(); it != sufijo.rend(); ++it)
    {
        char letra = *it;
        nodoActual = nodoActual->obtenerHijo(letra);
        if (nodoActual == nullptr)
        {
            return false;
        }
    }
    return nodoActual->esPalabra();
}

void ArbolTrieInverso::imprimirRecursivoInverso(NodoTrie *nodo, std::string palabraActual) const
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
        imprimirRecursivoInverso(par.second, par.first + palabraActual);
    }
}

void ArbolTrieInverso::imprimir()
{
    imprimirRecursivoInverso(raiz, "");
}

void ArbolTrieInverso::palabrasPorSufijoRecursivo(NodoTrie *nodo, std::string sufijo, std::vector<std::string> &palabras)
{
    if (nodo == nullptr)
    {
        return;
    }
    if (nodo->esPalabra())
    {
        palabras.push_back(sufijo);
    }
    for (auto &par : nodo->hijos)
    {
        palabrasPorSufijoRecursivo(par.second, par.first + sufijo, palabras);
    }
}

void ArbolTrieInverso::palabrasPorSufijo(const std::string &sufijo)
{
    std::vector<std::string> palabras;
    NodoTrie *nodoActual = raiz;

    // Se recorre el árbol Trie hasta el nodo correspondiente al último carácter del sufijo
    for (auto it = sufijo.rbegin(); it != sufijo.rend(); ++it)
    {
        char letra = *it;
        nodoActual = nodoActual->obtenerHijo(letra);
        if (nodoActual == nullptr)
        { // No se encontró nunguna coincidencia
            std::cout << "No hay palabras con el sufijo dado." << std::endl;
            return;
        }
    }

    // Se llama a una función auxiliar recursiva para encontrar todas las palabras con el sufijo dado, es decir las imprime
    palabrasPorSufijoRecursivo(nodoActual, "", palabras);

    // Se imprime un mensaje indicando las palabras encontradas con el sufijo dado
    std::cout << "Palabras con sufijo '" << sufijo << "':" << std::endl;
    for (const std::string &palabra : palabras)
    {
        std::cout << palabra << std::endl;
    }
}

void ArbolTrieInverso::imprimirContenidoAux(NodoTrie *nodo, std::string palabraActual) const
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

void ArbolTrieInverso::imprimirContenido() const
{
    imprimirContenidoAux(raiz, "");
}
