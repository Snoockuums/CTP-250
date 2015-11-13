# makefile for main using Time
main: main.o Time.o
	g++ -std=gnu++11 -o main Time.o main.o
main.o: main.cpp Time.h
	g++ -std=gnu++11 -c main.cpp
Time.o: Time.cpp Time.h
	g++ -std=gnu++11  -c Time.cpp