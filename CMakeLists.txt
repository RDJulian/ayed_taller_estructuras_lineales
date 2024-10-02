cmake_minimum_required(VERSION 3.22)
project(ayed_taller_estructuras_lineales)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "../")

add_compile_options(-Wall -Werror -Wconversion)

include_directories(include)

set(ARCHIVOS_FUENTE
        src/Cola.cpp
        src/Inventario.cpp
        src/Vector.cpp
        src/Recurso.cpp
        include/Cola.hpp
        include/Inventario.hpp
        include/Vector.hpp
        include/Recurso.hpp
)

add_executable(ayed_taller_estructuras_lineales
        ${ARCHIVOS_FUENTE}
        main.cpp
)

set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "main")