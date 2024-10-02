#include <iostream>
#include "Recurso.hpp"

Recurso::Recurso() : Recurso(NULO, 0) {
}

Recurso::Recurso(std::string nombre, size_t cantidad) {
    this->nombre = nombre;
    this->cantidad = cantidad;
}

bool Recurso::es_nulo() {
    return nombre == NULO;
}

void Recurso::mostrar_informacion() {
    if (!es_nulo()) {
        std::cout << "[" << nombre << ": " << cantidad << "]";
    } else {
        std::cout << "[    ]";
    }
}