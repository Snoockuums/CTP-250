/**
 * @file Passenger.h
 * @author Kylie Nicholson
 * @date  December 1, 2015
 * @class Passenger
 * Node type to be stored in the Priority Queue Max Heap.
 */ 
 
#ifndef PASSENGER_H

#include <string>
#include <fstream>
using namespace std;

class Passenger
{
private:
   /** 
    * Priority value, the key 
    */
   int key;
   
   /** 
    * Passenger's last name 
    */
   string lastName;
   
   /** 
    * Passenger type, a character where 
	 * 'H' is a child or passenger who needs help in boarding, 
	 * 'E' is an elite passenger (frequent flyer), and 
	 * 'G' is a general boarding passenger
    */
   char type;
	
	/** 
    * Passenger's seating row 
    */
   int row;
	
	/** 
    * Key Mutator 
    */
   void setKey(int newKey);
	
	/** 
    * Last Name Mutator 
    */
   void setlastName(string newLastName);
	
	/** 
    * Type Mutator 
    */
   void setType(char newType);
	
	/** 
    * Row Mutator 
    */
   void setRow(int newRow);
	
	
public:
   /**
    * Default constructor
    */
   Passenger();
	
	/**
    * Overloaded constructor
    * @param newKey- int for priority value (key)
    * @param newLastName- string for passenger lastName
    * @param newType - char for passenger type
	 * @param newRow - int for passenger row
    */
  	Passenger(const int& newKey,
          const string& newLastName,
			 const char& newType,
			 const int& newRow
			 );
       
   /**
    * Key Accessor 
    * @return int priority
    */
   int getKey();
	
	/**
    * Last Name Accessor 
    * @return string last name of passenger
    */
   string getLastName();
	
	/**
    * Type Accessor 
    * @return char passenger type
    */
   char getType();
	
	/**
    * Row Accessor 
    * @return int passenger seating row
    */
   int getRow();
		
   /**
    * Defines the > operator for a Passenger object. 
    * @param right - right hand Passenger object for comparison 
    *                to the this Passenger object using >
    */
   bool operator> (const Passenger &right);

   /**
    * Defines the < operator for an Passenger object. 
    * @param right - right hand Passenger object for comparison 
    *                to the this Passenger object using <
    */
   bool operator< (const Passenger &right);

   /**
    * Defines the == operator for an Passenger object. 
    * @param right - right hand Passenger object for comparison 
    *                to the this Passenger object using ==
    */
   bool operator== (const Passenger &right);
}; 
#define PASSENGER_H
#endif