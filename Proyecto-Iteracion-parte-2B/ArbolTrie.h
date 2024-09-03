// ArbolTrie.h
#ifndef ARBOLTRIE_H
#define ARBOLTRIE_H

#include "NodoTrie.h"
#include <string>
#include <iostream>
#include <vector>

class ArbolTrie
{
public:
    ArbolTrie();
    ~ArbolTrie();

    void insertarPalabra(const std::string &palabra);
    bool buscarPalabra(const std::string &palabra);
    void imprimir();
    void palabrasPorPrefijo(const std::string &prefijo);
    void imprimirContenido() const; // Método para imprimir el contenido del árbol

private:
    NodoTrie *raiz;

    void imprimirRecursivo(NodoTrie *nodo, std::string prefijo);
    void palabrasPorPrefijoRecursivo(NodoTrie *nodo, std::string prefijo, std::vector<std::string> &palabras);
    // Función auxiliar para recorrer en profundidad
    void imprimirContenidoAux(NodoTrie *nodo, std::string palabraActual) const;
};

#endif // ARBOLTRIE_H
