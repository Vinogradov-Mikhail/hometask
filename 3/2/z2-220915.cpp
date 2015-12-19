#include <iostream>

using namespace std;

int const n = 5000;

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

int binSearch(int number, int* subArray, int lengthArray)
{
	int left = 0;
	int right = lengthArray;
	while (left <= right)
	{
		int pivotal = (left + right) / 2;
		if (number < subArray[pivotal])
		{
			right = pivotal - 1;
		}
		else
		{
			if (number > subArray[pivotal])
			{
				left = pivotal + 1;
			}
			else
			{
				return 0;
			}
		}
	}
    return -1;
}
int main()
{
	long lengthArray = 0;
	long long amountNum = 0;
	cout << "Enter length of array( >= 1 and <= 5000) " << endl;
	cin >> lengthArray;
	cout << "Enter amount of numbers( >= 1 and <= 300000) " << endl;
	cin >> amountNum;
	int array[n];
	for (int i = 0; i < lengthArray; ++i)
	{
		array[i] = rand() % 1000000000 + 1;
	}
	int left = 0;
	int right = lengthArray - 1;
	quickSort(array, left, right);	
	for (int i = 0; i < amountNum; ++i)
	{
		long number = rand() % 1000000000 + 1;
		if (binSearch(number, array, lengthArray) == 0)
		{
			cout << number << "----- found" << endl;
		}
		else
		{
			cout << number << "----- not found" << endl;
		}
	}
	system("pause");
	return 0;
}