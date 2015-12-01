/**
 * @file Menu.cpp
 * @author Kylie Nicholson
 * @date  November 13, 2015
 * @class Menu
 * Implementation of Menu class
 */ 
  
#include "Menu.h"
#include <iostream>
#include <iomanip>

using namespace std;

void Menu::handleUserInput(){
	//variables
	char mainSelection; // holds the selection of the main menu
	char maintenanceSelection; // holds the maintainence menu selection. 
	char reportsSelection; 
	
	AthleteDatabase AthleteDB; 
	// read in text file and create binary tree
	AthleteDB.readTextFile();
		
	while (mainSelection != 'E')
	{
		displayMainMenu();
		cin>>mainSelection;
		cout<<"You entered: "<<mainSelection<<endl<<endl;
		//validate input
		if(mainSelection == 'D'){
			displayDescription();
		}
		else if(mainSelection == 'M'){
			//display maintinence menu 
			displayMaintenanceMenu();
			cin>>maintenanceSelection;
			cout<<"You entered: "<<maintenanceSelection<<endl<<endl;
	
			if(maintenanceSelection == 'I')
			{//insert into BST
				AthleteDB.addNewAthlete();
			}
			else if(maintenanceSelection == 'D'){
			// delete from BST
				AthleteDB.deleteAthlete();
			}
			else if(maintenanceSelection == 'R'){
				// display main menu  (do nothing in this loop)
			}
			else{
				// handle invalid input
				cout<<"Invalid input. Please try again."<<endl; 
			}
		}
		else if(mainSelection == 'R'){
			displayReportsMenu();
			cin>>reportsSelection;
			cout<<"You entered: "<<reportsSelection<<endl<<endl;
			
			if(reportsSelection == 'S'){
			// sort by key name
			// inoder traversal of BST
				AthleteDB.displayData();
			}
			else if(reportsSelection == 'O'){
			// order by rank
				AthleteDB.displayRanks();
			}
			else if (reportsSelection == 'R'){
			// return to main menu 
			}
			else{
				// handle invalid input
				cout<<"Invalid input. Please try again."<<endl; 
			}
		}
		else if(mainSelection == 'S'){
		// save database to file
		AthleteDB.saveDatabase();
		}
		else if(mainSelection == 'E'){
		//exit program 
		}
		else{ // input is invalid
		// handle invalid input
		cout<<"Invalid input. Please try again."<<endl;
		}

	}
	//default displays main menu again. 
	while(mainSelection != 'E'){
		displayMainMenu();
		cin>>mainSelection;
	}

}

void Menu::displayDescription(){
cout<<"PROGRAM DESCRIPTION"<<endl;
cout<<"This program creates a database with information on the 100 highest paid athletes"<<endl; 
cout<<"in the world as of June 2014. It uses a Binary Search Tree to store data."<<endl;
cout<<"The user can add or delete athletes from the database, sort the database by"<<endl;
cout<<"athlete last name (the key) or sort the database by rank (earnings, least"<<endl;
cout<<"to greatest). Each sorting operation produces a report. The updated BST can"<<endl;
cout<<"be saved to a .txt file. Data is initially read from a .csv file containing "<<endl;
cout<<"data on the 100 highest paying athletes in the world. "<<endl;

}

void Menu::displayMainMenu(){
	cout<<endl<<"WORLD'S HIGHEST PAID ATHLETES MAIN MENU"<<endl;
	cout<<" D - Describe the program"<<endl;
	cout<<" M - Maintain the database"<<endl;
	cout<<" R - Reports"<<endl;
	cout<<" S - Save and close the database"<<endl;
	cout<<" E - Exit the program"<<endl;
	cout<<endl;
	cout<<"Enter your selection: "; 
}

void Menu::displayMaintenanceMenu(){
	cout<<endl<<"WORLD'S HIGHEST PAID ATHLETES MAINTENANCE MENU"<<endl;
	cout<<" I - Insert new record"<<endl;
	cout<<" D - Delete existing record"<<endl;
	cout<<" R - Return to main menu"<<endl;
	cout<<endl;
	cout<<"Enter your selection: ";
}

void Menu::displayReportsMenu(){
	cout<<endl<<"WORLD'S HIGHEST PAID ATHLETES REPORTS MENU"<<endl;
	cout<<" S - Sort by key name report"<<endl;
	cout<<" O - Order by rank report"<<endl;
	cout<<" R - Return to main menu"<<endl;
	cout<<endl;
	cout<<"Enter your selection: ";
}
