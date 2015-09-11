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
    cout<<inputFile<<endl;
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
				if(inputSentence[i] != ' '){
					wordBuilder += inputSentence[i];
					}
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