/**
* @file Lab1-1.cpp 
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
		
	// do character assigning here.  
	firstLetter = inputValue[0];
	firstLetter = tolower(firstLetter);
		
	// cout<<"The First Letter is: "<<firstLetter;
		
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
		
	cout<<numVowels<<" words begin with a vowel."<<endl;
	cout<<numCons<<" words begin with a consonant."<<endl;
	cout<<numOther<<" other 'words' were found."<<endl; 
 
   return 0;
}
