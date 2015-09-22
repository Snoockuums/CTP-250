/** Experimenting with class templates
  *     Class templates allow the compiler to create instances of a class 
  *			dependent upon the parameter supplied dduring instantiation
  * @author Professor Gregory
  * @file ClassTemplate.h
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


// Technique 1 - the implementation is placed within the .h file
template<class T>            // Note class qualifier must include the template
MyClass<T>::MyClass()   
{  data = 0;
}

template<class T>
void MyClass<T>::setData(T newData)
{  data = newData;
}

template<class T>
T MyClass<T>::getData()
{ return data;
}

template<class T>
void MyClass<T>::showData()
{ cout << "Your data is " << data << endl;
} 