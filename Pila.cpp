//
// Created by okkid-a on 3/6/24.
//

#include "Pila.h"

Pila::Pila() {
    top = nullptr;
}


void Pila::pushOne(Nodo *nuevoTop) {
    if (top == nullptr){
        top = nuevoTop;
        nuevoTop->anterior = nullptr;
        nuevoTop->siguiente = nullptr;
    } else{
        top->siguiente = nuevoTop;
        nuevoTop->anterior = top;
        top = nuevoTop;
    }
    nuevoTop->siguiente = nullptr;
}

void Pila::pushMulti(Nodo *nuevoBot) {
    Nodo* nuevoTop = recorrerATop(nuevoBot);
    if (top == nullptr){
        nuevoTop->siguiente = nullptr;
        nuevoBot->anterior = nullptr;
        top = nuevoTop;
    } else {
        top->siguiente = nuevoBot;
        nuevoBot->anterior = top;
        nuevoBot->siguiente = nullptr;
        top = nuevoTop;
    }
}

Nodo *Pila::popMulti(int index) {
    if (top!= nullptr) {
        Nodo *temp = recorrer(index);
        if (temp!= nullptr&&temp->anterior!= nullptr){
            top = temp->anterior;
            top->siguiente = nullptr;
            temp->anterior = nullptr;
            top->carta->revelar();
        } else{
            top = nullptr;
        }
        temp->anterior = nullptr;
        return temp;
    } else{
        return nullptr;
    }
}

Nodo *Pila::pop() {
    if (!isEmpty()){
        Nodo *temp = top;
        if (top->anterior!= nullptr){
            top = temp->anterior;
            top->carta->revelar();
            top->siguiente = nullptr;
        } else{
            top = nullptr;
        }
        temp->anterior = nullptr;
        return temp;
    }
    return nullptr;
}

Nodo *Pila::recorrer(int index) {
    Nodo* temp = top;
    for (int i = 0; i < index-1; ++i) {
        if (temp->anterior!= nullptr){
            temp = temp->anterior;
        } else {
            return nullptr;
        }
    }
    return temp;
}

Nodo *Pila::recorrerATop(Nodo* nodoBot){
    Nodo* temp = nodoBot;
    while (nodoBot->siguiente!= nullptr){
        temp = temp->siguiente;
    }
    return temp;
}

Pila::~Pila()
{
    Nodo *reco = top;
    Nodo *bor;
    while (reco != NULL)
    {
        bor = reco;
        reco = reco->siguiente;
        delete bor;
    }
}

int Pila::getTamano(){
    int tamano=1;
    Nodo* temp = top;
    if (temp!= nullptr) {
        while (temp->anterior != nullptr) {
            temp = temp->anterior;
            tamano++;
        }
    } else {
        tamano = 0;
    }
    return tamano;
}

bool Pila::isEmpty() {
    if (top== nullptr){
        return true;
    } else {
        return false;
    }
}

Carta* Pila::peek() {
    return top->carta;
}




