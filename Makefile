all: main

main:  main.o Case.o Environnement.o Cell.o CellA.o CellB.o
	g++ -g main.o Case.o Environnement.o Cell.o CellA.o CellB.o -o env

main.o: main.cpp Case.cpp Environnement.cpp Cell.cpp CellA.cpp CellA.cpp
	g++ -g -c -Wall main.cpp -o main.o -std=c++11

Case.o: Case.cpp Case.h Cell.h CellA.h CellB.h 
	g++ -g -c -Wall  Case.cpp -o Case.o -std=c++11

Environnement.o :  Environnement.cpp Environnement.h Case.h
	g++ -g -c -Wall   Environnement.cpp -o Environnement.o -std=c++11

Cell.o:  Cell.cpp Cell.h
	g++ -g -c -Wall   Cell.cpp -o Cell.o -std=c++11

CellA.o:  CellA.cpp CellA.h
	g++ -g -c -Wall   CellA.cpp -o CellA.o -std=c++11

CellB.o:  CellB.cpp CellB.h
	g++ -g -c -Wall   CellB.cpp -o CellB.o -std=c++11


clean:
	rm -f *.o
