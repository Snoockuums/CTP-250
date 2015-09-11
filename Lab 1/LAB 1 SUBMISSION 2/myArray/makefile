# makefile for Client using myArray
Client.exe: Client.cpp Client.o myArray.o
	g++ -std=gnu++11 -o Client.exe myArray.o Client.o
Client.cpp: myArray.o
	g++ -std=gnu++11 -g -c Client.cpp
Client.o: Client.cpp myArray.cpp myArray.h
	g++ -std=gnu++11 -g -c Client.cpp
myArray.o: myArray.cpp myArray.h
	g++ -std=gnu++11 -g -c myArray.cpp

	
	
	