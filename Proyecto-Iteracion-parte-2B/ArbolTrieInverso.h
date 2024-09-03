// ArbolTrie.h
#ifndef ARBOLTRIEINVERSO_H
#define ARBOLTRIEINVERSO_H

#include "NodoTrie.h"
#include <string>
#include <iostream>
#include <vector>

class ArbolTrieInverso
{
public:
    ArbolTrieInverso();
    ~ArbolTrieInverso();

    void insertarPalabra(const std::string &palabra);
    bool buscarPalabraSufijo(const std::string &palabra);
    void imprimir();
    void palabrasPorSufijo(const std::string &sufijo);
    void imprimirContenido() const; // Método para imprimir el contenido del árbol

private:
    NodoTrie *raiz;

    void imprimirRecursivoInverso(NodoTrie *nodo, std::string sufijo) const;
    void palabrasPorSufijoRecursivo(NodoTrie *nodo, std::string sufijo, std::vector<std::string> &palabras);
    // Función auxiliar para recorrer en profundidad
    void imprimirContenidoAux(NodoTrie *nodo, std::string palabraActual) const;
};

#endif // ARBOLTRIEINVERSO_H
