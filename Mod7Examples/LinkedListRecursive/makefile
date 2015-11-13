# makefile for main using LinkedList
main.exe: main.o PrecondViolatedExcep.o 
	g++ -std=gnu++11 -o main.exe main.o PrecondViolatedExcep.o
main.o: main.cpp LinkedList.cpp LinkedList.h ListInterface.h Node.h Node.cpp
	g++ -std=gnu++11 -g -c main.cpp
PrecondViolatedExcep.o: PrecondViolatedExcep.h PrecondViolatedExcep.cpp
	g++ -std=gnu++11 -g -c PrecondViolatedExcep.cpp