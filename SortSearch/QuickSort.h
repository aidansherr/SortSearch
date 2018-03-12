#pragma once
class QuickSort
{
public:
	QuickSort();
	~QuickSort();

	void quicksort(int * arr, int start, int end, int len);
	void Swap(int * arr, int i, int j);
	int split(int * arr, int start, int end);
};

