#include "Puntaje.h"
#include "Letra.h"
#include <unordered_map>

Puntaje::Puntaje(const std::string& palabra, const std::list<char>& letras) : valor(0), palabra(palabra) {
    // Definir el mapa de valores de las letras
    std::unordered_map<char, int> valores_letras = {
        {'E', 1}, {'A', 1}, {'I', 1}, {'O', 1}, {'N', 1},
        {'R', 1}, {'T', 1}, {'L', 1}, {'S', 1}, {'U', 1},
        {'D', 2}, {'G', 2},
        {'B', 3}, {'C', 3}, {'M', 3}, {'P', 3},
        {'F', 4}, {'H', 4}, {'V', 4}, {'W', 4}, {'Y', 4},
        {'K', 5},
        {'J', 8}, {'X', 8},
        {'Q', 10}, {'Z', 10}
    };

    // Calcular el puntaje de la palabra sumando los valores de las letras
    for (char letra : letras) {
        valor += valores_letras[toupper(letra)]; // Convertir la letra a mayúscula antes de buscarla
    }
}

int Puntaje::obtenerValor() const {
    return valor;
}