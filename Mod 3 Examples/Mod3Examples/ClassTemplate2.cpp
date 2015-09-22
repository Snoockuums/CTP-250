/** Experimenting with class templates
  *     Class templates allow the compiler to create instances of a class 
  *			dependent upon the parameter supplied dduring instantiation
  *
  * Alternate approach (used by the textbook)
  *    .h file defines template and includes the .cpp file
  * This approach should be used ONLY when defining templates
  *
  * This file can NOT be compiled; the .h is compiled
  *    
  * @author Professor Gregory
  * @file ClassTemplate2.cpp
  */
  
#include <iostream>
using namespace std;

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