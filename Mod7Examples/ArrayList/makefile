# makefile for main using ArrayList
main.exe: main.o PrecondViolatedExcep.o 
	g++ -std=gnu++11 -o main.exe main.o PrecondViolatedExcep.o
main.o: main.cpp ArrayList.cpp ArrayList.h ListInterface.h 
	g++ -std=gnu++11 -g -c main.cpp
PrecondViolatedExcep.o: PrecondViolatedExcep.h PrecondViolatedExcep.cpp
	g++ -std=gnu++11 -g -c PrecondViolatedExcep.cpp