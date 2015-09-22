/** Experimenting with typedef and overloaded methods
  *     typedef allows us to use a different name for a datatype
  *     Overloaded methods allow us to define a several methods with the same name
  * @author Professor Gregory
  * @file MultipleDataTypes.cpp
  */
  
#include <iostream>
#include <string>
using namespace std;

// typedef is a way to give a new name to an existing data type
typedef double Number;     // giving double type a nickname of Number
typedef string chars;      // giving string type a nickname of chars

// prototypes for functions used by main 
Number getNumber();        
void showNumber(Number,chars);

//overloaded functions
int doubleIt(int);
double doubleIt(double);
long doubleIt(long);
short doubleIt(short);
float doubleIt(float);

int main()
{  
  cout << "Experimenting with typedef!\n\n";
  
  Number n = 0.0;         // declare a Number aka double
  chars name="Student";   // declare a chars aka string
  
  n = getNumber();
  showNumber(n,name);
  
  cout << "\nExperimenting with overloaded functions!\n\n";
  cout << "When I double 2 I get " << doubleIt(2) << endl;
  cout << "When I double 200 I get " << doubleIt(200) << endl;
  cout << "When I double 20000 I get " << doubleIt(20000) << endl;
  cout << "When I double 2.8 I get " << doubleIt(2.8) << endl;
  cout << "When I double 20000.8 I get " << doubleIt(20000.8) << endl;
  cout << "When I double " << n << " I get " << doubleIt(n) << endl;
  
  return 0;             // Same as EXIT_SUCCESS
}

// functions using the typedef data type
Number getNumber()
{  
   Number n; 
   cout << "Enter a number: ";
	cin >> n;
	return n;
}

void showNumber(Number n, chars name)
{
	cout << "Hello " << name << "! You entered " 
	     << n
		  << "!"
		  << endl;
}

// overloaded functions that all do the same thing
int doubleIt(int i)
{
   return i * 2;
}

double doubleIt(double x)
{
   return x * 2;
}

long doubleIt(long l)
{  
   return l * 2;
}

short doubleIt(short s)
{  
   return s * 2;
}

float doubleIt(float f)
{  
   return f * 2;
}

