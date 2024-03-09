#include <iostream>
#include "Pila.h"
#include "Dealer.h"
#include "Interfaz.h"
#include "Mesa.h"

int main() {
    Dealer* dealer = new Dealer();
    Mesa* mesa = new Mesa(dealer);
    Interfaz* interfaz = new Interfaz(dealer);
    while (1){
        mesa->dibujarMesa();
        interfaz->imprimirMenu();
    }
}

