#include <iostream>
#include "Inventario.hpp"

Inventario::Inventario() : Inventario(TAMANIO) {}

Inventario::Inventario(size_t tamanio_inicial) {
    // NOTA: Es necesario agregar manualmente los recursos nulos porque necesitamos
    // que la cantidad de datos del vector (máximo lógico) sea igual al tope.
    // Esto tiene sentido porque, para nosotros, un recurso nulo es un dato válido.
    // NOTA 2: Durante la clase escribimos "recursos = Vector(tamanio_inicial);".
    // Esto está bien, si y solo si implementan previamente el operador=() (asignación).
    // De forma similar a constructor de copia default, el operador de asignación, si no está
    // implementado manualmente, va a asumir el default, que copia todos los atributos.
    // Como nuestro Vector maneja memoria dinámica, no implementarlo leakea toda la memoria.
    // La implementación es similar al constructor de copia, pueden ver ejemplos acá:
    // https://en.cppreference.com/w/cpp/language/operators (donde dice assignment operator)
    agregar_recursos_nulos(tamanio_inicial);
    tope = tamanio_inicial;
}

void Inventario::agregar_recursos_nulos(size_t cantidad) {
    for (size_t i = 0; i < cantidad; ++i) {
        recursos.alta({});
    }
}

void Inventario::agrandar_inventario(size_t espacios_a_agregar) {
    agregar_recursos_nulos(espacios_a_agregar);
    tope += espacios_a_agregar;
}

void Inventario::guardar_recurso(Recurso recurso) {
    size_t i = 0;
    bool guardado = false;
    while (!guardado && i < tope) {
        if (recursos[i].es_nulo()) {
            recursos[i] = recurso;
            guardado = true;
        }
        i++;
    }
    if (!guardado) {
        throw new ExcepcionInventario("El inventario está lleno. No se pudo agregar el recurso.");
    }
}

Recurso Inventario::guardar_recurso(Recurso recurso, std::size_t posicion) {
    // Acá se puede tratar la excepción del Vector, relanzar una excepción
    // del Inventario o dejar sin tratar la excepción del Vector.
    Recurso recurso_a_devolver = recursos[posicion];
    recursos[posicion] = recurso;
    return recurso_a_devolver;
}

void Inventario::intercambiar_recursos(std::size_t posicion_1, std::size_t posicion_2) {
    // Acá se puede tratar la excepción del Vector, relanzar una excepción
    // del Inventario o dejar sin tratar la excepción del Vector.
    recursos.intercambiar(posicion_1, posicion_2);
}

void Inventario::mostrar_recursos() {
    for (size_t i = 0; i < tope; ++i) {
        recursos[i].mostrar_informacion();
        std::cout << " ";
    }
}