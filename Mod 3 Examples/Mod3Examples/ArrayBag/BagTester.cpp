// Created by Frank M. Carrano and Tim Henry.
// Copyright (c) 2013 __Pearson Education__. All rights reserved.
#include <iostream>
#include <string>
#include "ArrayBag.h"
using namespace std;
/*
Testing the Array-Based Bag:
The initial bag is empty.
isEmpty: returns 1; should be 1 (true)
The bag contains 0 items:
Add 6 items to the bag:
The bag contains 6 items:
one two three four five one
isEmpty: returns 0; should be 0 (false)
getCurrentSize: returns 6; should be 6
Try to add another entry: add("extra") returns 0
All done!
*/
void displayBag(ArrayBag<string>& bag);
void bagTester(ArrayBag<string>& bag);
void bagTester2(ArrayBag<string>& bag);
void unionTester(ArrayBag<string>& bag, ArrayBag<string>& bag2); 
int main()
{
 ArrayBag<string> bag;
 ArrayBag<string> bag2;
 cout << "Testing the Array-Based Bag:" << endl;
 cout << "The initial bag is empty." << endl;
 bagTester(bag);
 bagTester2(bag2);
 ArrayBag<string> unionResult = bag.bagUnion(bag2); 
 displayBag(unionResult);
 //unionTester(bag, bag2);
 cout << "All done!" << endl;

 return 0;
} // end main

void displayBag(ArrayBag<string>& bag)
{
 cout << "The bag contains " << bag.getCurrentSize()
 << " items:" << endl;
 vector<string> bagItems = bag.toVector();
 int numberOfEntries = (int)bagItems.size();
 for (int i = 0; i < numberOfEntries; i++)
 {
 cout << bagItems[i] << " ";
 } // end for
 cout << endl << endl;
} // end displayBag

void bagTester(ArrayBag<string>& bag)
{
 cout << "isEmpty: returns " << bag.isEmpty()
 << "; should be 1 (true)" << endl;
 displayBag(bag);

 string items[] = {"one", "two", "three", "four", "five", "one"};
 cout << "Add 6 items to the bag: " << endl;
 for (int i = 0; i < 6; i++)
 {
 bag.add(items[i]);
 } // end for

 displayBag(bag);

 cout << "isEmpty: returns " << bag.isEmpty()
 << "; should be 0 (false)" << endl;

 cout << "getCurrentSize: returns " << bag.getCurrentSize()
 << "; should be 6" << endl;

 cout << "Try to add another entry: add(\"extra\") returns "
 << bag.add("extra") << endl;
 
} // end bagTester

void bagTester2(ArrayBag<string>& bag)
{
 cout << "isEmpty: returns " << bag.isEmpty()
 << "; should be 1 (true)" << endl;
 displayBag(bag);

 string items[] = {"A", "B", "C", "D", "E", "F"};
 cout << "Add 6 items to the bag: " << endl;
 for (int i = 0; i < 6; i++)
 {
 bag.add(items[i]);
 } // end for

 displayBag(bag);

 cout << "isEmpty: returns " << bag.isEmpty()
 << "; should be 0 (false)" << endl;

 cout << "getCurrentSize: returns " << bag.getCurrentSize()
 << "; should be 6" << endl;

 cout << "Try to add another entry: add(\"extra\") returns "
 << bag.add("extra") << endl;
 
} // end bagTester

void unionTester(ArrayBag<string>& bag, ArrayBag<string>& bag2){

	bag.bagUnion(bag2); 
	cout<<"union tester ran!";

}