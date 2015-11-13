# makefile for main using BinaryNodeTree
main.exe: main.o PrecondViolatedExcep.o NotFoundException.o 
	g++ -std=gnu++11 -o main.exe main.o PrecondViolatedExcep.o NotFoundException.o
main.o: main.cpp BinaryNodeTree.cpp BinaryNodeTree.h BinaryTreeInterface.h BinaryNode.h BinaryNode.cpp
	g++ -std=gnu++11 -g -c main.cpp
PrecondViolatedExcep.o: PrecondViolatedExcep.h PrecondViolatedExcep.cpp
	g++ -std=gnu++11 -g -c PrecondViolatedExcep.cpp
NotFoundException.o: NotFoundException.h NotFoundException.cpp
	g++ -std=gnu++11 -g -c NotFoundException.cpp