/** Example program that utilizes a stack container object from the STL
  *    to determine if the brackets of a string are balanced.
  * @file brackets.cpp
  * @author Professor Gregory
  */
  
#include <iostream>
#include <stack>


using namespace std;

/* Test cases:
     {{s}}   is properly formed
	  {{s}    is missing 1 }
	  {s}}    is missing 1 {
	  s}}     is missing 2 {{
*/
	
int main()
{  
   string input;
	stack<char> aStack;

   cout << "Enter a string: ";
	getline(cin, input);            // input may contain spaces
   
	for (int i=0; i<input.length(); i++)
	{  char c = input[i];
	   if (c == '{')
		   aStack.push(c);
	   else if (c == '}')
				    aStack.pop();
	}
	
	if (aStack.empty())
	   cout << "The string '" << input 
		     << "' is formed correctly! " << endl;
   else 
	   cout << "The string '" << input 
		     << "' is NOT formed correctly!" << endl;

    return 0;
}

