// Prefijo.h
#ifndef PREFIJO_H
#define PREFIJO_H

#include "NodoTrie.h"
#include <string>
#include <iostream>
#include <vector>

class Prefijo {
public:
    static void palabrasPorPrefijo(const std::string& prefijo, const NodoTrie* raiz); // Cambio de parámetro
    static void palabrasPorPrefijoRecursivo(const NodoTrie* nodo, std::string prefijo, std::vector<std::string>& palabras); // Cambio de parámetro
};

#endif // PREFIJO_H
