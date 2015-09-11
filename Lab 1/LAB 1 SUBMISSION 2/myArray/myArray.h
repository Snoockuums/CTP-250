/** @file Array.h 
  * @author Kylie Nicholson
  * Defines an Array object and methods to support the object.
  */
class myArray
{
private:
	int arrayLength = 10;
//	int inputValues = 0;
    int theArray [10];

public:
    int numArrayValues = 0;
/** 
* Deafult constructor: Creates an array and initializes its size 
*/
	myArray();

// METHODS
/** 
* setNumber- Accepts and stores an integer value into the next available spot in array.
* Returns true if there is room in the array and the integer was successfully 
* stored.  Returns false otherwise. 
* @param inputValue: takes integer input
* @return true if there is room in array and value is added; false if array is full 
*/
	bool setNumber(int inputValue);

/**
* clear Ð clears all values from the array so that the array can be reused.
* @param none
* @return none
*/
	void clear(); 

/**
* displayNumbers Ð displays the values currently stored in the array.
* @param none
* @return none
*/
	void displayNumbers() const;

/**
* getStats Ð calculates the min, max, and average of the values currently
* stored in the array.  These stats are returned to the caller via reference 
* parameters.
* @ param max: integer value passed by reference to find maximum value in array
* @ param min: integer value passed by reference to find minimum value in array
* @ param avg: integer value passed by reference to find average value in array
* @return none
*/
	void getStats(int& max, int& min, float& avg);

};



