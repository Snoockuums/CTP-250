/**
 * @file Airworthy.h
 * @author Kylie Nicholson
 * @date  December 1, 2015
 * @class Airworthy
 * Class to hold and load simulation heaps and run simulation 
 */ 
#ifndef AIRWORTHY_H
#include "Heap_PriorityQueue.h"
#include "Passenger.h"
#include <string>
#include <fstream>
using namespace std;

class Airworthy
{
private:
	/**
    * Priority Queue to store Passenger data for old boarding procedure
    */
   Heap_PriorityQueue<Passenger> oldProcedure;
	
	/**
    * Priority Queue to store Passenger data for new boarding procedure 
    */
   Heap_PriorityQueue<Passenger> newProcedure;
	
	/**
    * Amount of time it takes to load plane with old procedure 
    */
	int oldTime;
	 
	 /**
    * Amount of time it takes to load plane with new procedure  
    */
	int newTime; 

public:
	/**
	* Default Constructor for Airworthy class
	*/
	Airworthy();
	
	/**
	* Reads input data 
	*/
	void readInputData(const string, const int);
	
	/**
	* Loads Queues
	*/
	void loadQueues();
	
	/**
	* Runs Simulation 
	*/
	void run();
};  
#define AIRWORTHY_H
#endif
