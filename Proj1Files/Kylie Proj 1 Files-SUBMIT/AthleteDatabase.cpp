/**
 * @file AthleteDatabase.cpp
 * @author Kylie Nicholson
 * @date  November 13, 2015
 */
#include "AthleteDatabase.h"
#include <iostream>
#include <fstream>

using namespace std;

int counter = 1;

void AthleteDatabase::readTextFile(){
	string tempKey;
	string tempLastName;
	string tempFirstName;
	int tempRank;
	float tempEarnings;
	float tempSalary; 
	float tempEndorsements;
	string tempSport;
	int i=0; 
	
	//name of input file
      const string INPUT_FILE = "worldsHighestPaid2.csv"; 
   // open the input file
      ifstream inFile(INPUT_FILE.c_str()); 
   // stores lines of data input from the file
      string inputString;  

      if (!inFile)
         cout << "Error opening file for input: " << INPUT_FILE << endl;
      else
      {
         getline (inFile, inputString, ','); // the prime read
         while (inFile) // while no errors have been encountered
         {
			// parse line for commas and white space
			// store last name
			tempLastName = inputString;
			//cout << "Last Name: "<< tempLastName << endl;
			// get first name
			getline (inFile, inputString, ',');
			tempFirstName = inputString;
			//cout << "First Name: "<< tempFirstName << endl;
			// create Key from Last and First names
			tempKey = tempLastName + " " + tempFirstName;
			//cout << "Key: "<< tempKey << endl;
			// get rank
			getline (inFile, inputString, ',');
			tempRank = stoi(inputString);
			//cout << "Rank: "<< tempRank << endl;
			// get earnings
			getline (inFile, inputString, ',');
			tempEarnings = stof(inputString);
			//cout << "Earnings: "<< tempEarnings << endl;
			// get salary 
			getline (inFile, inputString, ',');
			tempSalary = stof(inputString);
			//cout << "Salary: "<< tempSalary << endl;
			// get endorsements
			getline (inFile, inputString, ',');
			tempEndorsements = stof(inputString);
			//cout << "Endorsements: "<< tempEndorsements << endl;
			// get sport 
			getline (inFile, inputString);
			tempSport = inputString;
			//cout << "Sport: "<< tempSport << endl;
			// everything read in, create new object.
			Athlete inputAthlete(tempKey, tempLastName, tempFirstName, tempRank, tempEarnings, 
			tempSalary, tempEndorsements, tempSport);
			athleteDatabaseBST.add(inputAthlete); 
			getline (inFile, inputString, ',');
         }
      inFile.close();
      }
}

void AthleteDatabase::addNewAthlete (void)
{
	string confirm;
	Athlete item1;  // new athlete
	item1.inputAthlete(); // prompt user to input athlete data
	item1.printAthlete();		
	cout<<"Are you sure you want to add the above athlete to the database?"<<endl;
	cout<<"Enter 'Y' or 'y' to add. Enter any other key to abandon: ";
	getline(cin, confirm);
	if(confirm == "Y" || confirm == "y")
	{
		cout << "Adding " << item1.getKey() << " to binary search tree." << endl;
		athleteDatabaseBST.add (item1);
	}
	else{
		cout<<"Add abandoned."<<endl;
	}
		
}


void AthleteDatabase::deleteAthlete ()
{
	string confirm;
	string inputKey;
	// search for athlete by key
	// if found, delete it. 
	cout<<"Enter the key name of the athlete to delete: ";
	cin.ignore(20, '\n');
	getline(cin, inputKey); 
	//validate input
	Athlete findAthlete (inputKey, " ", " ", 0, 0, 0, 0," "); // Athlete object required as argument

   cout << "Searching for " << findAthlete.getKey() << " in binary search tree." 
        << endl;
   bool success; // true if operation is successful; false otherwise
   success = athleteDatabaseBST.contains(findAthlete); 
   if (success)
   {
      cout << "Found " << findAthlete.getKey() << " in binary search tree." << endl;
		//findAthlete.printAthlete();
		//begin kylie added code
		Athlete retrievedEntry = athleteDatabaseBST.getEntry(findAthlete);
		retrievedEntry.printAthlete();
		//end kylie added code
		cout<<endl;
		cout<<"Are you sure you want to remove the above listed athlete? To remove, "<<endl
		<<"type 'Y' or 'y'. Type any other character to abandon deletion :"; 
		getline(cin, confirm); 
		if(confirm =="y" || confirm == "Y"){
			success = athleteDatabaseBST.remove(findAthlete);
      	if (success)
         	cout << findAthlete.getKey() << " was successfully deleted from the"
              << " binary search tree." << endl;
      	else
         	cout << findAthlete.getKey() << " was NOT successfully deleted from"
              << " the binary search tree." << endl;
		}
		else{
			cout<<"Delete abandoned."<<endl;
		}
   }
   else
   {
      cout << "Error: "<< findAthlete.getKey() << " was NOT found in the"
           << " binary search tree." << endl;
   }

}


void saveData(Athlete& anItem)
{
   anItem.saveData(); 
}


void display(Athlete& anItem)
{
   anItem.printAthlete();
	cout<<endl;
}


void displayIfRankEqual(Athlete& anItem)
{ 
	if(anItem.getRank() == counter){
		anItem.printAthlete();
		cout<<endl;
	}
	
}

void AthleteDatabase::displayData (void)
{
   cout << endl << "Inorder traversal to display data" << endl;
   athleteDatabaseBST.inorderTraverse(display);
}

void AthleteDatabase::displayRanks()
{
	counter =0;
	while(counter<=100){
		athleteDatabaseBST.inorderTraverse(displayIfRankEqual);
		counter++;
	}
}

void AthleteDatabase::saveDatabase (void)
{
   // output the data to a text file
   cout << endl << "Saving all data in the binary search tree to a file named " 
        << OUTPUT_FILENAME << "." << endl;
   athleteDatabaseBST.preorderTraverse(saveData);
   Athlete::closeOutputFile();
}




