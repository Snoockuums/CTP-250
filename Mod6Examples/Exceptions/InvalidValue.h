/** Exception class 
  * @file InvalidValue.h
  * @author Prof Gregory
  */
#ifndef _INVALIDVALUE
#define _INVALIDVALUE

#include <stdexcept>
#include <string>

using namespace std;

class InvalidValueException : public logic_error  
{
public:
   InvalidValueException(const string& message = "");
}; 
#endif

