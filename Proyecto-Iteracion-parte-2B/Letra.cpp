#include "Letra.h"
#include <list>
#include <string>

Letra::Letra(const std::string& palabra) {
    for (char c : palabra) {
        letras.push_back(c);
    }
}

std::list<char> Letra::obtenerLista() const {
    return letras;
}