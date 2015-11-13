// @file FeetInches.h 
#ifndef FEETINCHES_H 
#include 
#include 
using namespace std; 

class FeetInches 
{ 
  friend ostream &operator<< (ostream &strm, const FeetInches &obj); 
  friend istream &operator>> (istream &strm, FeetInches &obj); 

private: 
int feet; // stores the number of feet 
int inches; // stores the number of inches 

void simplify(); 

public: 
  FeetInches(); 
  FeetInches(int newFeet, int newInches); 
  void setFeet (int newFeet); 
  int getFeet() const; 
  void setInches (int newInches); 
  int getInches() const; 
// overloaded operator methods 
  FeetInches operator+ (const FeetInches & right); 
  FeetInches operator- (const FeetInches &right); 
  bool operator> (const FeetInches &right); 
  bool operator< (const FeetInches &right); 
  bool operator== (const FeetInches &right); 
}; 
#define FEETINCHES_H 
#endif 