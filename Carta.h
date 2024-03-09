//
// Created by okkid-a on 3/6/24.
//

#ifndef SOLITARIO_CARTA_H
#define SOLITARIO_CARTA_H
#include <string>

class Carta {
private:
    int numero;
    int familia;
    bool color;
    bool revelada;

public:
    Carta(int numero, int familia, bool color);
    std::string getCartaString();
    void esconder();
    void revelar();

    int getFamilia() const;

    int getNumero() const;

    bool isRevelada() const;

    bool isColor() const;

private:
    std::string traducirNumero() const;
    std::string traducirFamilia() const;
    std::string traducirColor() const;


};


#endif //SOLITARIO_CARTA_H
