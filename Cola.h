//
// Created by okkid-a on 3/7/24
//

#ifndef SOLITARIO_COLA_H
#define SOLITARIO_COLA_H


#include "Nodo.h"

class Cola {
private:
    Nodo* top;
    Nodo* bot;
    int tamano;
public:
    Cola();
    Nodo* poll();
    void add(Nodo* nuevoBot);
    Nodo* peek();
    int getTamano();
    bool isEmpty();
    void addMulti(Nodo *nuevoBot, Nodo *nuevoTop);
    Nodo *peekReverse();
    void removeAll();

    Nodo *pop();
};


#endif //SOLITARIO_COLA_H
