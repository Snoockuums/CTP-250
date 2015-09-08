// 2. Using the algorithm developed above, create a function that determines 
// the status of the first character of a word.  
// The function should receive a string containing a word as the first parameter 
// which should be defined as constant, and integer reference parameters containing 
// the counts for the number of vowels, consonants and numbers found in a sentence.  
// The main function should open a file containing sentences, read each sentence, 
// and use the function to add to the counts for each word of the sentence.  
// The main function should output the total counts for each sentence contained 
// in the file.  Hint: each sentence from the file must be parsed into individual 
// words which the function can examine.  The find and substr string methods can
// assist in the parsing of the sentence.  You may assume that words will be 
// separated by a single space.  The text input can be created with any simple 
// text editor such as NotePad.  In jGrasp, text files can be created be selecting 
// New | Plain Text from the File menu.  Store the text file in the same folder as 
// the program.


/**
* @file Lab1-2.cpp 
* @author Kylie Nicholson
* Uses a function to count the type of words given by the main function. Takes sentence input from a file.
*/
#include <iostream>
#include <string>
#include <locale>
#include <fstream>
	 
using namespace std;

// define functions
void countLetters (string, int&, int&, int&);

int main(){

//0. DEFINE VARIABLES
	string inputSentence;
	string inWord = "Hippopotomous";
	string wordBuilder;
	int numVowels = 0;
	int numCons = 0;
	int numOther = 0;

//1. OPEN AND READ FROM THE FILE
	//name of input file
	const string inputFile = "inputFile.txt"; 
	//open file
	ifstream inFile(inputFile.c_str()); 
	//account for errors in file opening 
	if (!inFile)
		cout << "Error opening file for input: " << inputFile << endl;
	else
	{
//2. DO STUFF	
		while(inFile.peek() != EOF) 
		//while !EOF
		{
			getline(inFile, inputSentence);
			// read sentence
			// output sentence
			cout<<"Input String: "<<inputSentence<<endl;
	
			for(int i=0; i<inputSentence.length(); i++){ // iterate through each character of the line
				if(inputSentence[i] != ' ')
					wordBuilder += inputSentence[i];
				else{
					countLetters(wordBuilder, numVowels, numCons, numOther);
					wordBuilder.clear(); // reset word builder
				}
			}
			// upon for loop exit, entire sentence has been processed, so now output counts
			cout<<numVowels<<" vowels"<<endl;
			cout<<numCons<<" consonants"<<endl;
			cout<<numOther<<" other"<<endl;
			//reset counter variables
			numVowels = 0;
			numCons=0;
			numOther=0;
		}
	}
	return 0;
}


void countLetters (const string myWord, int& numVow2, int& numCons2, int& numOther2)
{	
	char firstLetter = myWord[0];	
	firstLetter = tolower(firstLetter);
		
	if(isalpha(firstLetter)){
 		if(firstLetter == 'a' || firstLetter == 'e' || firstLetter == 'i' || firstLetter == 'o' || firstLetter == 'u')
		//letter is a vowel
		{
			numVow2++;
		}
 		else { // letter is a consonant  
			numCons2++;
 		}
 			
 		}
 	else // not a letter ("other" category)
 	{
		numOther2++; 
 	}
 
	
}