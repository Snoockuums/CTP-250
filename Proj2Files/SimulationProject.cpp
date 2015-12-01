/**
 * @file SimulationProject.cpp
 * @author Kylie Nicholson
 * @date  December 1, 2015
 * Main project file for Simulation Project. This file contains a main() method and a method named description().
 * main() will call the description() method, open and close input and output files, call methods in Airworthy
 * class to load priority queues and run simulation using both old and new boarding schemes. It will
 * create 3 different output files for the results of each input file.  
 * description() will provide a non-technical description of this project.
 * This project runs a simulation for an airline boarding process, both the airline's current and newly
 * proposed random boarding processes. 
 */ 

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include "Airworthy.h"

using namespace std;

void description(); 

int main(){ 
	Airworthy Simulation;
	description();
	Simulation.readInputData("airworthy100.txt", 0); 
	// INPUT FILES: 
	// airworthy100.txt 
	// airworthy85.txt
	// airworthy70.txt
}

void description(){
cout<<"This is a simulation of boarding processes for Airworthy Airlines. The Airline currently"<<endl;
cout<<"boards"<<endl<<"1. Preboard"<<endl<<"2. General Boarding (in groups based on seat location)"<<endl;
cout<<"The airline has suggested a new, random general boarding procedure based on passenger queue"<<endl;
cout<<"location. This simulation was developed to test this new procedure and compare the time it"<<endl;
cout<<"takes to the time the current boarding procedure takes."<<endl;
}
