//NodoTrie.h
#ifndef NODOTRIE_H
#define NODOTRIE_H

#include <iostream>
#include <unordered_map>
#include <string>

class NodoTrie {
public:
    NodoTrie();
    explicit NodoTrie(char letra);
    ~NodoTrie();

    void imprimir(int nivel = 0); 
    NodoTrie* obtenerHijo(char letra) const; 
    NodoTrie* insertarHijo(char letra);
    void eliminarHijo(char letra);
    bool esPalabra() const; 
    void marcarComoPalabra();
    void incrementarFrecuencia();
    int obtenerFrecuencia() const; 
    int contarPalabras() const; 
    int contarNodos() const; 
    bool palabraExiste(const std::string& palabra) const; 
    std::unordered_map<char, NodoTrie*> hijos;

private:
    char letra;
    bool esPalabraFlag;
    int frecuencia;

};

#endif // NODOTRIE_H

