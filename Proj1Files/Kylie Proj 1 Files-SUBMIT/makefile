# This is the makefile for the Athlete Database
Project1: Athlete.o AthleteDatabase.o NotFoundException.o PrecondViolatedExcep.o Project1.o Menu.o
	g++ -std=gnu++11 -o Project1 Athlete.o AthleteDatabase.o NotFoundException.o PrecondViolatedExcep.o Project1.o Menu.o
Athlete.o: Athlete.cpp Athlete.h 
	g++ -std=gnu++11 -ggdb -c Athlete.cpp
AthleteDatabase.o: AthleteDatabase.cpp AthleteDatabase.h BinarySearchTree.h BinaryTreeInterface.h BinaryNodeTree.h BinaryNode.h NotFoundException.h PrecondViolatedExcep.h Athlete.h
	g++ -std=gnu++11 -ggdb -c AthleteDatabase.cpp
NotFoundException.o: NotFoundException.cpp NotFoundException.h 
	g++ -std=gnu++11 -ggdb -c NotFoundException.cpp
PrecondViolatedExcep.o: PrecondViolatedExcep.cpp PrecondViolatedExcep.h 
	g++ -std=gnu++11 -ggdb -c PrecondViolatedExcep.cpp
Menu.o: AthleteDatabase.h Menu.cpp Menu.h
	g++ -std=gnu++11 -ggdb -c Menu.cpp
Project1.o: Project1.cpp AthleteDatabase.h BinarySearchTree.h BinaryTreeInterface.h BinaryNodeTree.h BinaryNode.h NotFoundException.h PrecondViolatedExcep.h Athlete.h
	g++ -std=gnu++11 -ggdb -c Project1.cpp 