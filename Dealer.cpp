//
// Created by okkid-a on 3/8/24.
//

#include <ctime>
#include "Dealer.h"
#include "Mesa.h"
#include <bits/stdc++.h>

using namespace std;

Dealer::Dealer() {
    hand = new Cola();
    waste = new Cola();
    memoria = new Cola();
    iniPilas();
    barajar();
}

void Dealer::moverCartaEntreCol(int colFrom, int cardNum, int colDest){
        if (!tableau[colFrom-1]->isEmpty()) {
            if (cardNum == 1) {
                if (!tableau[colDest - 1]->isEmpty()) {
                    if (tableau[colFrom - 1]->peek()->isColor() != tableau[colDest - 1]->peek()->isColor()) {
                        if (tableau[colFrom - 1]->peek()->getNumero() ==
                            (tableau[colDest - 1]->peek()->getNumero() - 1)) {
                            Nodo *aMover = tableau[colFrom - 1]->pop();
                            tableau[colDest - 1]->pushOne(aMover);
                        } else {
                            cout << "El numero de la carta destino no es el requerido" << endl;
                        }
                    } else {
                        cout << "El color de la carta destino no es el requerido" << endl;
                    }
                } else {
                    if (tableau[colFrom - 1]->peek()->getNumero() == 13) {
                        Nodo *aMover = tableau[colFrom - 1]->pop();
                        tableau[colDest - 1]->pushOne(aMover);
                    } else {
                        cout << "Solo una carta K se puede mover a una columna vacia" << endl;
                    }
                }
            } else {
                if (tableau[colFrom - 1]->recorrer(cardNum) != nullptr) {
                    Carta *aComp = tableau[colFrom - 1]->recorrer(cardNum)->carta;
                    if (aComp->isRevelada()) {
                        if (!tableau[colDest - 1]->isEmpty()) {
                            if (aComp->isColor() != tableau[colDest - 1]->peek()->isColor()) {
                                if (aComp->getNumero() ==
                                    (tableau[colDest - 1]->peek()->getNumero() - 1)) {
                                    Nodo *aMover = tableau[colFrom - 1]->popMulti(cardNum);
                                    tableau[colDest - 1]->pushMulti(aMover);
                                } else {
                                    cout << "El numero de la carta destino no es el requerido" << endl;
                                }
                            } else {
                                cout << "El color de la carta destino no es el requerido" << endl;
                            }

                        } else {
                            if (aComp->getNumero() == 13) {
                                Nodo *aMover = tableau[colFrom - 1]->popMulti(cardNum);
                                tableau[colDest - 1]->pushMulti(aMover);
                            } else {
                                cout << "Solo una carta K se puede mover a una columna vacia" << endl;
                            }
                        }
                    } else{
                        cout << "Esa carta aun no ha sido revelada" <<endl ;
                    }
                } else {
                    cout << "La pila no contiene " << cardNum << " cartas" << endl;
                }
            }
        }else {
            cout<<"No existen cartas en la columna"<<endl;
        }

}

void Dealer::moverACimiento(int colFrom){
    if (!tableau[colFrom-1]->isEmpty()) {
        Carta* carSel = tableau[colFrom-1]->peek();
        if (!cimientos[carSel->getFamilia() - 1]->isEmpty()) {
                if (carSel->getNumero() ==
                    (cimientos[carSel->getFamilia() - 1]->peek()->getNumero() - 1)) {
                    Nodo *aMover = tableau[colFrom - 1]->pop();
                    cimientos[carSel->getFamilia() - 1]->pushOne(aMover);
                } else {
                    cout << "El numero de la carta destino no es el requerido" << endl;
                }
        } else {
            if (carSel->getNumero() == 1) {
                Nodo *aMover = tableau[colFrom - 1]->pop();
                cimientos[carSel->getFamilia() - 1]->pushOne(aMover);
            } else {
                cout << "Solo una carta A se puede mover a un cimiento vacio" << endl;
            }
        }
    }else {
        cout<<"No existen cartas en la columna"<<endl;
    }
}

void Dealer::pasarCartaAWaste(){
    if(!hand->isEmpty()){
        waste->add(hand->poll());
    } else if (!waste->isEmpty()){
        hand->addMulti(waste->peekReverse(),waste->peek());
        hand->peek()->carta->esconder();
        waste->removeAll();
    } else {
        cout << "No existen cartas para mover" << endl;
    }
}

void Dealer::pasarHandaCol(int colNum){
    Carta* aComp = waste->peekReverse()->carta;
    if (!waste->isEmpty()) {
        if (!tableau[colNum - 1]->isEmpty()) {
            if (aComp->isColor() != tableau[colNum - 1]->peek()->isColor()) {
                if (aComp->getNumero() ==
                    (tableau[colNum - 1]->peek()->getNumero() - 1)) {
                    Nodo *aMover = waste->pop();
                    tableau[colNum - 1]->pushOne(aMover);
                } else {
                    cout << "El numero de la carta destino no es el requerido" << endl;
                }
            } else {
                cout << "El color de la carta destino no es el requerido" << endl;
            }
        } else {
            if (aComp->getNumero() == 13) {
                Nodo *aMover = waste->pop();
                tableau[colNum - 1]->pushOne(aMover);
            } else {
                cout << "Solo una carta K se puede mover a una columna vacia" << endl;
            }
        }
    } else {
        cout << "No hay cartas en el deposito" << endl;
    }
}

void Dealer::verSiguiente(int colFrom, int cardNum){
    if (!tableau[colFrom-1]->isEmpty()) {
        if (tableau[colFrom-1]->recorrer(cardNum)!= nullptr){
            if ((tableau[colFrom-1]->recorrer(cardNum)->siguiente)!= nullptr){
               Nodo* temp =  (tableau[colFrom-1]->recorrer(cardNum)->siguiente);
               temp->carta->revelar();
               Mesa *mesa = new Mesa(this);
               mesa->dibujarMesa();
               cout <<"1. Continuar" << endl;
               int resultado;
               cin >> resultado;
               temp->carta->esconder();
            } else {
                cout << "Esta carta no tiene un siguiente" << endl;
            }
        } else {
            cout << "La pila no contiene " << cardNum << " cartas" << endl;
        }
    }else {
        cout<<"No existen cartas en la columna"<<endl;
    }
}

void Dealer::verAnterior(int colFrom, int cardNum){
    if (!tableau[colFrom-1]->isEmpty()) {
        if (tableau[colFrom-1]->recorrer(cardNum)!= nullptr){
            if ((tableau[colFrom-1]->recorrer(cardNum)->anterior)!= nullptr){
                Nodo* temp =  (tableau[colFrom-1]->recorrer(cardNum)->anterior);
                temp->carta->revelar();
                Mesa *mesa = new Mesa(this);
                mesa->dibujarMesa();
                cout <<"1. Continuar" << endl;
                int resultado;
                cin >> resultado;
                temp->carta->esconder();
            } else {
                cout << "Esta carta no tiene un anterior" << endl;
            }
        } else {
            cout << "La pila no contiene " << cardNum << " cartas" << endl;
        }
    }else {
        cout<<"No existen cartas en la columna"<<endl;
    }
}

void Dealer::barajar(){
    srand(time(nullptr));
    unsigned seed = rand();
    int baraja[52];
    for (int i = 0; i < 52; ++i) {
        baraja[i] = i+1;
    }
    shuffle(baraja, baraja + 52, default_random_engine(seed));
    for (int i = 0; i < 52; ++i) {
        Nodo *nuevo = new Nodo(crearCarta(baraja[i]));
        if (i<1) {
            nuevo->carta->revelar();
            tableau[0]->pushOne(nuevo);
        }else if (i<3) {
            if (i == 2) {
                nuevo->carta->revelar();
            }
            tableau[1]->pushOne(nuevo);
        }else if (i<6){
            if(i==5){
                nuevo->carta->revelar();
            }
            tableau[2]->pushOne(nuevo);
        }else if (i<10) {
            if(i==9){
                nuevo->carta->revelar();
            }
            tableau[3]->pushOne(nuevo);
        }else if (i<15) {
            if(i==14){
                nuevo->carta->revelar();
            }
            tableau[4]->pushOne(nuevo);
        }else if (i<21) {
            if(i==20){
                nuevo->carta->revelar();
            }
            tableau[5]->pushOne(nuevo);
        }else if (i<28) {
            if(i==27){
                nuevo->carta->revelar();
            }
            tableau[6]->pushOne(nuevo);
        }else
            hand->add(nuevo);
    }
}

Carta * Dealer::crearCarta(int cardNum){
    int cardTipo = cardNum % 13;
    int cardFam;
    bool color;
    if (cardTipo == 0){
        cardTipo = 13;
    }
    if (cardNum >= 1 && cardNum < 14) {
        cardFam = 1;
    } else if (cardNum > 13 && cardNum < 27) {
        cardFam = 2;
    } else if (cardNum > 26 && cardNum < 40) {
        cardFam = 3;
    } else {
        cardFam = 4;
    }
    if (cardFam<3){
        color = true;
    } else{
        color = false;
    }
    Carta *carta = new Carta(cardTipo,cardFam, color);
    return carta;
}

void Dealer::iniPilas() {
    for (int i = 0; i < 4; ++i) {
        cimientos[i] = new Pila();
    }
    for (int i = 0; i < 7; ++i) {
        tableau[i] = new Pila();
    }
}

