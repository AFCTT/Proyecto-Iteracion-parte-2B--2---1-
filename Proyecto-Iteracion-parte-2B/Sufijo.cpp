// Prefijo.cpp
#include "Sufijo.h"

std::string Sufijo::sufijoInvertido(const std::string &sufijo) // Implementación de sufijoInvertido como parte de la clase Sufijo
{
    std::string sufijoInvertido;
    for (auto it = sufijo.rbegin(); it != sufijo.rend(); ++it)
    {
        sufijoInvertido += *it;
    }
    return sufijoInvertido;
}

void Sufijo::palabrasPorSufijo(const std::string &sufijo, const NodoTrie *raiz)
{
    std::vector<std::string> palabras;
    std::string sufijoInv = sufijoInvertido(sufijo); // Obtener el sufijo invertido
    const NodoTrie *nodoActual = raiz;
    for (char letra : sufijoInv)
    { // Recorrer el sufijo invertido
        nodoActual = nodoActual->obtenerHijo(letra);
        if (nodoActual == nullptr)
        {
            std::cout << "No hay palabras con el sufijo dado." << std::endl;
            return;
        }
    }
    // Llamada a la función recursiva para encontrar las palabras con el sufijo desde el nodo actual
    palabrasPorSufijoRecursivo(nodoActual, sufijoInv, palabras);
    std::cout << "Palabras con sufijo '" << sufijo << "':" << std::endl;
    for (const std::string &palabra : palabras)
    {
        std::cout << palabra << std::endl;
    }
}

void Sufijo::palabrasPorSufijoRecursivo(const NodoTrie *nodo, std::string sufijo, std::vector<std::string> &palabras)
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
