// @file FeetInches.cpp 
#include "FeetInches.h" 

FeetInches::FeetInches() 
{ 
  feet = 0; 
  inches = 0; 
} 

FeetInches::FeetInches(int newFeet, int newInches) 
{ 
  setFeet(newFeet); 
  setInches(newInches); 
  simplify(); 
} 

void FeetInches::setFeet (int newFeet) 
{ 
  if (newFeet >= 0) 
    feet = newFeet; 
  else 
  { 
    cout << "Error: feet must be >= 0\n"; 
    feet = 0; 
  } 
} 

int FeetInches::getFeet() const 
{ 
  return feet; 
} 

void FeetInches::setInches (int newInches) 
{ 
  if (newInches >= 0) 
    inches = newInches; 
  else 
  { 
    cout << "Error: inches must be >= 0\n"; 
    feet = 0; 
  } 
} 

int FeetInches::getInches() const 
{ 
  return inches; 
} 

FeetInches FeetInches::operator+ (const FeetInches & right) 
{ 
  FeetInches temp; 
  temp.inches = inches + right.inches; 
  temp.feet = feet + right.feet; 
  temp.simplify(); 
  return temp; 
} 

FeetInches FeetInches:: operator - (const FeetInches& right){
  
  FeetInches temp;

  temp.inches = inches - right.inches;
  temp.feet = feet - right.feet;
  temp.simplify(); 

  return temp; 
}

bool FeetInches::operator> (const FeetInches & right) 
{ 
  bool status; 

  if (feet > right.feet)
    status = true; 
  else if (feet == right.feet && inches > right.inches) 
         status = true; 
       else 
         status = false; 
  return status; 
} 

bool FeetInches:: operator < (const FeetInches & right){
  
  if(feet < right.feet)
    return true; 
  else if (feet == right.feet && inches < right.inches)
    return true;  
  else
    return false; 
}

bool FeetInches :: operator == (const FeetInches& right){
  
  if(feet == right.feet && inches == right.inches)
    return true;
  else
    return false; 
}

ostream & operator<< (ostream &strm, const FeetInches &obj){
  // print operator
  strm<< obj.feet<< " feet, " <<obj.inches << " inches. "<<endl;
}

istream &operator>> (istream &strm, FeetInches &obj){
  // input operator
  cout << "Enter Feet: ";
  strm >> obj.feet;
  cout << "Enter Inches: ";
  strm >> obj.inches;
  return strm;

}

void FeetInches::simplify() 
{ 
  const int INCHES_IN_FEET = 12; 
  if (inches >= INCHES_IN_FEET) 
  { 
    feet += (inches / INCHES_IN_FEET); 
    inches = inches % INCHES_IN_FEET; 
  } 
  else if (inches < 0) 
       { 
         feet -= ((abs(inches) / INCHES_IN_FEET) + 1); 
         inches = INCHES_IN_FEET - (abs(inches) % INCHES_IN_FEET); 
       }

} 