#include "DiccionarioInverso.h"
#include <fstream>
#include <cctype>
#include <iostream>
#include <algorithm>

template<typename T>
DiccionarioInverso<T>::DiccionarioInverso() : inicializado(false) {}

template<typename T>
void DiccionarioInverso<T>::agregarPalabra(const T& palabra) {
    Ldiccionario.push_back(palabra);
}

template<typename T>
bool DiccionarioInverso<T>::obtenerPalabra(const T& palabra) {
    T palabraInvertida = palabra;
    std::reverse(palabraInvertida.begin(), palabraInvertida.end()); // Invertir la palabra

    for (const auto& p : Ldiccionario) {
        if (p == palabraInvertida) {
            std::cout << "Palabra encontrada en Diccionario Inverso" << std::endl;
            return true;
        }
    }
    std::cout << "Palabra no encontrada en Diccionario Inverso" << std::endl;
    return false;
}

template<typename T>
bool DiccionarioInverso<T>::inicializar(const std::string& nombreArchivo) {
    // Abrir el archivo
    std::ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        std::cout << "Error: No se pudo abrir el archivo " << nombreArchivo << std::endl;
        return false;
    }

    // Procesar cada palabra del archivo
    T palabra;
    bool alMenosUnaPalabraValida = false;
    while (archivo >> palabra) {
        // Verificar si la palabra contiene caracteres no válidos no alfabéticos
        bool palabra_valida = true;
        for (char c : palabra) {
            if (!std::isalpha(c)) {
                std::cout << "La palabra contiene caracteres no válidos: " << palabra << std::endl;
                palabra_valida = false;
                break;
            }
        }
        // Almacenar la palabra si es válida
        if (palabra_valida) {
          //Invertir la palabra antes de almacenarla
            reverse(palabra.begin(), palabra.end());
            Ldiccionario.push_back(palabra);
            std::cout << palabra << std::endl; // Imprimir la palabra agregada
            alMenosUnaPalabraValida = true;
        }
    }

    // Cerrar el archivo
    archivo.close();

    if (!alMenosUnaPalabraValida) {
        std::cout << "Ninguna palabra válida encontrada en el archivo. No se pudo inicializar el diccionario." << std::endl;
        inicializado = false;
        return false;
    }

    std::cout << "Sistema inicializado correctamente a partir del archivo " << nombreArchivo << ".txt" << std::endl;
    inicializado = true;
    return true;
}

// Explicit instantiation for supported types
template class DiccionarioInverso<std::string>;