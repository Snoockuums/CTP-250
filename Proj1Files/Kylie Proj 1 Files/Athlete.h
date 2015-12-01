/**
 * @file Athlete.h
 * @author Kylie Nicholson
 * @date  November 13, 2015
 * @class Athlete
 * Node type to be stored in the ADT binary search tree. It consists of
 * the key (first and last name together) first name, last name, 
 * rank, total earnings, salary/winnings, endorsements, and sport 
 */ 
#ifndef ATHLETE_H

#include <string>
#include <fstream>
using namespace std;

/**
 * Name of file in which to save all output data
 */
const string OUTPUT_FILENAME = "athleteOutFile.txt";


class Athlete
{
private:
   /** 
    * first and last name, the key 
    */
   string key;
   
   /** 
    * Athlete's first name 
    */
   string firstName;
   
   /** 
    * Athlete's last name 
    */
   string lastName;
	
	/** 
    * Athlete's rank 
    */
   int rank;
	
	/** 
    * Athlete's total earnings (in millions) 
    */
   float earnings;
	
	/** 
    * Athlete's salary and winnings (in millions) 
    */
   float salary;
	
	/** 
    * Athlete's endorsements (in millions) 
    */
   float endorsements;
	
	/** 
    * Athlete's sport 
    */
   string sport;
	
   /**
    * Output file to store the data for an athlete. Note this is a
    * static data member, so there is only one copy of it for all
    * Athlete objects. It MUST be defined and intialized (opened)
    * in the implementation file.
    */
   static ofstream outFile;

public:
   /**
    * Default constructor
    */
   Athlete();

   /**
    * Overloaded constructor
    * @param name - student's name; value for search key
    * @param newIdNum - value for student's idnum
    * @param newPhoneNumber - value for student's phone number
    */
   Athlete(const string& newKey,
          const string& newLastName,
          const string& newFirstName,
			 const int& newRank,
			 const float& newEarnings,
			 const float& newSalary,
			 const float& newEndorsements,
			 const string& newSport
			 );
          
   /**
    * Accessor for the name.
    * @return full name of this person, the key
    */
   string getKey(void);

   /**
    * Displays all the data stored for a student.
    */
   void printAthlete(void);

   /**
    * Inputs data for a student object, providing specific instructions
    * for the user and validating the input data.
    */
   void inputAthlete(void);

   /**
    * Outputs the data to the output file. 
    */
   void saveData();

   /**
    * Defines the > operator for an Athlete object. 
    * @param right - right hand Athlete object for comparison 
    *                to the this Athlete object using >
    */
   bool operator> (const Athlete &right);

   /**
    * Defines the < operator for an Athlete object. 
    * @param right - right hand Athlete object for comparison 
    *                to the this Athlete object using <
    */
   bool operator< (const Athlete &right);

   /**
    * Defines the == operator for an Athlete object. 
    * @param right - right hand Athlete object for comparison 
    *                to the this Athlete object using ==
    */
   bool operator== (const Athlete &right);

   /**
    * Closes the output file. This method MUST be called before the
    * program terminates.
    */
   static void closeOutputFile();
}; // end Student
#define ATHLETE_H
#endif
