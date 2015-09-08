/** @file myArray.cpp 
  * @author Kylie Nicholson
  * Defines an myArray object and methods to support the object.
  */
  
#include "myArray.h"    // include the header file
using namespace std;

myArray::myArray(){
	int theArray [10]; //creates an array of size 10
}

bool myArray::setNumber(int inputValue){	//DONE
	//if there is room
	//cout
	//cin (see lab description
	if(numArrayValues < 10){
		theArray[numArrayValues] = inputValue;
		numArrayValues++;
		return(true);
	}
	else
	//if there is not room
	return(false);
}

void myArray::clear(){	// DONE
	// clear the array
	for(int i=0; i<10; i++){
		theArray[i]=0;
	}
	// reset num array values
	numArrayValues = 0; 
}

void myArray::displayNumbers() const{	//DONE
	for(int i=0; i<numArrayValues; i++){
		cout<<theArray[i]<<" ";
	}
}

void myArray::getStats(int& max, int& min, float& avg){
	//find the min value in the array
	//find the max value in the array
	max = theArray[0];
	min = theArray[0];
	for(int i=1; i< numArrayValues; i++){
		if(theArray[i]<min)
			min=theArray[i];
		if(theArray[i] > max)
			max=theArray[i];
	}
	//find the average of values in the array
	int sum=0;
	for(int j=0; j<numArrayValues; j++)
		sum += theArray[j];
	avg = sum/numArrayValues;
	//avg = static_cast<float>sum/numArrayValues;
	
}

