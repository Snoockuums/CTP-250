string wordBuilder;

for(int i=0; i<inputSentence.length(); i++){ // iterate through each character of the line
	if(inputSentence[i] != ' ')
		wordBuilder += inputSentence[i]
	else{
		countLetters(wordBuilder, numVowels, numCons, numOther);
		wordBuilder.clear(); // reset word builder
	}
}
// upon for loop exit, entire sentence has been processed, so now output counts
cout<<numVowels<<" vowels"<<endl;
cout<<numCons<<" consonants"<<endl;
cout<<numOther<<" other"<<endl;