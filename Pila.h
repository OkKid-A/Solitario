//
// Created by okkid-a on 3/6/24.
//

#ifndef SOLITARIO_PILA_H
#define SOLITARIO_PILA_H


#include "Nodo.h"
#include "Carta.h"

class Pila {
public:
    Pila();
    ~Pila();
    void pushOne(Nodo* nuevoTop);
    void pushMulti(Nodo* nuevoBot);
    Nodo *popMulti(int index);
    Nodo* pop();
    Nodo* recorrer(int index);
    bool isEmpty();
    Carta *peek();
    static Nodo *recorrerATop(Nodo* nodoBot);
    int getTamano();

private:
    Nodo *top;
    int tamano;


};


#endif //SOLITARIO_PILA_H
