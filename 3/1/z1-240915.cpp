#include <iostream>

using namespace std;

void inSort(int* array, int left, int right)
{
	for (int i = left; i < right; ++i)
	{
		int key = i + 1;
		int change = array[key];
		for (int j = i + 1; j > 0; --j)
		{
			if (change < array[j - 1])
			{
				array[j] = array[j - 1];
				key = j - 1;
			}
		}
		array[key] = change;
	}
}

void quickSort(int* array, int left, int right)
{
	int leftTwo = left;
	int rightTwo = right;
	int const pivotal = array[left + (right - left) / 2];
    if ((right - left) < 10) 
	{
		inSort(array, left, right);
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
				swap(array[leftTwo],array[rightTwo]);
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

int main()
{
	int const n = 30;
	int array[n];
	for (int i = 0; i < n; ++i)
	{
		array[i] = rand() % 10;
	}
	for (int i = 0; i < n; ++i)
	{
		cout << i + 1 << " --- " << array[i] << endl;		
	}
	cout << "==========" << endl;
	int left = 0;
	int right = n - 1;
	quickSort(array, left, right);
	for (int i = 0; i < n; ++i)
	{
		cout << i + 1 << " --- " << array[i] << endl;
	}
	return 0;
}