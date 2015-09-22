/**
*
* @author Kylie Nicholson
* @file Lab2-3.cpp
* 
* The program contains a main method and a recursive method named isMember(). The isMember()
* method accepts four arguments: an array of integers, an integer search value, the next index to
* search, and the total number of elements in the array. The method must use recursion to
* determine if the integer value exists in the array returning the index of the value if the
* integer exists in the array, or -1 otherwise. The recursive method is calledthree times: once 
* to search for the value 32, once to search for the value 55, and once to search for the value
* 70.
*/

//includes
#include <iostream>

using namespace std;

// function declarations
int isMember(int[], int, int, int);

int main(){
    
    int theArray [8] = {25, 19, 88, 32, 91, 10, 37, 55};
    cout<<"Function returns: "<<isMember(theArray, 32, 0, 8)<<endl;
    cout<<"Function returns: "<<isMember(theArray, 55, 0, 8)<<endl;
    cout<<"Function returns: "<<isMember(theArray, 70, 0, 8)<<endl;
}

int isMember(int myArray[], int search, int start, int numElems){
    //if hit
    int index = -5;
    if(start == numElems)
        index = -1;
    else{
        if(myArray[start] == search){
            index = start;
        }
        else{
            start++;
            index = isMember(myArray, search, start, numElems);
        }
    }
    return(index);
}