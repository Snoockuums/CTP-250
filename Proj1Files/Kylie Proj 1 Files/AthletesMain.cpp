/**
 * @file AthletesMain.cpp
 * @author Kylie Nicholson
 * @date November 13, 2015
 */
 
#include <cstdlib>
#include <iostream>
using namespace std;

void displayMainMenu(); 
void displayDescription();
void displayMaintenanceMenu();
void displayReportsMenu();

int main(){
	char mainSelection; // holds the selection of the main menu
	char maintenanceSelection; // holds the maintainence menu selection. 
	char reportsSelection;
	displayMainMenu();
	cin>>mainSelection;
	cout<<"You entered: "<<mainSelection<<endl;
	//validate input
	if(mainSelection == 'D'){
		displayDescription();
	}
	else if(mainSelection == 'M'){
		//display maintinence menu 
		displayMaintenanceMenu();
		cin>>maintenanceSelection;
		cout<<"You entered: "<<maintenanceSelection<<endl;

		if(maintenanceSelection == 'I')
		{//insert into BST
		}
		else if(maintenanceSelection == 'D'){
		// delete from BST
		}
		else if(maintenanceSelection == 'R'){
			// display main menu 
		}
		else{
			// handle invalid input
			cout<<"Invalid input. Please try again."<<endl; 
		}
	}
	else if(mainSelection == 'R'){
		displayReportsMenu();
		cin>>reportsSelection;
		cout<<"You entered: "<<reportsSelection<<endl;
		
		if(reportsSelection == 'S'){
		// sort by key name
		}
		else if(reportsSelection == 'O'){
		// order by rank
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
	}
	else if(mainSelection == 'E'){
	//exit program 
	return(EXIT_SUCCESS);
	}
	else{ // input is invalid
	// handle invalid input
	cout<<"Invalid input. Please try again."<<endl;
	}

	//default displays main menu again. 
	displayMainMenu();
	cin>>mainSelection;

return(EXIT_SUCCESS);
}

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

void displayDescription(){
cout<<endl<<"This is my description"<<endl;
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