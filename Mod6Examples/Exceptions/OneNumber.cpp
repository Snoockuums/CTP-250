/** A simple class that throws an exception
  *    Class stores a single integer number
  * @file OneNumber.cpp
  * @author Prof Gregory
  */

#include "OneNumber.h"
OneNumber::OneNumber() : num(-1)
{
}

OneNumber::OneNumber(int newNum) throw (InvalidValueException)
{  setNum(newNum);
} 

void OneNumber::setNum(int newNum) throw (InvalidValueException)
{  if (newNum >= 0 and newNum <= 100)
      num=newNum;
	else
	   throw InvalidValueException("Value must be between 0 and 100");
}

int OneNumber::getNum()
{  return num;
}