# makefile for Client using OneNumber
Client.exe: Client.o InvalidValue.o OneNumber.o
	g++ -std=gnu++11 -o Client.exe Client.o InvalidValue.o OneNumber.o
Client.o: Client.cpp OneNumber.cpp OneNumber.h 
	g++ -std=gnu++11 -g -c Client.cpp
InvalidValue.o: InvalidValue.h InvalidValue.cpp
	g++ -std=gnu++11 -g -c InvalidValue.cpp
OneNumber.o: OneNumber.h OneNumber.cpp
	g++ -std=gnu++11 -g -c OneNumber.cpp

	
	
	