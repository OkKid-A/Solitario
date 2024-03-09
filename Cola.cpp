//
// Created by okkid-a on 3/7/24.
//

#include "Cola.h"

Cola::Cola(){
    top = nullptr;
    bot = nullptr;
    tamano = 0;
}

Nodo *Cola::poll() {
    if (top!= nullptr){
        Nodo* temp = top;
        if (top->anterior!= nullptr){
            top = top->anterior;
            top->siguiente = nullptr;
        } else {
            top = nullptr;
            bot = nullptr;
        }
        return temp;
    } else {
        return nullptr;
    }
}

bool Cola::isEmpty() {
    if (top== nullptr){
        return true;
    } else{
        return false;
    }
}

void Cola::add(Nodo *nuevoBot) {
    if (top== nullptr){
        nuevoBot->carta->revelar();
        top = nuevoBot;
        bot = nuevoBot;
        top->siguiente = nullptr;
        top->anterior = nullptr;
    } else {
        nuevoBot->carta->revelar();
        if (bot->siguiente == nullptr){
            top->anterior = nuevoBot;
        }
        nuevoBot->siguiente = bot;
        bot->anterior = nuevoBot;
        bot->carta->esconder();
        nuevoBot->anterior = nullptr;
        bot = nuevoBot;
    }
}

Nodo* Cola::pop(){
    if (bot!= nullptr){
        Nodo* temp = bot;
        if (bot->siguiente!= nullptr){
            bot = bot->siguiente;
            bot->carta->revelar();
            bot->siguiente = nullptr;
        } else {
            top = nullptr;
            bot = nullptr;
        }
        return temp;
    } else {
        return nullptr;
    }
}

void Cola::addMulti(Nodo *nuevoBot, Nodo *nuevoTop){
    top = nuevoTop;
    bot = nuevoBot;
}

void Cola::removeAll(){
    top = nullptr;
    bot = nullptr;
}

Nodo *Cola::peek() {
    return top;
}

Nodo *Cola::peekReverse() {
    return bot;
}

int Cola::getTamano() {
    return 0;
}


