//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** Implementation file for the class LinkedList.
 @file LinkedList.cpp */

#include "LinkedList.h"  // Header file
#include <cassert>
#include <iostream>

template<class ItemType>
LinkedList<ItemType>::LinkedList() : headPtr(nullptr), itemCount(0)
{
}  // end default constructor

template<class ItemType>
LinkedList<ItemType>::LinkedList(const LinkedList<ItemType>& aList)
{
   headPtr = copyListNodes(aList.headPtr);
   itemCount = aList.itemCount;
}  // end copy constructor

template<class ItemType>
LinkedList<ItemType>::~LinkedList()
{
   clear();
}  // end destructor

template<class ItemType>
bool LinkedList<ItemType>::isEmpty() const
{
   return itemCount == 0;
}  // end isEmpty

template<class ItemType>
int LinkedList<ItemType>::getLength() const
{
   return itemCount;
}  // end getLength

template<class ItemType>
bool LinkedList<ItemType>::insert(int newPosition, const ItemType& newEntry)
{
   bool ableToInsert = (newPosition >= 1) && (newPosition <= itemCount + 1);
   if (ableToInsert)
   {
      // Create a new node containing the new entry 
      Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);  
      
      // Attach new node to chain
      if (newPosition == 1)
      {
         // Insert new node at beginning of chain
         newNodePtr->setNext(headPtr); 
         headPtr = newNodePtr;
      }
      else
      {
         // Find node that will be before new node
         Node<ItemType>* prevPtr = getNodeAt(newPosition - 1);
         
         // Insert new node after node to which prevPtr points
         newNodePtr->setNext(prevPtr->getNext()); 
         prevPtr->setNext(newNodePtr);
      }  // end if

      itemCount++;  // Increase count of entries
   }  // end if
   
   return ableToInsert;
}  // end insert

template<class ItemType>
bool LinkedList<ItemType>::remove(int position)
{
   bool ableToRemove = (position >= 1) && (position <= itemCount);
   if (ableToRemove)
   {
      Node<ItemType>* curPtr = nullptr;
      if (position == 1)
      {
         // Remove the first node in the chain
         curPtr = headPtr; // Save pointer to node
         headPtr = headPtr->getNext();
      }
      else
      {
         // Find node that is before the one to delete
         Node<ItemType>* prevPtr = getNodeAt(position - 1);
         
         // Point to node to delete
         curPtr = prevPtr->getNext();
         
         // Disconnect indicated node from chain by connecting the
         // prior node with the one after
         prevPtr->setNext(curPtr->getNext());
      }  // end if
      
      // Return node to system
      curPtr->setNext(nullptr);
      delete curPtr;
      curPtr = nullptr;
      
      itemCount--;  // Decrease count of entries
   }  // end if
   
   return ableToRemove;
}  // end remove

template<class ItemType>
void LinkedList<ItemType>::clear()
{
   while (!isEmpty())
      remove(1);
}  // end clear

template<class ItemType>
ItemType LinkedList<ItemType>::getEntry(int position) const throw(PrecondViolatedExcep)
{
   // Enforce precondition
   bool ableToGet = (position >= 1) && (position <= itemCount);
   if (ableToGet)
   {
      Node<ItemType>* nodePtr = getNodeAt(position);
      return nodePtr->getItem();
   }
   else
   {
      string message = "getEntry() called with an empty list or "; 
      message  = message + "invalid position.";
      throw(PrecondViolatedExcep(message)); 
   }  // end if
}  // end getEntry

template<class ItemType>
void LinkedList<ItemType>::setEntry(int position, const ItemType& newEntry) throw(PrecondViolatedExcep)
{
   // Enforce precondition
   bool ableToSet = (position >= 1) && (position <= itemCount);
   if (ableToSet)
   {
      Node<ItemType>* nodePtr = getNodeAt(position);
     nodePtr->setItem(newEntry);
 // nodePtr->item = newEntry;
   }
   else
   {
      string message = "setEntry() called with an invalid position."; 
      throw(PrecondViolatedExcep(message)); 
   }  // end if
}  // end setEntry

template<class ItemType>
Node<ItemType>* LinkedList<ItemType>::getNodeAt(int position) const
{
   // Debugging check of precondition
   assert( (position >= 1) && (position <= itemCount) );
   
   // Count from the beginning of the chain
   Node<ItemType>* curPtr = headPtr;
   for (int skip = 1; skip < position; skip++)
      curPtr = curPtr->getNext();
      
   return curPtr;
}  // end getNodeAt

template <class ItemType>
bool LinkedList<ItemType>::operator==(const LinkedList<ItemType>& rightHandSide) const
{
   bool isEqual = true; // Assume equal
   
   // First check number of items is the same
   if (itemCount != rightHandSide.getLength())
      isEqual = false;
   else
   {  // Then compare items
      Node<ItemType>* leftSidePtr = headPtr;
      Node<ItemType>* rightSidePtr = rightHandSide.headPtr;
      
      while ((leftSidePtr != nullptr) && (rightSidePtr != nullptr) && isEqual)
      {
         ItemType leftItem = leftSidePtr->getItem();
         ItemType rightItem = rightSidePtr->getItem();
         isEqual = (leftItem == rightItem);
         
         leftSidePtr = leftSidePtr->getNext();
         rightSidePtr = rightSidePtr->getNext();
      }  // end whiile
   }  // end if
   
   return isEqual;
}  // end operator==

template <class ItemType>
LinkedList<ItemType>& LinkedList<ItemType>::operator=(const LinkedList<ItemType>& rightHandSide)
{
   // Check for assignment to self
   if (this != &rightHandSide)
   {
      this->clear();                                  // Deallocate left-hand side
      headPtr = copyListNodes(rightHandSide.headPtr); // Copy nodes in right-hand side
      itemCount = rightHandSide.itemCount;            // Copy size of list
   }  // end if
   
   return *this;
} // end operator=

template <class ItemType>
LinkedList<ItemType> LinkedList<ItemType>::operator+(const LinkedList<ItemType>& rightHandSide) const
{
   LinkedList<ItemType> concatList;
   
   Node<ItemType>* leftChainPtr = copyThisList();
   concatList.headPtr = leftChainPtr;
   Node<ItemType>* rightChainPtr = copyListNodes(rightHandSide.headPtr);
   
   concatList.itemCount = itemCount;
   Node<ItemType>* leftChainTailPtr = concatList.getNodeAt(itemCount);
   leftChainTailPtr->setNext(rightChainPtr);
  concatList.itemCount += rightHandSide.itemCount;
   
    return concatList;
}  // end operator+

template<class friendItemType>
ostream& operator<<(ostream& outStream, const LinkedList<friendItemType>& outputList)
{
   int position = 1;
   Node<friendItemType>* currPtr = outputList.headPtr;
   while (currPtr != nullptr)
   {
      outStream << position << "\t" << currPtr->getItem() << endl;
      currPtr = currPtr->getNext();
      position++;
   }
   return outStream;
} // end operator<<

// PRIVATE:

template<class ItemType>
Node<ItemType>* LinkedList<ItemType>::copyThisList() const
{
   Node<ItemType>* newChainPtr = nullptr;
   Node<ItemType>* origChainPtr = headPtr;  // Points to nodes in original chain
   
   if (origChainPtr == nullptr)
      newChainPtr = nullptr;  // Original list is empty
   else
   {
      ItemType nextItem = origChainPtr->getItem();
      
      // Create first node in chain
      Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);
      
      newChainPtr = newNodePtr; // First node in new chain
      Node<ItemType>* tailPtr = newNodePtr;     // Points to last node in new chain
      
      // Advance original-chain pointer
      origChainPtr = origChainPtr->getNext();
      
      while (origChainPtr != nullptr)
      {
         // Get next item from original chain
         nextItem = origChainPtr->getItem();
         
         // Create a new node containing the next item
         newNodePtr = new Node<ItemType>(nextItem);
         
         // Link new node to end of new chain
         tailPtr->setNext(newNodePtr);
         
         // Advance pointer to new last node
         tailPtr = tailPtr->getNext();
         
         // Advance original-chain pointer
         origChainPtr = origChainPtr->getNext();
      }  // end while
      
      tailPtr->setNext(nullptr);           // Flag end of chain
   }  // end if
   
   return newChainPtr;
}  // end copyThisList

template<class ItemType>
Node<ItemType>* LinkedList<ItemType>::copyListNodes(Node<ItemType>* origChainPtr) const
{
   Node<ItemType>* newChainPtr = nullptr;
   //Node<ItemType>* origChainPtr = aList.headPtr;  // Points to nodes in original chain
   
   if (origChainPtr == nullptr)
      newChainPtr = nullptr;                      // Original list is empty
   else
   {
      ItemType nextItem = origChainPtr->getItem();
      
      // Create first node in chain
      Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);
      
      newChainPtr = newNodePtr;                  // First node in new chain
      Node<ItemType>* tailPtr = newNodePtr;      // Points to last node in new chain
      
      // Advance original-chain pointer
      origChainPtr = origChainPtr->getNext();
      
      while (origChainPtr != nullptr)
      {
         // Get next item from original chain
         nextItem = origChainPtr->getItem();
         
         // Create a new node containing the next item
         newNodePtr = new Node<ItemType>(nextItem);
         
         // Link new node to end of new chain
         tailPtr->setNext(newNodePtr);
         
         // Advance pointer to new last node
         tailPtr = tailPtr->getNext();
         
         // Advance original-chain pointer
         origChainPtr = origChainPtr->getNext();
      }  // end while
      
      tailPtr->setNext(nullptr);                 // Flag end of chain
   }  // end if
   
   return newChainPtr;
}  // end copyListNodes
//  End of implementation file.

