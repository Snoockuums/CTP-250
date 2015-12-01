/**
 * @file Athlete.cpp
 * @author Kylie Nicholson
 * Implementation of Athlete Class
 */
#include "Athlete.h"
#include <iostream>
#include <iomanip>
#include <cctype>

using namespace std;

ofstream Athlete::outFile(OUTPUT_FILENAME.c_str());  // define and open static
                                                     // output file
Athlete::Athlete()
{
}


Athlete::Athlete(const string& newKey,
          const string& newLastName,
          const string& newFirstName,
			 const int& newRank,
			 const float& newEarnings,
			 const float& newSalary,
			 const float& newEndorsements,
			 const string& newSport):
			 key(newKey), lastName(newLastName), firstName(newFirstName), rank(newRank),
			 earnings(newEarnings), salary(newSalary), endorsements(newEndorsements), sport(newSport)
			 {
}

string Athlete::getKey(void)
{
   return key;
}


void Athlete::printAthlete(void)
{
     cout << left << "Key: " << key <<endl; 
	  cout << left << "Rank: " << rank <<endl; 
	  cout << left << "Earnings: $" << earnings <<" million"<<endl; 
	  cout << left << "Salary/Winnings: $"<< salary << " million" <<endl;
	  cout << left << "Endorsements: $" << key << " million" <<endl; 
	  cout << left << "Sport: " << key <<endl; 
}


void Athlete::inputAthlete(void)
{
   string inputData;
   bool validInput = false;
   
 	// Validate Last Name  
	while (!validInput)
   {    
		cout << "Enter last name for new athlete. Use alphabetical entries only" << endl;
      getline(cin, inputData);
		validInput=true;
		for(int i=0; i<inputData.length(); i++){
			if(!isalpha(inputData[i])){
				validInput=false;
				break;
			}
			else{ // char is alphabetical
				// keep going
			}
		}
      if (validInput)
      {
         lastName = inputData;
      }
      else
         cout << inputData << " is an invalid name. Please try again." << endl;
   }
   
	//Validate First Name
	validInput = false; 
	while (!validInput)
   {
      cout << "Enter first name for new athlete. Use alphabetical entries only" << endl;
      getline(cin, inputData);
		validInput=true;
      if (isalpha(inputData[0]))
      {
         firstName = inputData;
         validInput = true;
      }
      else
         cout << inputData << " is an invalid name. Please try again." << endl;
   }

	//create key from first and last name data
	key = lastName + " " + firstName;
	cout<<"Key created with first and last name: "<<key<<endl;
	
	//validate earnings
	validInput = false; 
	while (!validInput)
   {
      cout << "Enter total earnings (in millions) for athlete. Use only positive numeric values " << endl;
      getline(cin, inputData);
      if (stof(inputData) > 0)
      {
         earnings = stof(inputData);
         validInput = true;
      }
      else
         cout << inputData << " is invalid. Please try again." << endl;
   }

//validate salary and winnings
	validInput = false; 
	while (!validInput)
   {
      cout << "Enter salary/winnings (in millions) for athlete. Use only positive numeric values " << endl;
      getline(cin, inputData);
      if (stof(inputData) > 0)
      {
         salary = stof(inputData);
         validInput = true;
      }
      else
         cout << inputData << " is invalid. Please try again." << endl;
   }
	
	//validate endorsements
	validInput = false; 
	while (!validInput)
   {
      cout << "Enter endorsements for athlete. Use only positive numeric values " << endl;
      getline(cin, inputData);
      if (stof(inputData) > 0)
      {
         endorsements = stof(inputData);
         validInput = true;
      }
      else
         cout << inputData << " is invalid. Please try again." << endl;
   }
	
	//validate sport
	validInput = false; 
	while (!validInput)
   {
      cout << "Enter athlete's sport. Use only alphabetical values. " << endl;
      getline(cin, inputData);
      if (isalpha(inputData[0]))
      {
         sport = inputData;
         validInput = true;
      }
      else
         cout << inputData << " is invalid. Please try again." << endl;
   }
	
	// done validating
  }


void Athlete::saveData()
{
   if (outFile)
      outFile << lastName << "," << firstName << "," << rank << "," << earnings << 
		"," << salary << "," << endorsements << "," << sport << endl;
   else
       cout << "Error: Output file " << OUTPUT_FILENAME 
            << " is not ready for output." << endl << endl;
}


bool Athlete::operator> (const Athlete &right)
{
   return (key > right.key);
}



bool Athlete::operator< (const Athlete &right)
{
   return (key < right.key);
}


bool Athlete::operator== (const Athlete &right)
{
   return (key == right.key);
}

void Athlete::closeOutputFile()
{
   outFile.close();
}

