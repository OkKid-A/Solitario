//
// Created by okkid-a on 3/8/24.
//

#ifndef SOLITARIO_MESA_H
#define SOLITARIO_MESA_H


#include "Dealer.h"
using namespace std;

class Mesa {
    const string cVacia = "[    ]";
    Dealer* dealer;
public:
    Mesa(Dealer* dealer);
    ~Mesa();
    void dibujarMesa();

    std::string dibujarFilaFoundations();

    void dibujarFilaTableau();
};


#endif //SOLITARIO_MESA_H
