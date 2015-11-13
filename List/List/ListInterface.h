//
//  ListInterface.h
//  List
//
//  Created by Kylie Nicholson on 10/20/15.
//  Copyright (c) 2015 Kylie Nicholson. All rights reserved.
//

#ifndef List_ListInterface_h
#define List_ListInterface_h

template<class ItemType>
class ListInterface{
    virtual bool isEmpty() const = 0;
    virtual int getLength() const =0;
    virtual bool insert(int, const) =0;
    virtual bool remove(int) =0;
    virtual void clear =0;
    virtual ItemType getEntry(int) const throw(PrecondViolatedExcep) =0;
    virtual void setEntry(int, ItemType&) throw (PrecondViolatedExcep) =0;
}; // end class def
#endif
