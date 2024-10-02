#ifndef AYED_TALLER_ESTRUCTURAS_LINEALES_RECURSO_HPP
#define AYED_TALLER_ESTRUCTURAS_LINEALES_RECURSO_HPP

#include <cstddef>
#include <string>

const std::string NULO = "";

class Recurso {
private:
    std::string nombre;
    std::size_t cantidad;
public:
    // Constructor.
    Recurso();

    // PRE: -
    // Constructor
    Recurso(std::string nombre, std::size_t cantidad);

    // PRE: -
    // POST: Devuelve true si el recurso es nulo (es decir, su nombre es NULO).
    bool es_nulo();

    // PRE: -
    // Post: Imprime por pantalla la información del recurso.
    // Si es nulo, muestra un espacio vacío.
    void mostrar_informacion();
};

#endif