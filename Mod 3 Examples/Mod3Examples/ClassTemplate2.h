/** Experimenting with class templates
  *     Class templates allow the compiler to create instances of a class 
  *			dependent upon the parameter supplied dduring instantiation
  *
  * Alternate approach (used by the textbook)
  *    .h file defines template and includes the .cpp file
  * This approach should be used ONLY when defining templates
  *            
  * @author Professor Gregory
  * @file ClassTemplate2.h
  */
  
#include <iostream>
using namespace std;

// Javadoc documentation comments should be included in the .h file
// Comments have been removed so that we can focus on syntax

// template - data type provided will be substituted where T is used 
template<class T>   

class MyClass
{
private: 
   T data;
public:
   MyClass();
	void setData(T newData);
	T getData();
	void showData();
};
#include "ClassTemplate2.cpp"    // DO THIS ONLY FOR TEMPLATES