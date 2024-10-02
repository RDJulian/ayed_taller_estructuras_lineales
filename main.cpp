#include <iostream>
#include "Inventario.hpp"

int main() {
    Inventario inventario(10);

    inventario.mostrar_recursos();
    std::cout << std::endl;

    inventario.agrandar_inventario(5);
    inventario.guardar_recurso({"Cable", 200});
    inventario.guardar_recurso({"Motor", 30});
    inventario.guardar_recurso({"Supercomputadora", 15});

    inventario.mostrar_recursos();
    std::cout << std::endl;

    Recurso recurso = inventario.guardar_recurso({"Lingote de Hierro", 100}, 0);

    std::cout << "El recurso que se quitó del inventario es: ";
    recurso.mostrar_informacion();
    std::cout << std::endl;

    inventario.mostrar_recursos();
    std::cout << std::endl;

    inventario.intercambiar_recursos(0, 1);

    inventario.mostrar_recursos();
    std::cout << std::endl;

    return 0;
}