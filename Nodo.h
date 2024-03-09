//
// Created by okkid-a on 3/6/24.
//

#ifndef SOLITARIO_NODO_H
#define SOLITARIO_NODO_H


#include "Carta.h"

class Nodo {
public:

    Nodo* siguiente;
    Nodo* anterior;
    Nodo* retrocede;
    Nodo* adelanta;
    Carta* carta;


    explicit Nodo(Carta *carta);

};


#endif //SOLITARIO_NODO_H
