
#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include "QSORT.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");
	int size = 0;
	int array[10000] = {};
	fstream file;
	file.open("accounts.txt");
	if (file)
	{
		while (!file.eof())
		{
			file >> array[size];
			cout << array[size] << " ";
			++size;
		}
		quickSort(array, 0, size - 1);
		file.close();
	}
	else
	{
		cout << " Файл не существует" << endl;
	}
	cout << endl << endl;
	for (int i = 0; i < size; ++i)
	{
		cout << array[i] << " ";
	}
	system("pause");
	return 0;
}