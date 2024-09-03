//NodoTrie.cpp
#include "NodoTrie.h"

NodoTrie::NodoTrie() : letra('\0'), esPalabraFlag(false), frecuencia(0) {}

NodoTrie::NodoTrie(char letra) : letra(letra), esPalabraFlag(false), frecuencia(0) {}

NodoTrie::~NodoTrie() {
    for (auto& par : hijos) {
        delete par.second;
    }
}

void NodoTrie::imprimir(int nivel) {
    for (int i = 0; i < nivel; ++i) {
        std::cout << " ";
    }
    std::cout << letra;
    if (esPalabraFlag) {
        std::cout << " *";
    }
    std::cout << std::endl;

    for (auto& par : hijos) {
        par.second->imprimir(nivel + 1);
    }
}

NodoTrie* NodoTrie::obtenerHijo(char letra) const { // Modificación aquí
    auto it = hijos.find(letra);
    if (it != hijos.end()) {
        return it->second;
    }
    return nullptr;
}

NodoTrie* NodoTrie::insertarHijo(char letra) {
    if (obtenerHijo(letra) == nullptr) {
        hijos[letra] = new NodoTrie(letra);
    }
    return hijos[letra];
}

void NodoTrie::eliminarHijo(char letra) {
    auto it = hijos.find(letra);
    if (it != hijos.end()) {
        delete it->second;
        hijos.erase(it);
    }
}

bool NodoTrie::esPalabra() const { // Modificación aquí
    return esPalabraFlag;
}

void NodoTrie::marcarComoPalabra() {
    esPalabraFlag = true;
}

void NodoTrie::incrementarFrecuencia() {
    ++frecuencia;
}

int NodoTrie::obtenerFrecuencia() const { // Modificación aquí
    return frecuencia;
}

int NodoTrie::contarPalabras() const { // Modificación aquí
    int total = esPalabraFlag ? 1 : 0;
    for (auto& par : hijos) {
        total += par.second->contarPalabras();
    }
    return total;
}

int NodoTrie::contarNodos() const { // Modificación aquí
    int total = 1; 
    for (auto& par : hijos) {
        total += par.second->contarNodos();
    }
    return total;
}

bool NodoTrie::palabraExiste(const std::string& palabra) const { // Modificación aquí
    const NodoTrie* nodoActual = this;
    for (char letra : palabra) {
        nodoActual = nodoActual->obtenerHijo(letra);
        if (nodoActual == nullptr) {
            return false;
        }
    }
    return nodoActual->esPalabra();
}
