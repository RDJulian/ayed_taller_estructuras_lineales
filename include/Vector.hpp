#ifndef AYED_TALLER_ESTRUCTURAS_LINEALES_VECTOR_HPP
#define AYED_TALLER_ESTRUCTURAS_LINEALES_VECTOR_HPP

#include <cstddef>
#include <stdexcept>
#include "Recurso.hpp"

class ExcepcionVector : public std::runtime_error {
    // Excepción específica para el Vector.
public:
    ExcepcionVector(std::string mensaje) : std::runtime_error(mensaje) {}
};

class Vector {
private:
    std::size_t maximo_fisico;
    std::size_t maximo_logico;
    Recurso* recursos;

    // PRE: -
    // POST: Redimensiona el vector, aumentando el máximo físico en 1.
    void redimensionar();

public:
    // Constructor.
    Vector();

    // PRE: -
    // Constructor.
    Vector(std::size_t cantidad_inicial);

    // PRE: -
    // POST: Agrega el dato al final del vector.
    void alta(Recurso recurso);

    // PRE: El índice debe ser menor que el máximo lógico.
    // POST: Devuelve una referencia del dato en el índice indicado.
    Recurso& operator[](std::size_t indice);

    // PRE: Ambos índices deben ser menores que el máximo lógico.
    // POST: Intercambia los elementos en los índices indicados.
    void intercambiar(std::size_t indice_1, std::size_t indice_2);

    // Destructor.
    ~Vector();
};

#endif