#include <iostream>
#include "Main.h"
#include <ctime>
#include <string>
#include "QuickSort.h"
#include "BinarySearch.h"

Main::Main()
{
}


Main::~Main()
{
}

using namespace std;

int main()
{
	// Global Variables
	const int ARRAY_SIZE = 1000;
	const int RAND_LIMIT = 1000;
	int arr[ARRAY_SIZE];
	QuickSort quickSort;
	BinarySearch bSearch;
	char input[10];
	int indexFound = -1;

	cout << "Creating array of " << ARRAY_SIZE << " elements between 0 and " << RAND_LIMIT << endl;

	srand(time(0));
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		arr[i] = (rand() % (RAND_LIMIT + 1));
	}

	cout << "Sorting array from smallest to largest. \n\n";
	int len = sizeof(arr) / sizeof(arr[0]);

	quickSort.quicksort(arr, 0, (len-1), len);

	cout << "The array has been sorted and the first 20 elements are: \n";
	for (int i = 0; i < 20; i++)
	{
		cout << arr[i] << "\t";
	}

	do
	{
		cout << "\n\nEnter a number between 0 and " << RAND_LIMIT << " to search for in the array or a character to exit: ";
		cin >> input;

		int search;
		if (isdigit(input[0]))
		{
			search = atoi(input);
		}
		else
		{
			continue;
		}

		if ((search < 1001) && (search >= 0))
		{
			bSearch.binarysearch(arr, 0, (len - 1), search, indexFound);
		}
		else
		{
			cout << "Invalid entry!\n";
			continue;
		}

		if (indexFound != -1)
		{
			cout << "\nValue " << input << " was found at the " << indexFound << " position in the array.\n";
		}
		else
		{
			cout << "\nValue " << input << " was not found.\n";
		}
		indexFound = -1;

	} while (isdigit(input[0]));

	return 0;
}