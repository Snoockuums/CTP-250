#ifndef TIME_H
#define TIME_H
#include <iostream>
using namespace std;

class Time
{
private:
   int hours;
   int minutes;
public:
/** Default constructor
  */
   Time();
/** Overloaded Constructor
  * @param int number of hours
  * @param int number of minutes
  */
   Time(int h, int m);
/** Mutator method for hours
  * @param int new hours value
  */
   void setHours(int h);
/** Accessor method for hours
  * @return int current value of hours
  */
   int getHours();
/** Mutator method for minutes
  * @param int new minutes value
  */
   void setMinutes(int m);
/** Accessor method for minutes
  * @return int current value of minutes
  */
   int getMinutes();
	
// Overloaded operators
/** Addition Operator
  * Handles the addition of two Time objects
  * @param right-hand side operand - Time object
  * @return new Time object containing the sum of the Time objects
  */
   Time operator+(const Time & t) const;
/** Addition Operator
  * Handles the addition of a Time object and an integer minutes value
  * @param right-hand side operand -  minutes value
  * @return new Time object operand -  containing the sum of the Time object and minutes
  */
	Time operator+(int minutesToAdd) const;
/** Addition Operator
  * Handles the addition of an integer minutes value and a Time object
  * @param left-hand side operand - integer minutes value
  * @param right-hand side operand -  Time object 
  * @return new Time object containing the sum of the Time objects
  */
   friend Time operator+(int minutesToAdd, const Time & t);
/** Stream Output Operator
  * @param left-hand side operpand - stream to use
  * @param right-hand side operand - Time object
  */
   friend ostream & operator<<(ostream &os, const Time &t);
/** Stream Input Operator
  * @param left-hand side operpand - stream to use
  * @param right-hand side operand - Time object
  */
   friend istream & operator>>(istream &os, Time &t);
};

#endif


