/**
 * @file Passenger.cpp
 * @author Kylie Nicholson
 * @date December 1, 2015
 * Implementation of Passenger Class
 */
#include "Passenger.h"
#include <iostream>
#include <iomanip>
#include <cctype>

using namespace std;
                                     
Passenger::Passenger()
{
}


Passenger::Passenger(const int& newKey,
          const string& newLastName,
			 const char& newType,
			 const int& newRow
			 ):
			 key(newKey), lastName(newLastName), type(newType), row(newRow){
}

int Passenger::getKey(void)
{
   return key;
}

string Passenger::getLastName(void)
{
	return lastName;
}

char Passenger::getType(void)
{
	return type;
}

int Passenger::getRow(void)
{
   return row;
}

bool Passenger::operator> (const Passenger &right)
{
	return(key > right.key);
}

bool Passenger::operator< (const Passenger &right)
{
	return(key < right.key);	
}


bool Passenger::operator== (const Passenger &right)
{
	return (key == right.key);
}

// private methods

void Passenger::setKey(int newKey)
{
	key = newKey;
}

void Passenger::setlastName(string newLastName)
{
	lastName = newLastName;
}

void Passenger::setType(char newType)
{
	type = newType;
}

void Passenger::setRow(int newRow)
{
	row = newRow; 
}