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
    
    
    cout << "Enter a Value to add to the array. Type 999 to clear array. Type -1 to quit. 888 to display stats: ";
    cin>>userInput;
    while (userInput != -1){
        bool addNum = test.setNumber(userInput);
        if(addNum && userInput != 999 && userInput != 888){
            //add sucessful
            cout<<"value sucessfully added."<<endl;
            cout<<"the values in the array are: ";
            test.displayNumbers();
            cout<<endl;
        }
        else if (userInput == 999){
            test.clear();
            cout<<"Array sucessfully cleared."<<endl;
        }
        else if (userInput == 888){
            test.getStats(max, min, avg);
            cout<<"The average of the array values is: "<<avg<<endl;
            cout<<"The max of the array values is: "<<max<<endl;
            cout<<"The min of the array values is: "<<min<<endl;
        }
        else
            // add failed
            cout<<"Array is full. Cannot add value."<<endl;
        cout << "Enter a Value to add to the array: ";
        cin>>userInput;
    }
    
    
    return 0;
}  // end main