/** Numeric conversion application example.  
  * This application converts a string containing an integer to its
  *   binary equivalent.
  * @file example.cpp
  * @author Professor Gregory
  */
  
#include <iostream>
#include <string>
#include <cstdlib>
#include <stack>

using namespace std;

int main()
{
   int  num;       // the number to be converted
   string numStr;  // string used for input
   int  remainder; // remainder when num is divided by 2
   stack <int> stackOfRemainders; // remainders
   char response;           // user response
   do
   {
      cout << "Enter positive integer to convert: ";
      cin >> numStr;
      num = atoi(numStr.c_str());
      while (num > 0)
      {
         remainder = num % 2;
         stackOfRemainders.push(remainder);
         num /= 2;
      }
		cout << "Base-two representation: ";
      while ( !stackOfRemainders.empty() )
      {
         remainder = stackOfRemainders.top();
         stackOfRemainders.pop();
         cout << remainder;
      }
      cout << endl;
      cout << "\nMore (Y or N)? ";
      cin >> response;
   }
   while (response == 'Y' || response == 'y');

   return EXIT_SUCCESS;

}  // end main
