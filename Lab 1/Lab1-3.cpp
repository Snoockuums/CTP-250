// 3. Define a class which stores 10 integer values in an array.  The class should
// also define the following 4 public methods:
// 
//     setNumber Ð accepts an integer value to store in the array.  The value is
// 		stored in the next available element of the array (first call to the method 
//			stores the value in element 0 with the second call storing the value in  
//			element 1.) The method returns true if there is room in the array and the 
//			integer was successfully stored.  Returns false otherwise.  
// 
//     clear Ð removes all values from the array so that the array can be reused.
// 
//     displayNumbers Ð displays the values currently stored in the array.
// 
//     getStats Ð determines the largest, smallest, and average of the values currently 
//			stored in the array.  These values are returned to the caller via reference 
//			parameters.

// All methods should produce correct results regardless of the order in which the 
// methods are called.  Thus, calling displayNumbers prior to setNumber will 
// produce an appropriate result.
// 
// A specification file (.h) and an implementation file (.cpp) for the class are 
// required.  The specification should be documented using Javadoc documentation 
// comments for all public members.  The @author @file @param and @return Javadoc 
// tags should be used as appropriate.  The implementation file requires only a 
// single Javadoc documentation comment at the top of the file which includes the 
// @author and @file tags.
// 
// Also develop a Client to utilize your class.  A sample run is shown below; your 
// output does not need to match the sample.  Other tests are recommended to 
// thoroughly test all methods of the class.
// 
// A makefile must also be submitted for this exercise.

/**
* @file Lab1-3.cpp 
* @author Kylie Nicholson
* Defines a class
*/
#include <iostream>
#include <string>
#include <locale>
#include <fstream>
	 
using namespace std;
