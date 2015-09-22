//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** Implementation file for the class ArrayBag.
 @file ArrayBag.cpp */

#include "ArrayBag.h"
#include <cstddef>

using namespace std;

template<class ItemType>
ArrayBag<ItemType>::ArrayBag(): itemCount(0), maxItems(DEFAULT_CAPACITY)
{
}  // end default constructor

template<class ItemType>
int ArrayBag<ItemType>::getCurrentSize() const
{
	return itemCount;
}  // end getCurrentSize

template<class ItemType>
bool ArrayBag<ItemType>::isEmpty() const
{
	return itemCount == 0;
}  // end isEmpty

template<class ItemType>
bool ArrayBag<ItemType>::add(const ItemType& newEntry)
{
	bool hasRoomToAdd = (itemCount < maxItems);
	if (hasRoomToAdd)
	{
		items[itemCount] = newEntry;
		itemCount++;
	}  // end if
    
	return hasRoomToAdd;
}  // end add

/*
// STUB
 template<class ItemType>
 bool ArrayBag<ItemType>::remove(const ItemType& anEntry)
 {
    return false; // STUB
 }  // end remove
*/   
 
template<class ItemType>
bool ArrayBag<ItemType>::remove(const ItemType& anEntry)
{
   int locatedIndex = getIndexOf(anEntry);
	bool canRemoveItem = !isEmpty() && (locatedIndex > -1);
	if (canRemoveItem)
	{
		itemCount--;
		items[locatedIndex] = items[itemCount];
	}  // end if
    
	return canRemoveItem;
}  // end remove

/*
 // STUB
 template<class ItemType>
 void ArrayBag<ItemType>::clear()
 {
    // STUB
 }  // end clear
*/

template<class ItemType>
void ArrayBag<ItemType>::clear()
{
	itemCount = 0;
}  // end clear

template<class ItemType>
int ArrayBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const
{
   int frequency = 0;
   int curIndex = 0;       // Current array index
   while (curIndex < itemCount)
   {
      if (items[curIndex] == anEntry)
      {
         frequency++;
      }  // end if
      
      curIndex++;          // Increment to next entry
   }  // end while
   
   return frequency;
}  // end getFrequencyOf

template<class ItemType>
bool ArrayBag<ItemType>::contains(const ItemType& anEntry) const
{
	return getIndexOf(anEntry) > -1;
}  // end contains

/* ALTERNATE 1: First version
template<class ItemType>
bool ArrayBag<ItemType>::contains(const ItemType& target) const 
{
   return getFrequencyOf(target) > 0;
}  // end contains

// ALTERNATE 2: Second version 
template<class ItemType>
bool ArrayBag<ItemType>::contains(const ItemType& anEntry) const
{
   bool found = false;
   int curIndex = 0;        // Current array index
   while (!found && (curIndex < itemCount))
   {
      if (anEntry == items[curIndex])
      {
         found = true;
      } // end if
      
      curIndex++;           // Increment to next entry
   }  // end while   
   
   return found;
}  // end contains
*/

template<class ItemType>
vector<ItemType> ArrayBag<ItemType>::toVector() const
{
	vector<ItemType> bagContents;
	for (int i = 0; i < itemCount; i++)
		bagContents.push_back(items[i]);
      
   return bagContents;
}  // end toVector

template<class ItemType>
ArrayBag<ItemType> ArrayBag<ItemType>::bagUnion(const ArrayBag& input) const{
	// declare a new ArrayBag that will hold the union
	ArrayBag<ItemType> theUnion;
	// for each entry in input, set a slot in the new ArrayBag equal to the entry and increment itemCount.
	for(int i=0; i<input.itemCount; i++){
		theUnion.items[i] = input.items[i];
		cout<<"The entry in input was: "<<input.items[i]<<endl;
		cout<<"The entry in theUnion is: "<<theUnion.items[i]<<endl;
		theUnion.itemCount++;
		cout<<"Union item count: "<<theUnion.itemCount<<endl;

	}
	int itemCountAfterPart1 = theUnion.itemCount;
	// for each entry in current array, set a slot in the new ArrayBag equal to the entry and increment itemCount.
	for(int j=0; j<itemCount; j++){
		theUnion.items[j+itemCountAfterPart1] = items[j];
		cout<<"The entry in caller was: "<<items[j]<<endl;
		cout<<"The entry in theUnion is: "<<theUnion.items[j+itemCountAfterPart1]<<endl;
		theUnion.itemCount++; 
		cout<<"Union item count: "<<theUnion.itemCount<<endl;
	}
	return theUnion;
	}
template<class ItemType>
ArrayBag<ItemType> ArrayBag<ItemType>::intersect(const ArrayBag& input) const{
	// declare a new ArrayBag that will hold the intersection
	ArrayBag<ItemType> theIntersect;
	for(int i=0; i<input.itemCount; i++)
		for(int j=0; j<itemCount; j++)
			if(input.items[i] == items[j]){
				//add to intersection array
				cout<<"There's a match: "<<items[j]<<endl;
				theIntersect.items[theIntersect.itemCount] = items[j];
				theIntersect.itemCount++;
				cout<<"Item Count: "<<theIntersect.itemCount;
			}
	return theIntersect; 
}
// private
template<class ItemType>
int ArrayBag<ItemType>::getIndexOf(const ItemType& target) const
{
	bool found = false;
   int result = -1;
   int searchIndex = 0;
   
   // If the bag is empty, itemCount is zero, so loop is skipped
   while (!found && (searchIndex < itemCount))
   {
      if (items[searchIndex] == target)
      {
         found = true;
         result = searchIndex;
      } 
      else
      {
         searchIndex++;
      }  // end if
   }  // end while
   
   return result;
}  // end getIndexOf
