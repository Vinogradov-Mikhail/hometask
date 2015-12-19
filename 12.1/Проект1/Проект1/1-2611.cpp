#include <iostream>
#include <string.h>
#include <time.h>
#include <stdlib.h>

using namespace std;

int searchStr(char str[], char subStr[])
{
	int sizeStr = strlen(str);
	int sizeSubStr = strlen(subStr);
	int *dynamic = new int[sizeSubStr * sizeof(int)];
	dynamic[0] = -1;
	int i = 0;
	int j = -1;
	while (i < sizeSubStr - 1)
	{
		while ((j >= 0) && (subStr[j] != subStr[i]))
		{
			j = dynamic[j];
		}
		++i;
		++j;
		if (subStr[i] == subStr[j])
		{
			dynamic[i] = dynamic[j];
		}
		else
		{
			dynamic[i] = j;
		}
	}
	for (i = 0, j = 0; (i < sizeStr) && (j < sizeSubStr); ++i, ++j)
	{
		while ((j >= 0) && (subStr[j] != str[i]))
		{
			j = dynamic[j];
		}
	}
	delete dynamic;  
	if (j == sizeSubStr)
	{
		return i - j + 1;
	}
	else
	{
		return -1;
	}
}

void print(char str[], char subStre[])
{
	int numSymbol = searchStr(str, subStre);
	if (numSymbol == -1)
	{
		cout << "\n�� �������\n\n";
	}
	else
	{
		cout << "\n��������� ���������� � " << numSymbol << " �������\n\n";
	}
}

void main()
{
	setlocale(LC_ALL, "Russian");
	const int n = 10;
	char str[256];
	char subStre[256];
	cout << "������� ������:\n";
	cin.getline(str, 256);
	cout << "\n������� ��������� ��� ������:\n";
	cin >> subStre;
	print(str, subStre);
	system("pause");
}