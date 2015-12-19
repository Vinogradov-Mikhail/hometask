#include <iostream>

using namespace std;

void bubble(int* Array, int n) //сортировка пузырьком
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n - 1; ++j)
		{
			if (Array[j] > Array[j + 1])
			{
				swap(Array[j], Array[j + 1]);
			}
		}
	}
}

int maximum(int* subArrayTwo, int n)// находим максимум, чтобы понять из скольки элементов делать дополнительный массив
{
	int max = subArrayTwo[0];
	for (int i = 1; i < n; ++i)
	{
		if (subArrayTwo[i] > max)
		{
			max = subArrayTwo[i];
		}
	}
	return max;
}

void counting(int* subArray, int n)//сортировка подсчетом
{
	int max = maximum(subArray, n);

	int countArray[1000];

	for (int i = 0; i <= max; ++i)
	{
		countArray[i] = 0;
	}
	for (int i = 0; i < n; ++i) {
		++countArray[subArray[i]];
	}
	int i = 0;
	for (int j = 1; j <= max; j++) 
	{
		while (countArray[j] != 0) 
		{
			subArray[i] = j;
			--countArray[j];
			++i;
		}
	}
}

int main()
{
	int const n = 7;
	int Array[n];
	for (int i = 0; i < n; ++i)
	{
		cout << i + 1 << " --- ";
		cin >> Array[i];
	}
	cout << "----------------" << endl;
    //bubble(Array, n); // пузырек
	counting(Array, n); // подсчет
	for (int i = 0; i < n; ++i)
	{
		cout << i + 1 << " --- " << Array[i] << endl;
	}
	return 0; // enter : 1 1 5 6 2 2 1  -  out : 1 1 1 2 2 5 6 ; enter :  9 8 7 6 5 5 4  -  out : 4 5 5 6 7 8 9 
}