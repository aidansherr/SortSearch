#include "QuickSort.h"



QuickSort::QuickSort()
{
}


QuickSort::~QuickSort()
{
}


// Sort elements of an array by choosing a mid point and splitting and sorting data recursively
void QuickSort::quicksort(int * arr, int start, int end, int len)
{
	if (start >= end)
	{
		return;
	}

	int splitPoint = split(arr, start, end);	  // find spliting point

	quicksort(arr, start, (splitPoint - 1), len); // sort beginning
	quicksort(arr, (splitPoint + 1), end, len);	  // sort end
}


// Used to swap two values
void QuickSort::Swap(int * arr, int i, int j)
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

// Split the data
int QuickSort::split(int * arr, int start, int end)
{
	int mid = (start + end)/ 2;
	int splitValue = arr[mid];

	Swap(arr, mid, start);							// move the mid point value to the front
	int i = (start + 1);							// now start after the mid point value
	int j = end;
	while (i <= j) {
		while ((i <= j) && (arr[i] <= splitValue))	// in order, move on to next one (working from beginning)
		{
			i++;
		}

		while ((i <= j) && (arr[j] > splitValue))	// in order, move on to previous value (working from end)
		{
			j--;
		}

		if (i < j)									
		{
			Swap(arr, i, j);						// swap the values
		}
	}
	Swap(arr, (i-1), start);						// put mid point nack in it's place
	return (i - 1);									// return mid point
}
