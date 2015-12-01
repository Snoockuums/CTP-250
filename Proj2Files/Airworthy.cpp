/**
 * @file Airworthy.cpp
 * @author Kylie Nicholson
 * @date December 1, 2015
 * Implementation of Airworthy Class
 */
#include "Airworthy.h"
#include <iostream>
#include <iomanip>
#include <cctype>
#include <fstream>

using namespace std;

Airworthy::Airworthy(){

}
 
void Airworthy::readInputData(const string INPUT_FILE, const int schema){
	int tempKey;
	string tempLastName;
	char tempType;
	int tempRow; 
	int boardingTime=0;
	int lastPassengerRow=0; 
   int priority=0; 
	
	// open the input file
   ifstream inFile(INPUT_FILE.c_str()); 
   // stores lines of data input from the file 
   if (!inFile)
      cout << "Error opening file for input: " << INPUT_FILE << endl;
   else
      {
		while(inFile){
		// read data
			inFile>> tempLastName;
			if( inFile.eof() ) break;
			cout << "Last Name: "<< tempLastName << endl;
			inFile>>tempType;
			cout << "Passenger Type: "<< tempType << endl;
			inFile>>tempRow;
			cout << "Row: "<< tempRow << endl;
			if(tempRow == lastPassengerRow || tempRow-1 == lastPassengerRow){
				boardingTime += 25;
				cout<<"Blockage!"<<endl;
			}
			else{
				boardingTime+=1; 
			}
			cout<<"Running boarding time: "<<boardingTime<<" seconds."<<endl;
			lastPassengerRow = tempRow;
			// calculate priority
			if(schema == 0) {// old boarding schema
				if(tempType == 'H'){
					priority = 99;
					cout<<"Priority: 1"<<endl;
				}
				else if(tempRow <=4){
					priority = 98;
					cout<<"Priority: 2"<<endl;
				}
				else if(tempType == 'E'){
					priority = 97;
					cout<<"Priority: 3"<<endl; 
				}
				else if(tempRow <= 26 && tempRow >=23){
					priority = 96;
					cout<<"Priority: 4"<<endl; 
				}
				else if(tempRow <= 22 && tempRow >=17){
					priority = 95;
					cout<<"Priority: 5"<<endl; 
				}
				else if(tempRow <= 16 && tempRow >=11){
					priority = 94;
					cout<<"Priority: 6"<<endl; 
				}
				else if(tempRow <= 10 && tempRow >=5){
					priority = 93;
					cout<<"Priority: 7"<<endl; 
				}
				else
					cout<<"ERROR. PRIORITY FLAG DID NOT CATCH"<<endl;
			}
			else if(schema == 1) { // new random boarding schema
				if(tempType == 'H'){
					priority = 99;
					cout<<"Priority: 1"<<endl;
				}
				else if(tempRow <=4){
					priority = 98;
					cout<<"Priority: 2"<<endl;
				}
				else if(tempType == 'E'){
					priority = 97;
					cout<<"Priority: 3"<<endl; 
				}
				else{
					priority = 96;
					cout<<"Priority: 4"<<endl; 
				}

			}
			else
				cout<<"ERROR. Did not pass valid schema value"<<endl;
			// make a new passenger object to pass to heap 
			Passenger newPassenger(priority, tempLastName, tempType, tempRow); 
		}
	inFile.close();
	}
}


void Airworthy::loadQueues() {

}

void Airworthy::run(){

}                      