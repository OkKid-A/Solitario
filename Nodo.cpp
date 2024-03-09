//
// Created by okkid-a on 3/6/24.
//

#include "Nodo.h"

Nodo::Nodo(Carta *carta) : carta(carta) {
    this->siguiente = nullptr;
    this->anterior = nullptr;
}

