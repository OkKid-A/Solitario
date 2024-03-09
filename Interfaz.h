//
// Created by okkid-a on 3/8/24.
//

#ifndef SOLITARIO_INTERFAZ_H
#define SOLITARIO_INTERFAZ_H


#include "Dealer.h"

class Interfaz {
private:
    Dealer* dealer;

public:
    explicit Interfaz(Dealer *dealer);

    void imprimirMenu();

    void realizarMovimiento();

    void moverPila();

    void usarDeposito();

    void verAnteSiguiente();

    void moverACimiento();
};


#endif //SOLITARIO_INTERFAZ_H
