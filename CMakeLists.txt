cmake_minimum_required(VERSION 3.19)
project(Veterinaria_Syntax_Error)

include(CTest)
enable_testing()

set(CMAKE_CXX_STANDARD 17)

add_executable(Veterinaria_Syntax_Error  src/ConsultaVeterinario.cpp  src/ConsultaVeterinario.h  src/GestionPerrosController.cpp  src/GestionPerrosController.h  src/Perro.cpp  src/Perro.h  src/Propietario.h  src/Propietario.cpp  src/Raza.cpp  src/Raza.h  src/Veterinario.cpp  src/Veterinario.h  src/main.cpp)

