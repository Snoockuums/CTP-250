/** A Client for testing 
  * @file Client.cpp
  * @author Prof Gregory
  */
  
#include "OneNumber.h"
#include "InvalidValue.h"
#include <iostream>
//
int main()
{  cout << "Test 1: Testing using the default constructor" << endl;
   OneNumber myNumber;
	cout << "Initially, value is " << myNumber.getNum() << endl;
	
	cout << "Setting number to a good value" << endl;
	myNumber.setNum(5);
	cout << "Value is " << myNumber.getNum() << endl; 

   cout << endl << "Test2: Testing using the overloaded constructor" << endl;
   OneNumber myNumber2(11);
	cout << "Initially, value is " << myNumber2.getNum() << endl;
	
	cout << "Setting number to a good value" << endl;
	myNumber2.setNum(15);
	cout << "Value is " << myNumber2.getNum() << endl; 

	cout << "Setting number to a invalid value" << endl;
	try      // comment out the try and catch and the program will abort
	{
	   myNumber2.setNum(-15);
	   cout << "Value is " << myNumber2.getNum() << endl;   
	} catch (InvalidValueException err)   
	  {  cout << "Exception occurred! Message: " << err.what() << endl;
	     cout << "Value is " << myNumber2.getNum() << endl;
	  } 
	  
	try
	{
	   cout << endl << "Test3: Testing using the overloaded constructor with invalid number" << endl;
      OneNumber myNumber3(111);
	} catch (InvalidValueException err)   
	  {  cout << "Exception occurred! Message: " << err.what() << endl;
	  }
  
	
	cout << endl << "Test4: Testing using user input" << endl;
	OneNumber myNumber4;
	
	int val;
	bool valid = false;
	while (!valid)
	{  cout << "Enter a value between 0 and 100: ";
	   cin >> val;
		try
		{
		   myNumber4.setNum(val);
			cout << "Thank you!";
			valid = true;
	   } catch (InvalidValueException err)
		  { cout << "Input was not accepted - " << err.what() << endl;
		    cout << "Try again" << endl;
		  }
	}
	cout << "Value is " << myNumber4.getNum(); 
	 
   return 0;
}