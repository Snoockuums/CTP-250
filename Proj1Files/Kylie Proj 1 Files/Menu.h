/**
 * @file Menu.h
 * @author Kylie Nicholson
 * @date  November 13, 2015
 * @class Menu
 * Class to define user interface menus and respond to user menu choices
 */ 
  
#ifndef MENU_H
#define MENU_H

#include <string>
#include <fstream>
using namespace std;

class Menu{

private:

public: 
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