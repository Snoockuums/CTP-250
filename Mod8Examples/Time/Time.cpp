#include <iostream>
#include "Time.h"
using namespace std;

Time::Time() : hours(0), minutes(0)
{}

Time::Time(int h, int m) : hours(h), minutes(m)
{}

void Time::setHours(int h)
{  hours = h;
}
int Time::getHours()
{  return hours;
}

void Time::setMinutes(int m)
{   minutes = m;
}
int Time::getMinutes()
{   return minutes;
}

Time Time::operator+(const Time & t) const
{  Time result;
   result.minutes = minutes + t.minutes;
	result.hours = hours + t.hours + result.minutes/60;
   result.minutes %= 60;
   return result;
}

Time Time::operator+(int minutesToAdd)const
{  int hrs = minutesToAdd / 60;
   Time result;
   result.minutes = minutes + minutesToAdd;
   result.hours = hours + hrs + result.minutes/60;
   result.minutes %= 60;
   return result;
}

// Note: Scope resolution operator is NOT included b/c it is a non-member function
Time operator+(int minutesToAdd, const Time & t) 
{  
   Time result = t + minutesToAdd;    // Calling the member function
   return result;
}

// Note: Scope resolution operator is NOT included b/c it is a non-member function
ostream & operator<<(ostream &os, const Time &t)
{  os << t.hours <<  " Hours, " <<  t.minutes << " Minutes ";
   return os;
}

// Note: Scope resolution operator is NOT included b/c it is a non-member function
istream & operator>>(istream &os, Time &t)
{  cout << "Enter Hours: ";
   os >> t.hours;
	cout << "Enter Minutes: ";
	os >> t.minutes;
	return os;
}