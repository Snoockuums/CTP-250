/** Example program that utilizes a stack container object from the STL
  *    to determine if the brackets of a string are balanced.
  *    This version allows multiple string inputs, uses a global function to
  *    determine the result, and properly checks for an empty stack.
  * @file brackets2.cpp
  * @author Professor Gregory
  */
  
#include <iostream>
#include <string>
#include <stack>            // STL stack ADT
#include <algorithm>        // STL transform algorithm to convert to uppercase

using namespace std;

const int VALID = 0;        // indicates that the string has balanced brackets
const int INVALID_R = 1;    // indicates that the string is missing one or more }
const int INVALID_L = 2;    // indicates that the string is missing one or more {
	
int brackets(string&);

/* Test cases:
     {{s}}   is properly formed
	  {{s}    is missing 1 }
	  {s}}    is missing 1 {
	  s}}     is missing 2 {{
*/

int main()
{  
   string input;
	bool done = false;

   do
	{
	   cout << "Enter a string (or QUIT to exit): ";
	   getline(cin, input);            // input may contain spaces
      
		transform(input.begin(),input.end(),input.begin(),::toupper);  // convert input to uppercase
		
      if (input == "QUIT") 
		{  cout << "Goodbye!";
		   done = true;
		}	
		else
		{
         int result = brackets(input);
	      switch (result)
	      {  case VALID: 		  	  
	           cout << "The string '" << input 
		             << "' is formed correctly! " << endl << endl;
				  break;
	         case INVALID_L: 
		        cout << "The string '" << input 
		             << "' is not formed correctly! Missing 1 or more { " << endl << endl;			
				  break;
		      case INVALID_R:
		        cout << "The string '" << input 
		             << "' is not formed correctly! Missing 1 or more } " << endl << endl;
	      }
      }
	} while (!done);
	
   return 0;
}

int brackets(string& str)
{  stack<char> aStack;
   bool err = false;

	for (int i=0; i<str.length() && ! err; i++)
	{  char c = str[i];
	   if (c == '{')
		   aStack.push(c);
	   else if (c == '}')
             if (!aStack.empty())    // stack should NOT be empty
				    aStack.pop();            // pre-condition of stack: empty() is false
 				 else
	   		    err = true;          // indicate an error } without {
	}
	
	if (aStack.empty() && !err)
	   return VALID;
   else if(err)
	       return INVALID_L;
		  else
		    return INVALID_R; 

}