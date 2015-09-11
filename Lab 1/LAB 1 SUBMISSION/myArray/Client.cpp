/**
* @file Client.cpp
* @author Kylie Nicholson
* This program tests the myArray class.
*/

#include "myArray.h"
#include <iostream>

using namespace std;

int main()
{
   myArray test;
    int max = 0;
    int min = 0;
    float avg = 0;
	
	int userInput = 0;

    cout << "Enter a Value to add to the array. Press 999 to clear the array: " << endl;
	cin>>userInput;
    while (userInput != -1 && test.numArrayValues < 10){
	bool addNum = test.setNumber(userInput);
	if(addNum && userInput != 999){
		//add sucessful
		cout<<"value sucessfully added."<<endl;
		cout<<"the values in the array are: ";
		test.displayNumbers();
        cout<<endl;
        cout<<"# of values: "<<test.numArrayValues<<endl;
        if(test.numArrayValues < 10){
            cout << "Enter a Value to add to the array. Press 999 to clear the array: " << endl;
            cin>>userInput;
            }
	}
    else if (userInput == 999){
        test.clear();
        cout<<"Array sucessfully cleared."<<endl;
        cout << "Enter a Value to add to the array. Press 999 to clear the array: " << endl;
        cin>>userInput;
    }
    else if (userInput == 888){
        test.getStats(max, min, avg);
    }
    else{
		// add failed 
		cout<<"Array is full. Cannot add value."<<endl;
        cout << "Enter a Value to add to the array: ";
        cin>>userInput;
    }
    }
	
    if(test.numArrayValues == 10){
        //array is full. display stats.
        test.getStats(max, min, avg);
        cout<<"AVERAGE: "<<avg<<endl;
        cout<<"MAX: "<<max<<endl;
        cout<<"MIN: "<<min<<endl;
    }
    
   return 0;
}  // end main