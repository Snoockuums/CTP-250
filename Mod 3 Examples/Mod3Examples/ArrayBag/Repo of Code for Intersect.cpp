	/*for(int i=0; i<input.itemCount; i++)
		for(int j=0; j<itemCount; j++)
			if(input.items[i] == items[j]){
				//add to intersection array
				cout<<"There's a match: "<<items[j]<<endl;
				theIntersect.items[theIntersect.itemCount] = items[j];
				theIntersect.itemCount++;
				cout<<"Item Count: "<<theIntersect.itemCount;
			}
			*/
			
			
			
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
			
			--------
			
			
			
			ArrayBag<ItemType> ArrayBag<ItemType>::intersect(const ArrayBag& input) const{
	// declare a new ArrayBag that will hold the intersection
	ArrayBag<ItemType> theIntersect;
	ItemType tracker[20];
	int trackerCount = 0;
	bool exists = false; 
	for(int i=0; i<input.itemCount; i++)
		for(int j=0; j<itemCount; j++)
			if(input.items[i] == items[j]){
				//add to intersection array
				cout<<"There's a match: "<<items[j]<<endl;
				for(int m=0; m<trackerCount; m++){
					if(tracker[m] == items[j]) // item already exists in tracker
						//skip this item
						exists = true;
				}
				if(!exists){
					tracker[trackerCount] = items[j];
					trackerCount++;
				} 
	//end for loops
				// count frequency of this item in first array
				int countMain = getFrequencyOf(items[i]);
				// count frequency of this item in second array
				int countInput = input.getFrequencyOf(items[i]);
				//compare frequencies
				int smaller = min(countMain, countInput); 
				// add this number of entries to the intersect array
				cout<<"The min is: "<<smaller<<endl; 
				for(int k=0; k<smaller; k++){
					theIntersect.add(items[i]);
					cout<<"Added item "<<k<<endl;
				}	
				/*
				theIntersect.items[theIntersect.itemCount] = items[j];
				theIntersect.itemCount++;
				cout<<"Item Count: "<<theIntersect.itemCount;
				*/
			}
	return theIntersect; 
}
