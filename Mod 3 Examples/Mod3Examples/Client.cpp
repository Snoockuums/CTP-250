/** A Client class to test the MyClass templates
  * @author Professor Gregory
  * @file Client.cpp
  */
  
#include "ClassTemplate.h"   // or "ClassTemplate2.h

int main()
{  MyClass<int> example1;

   MyClass<double> example2;
	
	int a  = 3;
	example1.setData(a);
	example2.setData(5.4);
	
	example1.showData();
	example2.showData();
	
	example1.setData(105);
	example1.showData();
	
	return 0;
}