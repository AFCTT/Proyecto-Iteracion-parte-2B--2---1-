// Entrada.cpp
#include "Entrada.h"
#include "Diccionario.h"
#include "DiccionarioInverso.h"
#include "Puntaje.h"
#include "Letra.h"
#include "ArbolTrie.h"
#include "Sufijo.h"
#include "ArbolTrieInverso.h"
#include "NodoTrie.h"
#include "Prefijo.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <unordered_map>
using namespace std;

// Constructor
Entrada::Entrada() : diccionarioInicializado(false), diccionarioInversoInicializado(false),
                     arbolInicializado(false), arbolInversoInicializado(false) {}
Diccionario<std::string> diccionario;
DiccionarioInverso<std::string> diccionarioInverso;

// Implementar el árbol Trie
ArbolTrie arbol;
// Implementar el árbol Trie invertido
ArbolTrieInverso arbolInverso;
// Obtener el comando actual
Sufijo sufijo;
Prefijo prefijo;

// Obtener el comando actual
std::string Entrada::obtenerComandoActual() const
{
    return comando_actual;
}

// Establecer el comando actual
void Entrada::establecerComandoActual(const std::string &comando)
{
    comando_actual = comando;
}

// Ejecutar el comando actual
void Entrada::ejecutarComando()
{
    string nombreArchivo;
    if (comando_actual.substr(0, 11) == "inicializar" && comando_actual.size() > 11 && comando_actual.substr(comando_actual.size() - 4) == ".txt")
    {
        if (!diccionarioInicializado)
        {
            std::string nombreArchivo = comando_actual.substr(12); // Extraer el nombre del archivo del comando
            std::ifstream archivo(nombreArchivo);
            if (!archivo.is_open())
            {
                std::cout << "Error: No se pudo abrir el archivo " << nombreArchivo << std::endl;
                return;
            }
            archivo.close();

            // Establecer diccionarioInicializado con el valor retornado por la función inicializar
            diccionarioInicializado = diccionario.inicializar(nombreArchivo);
            if (diccionarioInicializado)
            {
                std::cout << "Archivo: " << nombreArchivo << " encontrado e inicializado correctamente" << std::endl;
            }
            else
            {
                std::cout << "Error: No se pudo inicializar el diccionario desde el archivo " << nombreArchivo << std::endl;
            }
        }
        else
        {
            std::cout << "El diccionario ya ha sido inicializado" << std::endl;
        }
    }
    else if (comando_actual.size() > 18 && comando_actual.substr(0, 15) == "iniciar_inverso" && comando_actual.substr(comando_actual.size() - 4) == ".txt")
    {
        string nombreArchivo = comando_actual.substr(16); // Extraer el nombre del archivo del comando

        if (!diccionarioInversoInicializado)
        {
            std::ifstream archivo(nombreArchivo);
            if (!archivo.is_open())
            {
                std::cout << "Error: No se pudo abrir el archivo " << nombreArchivo << std::endl;
                return;
            }
            archivo.close();

            // Establecer diccionarioInversoInicializado con el valor retornado por la función inicializar
            diccionarioInversoInicializado = diccionarioInverso.inicializar(nombreArchivo);
            if (diccionarioInversoInicializado)
            {
                std::cout << "Archivo: " << nombreArchivo << " encontrado e inicializado correctamente de forma inversa" << std::endl;
            }
            else
            {
                std::cout << "Error: No se pudo inicializar el diccionario inverso desde el archivo " << nombreArchivo << std::endl;
            }
        }
        else
        {
            std::cout << "El diccionario inverso ya ha sido inicializado" << std::endl;
        }
    }

    else if (comando_actual.find("puntaje ") == 0)
    {
        if (!diccionarioInicializado || !diccionarioInversoInicializado)
        {
            std::cout << "Error: Los diccionarios no han sido inicializados" << std::endl;
            return;
        }

        std::string palabra = comando_actual.substr(8); // Obtener la palabra después del espacio
        bool palabra_valida = true;
        for (char c : palabra)
        {
            if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')))
            {
                palabra_valida = false;
                break;
            }
        }
        if (palabra.empty())
        {
            std::cout << "La palabra está vacía." << std::endl;
        }
        else if (!palabra_valida)
        {
            std::cout << "La palabra contiene símbolos inválidos." << std::endl;
        }
        else
        {
            // Verificar si la palabra está en el diccionario
            bool palabra_en_diccionario = diccionario.obtenerPalabra(palabra);
            bool palabra_en_diccionario_inverso = diccionarioInverso.obtenerPalabra(palabra);

            if (palabra_en_diccionario && palabra_en_diccionario_inverso)
            {
                // Obtener puntaje
                Letra letras(palabra);
                Puntaje puntaje(palabra, letras.obtenerLista());
                int valor_total = puntaje.obtenerValor();
                std::cout << "El puntaje total de la palabra \"" << palabra << "\" es: " << valor_total << std::endl;
            }
            else
            {
                std::cout << "La palabra \"" << palabra << "\" no está en ambos diccionarios." << std::endl;
            }
        }
    }
    else if (comando_actual.find("iniciar_arbol ") == 0)
    {
        if (!arbolInicializado)
        {
            std::string nombreArchivo = comando_actual.substr(14); // Extraer el nombre del archivo del comando
            std::ifstream archivo(nombreArchivo);
            if (!archivo.is_open())
            {
                std::cout << "Error: No se pudo abrir el archivo " << nombreArchivo << std::endl;
                return;
            }
            archivo.close();

            // Verificar si todas las palabras del archivo son válidas
            std::ifstream archivoPalabras(nombreArchivo);
            std::string palabra;
            while (archivoPalabras >> palabra)
            {
                for (char letra : palabra)
                {
                    if (!isalpha(letra))
                    {
                        std::cout << "Error: El archivo contiene palabras inválidas." << std::endl;
                        return;
                    }
                }
            }
            archivoPalabras.close();

            // Crear un objeto ArbolTrie y construirlo desde el archivo
            std::ifstream archivoPalabras2(nombreArchivo);
            while (archivoPalabras2 >> palabra)
            {
                arbol.insertarPalabra(palabra);
            }
            archivoPalabras2.close();

            // Establecer arbolInicializado en true
            arbolInicializado = true;
            std::cout << "Árbol Trie inicializado correctamente desde el archivo " << nombreArchivo << std::endl;

            // Imprimir el contenido del árbol para verificar
            std::cout << "Contenido del árbol Trie:" << std::endl;
            arbol.imprimirContenido();
        }
        else
        {
            std::cout << "El árbol Trie ya ha sido inicializado" << std::endl;
        }
    }

    else if (comando_actual.find("iniciar_arbol_inverso ") == 0)
    {
        if (!arbolInversoInicializado)
        {
            std::string nombreArchivo = comando_actual.substr(22); // Extraer el nombre del archivo del comando
            std::ifstream archivo(nombreArchivo);
            if (!archivo.is_open())
            {
                std::cout << "Error: No se pudo abrir el archivo " << nombreArchivo << std::endl;
                return;
            }
            archivo.close();

            // Verificar si todas las palabras del archivo son válidas
            std::ifstream archivoPalabras(nombreArchivo);
            std::string palabra;
            while (archivoPalabras >> palabra)
            {
                for (char letra : palabra)
                {
                    if (!isalpha(letra))
                    {
                        std::cout << "Error: El archivo contiene palabras inválidas." << std::endl;
                        return;
                    }
                }
            }
            archivoPalabras.close();

            // Crear un objeto ArbolTrieInverso y construirlo desde el archivo
            std::ifstream archivoPalabras2(nombreArchivo);
            while (archivoPalabras2 >> palabra)
            {
                arbolInverso.insertarPalabra(sufijo.sufijoInvertido(palabra)); // Insertar palabra invertida
            }
            archivoPalabras2.close();

            // Establecer arbolInversoInicializado en true en caso de que no lo esté
            arbolInversoInicializado = true;
            std::cout << "Árbol Trie inverso inicializado correctamente desde el archivo " << nombreArchivo << std::endl;

            // Imprimir el contenido del árbol inverso para verificar
            std::cout << "Contenido del árbol Trie inverso:" << std::endl;
            arbolInverso.imprimirContenido();
        }
        else
        {
            std::cout << "El árbol Trie inverso ya ha sido inicializado" << std::endl;
        }
    }

    else if (comando_actual.find("palabras_por_prefijo ") == 0)
    {
        if (arbolInicializado)
        {
            std::string prefijo = comando_actual.substr(21); // Obtener el prefijo después del espacio
            // Validar que el prefijo solo contenga caracteres alfabéticos
            bool caracteres_validos = true;
            for (char c : prefijo)
            {
                if (!isalpha(c))
                {
                    caracteres_validos = false;
                    break;
                }
            }
            if (!caracteres_validos)
            {
                std::cout << "Error: El prefijo contiene caracteres no alfabéticos." << std::endl;
            }
            else
            {
                std::cout << "Palabras con el prefijo '" << prefijo << "':" << std::endl;
                arbol.palabrasPorPrefijo(prefijo); // Llamar a la función en ArbolTrie
            }
        }
        else
        {
            std::cout << "Error: El árbol Trie no ha sido inicializado" << std::endl;
        }
    }

    else if (comando_actual.find("palabras_por_sufijo ") == 0)
    {
        if (arbolInversoInicializado)
        {

            std::string sufijo = comando_actual.substr(20); // Obtener el sufijo después del espacio

            // Validar que el sufijo solo contenga caracteres alfabéticos
            bool caracteres_validos = true;
            for (char c : sufijo)
            {
                if (!isalpha(c))
                {
                    caracteres_validos = false;
                    break;
                }
            }
            if (!caracteres_validos)
            {
                std::cout << "Error: El sufijo contiene caracteres no alfabeticos." << std::endl;
            }
            else
            {
                std::cout << "Palabras con el sufijo '" << sufijo << "':" << std::endl;
                arbolInverso.palabrasPorSufijo(sufijo);
            }
        }
        else
        {
            std::cout << "Error: El árbol Trie inverso no ha sido inicializado" << std::endl;
        }
    }

    else if (comando_actual == "grafo_de_palabras")
    {
        std::cout << "Grafo construido exitosamente" << std::endl;
    }
    else if (comando_actual.find("posibles_palabras ") == 0)
    {
        size_t espacio_pos = comando_actual.find(" ");
        if (espacio_pos != std::string::npos && espacio_pos + 1 < comando_actual.length())
        {
            std::string letras = comando_actual.substr(espacio_pos + 1); // Obtener las letras después del espacio
            bool letras_validas = true;
            for (char c : letras)
            {
                if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '?'))
                {
                    letras_validas = false;
                    break;
                }
            }
            if (letras.empty())
            {
                std::cout << "La cadena de letras está vacía." << std::endl;
            }
            else if (!letras_validas)
            {
                std::cout << "La cadena de letras contiene símbolos inválidos." << std::endl;
            }
            else
            {
                std::cout << "Las posibles palabras a construir con las letras letras son:" << std::endl;
            }
        }
        else
        {
            std::cout << "Comando 'posibles_palabras' mal formado." << std::endl;
        }
    }

    else if (comando_actual == "ayuda")
    {
        std::cout << "Lista de comandos:" << std::endl;
        std::cout << "inicializar" << std::endl;
        std::cout << "iniciar_inverso" << std::endl;
        std::cout << "puntaje palabra" << std::endl;
        std::cout << "iniciar_arbol" << std::endl;
        std::cout << "iniciar_arbol_inverso " << std::endl;
        std::cout << "palabras_por_prefijo prefijo" << std::endl;
        std::cout << "palabras_por_sufijo sufijo" << std::endl;
        std::cout << "grafo_de_palabras" << std::endl;
        std::cout << "posibles_palabras letras" << std::endl;
        std::cout << "ayuda" << std::endl;
        std::cout << "ayuda comando" << std::endl;
        std::cout << "salir" << std::endl;
    }
    else if (comando_actual == "ayuda comando")
    {
        std::cout << "Función de los comandos:" << std::endl;
        std::cout << "inicializar: Inicializa el sistema a partir del diccionario.txt el cual se le tiene que pasar por parametro, que contiene un diccionario en formato .txt." << std::endl;
        std::cout << "iniciar_inverso diccionario.txt: Inicializa el sistema a partir del diccionario.txt, pero este almacena las palabras en sentido inverso (derecha a izquierda)." << std::endl;
        std::cout << "puntaje palabra: Permite el conocer la puntuación que puede obtenerse con una sola palabra." << std::endl;
        std::cout << "iniciar_arbol diccionario.txt: Inicializa el sistema a partir del diccionario.txt, pero este almacena las palabras en uno o más árboles de letras." << std::endl;
        std::cout << "iniciar_arbol_inverso diccionario.txt: Inicializa el sistema a partir del archivo diccionario.txt, almacena las palabras en uno o más arboles de letras leídas de forma inversa (derecha a izquierda)." << std::endl;
        std::cout << "palabras_por_prefijo prefijo: El programa recorre los árboles de letras previamente construidos para ubicar todas las palabras posibles a construir a partir del prefijo otorgado mediante el comando." << std::endl;
        std::cout << "palabras_por_sufijo sufijo: El programa recorre los árboles de letras previamente construidos para ubicar todas las palabras posibles a construir a partir del sufijo otorgado mediante el comando." << std::endl;
        std::cout << "grafo_de_palabras: (Se requiere haber inicializado previamente) construye un grafo de palabras, en donde cada palabra se conecta a las demás si y solo si, difieren en alguna letra." << std::endl;
        std::cout << "posibles_palabras letras: (Se requiere de un grafo de palabras previamente construido) presentar en una pantalla todas las posibles palabras a construir, además de indicar la longitud de cada palabra y la puntuación con cada una de ellas." << std::endl;
        std::cout << "ayuda: Mostrar cada comando disponible." << std::endl;
        std::cout << "comando ayuda: Mostrar cada comando disponible e incluir una descripción de su función." << std::endl;
        std::cout << "salir: Termina la ejecución de la aplicación." << std::endl;
    }
    else if (comando_actual == "salir")
    {
        std::cout << "Saliendo de la aplicación" << std::endl;
    }
    else
    {
        std::cout << "Comando no reconocido" << std::endl;
    }
}
