for(int i=0; i<input.itemCount; i++)
	for(int j=0; j<itemCount; j++)
		if(input.items[i] == items[j]){
			// there's a match
			// count frequency of this item in first array
			int countMain = getFrequencyOf(items[i]);
			// count frequency of this item in second array
			int countInput = input.getFrequencyOf(items[i]);
			//compare frequencies
			int smaller = min(countMain, countInput); 
			// add this number of entries to the intersect array
			cout<<"The min is: "<<smaller; 
			}
