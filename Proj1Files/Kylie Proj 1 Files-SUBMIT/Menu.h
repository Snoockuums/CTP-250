/**
 * @file Menu.h
 * @author Kylie Nicholson
 * @date  November 13, 2015
 * @class Menu
 * Class to define user interface menus and respond to user menu choices.
 * The program begins by inputting the text data from the WorldHighestPaidAthletes.csv 
 * text file and building a binary search tree for the Athletes, in order by the key 
 * (the last name of the athlete). Then the program displays the main menu
 */ 
  
#ifndef MENU_H
#define MENU_H

#include <string>
#include <fstream>
#include "AthleteDatabase.h"
using namespace std;

class Menu{

private:

public: 
	/**
	* Handles user input and calls menus
	*/
	void handleUserInput();
	/**
	* Displays Description
	*/
	void displayDescription();
	/**
	* Displays Main Menu
	*/
	void displayMainMenu();
	/**
	* Displays Maintenance Menu
	*/
	void displayMaintenanceMenu();
	/**
	* Displays Reports Menu
	*/
	void displayReportsMenu();

};

#endif