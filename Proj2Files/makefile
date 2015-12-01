# This is the makefile for the Simulation Project
SimulationProject: Passenger.o Airworthy.o PrecondViolatedExcep.o SimulationProject.o 
	g++ -std=gnu++11 -o SimulationProject Passenger.o Airworthy.o PrecondViolatedExcep.o SimulationProject.o 
Passenger.o: Passenger.cpp Passenger.h 
	g++ -std=gnu++11 -ggdb -c Passenger.cpp
Airworthy.o: Airworthy.cpp Airworthy.h ArrayMaxHeap.h PriorityQueueInterface.h HeapInterface.h Heap_PriorityQueue.h PrecondViolatedExcep.h Passenger.h
	g++ -std=gnu++11 -ggdb -c Airworthy.cpp
PrecondViolatedExcep.o: PrecondViolatedExcep.cpp PrecondViolatedExcep.h 
	g++ -std=gnu++11 -ggdb -c PrecondViolatedExcep.cpp
SimulationProject.o: SimulationProject.cpp Airworthy.h ArrayMaxHeap.h PriorityQueueInterface.h HeapInterface.h PrecondViolatedExcep.h Passenger.h
	g++ -std=gnu++11 -ggdb -c SimulationProject.cpp 