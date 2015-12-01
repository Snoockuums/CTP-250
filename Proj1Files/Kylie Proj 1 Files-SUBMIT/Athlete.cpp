/**
 * @file Athlete.cpp
 * @author Kylie Nicholson
 * @date November 13, 2015
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
			 earnings(newEarnings), salary(newSalary), endorsements(newEndorsements), sport(newSport){
}

string Athlete::getKey(void)
{
   return key;
}

int Athlete::getRank(void)
{
	return rank;
}

void Athlete::printAthlete(void)
{
     cout << left << "Key: " << key <<endl; 
	  cout << left << "Rank: " << rank <<endl; 
	  cout << left << "Earnings: $" << earnings <<" million"<<endl; 
	  cout << left << "Salary/Winnings: $"<< salary << " million" <<endl;
	  cout << left << "Endorsements: $" << endorsements << " million" <<endl; 
	  cout << left << "Sport: " << sport <<endl; 
}


void Athlete::inputAthlete(void)
{
   string inputData;
	int validateInt;
	int inputInt;
	float validFloat; 
   bool validInput = false;
   cin.ignore(20, '\n');
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
         firstName = inputData;
      }
      else
         cout << inputData << " is an invalid name. Please try again." << endl;
   }


	//create key from first and last name data
	key = lastName + " " + firstName;
	cout<<"Entering data for: "<<key<<endl;
	
	//validate rank
	validInput = false; 
	while (!validInput)
   {
      cout << "Enter rank for athlete. Use only integer values between 1 and 100. " << endl;
  	
		getline(cin, inputData);
		validInput = true;
		for(int i=0; i<inputData.length(); i++){
			if(!isdigit(inputData[i])){
				validInput=false;
				break;
			}
			else{ // char is an integer
				// keep going
			}
		}
      if (validInput && stoi(inputData) > 0 && stoi(inputData) <=100) 
      {				
			cout<<"got into rank if statement"<<endl;
			rank = stoi(inputData);
			
      }
		else{
         	cout << inputData << " is an invalid rank. Please try again." << endl;
				validInput = false;
		}
		
      		
   }

	
	//validate earnings
	validInput = false; 
	while (!validInput)
   {
      cout << "Enter total earnings (in millions) for athlete. Use only positive numeric values " << endl;
      
		getline(cin, inputData);
		validInput = true;
		for(int i=0; i<inputData.length(); i++){
			if(!isdigit(inputData[i])&& inputData[i]!='.'){
				validInput=false;
				break;
			}
			else{ // char is an integer or '.'
				// keep going
			}
		}
      if (validInput && stof(inputData) > 0) 
      {				
			earnings = stof(inputData);
			
      }
		else{
         	cout << inputData << " is invalid. Please try again." << endl;
				validInput = false;
		}
		
     } 		

//validate salary and winnings
	validInput = false; 
	while (!validInput)
   {
      cout << "Enter salary/winnings (in millions) for athlete. Use only positive numeric values " << endl;
  		getline(cin, inputData);
		validInput = true;
		for(int i=0; i<inputData.length(); i++){
			if(!isdigit(inputData[i])&& inputData[i]!='.'){
				validInput=false;
				break;
			}
			else{ // char is an integer or '.'
				// keep going
			}
		}
      if (validInput && stof(inputData) >= 0) 
      {				
			salary = stof(inputData);
			
      }
		else{
         	cout << inputData << " is invalid. Please try again." << endl;
				validInput = false;
		}
		
     } 		
	
	//validate endorsements
	validInput = false; 
	while (!validInput)
   {
      cout << "Enter endorsements for athlete. Use only positive numeric values " << endl;
      getline(cin, inputData);
		validInput = true;
		for(int i=0; i<inputData.length(); i++){
			if(!isdigit(inputData[i])&& inputData[i]!='.'){
				validInput=false;
				break;
			}
			else{ // char is an integer or '.'
				// keep going
			}
		}
      if (validInput && stof(inputData) >= 0) 
      {				
			endorsements = stof(inputData);
			
      }
		else{
         	cout << inputData << " is invalid. Please try again." << endl;
				validInput = false;
		}
		
     } 		
	
	//validate sport
	validInput = false; 
	while (!validInput)
   {
      cout << "Enter athlete's sport. Use only alphabetical values. " << endl;
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
         sport = inputData;
      }
      else
         cout << inputData << " is an invalid sport. Please try again." << endl;
	
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
	string leftUpper;
	string rightUpper; 
	for(int i=0; i<key.length(); i++)
		leftUpper[i] = key[i];
	for(int i=0; i<right.key.length(); i++)
		leftUpper[i] = right.key[i];

	return(leftUpper > rightUpper);
	
}

bool Athlete::operator< (const Athlete &right)
{
	string leftUpper;
	string rightUpper; 
	for(int i=0; i<key.length(); i++)
		leftUpper[i] = key[i];
	for(int i=0; i<right.key.length(); i++)
		leftUpper[i] = right.key[i];

	return(leftUpper < rightUpper);

	//return (key < right.key);
}


bool Athlete::operator== (const Athlete &right)
{
	string leftUpper;
	string rightUpper; 
	for(int i=0; i<key.length(); i++)
		leftUpper[i] = key[i];
	for(int i=0; i<right.key.length(); i++)
		leftUpper[i] = right.key[i];

	return(leftUpper == rightUpper);

	//return (key == right.key);
}

void Athlete::closeOutputFile()
{
   outFile.close();
}

