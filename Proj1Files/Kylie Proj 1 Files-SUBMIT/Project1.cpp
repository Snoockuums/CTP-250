/**
 * @file AthletesMain.cpp
 * @author Kylie Nicholson
 * @date November 13, 2015
 * This project creates a database pertaining to the 100 highest paid athletes 
 * in the world as of June 2014. It uses a Binary Search Tree to store data.
 * The user can add or delete athletes from the database, sort the database by
 * athlete last name (the key) or sort the database by rank (earnings, least
 * to greatest). Each sorting operation produces a report. The updated BST can
 * be saved to a .txt file. Data is initially read from a .csv file containing 
 * data on the 100 highest paying athletes in the world. 
 */
// #include "AthleteDatabase.h"
#include "Menu.h"
#include <cstdlib>
#include <iostream>

using namespace std;

int main(){
	Menu mainMenu; 
	mainMenu.handleUserInput();
	cout<<"Exiting Program."<<endl;
	return(EXIT_SUCCESS);
}