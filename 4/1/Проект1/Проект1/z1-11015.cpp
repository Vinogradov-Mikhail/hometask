#include <iostream>
#include <stdio.h>
#include <sstream>

using namespace std;

void binDec(int* bin, int size)
{
	int rez = 0;
	cout << "\nДесятичное число: ";
	for (int i = size - 1; i > 0; --i)
		rez += (bin[i]) << i;
    cout << rez << endl;
}

int* decBin(int number, int size)
{
	int* bin = new int[size];
	cout << "Двоичный код:  ";
	for (int i = size - 1; i >= 0; --i)
	{
		if (!((i + 1) % 4))
		{
			cout << " ";
		}
		bin[i] = (number >> i) & 1;
		cout << static_cast<int>((number >> i) & 1);
	}
	cout << endl;
	return bin;
}

void addition(int* binOne, int* binTwo, int size)
{
	int *add = new int[size];
	int *binThree = new int[size + 1];
	for (int i = 0; i < size; i++)
	{
		binThree[i] = 0;
	}
	for (int i = 0; i < size; i++)
	{
		add[i] = binOne[i] + binTwo[i] + binThree[i];
		if (add[i] == 2)
		{
			add[i] = 0;
			binThree[i + 1]++;
		}
		if (add[i] > 2)
		{
			add[i] = 1;
			binThree[i + 1]++;
		}
	}
	cout << endl << "Двоичный код суммы:  ";
	for (int i = size - 1; i >= 0 ; --i)
	{
		if (!((i + 1) % 4))
		{
			cout << " ";
		}
		cout << add[i];
	}
	binDec(add, size);
	delete binThree;
	delete add;
	delete binOne;
	delete binTwo;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int numberOne = 0;
	int numberTwo = 0;
	int const size = sizeof(numberOne) * 8;
	cout << "Введите первое число: ";
	cin >> numberOne;
	cout << "Введите второе число: ";
	cin >> numberTwo;
	cout << endl;
	addition(decBin(numberTwo, size), decBin(numberOne, size), size);
	system("pause");
	return 0; // num1 : 111 num2 : 11   bin 1: 110 111  bin2: 1011 addInBin: 111 1010  add10: 122
}