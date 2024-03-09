CPP = g++
TARGET = solitario

all: .all-post

.all-post: Carta.o Dealer.o Interfaz.o Mesa.o main.o Cola.o Nodo.o Pila.o
	$(CPP) Carta.o Dealer.o Interfaz.o Mesa.o Cola.o Nodo.o Pila.o main.o -o $(TARGET)

Carta.o: Carta.cpp Carta.h
	$(CPP) -c Carta.cpp

Dealer.o: Dealer.cpp Dealer.h
	$(CPP) -c Dealer.cpp

Interfaz.o: Interfaz.cpp Interfaz.h
	$(CPP) -c Interfaz.cpp

Mesa.o : Mesa.cpp Mesa.h
	$(CPP) -c Mesa.cpp

Cola.o: Cola.cpp Cola.h
	$(CPP) -c Cola.cpp

Nodo.o: Nodo.cpp Nodo.h
	$(CPP) -c Nodo.cpp

Pila.o: Pila.cpp Pila.h
	$(CPP) -c Pila.cpp

main.o:
	$(CPP) -c main.cpp

clean:
	rm -f *.o $(TARGET)