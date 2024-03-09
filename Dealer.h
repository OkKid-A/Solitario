//
// Created by okkid-a on 3/8/24.
//

#ifndef SOLITARIO_DEALER_H
#define SOLITARIO_DEALER_H


#include "Pila.h"
#include "Cola.h"
#include <bits/stdc++.h>

class Dealer {
private:
    Carta * crearCarta(int cardNum);
    void iniPilas();
public:
    Pila *tableau[7];
    Pila *cimientos[4];
    Cola *hand;
    Cola *waste;
    Cola *memoria;

    Dealer();

    void moverCartaEntreCol(int colFrom, int cardNum, int colDest);
    void pasarCartaAWaste();
    void barajar();
    void verSiguiente(int colNum, int cardNum);

    void verAnterior(int colFrom, int cardNum);

    void pasarHandaCol(int colNum);

    void moverACimiento(int colFrom);
};


#endif //SOLITARIO_DEALER_H
