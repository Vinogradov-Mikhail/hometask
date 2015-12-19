#include <iostream>

using namespace std;

void insertSort(int* array, int right)
{
	for (int i = 0; i < right; i++)
	{
		int change = array[i];
		int j = i - 1;
		while ((j >= 0) && (array[j] > change))
		{
			array[j + 1] = array[j];
			--j;
		}
		array[j + 1] = change;
	}
}

void quickSort(int* array, int left, int right)
{
	int leftTwo = left;
	int rightTwo = right;
	int const pivotal = array[left + (right - left) / 2];
	if ((right - left) < 10)
	{
		insertSort(array, right);
	}
	else
	{
		while (leftTwo <= rightTwo)
		{
			while (array[leftTwo] < pivotal)
			{
				++leftTwo;
			}
			while (array[rightTwo] > pivotal)
			{
				--rightTwo;
			}
			if (leftTwo <= rightTwo)
			{
				swap(array[leftTwo], array[rightTwo]);
				++leftTwo;
				--rightTwo;
			}
		}

		if (left < leftTwo)
		{
			quickSort(array, left, rightTwo);
		}

		if (leftTwo < right)
		{
			quickSort(array, leftTwo, right);
		}
	}
}