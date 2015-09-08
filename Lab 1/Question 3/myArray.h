/** @file Array.h 
  * @author Kylie Nicholson
  * Defines an Array object and methods to support the object.
  */

// I am not sure how to use @param and @return javadoc!!!!

// @param and @return: https://students.cs.byu.edu/~cs240ta/fall2012/tutorials/javadoctutorial.html

class myArray
{
private:
	int arrayLength = 10;
	int max = 0;
	int min = 0;
	int avg = 0; 
	int numArrayValues = 0; 

public: 
/** 
* Deafult constructor: Creates an array and initializes its size
* Precondition: None.
* Postcondition: An array with 10 values exists. 
*/
	myArray();

// METHODS
/** 
* setNumber- Accepts and stores an integer value into the next available spot in array.
* Returns true if there is room in the array and the integer was successfully 
* stored.  Returns false otherwise.  
*/
	bool setNumber(int inputValue);

/**
* clear Ð removes all values from the array so that the array can be reused.
*/
	void clear(); 

/**
* displayNumbers Ð displays the values currently stored in the array.
*/
	void displayNumbers();

/**
* getStats Ð determines the largest, smallest, and average of the values currently 
* stored in the array.  These values are returned to the caller via reference 
* parameters.
*/
	void getStats(int& max, int& min, float& avg);

};



