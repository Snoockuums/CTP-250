int binarySearch(const int anArray[], int start, int end, int target)
{
	int index;
	if (start > end)
		index = -1;
	else
	{
		int mid = start + (end - start) /2;
		if (target == anArray[mid])
			index = mid; //FOUND
		else if (target < anArray[mid])
			index = binarySearch(anArray, start, mid-1, target);
			else
				index = binarySearch(anArray, mid+1, end, target);
	}
	return index; 
}

/**

binary search pseudocode 
find middle.
if target = middle, stop.
if target != middle{
	if target is less than middle, examine the upper half.
	otherwise (target is > middle) examine the lower half.
return the answer. 

*/

