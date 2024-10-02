#ifndef AYED_TALLER_ESTRUCTURAS_LINEALES_INVENTARIO_HPP
#define AYED_TALLER_ESTRUCTURAS_LINEALES_INVENTARIO_HPP

#include <cstddef>
#include <stdexcept>
#include "Recurso.hpp"
#include "Vector.hpp"

class ExcepcionInventario : public std::runtime_error {
    // Excepción específica para el Inventario.
public:
    ExcepcionInventario(std::string mensaje) : std::runtime_error(mensaje) {}
};

const std::size_t TAMANIO = 27;

class Inventario {
private:
    Vector recursos;
    std::size_t tope;

    // PRE: -
    // POST: Agrega la cantidad indicada de recursos nulos al Inventario.
    void agregar_recursos_nulos(size_t cantidad);

public:
    // Constructor.
    Inventario();

    // PRE: -
    // Constructor.
    Inventario(std::size_t tamanio_inicial);

    // PRE: -
    // POST: Agranda el inventario, agregando los espacios indicados.
    void agrandar_inventario(std::size_t espacios_a_agregar);

    // PRE: Debe haber espacio en el inventario.
    // POST: Guarda el recurso en el primer espacio vacío.
    void guardar_recurso(Recurso recurso);

    // PRE: Posición debe ser menor al tope.
    // POST: Guarda el recurso en la posición indicada.
    // Devuelve el recurso que estaba en esa posición.
    Recurso guardar_recurso(Recurso recurso, std::size_t posicion);

    // PRE: Las posiciones deben ser menor al tope.
    // POST: Intercambia los recursos de las posiciones indicadas.
    void intercambiar_recursos(std::size_t posicion_1, std::size_t posicion_2);

    // PRE: -
    // POST: Muestra por pantalla todos los recursos guardados en el Inventario.
    void mostrar_recursos();
};

#endif