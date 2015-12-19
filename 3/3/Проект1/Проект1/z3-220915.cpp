#include <iostream>

using namespace std;

int const lengthArray = 10;

void quickSort(int* array, int left, int right)
{
	int leftTwo = left;
	int rightTwo = right;
	int const pivotal = array[left + (right - left) / 2];
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

int search(int* array, int lengthArray)
{
	int maxLine = 0;
	int numMax = 0;
	int check = array[0];
	int subMax = 1;
	for (int i = 1; i < lengthArray; ++i)
	{
		if (array[i] == check)
		{
			++subMax; 
		}
		else
		{
			if (subMax > maxLine)
			{
				maxLine = subMax; 
				numMax = check; 
			}
			subMax = 1;
			check = array[i]; 
		}
		if (array[i] == array[lengthArray - 1])
		{
			if (subMax > maxLine)
			{
				maxLine = subMax;
				numMax = check;
			}
		}
	}
	return numMax;
}

int main()
{
	int array[lengthArray] = {};
	for (int i = 0; i < lengthArray; ++i)
	{
		cout << i + 1 << " --- ";
		cin >> array[i];
	}
	for (int i = 0; i < lengthArray; ++i)
	{
		cout << i + 1 << " --- " << array[i] << endl;
	}
	cout << "==========" << endl;
	int left = 0;
	int right = lengthArray - 1;
	quickSort(array, left, right);
	for (int i = 0; i < lengthArray; ++i)
	{
		cout << i + 1 << " --- " << array[i] << endl;
	}
	cout << "==========" << endl;
	cout << search(array, lengthArray) << " is the most common element in the array" << endl;
	cin.get();
	cin.get();
	return 0; // i enter:  1 2 3 4 4 5 5 5 5 5  out: 5 is most; and enter: 11 1 11 11 0 0 0 0 0 0 out: 0 is most 
}