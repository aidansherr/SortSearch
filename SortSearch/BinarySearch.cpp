#include "BinarySearch.h"



BinarySearch::BinarySearch()
{
}


BinarySearch::~BinarySearch()
{
}

void BinarySearch::binarysearch(int arr[], int start, int end, int searchVal, int & index)
{
	if (end >= start)
	{
		int mid = start + ((end - start) / 2);		// find mid point

		if (arr[mid] == searchVal)					// if found at mid point, set index to mid
		{
			index = mid;
		}

		if (arr[mid] > searchVal)					// if mid point is greater, search beginning half of array
		{
			binarysearch(arr, start, (mid - 1), searchVal, index);
		}
		else										// mid point is smaller, search last half of array
		{
			binarysearch(arr, (mid + 1), end, searchVal, index);
		}
	}

	return;
}
