//
// Created by okkid-a on 3/6/24.
//
#include "Carta.h"
using namespace std;

Carta::Carta(int numero, int familia, bool color) : numero(numero), familia(familia), color(color) {
    this->revelada = false;
}

string Carta::getCartaString() {
    string resultado;
    if (revelada) {
        resultado.append("[");
        resultado.append(traducirNumero());
        resultado.append(traducirFamilia());
        resultado.append(traducirColor());
        resultado.append("]") ;
    } else {
        resultado = "[----]";
    }
    return resultado ;
}

string Carta::traducirNumero() const {
    switch (numero) {
        case 0:
            return "K";
        case 1:
            return "A";
        case 2:
            return "2";
        case 3:
            return "3";
        case 4:
            return "4";
        case 5:
            return "5";
        case 6:
            return "6";
        case 7:
            return "7";
        case 8:
            return "8";
        case 9:
            return "9";
        case 10:
            return "10";
        case 11:
            return "J";
        case 12:
            return "Q";
        case 13:
            return "K";
        default:
            return "";
    }
}

string Carta::traducirFamilia() const{
    switch (familia) {
        case 1:
            return "<3";
        case 2:
            return "<>";
        case 3:
            return "E3";
        case 4:
            return "!!";
        default:
            return "";
    }
}

string Carta::traducirColor() const{
    if (color){
        return "R";
    } else{
        return "N";
    }
}

void Carta::revelar(){
    revelada = true;
}

void Carta::esconder(){
    revelada = false;
}

int Carta::getNumero() const {
    return numero;
}

bool Carta::isColor() const {
    return color;
}

bool Carta::isRevelada() const {
    return revelada;
}

int Carta::getFamilia() const {
    return familia;
}

