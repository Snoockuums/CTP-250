/** A simple class that throws an exception
  *    Class stores a single integer number
  * @file OneNumber.h
  * @author Prof Gregory
  */
#include "InvalidValue.h"

class OneNumber
{
private:
   int num;
public:
   OneNumber();
	OneNumber(int) throw (InvalidValueException);
	void setNum(int) throw (InvalidValueException);
	int getNum();
};

