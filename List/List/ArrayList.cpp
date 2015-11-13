//
//  ArrayList.cpp
//  List
//
//  Created by Kylie Nicholson on 10/20/15.
//  Copyright (c) 2015 Kylie Nicholson. All rights reserved.
//

#include <stdio.h>
#include "ArrayList.h"

template <class ItemType>
ArrayList<ItemType>::ArrayList(){
    
    // default constructor
    ItemType items[MAX_SIZE];
}

template <class ItemType>
bool ArrayList<ItemType>::isEmpty(){
    return (itemCount == 0);
}

template <class ItemType>
int getLength() const {
    
    return itemCount;
}

template <class ItemType>
bool insert(int newPosition, const ItemType& newEntry){
    //move stuff
    // insert
}

template <class ItemType>
bool remove(int position){
    //move stuff
}

template <class ItemType>
void clear(){
    
}

template <class ItemType>
ItemType getEntry(int position) const throw(PrecondViolatedExcep){
    
}

template <class ItemType>
void SetEntry(int position, const ItemType& newEntry) throw (PrecondViolatedExcep){
    
}
