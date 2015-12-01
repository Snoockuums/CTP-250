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

void displayMainMenu(){
cout<<endl<<"WORLD'S HIGHEST PAID ATHLETES MAIN MENU"<<endl;
cout<<" D - Describe the program"<<endl;
cout<<" M - Maintain the database"<<endl;
cout<<" R - Reports"<<endl;
cout<<" S - Save and close the database"<<endl;
cout<<" E - Exit the program"<<endl;
cout<<endl;
cout<<"Enter your selection: "; 
}

void displayMaintenanceMenu(){
cout<<endl<<"WORLD'S HIGHEST PAID ATHLETES MAINTENANCE MENU"<<endl;
cout<<" I - Insert new record"<<endl;
cout<<" D - Delete existing record"<<endl;
cout<<" R - Return to main menu"<<endl;
cout<<endl;
cout<<"Enter your selection: ";
}

void displayReportsMenu(){
cout<<endl<<"WORLD'S HIGHEST PAID ATHLETES REPORTS MENU"<<endl;
cout<<" S - Sort by key name report"<<endl;
cout<<" O - Order by rank report"<<endl;
cout<<" R - Return to main menu"<<endl;
cout<<endl;
cout<<"Enter your selection: ";
}