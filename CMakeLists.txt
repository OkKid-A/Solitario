cmake_minimum_required(VERSION 3.27)
project(Solitario)

set(CMAKE_CXX_STANDARD 17)

add_executable(Solitario main.cpp
        Pila.cpp
        Pila.h
        Carta.cpp
        Carta.h
        Nodo.cpp
        Nodo.h
        Cola.cpp
        Cola.h
        Dealer.cpp
        Dealer.h
        Mesa.cpp
        Mesa.h
        Interfaz.cpp
        Interfaz.h
)
