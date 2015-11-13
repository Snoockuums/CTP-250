//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** ADT bag: Link-based implementation.
    @file LinkedBag.cpp */

#include "LinkedBag.h"
#include "Node.h"
#include <cstddef>

template<class ItemType>
LinkedBag<ItemType>::LinkedBag() : headPtr(nullptr), itemCount(0)
{
}  // end default constructor

template<class ItemType>
LinkedBag<ItemType>::LinkedBag(const LinkedBag<ItemType>& aBag)
{
	itemCount = aBag.itemCount;
   Node<ItemType>* origChainPtr = aBag.headPtr;  // Points to nodes in original chain
   
   if (origChainPtr == nullptr)
      headPtr = nullptr;  // Original bag is empty
   else
   {
      // Copy first node
      headPtr = new Node<ItemType>();
      headPtr->setItem(origChainPtr->getItem());
      
      // Copy remaining nodes
      Node<ItemType>* newChainPtr = headPtr;      // Points to last node in new chain
      origChainPtr = origChainPtr->getNext();     // Advance original-chain pointer
      
      while (origChainPtr != nullptr)	// origChainPtr is used as our counting pointer to traverse
		// the old chain
      {
         // Get next item from original chain
         ItemType nextItem = origChainPtr->getItem();
              
         // Create a new node containing the next item
         Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);
         
         // Link new node to end of new chain
         newChainPtr->setNext(newNodePtr);
         
         // Advance pointer to new last node
         newChainPtr = newChainPtr->getNext();

         // Advance original-chain pointer
         origChainPtr = origChainPtr->getNext();
      }  // end while
      
      newChainPtr->setNext(nullptr);              // Flag end of chain
   }  // end if
}  // end copy constructor

template<class ItemType>
LinkedBag<ItemType>::~LinkedBag()
{
   clear();
}  // end destructor

template<class ItemType>
bool LinkedBag<ItemType>::isEmpty() const
{
	return itemCount == 0;
}  // end isEmpty

template<class ItemType>
int LinkedBag<ItemType>::getCurrentSize() const
{
	return itemCount;
}  // end getCurrentSize

template<class ItemType>
bool LinkedBag<ItemType>::add(const ItemType& newEntry)
{
   // Add to beginning of chain: new node references rest of chain;
   // (headPtr is null if chain is empty)        
   Node<ItemType>* nextNodePtr = new Node<ItemType>();
   nextNodePtr->setItem(newEntry);
   nextNodePtr->setNext(headPtr);  // New node points to chain
//   Node<ItemType>* nextNodePtr = new Node<ItemType>(newEntry, headPtr); // alternate code

   headPtr = nextNodePtr;          // New node is now first node
   itemCount++;
   
   return true;
}  // end add

template<class ItemType>
vector<ItemType> LinkedBag<ItemType>::toVector() const
{
   vector<ItemType> bagContents;
   Node<ItemType>* curPtr = headPtr;
   int counter = 0;
	while ((curPtr != nullptr) && (counter < itemCount))
   {
		bagContents.push_back(curPtr->getItem());
      curPtr = curPtr->getNext();
      counter++;
   }  // end while
   
   return bagContents;
}  // end toVector

template<class ItemType>
bool LinkedBag<ItemType>::remove(const ItemType& anEntry)
{
   Node<ItemType>* entryNodePtr = getPointerTo(anEntry);
   bool canRemoveItem = !isEmpty() && (entryNodePtr != nullptr);
   if (canRemoveItem)
   {
      // Copy data from first node to located node
      entryNodePtr->setItem(headPtr->getItem());
      
      // Delete first node
      Node<ItemType>* nodeToDeletePtr = headPtr;
      headPtr = headPtr->getNext();
      
      // Return node to the system
      nodeToDeletePtr->setNext(nullptr);
      delete nodeToDeletePtr;
      nodeToDeletePtr = nullptr;
      
      itemCount--;
   } // end if
   
	return canRemoveItem;
}  // end remove

template<class ItemType>
void LinkedBag<ItemType>::clear()
{
   Node<ItemType>* nodeToDeletePtr = headPtr;
   while (headPtr != nullptr)
   {
      headPtr = headPtr->getNext();

      // Return node to the system
      nodeToDeletePtr->setNext(nullptr);
      delete nodeToDeletePtr;
      
      nodeToDeletePtr = headPtr;
   }  // end while
   // headPtr is nullptr; nodeToDeletePtr is nullptr
   
	itemCount = 0;
}  // end clear

template<class ItemType>
int LinkedBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const
{
	int frequency = 0;
   int counter = 0;
   Node<ItemType>* curPtr = headPtr;
   while ((curPtr != nullptr) && (counter < itemCount))
   {
      if (anEntry == curPtr->getItem())
      {
         frequency++;
      } // end if
      
      counter++;
      curPtr = curPtr->getNext();
   } // end while
   
	return frequency;
}  // end getFrequencyOf

template<class ItemType>
bool LinkedBag<ItemType>::contains(const ItemType& anEntry) const
{
	return (getPointerTo(anEntry) != nullptr);
}  // end contains

/* ALTERNATE 1
template<class ItemType>
bool LinkedBag<ItemType>::contains(const ItemType& anEntry) const
{
   return getFrequencyOf(anEntry) > 0;
} 
*/
/* ALTERNATE 2 
template<class ItemType>
bool LinkedBag<ItemType>::contains(const ItemType& anEntry) const
{
   bool found = false;
   Node<ItemType>* curPtr = headPtr;
   int i = 0;
   while (!found && (curPtr != nullptr) && (i < itemCount))
   {
      if (anEntry == curPtr-<getItem())
      {
         found = true;
      }
      else
      {
         i++;
         curPtr = curPtr->getNext();
      }  // end if
   }  // end while

   return found;
}  // end contains
*/

//Lab 4
//Lab 4-1
template<class ItemType>
LinkedBag<ItemType> LinkedBag<ItemType>::bagUnion(const LinkedBag& input) const{
	// make a new LinkedBag that will hold the union
	// copy input values into the union bag using copy constructor 
	LinkedBag<ItemType> theUnion = LinkedBag(input);
	// add the caller values 
   Node<ItemType>* origChainPtr = headPtr;  // Points to nodes in original chain
   while (origChainPtr != nullptr) // only add if second chain isn't empty.
   {
      // Copy first node
		theUnion.add(origChainPtr->getItem());
		origChainPtr=origChainPtr->getNext();
	}
	return theUnion;
	}

//Lab 4-2
template<class ItemType>
LinkedBag<ItemType> LinkedBag<ItemType>::intersect(const LinkedBag& input) const{
	// make a new LinkedBag that will hold the intersect
	LinkedBag<ItemType> theIntersect;
	// traverse the existing linked list
	Node<ItemType>* callerPtr = headPtr;
	Node<ItemType>* paramPtr = input.headPtr;
	while (callerPtr != nullptr)
	{
		//cout<<"caller: "<<callerPtr->getItem()<<endl;
		while(paramPtr != nullptr){
		// compare item entries
		//cout<<"input: "<<paramPtr->getItem()<<endl;
			if(callerPtr->getItem() == paramPtr->getItem()){ //if there's a match
				//add to intersect
				theIntersect.add(callerPtr->getItem());
				// stop looking for this value 
				paramPtr = paramPtr->getNext();
				break; 
			}
			//advance to next item in paramPtr
			paramPtr = paramPtr->getNext();
		}
	//reset paramPtr
	paramPtr = input.headPtr;
	//advance to next item in callerPtr
	callerPtr = callerPtr->getNext();
	}
return theIntersect; 
}

//Lab 4-2 extension: true intersect 
template<class ItemType>
LinkedBag<ItemType> LinkedBag<ItemType>::trueIntersect(const LinkedBag& input) const{
	// make a new LinkedBag that will hold the intersect
	LinkedBag<ItemType> theIntersect;
	// traverse the existing linked list
	Node<ItemType>* callerPtr = headPtr;
	Node<ItemType>* paramPtr = input.headPtr;
	int callerCount = 0;
	int inputCount = 0; 
	int intersect = 0;
	int sectCount = 0;
	while (callerPtr != nullptr)
	{
		//cout<<"caller: "<<callerPtr->getItem()<<endl;
		while(paramPtr != nullptr){
		// compare item entries
		//cout<<"input: "<<paramPtr->getItem()<<endl;
			if(callerPtr->getItem() == paramPtr->getItem()){ //if there's a match
			//check to see if already in intersect
				sectCount = theIntersect.getFrequencyOf(callerPtr->getItem());
				// if already in difference, break
				if(sectCount > 0)
					break; 
				callerCount = getFrequencyOf(callerPtr->getItem());
				//cout<<"callerCount is: "<<callerCount<<endl;
				inputCount = input.getFrequencyOf(paramPtr->getItem());
				//cout<<"inputCount is: "<<inputCount<<endl; 
				if(callerCount < inputCount) 
					intersect = callerCount;
				else if (inputCount < callerCount)
					intersect = inputCount;
				else
					// they're the same
					intersect = inputCount;
				//add to intersect
				for(int i=0; i<intersect; i++)
					theIntersect.add(callerPtr->getItem());
				// stop looking for this value 
				paramPtr = paramPtr->getNext();
				break; 
			}
			//advance to next item in paramPtr
			paramPtr = paramPtr->getNext();
		}
	//reset paramPtr
	paramPtr = input.headPtr;
	//advance to next item in callerPtr
	callerPtr = callerPtr->getNext();
	}
return theIntersect; 
}



//Lab 4-3
template<class ItemType>
LinkedBag<ItemType> LinkedBag<ItemType>::difference(const LinkedBag& input) const{
	// make a new LinkedBag that will hold the difference
	LinkedBag<ItemType> theDiff;
	// traverse the existing linked list
	Node<ItemType>* callerPtr = headPtr;
	Node<ItemType>* paramPtr = input.headPtr;
	while (callerPtr != nullptr)
	{
		while(paramPtr != nullptr){
		// compare item entries
		if(callerPtr->getItem() == paramPtr->getItem()){
			//do nothing and stop looking 
			break;
		}
		//if we get to the end of input and don't find it.
		if(paramPtr->getNext() == nullptr){ 
			// items are not equivalent. 
			//add to difference
			theDiff.add(callerPtr->getItem());
			break;
		}
		//advance to next item in paramPtr
		paramPtr = paramPtr->getNext();
		}
	//reset paramPtr
	paramPtr = input.headPtr;
	//advance to next item in callerPtr
	callerPtr = callerPtr->getNext();

	}
return theDiff; 


}

//Lab 4-3 extension- true difference 
template<class ItemType>
LinkedBag<ItemType> LinkedBag<ItemType>::trueDifference(const LinkedBag& input) const{
	// make a new LinkedBag that will hold the difference
	LinkedBag<ItemType> theDiff;
	// traverse the existing linked list
	Node<ItemType>* callerPtr = headPtr;
	Node<ItemType>* paramPtr = input.headPtr;
	int callerCount = 0;
	int inputCount = 0; 
	int diff = 0;
	int diffCount = 0;
	while (callerPtr != nullptr)
	{
		while(paramPtr != nullptr){
		// compare item entries
			if(callerPtr->getItem() == paramPtr->getItem()){
				//check to see if already in difference
				diffCount = theDiff.getFrequencyOf(callerPtr->getItem());
				// if already in difference, break
				if(diffCount > 0)
					break; 
				callerCount = getFrequencyOf(callerPtr->getItem());
				//cout<<"callerCount is: "<<callerCount<<endl;
				inputCount = input.getFrequencyOf(paramPtr->getItem());
				//cout<<"inputCount is: "<<inputCount<<endl; 
				diff = callerCount - inputCount;
				//cout<<"diff is: "<<diff<<endl;
				if (diff < 0)
					diff = 0; 
				if (diff > 0){
					for(int i=0; i<diff; i++)
						theDiff.add(callerPtr->getItem());
				}
				break;
	
			}		
			//if we get to the end of input and don't find it.
			if(paramPtr->getNext() == nullptr){ 
				// items are not equivalent. 
				//add to difference
				theDiff.add(callerPtr->getItem());
				break;
			}
		//advance to next item in paramPtr
		paramPtr = paramPtr->getNext();
		}
	//reset paramPtr
	paramPtr = input.headPtr;
	//advance to next item in callerPtr
	callerPtr = callerPtr->getNext();

	}
return theDiff; 
}

// private
// Returns either a pointer to the node containing a given entry 
// or the null pointer if the entry is not in the bag.
template<class ItemType>
Node<ItemType>* LinkedBag<ItemType>::getPointerTo(const ItemType& anEntry) const
{
   bool found = false;
   Node<ItemType>* curPtr = headPtr;
   
   while (!found && (curPtr != nullptr))
   {
      if (anEntry == curPtr->getItem())
         found = true;
      else
         curPtr = curPtr->getNext();
   } // end while
   
   return curPtr;
} // end getPointerTo

