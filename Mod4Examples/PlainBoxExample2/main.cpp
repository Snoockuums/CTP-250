/** @file main.cpp
  * @author Professor Gregory
  * A program to test polymorphism - testing whether the correct setItem method is called
  *
  * virtual methods are defined in the PlainBox class
  *
  * Uses the PlainBox and MagicBox classes
  * The MagicBox class is a sub class of the PlainBox class
  * A PlainBox contains 1 item which can be changed at any time
  * A MagicBox can have it contents set only once and can not be changed
  */

#include <iostream>
#include <string>
#include "MagicBox.h"

using namespace std;

void test1();  // Contents of a MagicBox can only be set once
void test2();  // Correct setItem method called?
void test3();  // Correct setItem method called?
void test4();  // Correct setItem method called?
void placeInBox(PlainBox<string>&, string);

int main()
{  cout << "Test to see that MagicBox contents can only be set once." << endl;
   test1();
	cout << "Test 1 Summary: " << endl;
	cout << "The setItem method of the MagicBox class allows the item to only be set once." << endl;

   cout << endl << "Test to see that the correct setItem method is called." << endl;
   test2();		
	cout << "Test 2 Summary: " << endl;
	cout << "Compiler can tell that the oldBox is really a MagicBox.  Therefore " << endl
	     << "  the setItem method of the MagicBox class is called which does not " << endl
		  << "  allow the item to be changed." << endl;
	
	cout << endl << "Test to see if correct setItem method is called when pointers are used." << endl;
	test3();	
	cout << "Test 3 Summary: " << endl;
	cout << "Compiler knows that the first parameter of the placeInBox function is a PlainBox.  However, " << endl
	     << "  since the setItem method of the PlainBox class is defined as virtual, the compiler will " << endl
		  << "  utilize late binding (Polymorphism) to call the appropriate setItem method." << endl;

   cout << endl << "Test 4" << endl;
   test4();
	cout << "Test 4 Summary: " << endl;
	cout << "Since the array contains both PlainBox and MagicBox objects, the array must be of the super class type.  Hence, " << endl
	     << "  the array is a PlainBox. Hwever, since the setItem method of the PlainBox class is defined as virtual, " << endl
		  << "  the compiler will utilize late binding (Polymorphism) to call the appropriate setItem method." << endl;
		  
   return 0;
} // end main


void test1()
{  string rabbit = "Rabbit";
   string wand = "Wand";
   
   MagicBox<string> magicHat;
   magicHat.setItem(rabbit);
   cout << "magicHat.getItem() = " << magicHat.getItem() << endl;
   
   magicHat.setItem(wand);
	cout << "setItem method called a second time setItem('Wand')" << endl;
   // magicHat still holds the rabbit
   cout << "magicHat.getItem() = " << magicHat.getItem() << endl;
} 

void test2()
{  PlainBox<string> oldBox;
   MagicBox<string> magicBox;
	
	oldBox.setItem("Original PlainBox contents");
	magicBox.setItem("Original MagicBox contents");
	
   cout << "oldBox item set - oldBox.getItem() = " << oldBox.getItem() << endl;
   
   cout << "magicBox item set - magicBox.getItem() = " << magicBox.getItem() << endl;
	
	cout << "Changing the oldBox to a magicBox." << endl;
	oldBox = magicBox;      // This is legal because a magicBox is an plainBox
	oldBox.setItem("No, you didn't!");
	
   cout << "setItem method called - magicBox.getItem() = " << magicBox.getItem() << endl;

}

void test3()
{  PlainBox<string> myPlainBox;
   placeInBox(myPlainBox,"A Plain Old Box");
   MagicBox<string> myMagicBox;
	placeInBox(myMagicBox,"A Magic Box!");
	
	cout << "Original contents of plain box: " << myPlainBox.getItem() << endl;
	cout << "Original contents of magic box: " << myMagicBox.getItem() << endl;
	
	placeInBox(myPlainBox,"Old Box - Revised contents");
	placeInBox(myMagicBox,"Magic Box - Revised contents");
	
	cout << "Revised contents of plain box: " << myPlainBox.getItem() << endl;
	cout << "Revised contents of magic box?: " << myMagicBox.getItem() << endl;

}

void placeInBox(PlainBox<string>& theBox, string theItem)
{  theBox.setItem(theItem);
}

void test4()
{  PlainBox<string>* boxes[5];
   boxes[0] = new PlainBox<string>("One plainBox");
	boxes[1] = new PlainBox<string>("Second plainBox");
	boxes[2] = new MagicBox<string>("First magicBox");
	boxes[3] = new MagicBox<string>("Second magicBox");
	boxes[4] = new MagicBox<string>("Third magicBox");
	
	cout << "The original contents of an array of 5 boxes:" << endl;
	for (int i=0; i<5; i++)
	    cout << "   box " << i+1 << ": " << boxes[i]->getItem() << endl;
	
	boxes[0]->setItem("One plainBox REVISED");
	boxes[1]->setItem("Second plainBox REVISED");
	boxes[2]->setItem("First magicBox REVISED");
	boxes[3]->setItem("Second magicBox REVISED");
	boxes[4]->setItem("Third magicBox REVISED");
	
	cout << "After contents revised, the contents of an array of 5 boxes:" << endl;
	for (int i=0; i<5; i++)
	    cout << "   box " << i+1 << ": " << boxes[i]->getItem() << endl;
}