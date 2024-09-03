#ifndef LETRA_H
#define LETRA_H

#include <list>
#include <string>

class Letra {
private:
    std::list<char> letras;

public:
    Letra(const std::string& palabra);
    std::list<char> obtenerLista() const;
};

#endif // LETRA_H
