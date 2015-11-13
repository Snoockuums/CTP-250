/** @file pointers.cpp
  * @author Professor Gregory
  * A program to experiment with pointers and dynamic memory allocation
  */

#include <iostream>
#include <string>

using namespace std;

int main()
{  int i;       // declare an identifier and allocate memory (contents is garbage but interpreted as an integer)
   int j = 0;   // declare an identifier, allocate and initialize memory
   int *k;      // declare an identifier (contents is garbage but interpreted as an address)
	
	cout << "The value of i is " << i << endl;
	cout << "The value of j is " << j << endl;
	cout << "The value of k is " << k << endl << endl;
	
	k = &i;     // store the address of i in pointer k
	*k = 55;    // go to the location stored in k and store 55
	
	cout << "After setting k to point to i and setting that location to 55: " << endl;
	cout << "The address of i is " << &i << endl;
	cout << "The value of i is " << i << endl;
	cout << "The value of k is " << k << endl;
	cout << "The value at the location pointed to by k is " << *k << endl;
	cout << "i and *k are the same!" << endl << endl;
	
	int *p;    // declare an identifier (contents is garbage)
	p = new int;    // allocate memory for an int and store the location in p
	*p = 105;
	
	cout << "New identifier, p created, memory allocated, and value set" << endl;
	cout << "The value of p is " << p << endl;
	cout << "The value of *p is " << *p << endl;
	cout << "Memory was allocated dynmaically!" << endl << endl;
	
	k = p;    // k points to the same location as p
	
	cout << "k changed to the value stored in p" << endl;
	cout << "The value of k is " << k << endl;
	cout << "The value of *k is " << *k << endl;
	cout << "The value of p is " << p << endl;
	cout << "The value of *p is " << *p << endl;
	cout << "k and p point to the same memory location!" << endl;
	
}
