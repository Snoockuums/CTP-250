/**
 * @file AthleteDatabase.cpp
 * @author Kylie Nicholson
 * @date  November 13, 2015
 */
#include "AthleteDatabase.h"
#include <iostream>
#include <fstream>

using namespace std;

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
      const string INPUT_FILE = "WorldHighestPaidAthletes.csv"; 
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
			tempLastName = inputString;
			cout << inputString << endl;
			getline (inFile, inputString, ',');
			tempFirstName = inputString;
			cout << inputString << endl;
			getline (inFile, inputString, ',');
			tempKey = tempLastName + " " + tempFirstName;
			cout << inputString << endl;
			getline (inFile, inputString, ',');
			tempRank = stoi(inputString);
			cout << inputString << endl;
			getline (inFile, inputString, ',');
			tempEarnings = stof(inputString);
			cout << inputString << endl;
			getline (inFile, inputString, ',');
			tempSalary = stof(inputString);
			cout << inputString << endl;
			getline (inFile, inputString, ',');
			tempEndorsements = stof(inputString);
			cout << inputString << endl;
			getline (inFile, inputString);
			tempSport = inputString;
			cout << inputString << endl;
			// everything read in, create new object.
			Athlete inputAthlete(tempKey, tempLastName, tempFirstName, tempRank, tempEarnings, 
			tempSalary, tempEndorsements, tempSport);
			AthleteDatabaseBST.add(inputAthlete); 
			getline (inFile, inputString, ',');
         }
      inFile.close();
      }
}

void AthleteDatabase::addNewAthlete (void)
{
	Athlete item1;  // new athlete
	item1.inputAthlete(); // prompt user to input athlete data
	cout << "Adding " << item1.getKey() << " to binary search tree." << endl;
   AthleteDatabaseBST.add (item1);

}


void AthleteDatabase::deleteAthlete (Athlete & findAthlete)
{
	char confirm;
	// search for athlete by key
	// if found, delete it. 
   cout << "Searching for " << findAthlete.getKey() << " in binary search tree." 
        << endl;
   bool success; // true if operation is successful; false otherwise
   success = AthleteDatabaseBST.contains(findAthlete); 
   if (success)
   {
      cout << "Found " << findAthlete.getKey() << " in binary search tree." << endl;
		findAthlete.printAthlete();
		cout<<"Are you sure you want to remove the above listed athlete? To remove, "<<endl
		<<"type 'Y' or 'y' :"; 
		cin>>confirm; 
		if(confirm =='y' || confirm == 'Y'){
			success = AthleteDatabaseBST.remove(findAthlete);
      	if (success)
         	cout << findAthlete.getKey() << " was successfully deleted from the"
              << " binary search tree." << endl;
      	else
         	cout << findAthlete.getKey() << " was NOT successfully deleted from"
              << " the binary search tree." << endl;
		}
   }
   else
   {
      cout << "Error: "<< findAthlete.getKey() << " was NOT found in the"
           << " binary search tree." << endl;
   }

}


/**
 * Saves the contents of a tree node (an Athlete) to the text file
 */
void saveData(Athlete& anItem)
{
   anItem.saveData(); 
   anItem.printAthlete();
}


/**
 * Displays the contents of a tree node (an Athlete)
 */
void display(Athlete& anItem)
{
   anItem.printAthlete();
}


void AthleteDatabase::displayData (void)
{
   cout << endl << "Inorder traversal" << endl;
   AthleteDatabaseBST.inorderTraverse(display);
   cout << endl << "Preorder traversal" << endl;
   AthleteDatabaseBST.preorderTraverse(display);
   cout << endl << "Postorder traversal" << endl;
   AthleteDatabaseBST.postorderTraverse(display);
}


void AthleteDatabase::saveDatabase (void)
{
   // output the data to a text file
   cout << endl << "Saving all data in the binary search tree to a file named " 
        << OUTPUT_FILENAME << "." << endl;
   AthleteDatabaseBST.preorderTraverse(saveData);
   Athlete::closeOutputFile();
}




