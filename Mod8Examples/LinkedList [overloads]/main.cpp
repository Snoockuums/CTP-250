//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

#include "LinkedList.h" // ADT list operations
#include <iostream>
#include <string>

using namespace std;

void displayList(ListInterface<string>* listPtr)
{
   for (int pos = 1; pos <= listPtr->getLength(); pos++)
   {
      cout << listPtr->getEntry(pos) << " ";
   } // end for
	cout << endl;
}  // end displayList

int main()
{  
   cout << "Testing the == operator:" << endl;
   
	LinkedList<string>* list1Ptr = new LinkedList<string>();
	string data[] = {"one", "two", "three", "four", "five", "six"};
	for (int i = 0; i < 6; i++)
      list1Ptr->insert(i + 1, data[i]);
   cout << "List 1:" << endl;
   displayList(list1Ptr);
   cout << endl;
   
	LinkedList<string>* list2Ptr = new LinkedList<string>();
	for (int i = 0; i < 6; i++)
      list2Ptr->insert(i + 1, data[i]);
   cout << "List 2:" << endl;
   displayList(list2Ptr);
   cout << endl;
   
   cout << "Comparing Lists 1 and 2:\n";
  if (*list1Ptr == *list2Ptr)
      cout << "Lists 1 and 2 are equal\n";
   else
      cout << "Lists 1 and 2 are NOT equal -- ERROR!\n";
   
   cout << endl;
   list1Ptr->remove(2);
   cout << "List 1:" << endl;
   displayList(list1Ptr);
   cout << endl;
   cout << "List 2:" << endl;
   displayList(list2Ptr);
   cout << endl;
   cout << "Comparing Lists 1 and 2:\n";
   
  if (*list1Ptr == *list2Ptr)
      cout << "Lists 1 and 2 are equal-- ERROR!\n";
   else
      cout << "Lists 1 and 2 are NOT equal \n";
   
   cout << endl;
   list1Ptr->insert(2, "TWO");
   cout << "List 1:" << endl;
   displayList(list1Ptr);
   cout << endl;
   cout << "List 2:" << endl;
   displayList(list2Ptr);
   cout << endl;
   cout << "Comparing Lists 1 and 2:\n";
   
   if (*list1Ptr == *list2Ptr)
      cout << "Lists 1 and 2 are equal-- ERROR!\n";
   else
      cout << "Lists 1 and 2 are NOT equal \n";
   //===============================================================
   cout << endl;
   cout << "Testing the + operator by concatenating the previous two lists:" << endl;
   LinkedList<string> list3 = *list1Ptr + *list2Ptr;
   displayList(&list3);
   
   
   //===============================================================
   cout << endl;
   cout << "Testing the = operator:" << endl;
   
   LinkedList<string> assignedList = *list1Ptr;
   cout << "List 1:" << endl;
   displayList(list1Ptr);
   cout << "List assigned:" << endl;
   displayList(&assignedList);
   
   //===============================================================
   cout << endl;
   cout << "Testing the << operator by displaying List 1:" << endl;
   cout << *list1Ptr;
   
   //===============================================================
	cout << endl;
	cout << "Testing << operator by displaying item 1 from List 1: "<< endl;
	cout << "List 1's first item was " << list1Ptr->getEntry(1) << endl;
	list1Ptr->setEntry(1,"New Stuff");
   cout << "List 1's first item is now " << list1Ptr->getEntry(1) << endl;
		
   return 0;
}  // end main

/*
 Testing the == operator:
 List 1:
 one two three four five six
 
 List 2:
 one two three four five six
 
 Comparing Lists 1 and 2:
 Lists 1 and 2 are equal
 
 List 1:
 one three four five six
 
 List 2:
 one two three four five six
 
 Comparing Lists 1 and 2:
 Lists 1 and 2 are NOT equal
 
 List 1:
 one TWO three four five six
 
 List 2:
 one two three four five six
 
 Comparing Lists 1 and 2:
 Lists 1 and 2 are NOT equal
 
 Testing the + operator by concatenating the previous two lists:
 one TWO three four five six one two three four five six
 
 Testing the = operator:
 List 1:
 one TWO three four five six
 List assigned:
 one TWO three four five six
 
 Testing the << operator by displaying List 1:
 1	one
 2	TWO
 3	three
 4	four
 5	five
 6	six
 
 Testing << operator by displaying item 1 from List 1: 
 List 1's first item was one
 List 1's first item is now New Stuff
 */
