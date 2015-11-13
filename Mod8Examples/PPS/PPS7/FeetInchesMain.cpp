// @file FeetInchesMain.cpp 
#include "FeetInches.h" 
using namespace std; 

int main (void) 
{ 
// initialize some lengths in feet and inches 
  FeetInches length1(5, 9); 
  FeetInches length2(2, 8); 
  FeetInches length3(4, 15); 

// output the lengths initialized above 
  cout << "The lengths are:\n"; 
  cout << "length1: " << length1.getFeet() << " feet, " 
       << length1.getInches() << " inches\n"; 
  cout << "length2: " << length2.getFeet() << " feet, " 
       << length2.getInches() << " inches\n"; 
  cout << "length3: " << length3.getFeet() << " feet, " 
       << length3.getInches() << " inches\n"; 
  cout << endl; 

// test the + overloaded operator 
  FeetInches length4 = length1 + length2; 
  cout << "length1 + length2 = "; 
  cout << length4.getFeet() << " feet, " 
       << length4.getInches() << " inches\n"; 
  cout << endl; 

// test the - overloaded operator 
  // FeetInches length5 = length1 - length2; 
  // cout << "length1 - length2 = "; 
  // cout << length5.getFeet() << " feet, " 
  //      << length5.getInches() << " inches\n"; 
  // cout << endl; 

// test the > overloaded operator 
  if (length1 > length2) 
    cout << "length1 is greater than length2\n"; 
  else 
    cout << "length1 is not greater than length2\n"; 
  cout << endl; 

// test the < overloaded operator 
  // if (length1 < length2) 
  //   cout << "length1 is less than length2\n"; 
  // else 
  //   cout << "length1 is not less than length2\n"; 
  // cout << endl; 

// test the == overloaded operator 
  // if (length1 == length2) 
  //   cout << "length1 is equal to length2\n"; 
  // else 
  //   cout << "length1 is not equal to length2\n"; 
  // cout << endl; 

  FeetInches measurement1; 
  FeetInches measurement2; 
// test the << and >> overloaded operators 
   get a length for the first measurement 
   cout << "Enter a length in feet and inches.\n"; 
   cin >> measurement1; 
   cout << "The first measurement entered was: " << measurement1 << endl; 
   get a length for the second measurement 
   cout << "Enter a length in feet and inches.\n"; 
   cin >> measurement2; 
   cout << "The second measurement entered was: " << measurement2 << endl; 
  system("pause"); 
  return EXIT_SUCCESS; 
}