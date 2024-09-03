// SUFIJO.h
#ifndef SUFIJO_H
#define SUFIJO_H

#include "NodoTrie.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;
class Sufijo
{
public:
    static void palabrasPorSufijo(const std::string &sufijo, const NodoTrie *raiz);                                       // Cambio de parámetro
    static void palabrasPorSufijoRecursivo(const NodoTrie *nodo, std::string sufijo, std::vector<std::string> &palabras); // Cambio de parámetro
    static string sufijoInvertido(const std::string &sufijo);
};

#endif // SUFIJO_H