#include "Vector.hpp"

Vector::Vector() : Vector(0) {
}

Vector::Vector(std::size_t cantidad_inicial) {
    if (cantidad_inicial == 0) {
        recursos = nullptr;
    } else {
        recursos = new Recurso[cantidad_inicial];
    }
    maximo_fisico = cantidad_inicial;
    maximo_logico = 0;
}

void Vector::alta(Recurso recurso) {
    if (maximo_fisico == maximo_logico) {
        redimensionar();
    }
    recursos[maximo_logico] = recurso;
    maximo_logico++;
}

Recurso& Vector::operator[](std::size_t indice) {
    if (indice < maximo_logico) {
        return recursos[indice];
    } else {
        throw ExcepcionVector("El índice no es válido: " + std::to_string(indice));
    }
}

void Vector::intercambiar(std::size_t indice_1, std::size_t indice_2) {
    if (indice_1 < maximo_logico && indice_2 < maximo_logico) {
        Recurso aux = recursos[indice_1];
        recursos[indice_1] = recursos[indice_2];
        recursos[indice_2] = aux;
    } else {
        throw ExcepcionVector(
                "Los índices no son válidos: " + std::to_string(indice_1) + ", " + std::to_string(indice_2));
    }
}

void Vector::redimensionar() {
    if (maximo_fisico == 0) {
        recursos = new Recurso[1];
        maximo_fisico = 1;
    } else {
        Recurso* aux = new Recurso[maximo_fisico + 1];
        for (size_t i = 0; i < maximo_logico; ++i) {
            aux[i] = recursos[i];
        }
        delete[] recursos;
        recursos = aux;
        maximo_fisico++;
    }
}

Vector::~Vector() {
    delete[] recursos;
}