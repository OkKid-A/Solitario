//
// Created by okkid-a on 3/8/24.
//

#include "Interfaz.h"
using namespace std;

Interfaz::Interfaz(Dealer *dealer) : dealer(dealer) {}

void Interfaz::imprimirMenu(){
    int respuesta;
    cout << "1. Realizar Movimiento" << endl << "2. Ver Siguiente o Anterior"<<endl;
    cin >> respuesta;
    switch (respuesta) {
        case 1:
            realizarMovimiento();
            break;
        case 2:
            verAnteSiguiente();
            break;
        default:
            cout << "Ingreso no valido" << endl;
    }
}

void Interfaz::verAnteSiguiente(){
    int respuesta;
    int cardNum;
    int colFrom;
    cout << "Selecciona la pila que deseas mover con un numero del 1 al 7" << endl;
    cin >> colFrom;
    if (colFrom<8&&colFrom>0){
        cout << endl << "Selecciona la carta a mover (empezando con 1 desde la parte de abajo)"<<endl;
        cin >> cardNum;
        if (cardNum<21&&cardNum>0){
            cout << "1. Revelar la carta siguiente" << endl << "2.Revelar la carta anterior" << endl;
            cin >> respuesta;
            switch (respuesta) {
                case 1:
                    dealer->verSiguiente(colFrom,cardNum);
                    break;
                case 2:
                    dealer->verAnterior(colFrom,cardNum);
                    break;
                default:
                    cout << "Ingreso no valido" <<endl;
            }
        } else {
            cout << "Numero de carta no valido" << endl;
        }
    } else{
        cout << "Pila seleccionada no valida" <<endl;
    }
}

void Interfaz::realizarMovimiento(){
    int respuesta;
    cout << "1. Mover desde pila" << endl << "2. Usar el deposito" << endl << "3. Mover hacia cimientos" <<endl;
    cin >>  respuesta;
    switch (respuesta) {
        case 1:
            moverPila();
            break;
        case 2:
            usarDeposito();
            break;
        case 3:
            moverACimiento();
            break;
        default:
            cout << "Ingreso no valido" << endl;
    }
}

void Interfaz::moverACimiento(){
    int colFrom;
    cout << "Selecciona la pila que deseas mover con un numero del 1 al 7" << endl;
    cin >> colFrom;
    if (colFrom<8&&colFrom>0) {
        dealer->moverACimiento(colFrom);
    } else {
        cout << "Pila seleccionada no valida" <<endl;
    }
}

void Interfaz::usarDeposito(){
    int colDest;
    int respuesta;
    cout << "1.Carta Siguiente" << endl << "2.Pasar Carta a una Pila" << endl;
    cin >> respuesta;
    if (respuesta==1){
        dealer->pasarCartaAWaste();
    } else if (respuesta==2){
        cout << "Selecciona la pila destino para la carta, del 1 al 7" << endl;
        cin >>colDest;
        dealer->pasarHandaCol(colDest);
    } else {
        cout << "Ingreso no valido" << endl;
    }
}

void Interfaz::moverPila(){
    int respuesta;
    int cartaUsed;
    int colDest;
    cout << "Selecciona la pila que deseas mover con un numero del 1 al 7" << endl;
    cin >> respuesta;
    if (respuesta<8&&respuesta>0){
        cout << endl << "Selecciona la carta a mover (empezando 1 desde la parte de abajo)"<<endl;
        cin >> cartaUsed;
        if (cartaUsed<21&&cartaUsed>0){
            cout << endl << "Selecciona la pila destino para la carta del 1 al 7" <<endl;
            cin >> colDest;
            if (colDest>0&&colDest<8){
                dealer->moverCartaEntreCol(respuesta,cartaUsed,colDest);
            } else {
                cout << "Pila seleccionada no valida" <<endl;
            }
        } else {
            cout << "Numero de carta no valido" << endl;
        }
    } else{
        cout << "Pila seleccionada no valida" <<endl;
    }

}

