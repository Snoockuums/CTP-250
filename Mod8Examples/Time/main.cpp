#include "Time.h"
#include <iostream>
using namespace std;

int main()
{  Time t1;
   t1.setHours(5);
   t1.setMinutes(30);
	  
   cout << "First time is ";
   cout << t1 << endl;
   
   Time t2(4,40);
   
   cout << "Second time is ";
   cout << t2 << endl;
   
 // Practice with overloaded + operator (add two Time objects)
   Time newTime = t1 + t2;       // newTime = t1.operator+(t2); 
   cout << endl << "The total time is ";
   cout << newTime << endl;
   
 // Practice with overloaded + operator (add minutes to Time object) 
   Time newTime2 = t1 + 30;     // newTime2 = t1.operator+(30);
   cout << endl << "First time plus 30 minutes is  ";
   cout << newTime2 << endl;
   
 // Practice with overloaded + operator (add minutes to Time object) 
   Time newTime3 = 30 + t2;    // newTime3 = operator+(30,t2);
   cout << endl << "Second time plus 30 minutes is  ";
   cout << newTime3 << endl;
	
 // Practice with overloaded >> operator
   cout << endl << "Please enter data for a new Time object" << endl;
	Time anotherTime;
	cin >> anotherTime;
	cout << endl << "Your time input was " << anotherTime;
}

