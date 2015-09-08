/**
* @file Lab1-1_a.cpp 
* @author Kylie Nicholson
* Determines whether a word begins with a vowel, a consonant or other. Then outputs
* count of each category (vowel, consonant, or other)
*/
#include <iostream>
#include <string>
#include <locale>
	 
using namespace std;
     
int main()
{
	string inputValue;
	char firstLetter;
	int numVowels = 0;
	int numCons = 0;
	int numOther = 0;
	 
	cout << "Type words. Type quit to end: ";
   cin >>inputValue;

	 
	while (inputValue != "quit"){
	 
  	 cout << inputValue << " ";
		
	// do character assigning here.  
	firstLetter = inputValue[0];
	firstLetter = tolower(firstLetter);
		
	//loops for testing category of first letter
	if(isalpha(firstLetter)){
 		if(firstLetter == 'a' || firstLetter == 'e' || firstLetter == 'i' || firstLetter == 'o' || firstLetter == 'u')
		{
			// cout<<"The letter is a vowel!"<<endl;
			numVowels++;
		}
 		else {
			// cout<<"The letter is a consonant!"<<endl; 
			numCons++;
 		}
 			
 		}
 	else // not a letter ("other" category)
 	{
 		// cout<<"The letter is OTHER!"<<endl;
		numOther++; 
 	}
		
  		cin >>inputValue;
 
   }
 
   return 0;
}
