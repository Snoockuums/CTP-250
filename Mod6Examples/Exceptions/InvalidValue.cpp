/** Exception class
  * @file InvalidValue.cpp
  * @author Proff Gregory
  */
#include "InvalidValue.h"  

InvalidValueException::InvalidValueException(const string& message) 
  : logic_error( "Value provided is not within the given range: " + message)
  // invalidValueException extends logic_error and tells it to output "Value provided..."
{  
}  // end constructor


