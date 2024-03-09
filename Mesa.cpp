//
// Created by okkid-a on 3/8/24.
//

#include "Mesa.h"
using namespace std;



void Mesa::dibujarMesa(){
    cout << dibujarFilaFoundations() <<endl << endl;
    dibujarFilaTableau();
    cout<<endl;
}

string Mesa::dibujarFilaFoundations(){
    string fila = "\t";
    if(!dealer->hand->isEmpty()){
        fila = "\t"+dealer->hand->peek()->carta->getCartaString();
    } else{
        fila = "\t" + cVacia;
    }
    if (!dealer->waste->isEmpty()){
        fila = fila + "\t" + dealer->waste->peekReverse()->carta->getCartaString();
    } else {
        fila = fila + "\t" + cVacia;
    }
    fila = fila + "\t      ";
    for (Pila* pila: dealer->cimientos) {
        if (!pila->isEmpty()){
            fila = fila + "\t" + pila->peek()->getCartaString();
        } else {
            fila = fila + "\t" + cVacia;
        }
    }
    return fila;
}

void Mesa::dibujarFilaTableau(){
    string fila = "";
    int filasEx = 0;
    bool dentenerse = false;
    while (!dentenerse){
        for (int i = 0; i < 7; ++i) {
            if ((dealer->tableau[i]->getTamano() - filasEx) >= 1){
                string toAdd = dealer->tableau[i]->recorrer(dealer->tableau[i]->getTamano()-filasEx)->carta->getCartaString();
                fila.append("\t"+toAdd);
                dentenerse = false;
            } else {
                dentenerse = true;
                fila.append("      \t");
            }
        }
        cout << fila << endl;
        fila = "";
        filasEx++;
    }
}

Mesa::Mesa(Dealer *dealer) {
    this->dealer = dealer;
}

Mesa::~Mesa() {
    delete(this);
}

