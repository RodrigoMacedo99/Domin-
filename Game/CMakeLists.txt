cmake_minimum_required(VERSION 3.28)
project(Domino C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Domino
        control.h
        Fila.h
        lista_de.h
        main.c
        model.h
        pilha.h
        viwer.h)
