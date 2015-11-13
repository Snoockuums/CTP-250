// way #1
void ArrayBag<itemType>::union(ArrayBag<itemtype>&bag1, ArrayBag<itemtype> &bag2, ArrayBag<itemtype>&bag3)
{
	for(int i=0; i<bag1.itemCount; i++) // because you use the scope operator, you have access to the private data member itemCount in bag.
		bag3.add(bag1.items[i]);
	for(int i=0; i<bag2.itemCount; i++)
		bag3.add(bag2.items[i]);
}


// simpler way. 
bagC = bagA.union(bagB); 
	// rather than passing by reference, return a bag, and call on a bag. Then you're left with just one parameter.

// second way* better and easier. 
ArrayBag<itemType> ArrayBag<itemType> :: union(ArrayBag<itemtype> bag1){
	ArrayBag<itemtype> result; 
	for(int i=0; i<itemCount; i++) // because you use the scope operator, you have access to the private data member itemCount in bag.
		result.add(items[i]);
	for(int i=0; i<bag2.itemCount; i++)
		result.add(bag2.items[i]);
}

}


