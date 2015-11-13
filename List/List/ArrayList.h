//
//  ArrayList.h
//  List
//
//  Created by Kylie Nicholson on 10/20/15.
//  Copyright (c) 2015 Kylie Nicholson. All rights reserved.
//

#ifndef List_ArrayList_h
#define List_ArrayList_h

#include "ListInterface.h"
#include "PrecondViolatedExcep.h"

template<class ItemType>
class ArrayList:: public ListInterface<ItemType>
{
private:
    int MAX_SIZE = 100;
    //ItemType items[MAX_SIZE];
    int itemCount;
    int maxItems;
    
public:
    bool isEmpty() const;
    int getLength() const;
    bool insert(int, const);
    bool remove(int);
    void clear;
    ItemType getEntry(int) const throw(PrecondViolatedExcep);
    void setEntry(int, ItemType&) throw (PrecondViolatedExcep);
    
}

#endif
