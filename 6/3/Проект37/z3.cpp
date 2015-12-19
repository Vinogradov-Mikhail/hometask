#include "workWithSpis.h"
#include <iostream>
#include <stdio.h>
#include <conio.h>

using namespace std;

void gameWar(ElementList *top, int amount, int gap)
{
	for (int i = 1; i <= amount; ++i)
	{
		add(top, i);
	}
	print(top);
	del(top, amount, gap);
	print(top);
}

int main()
{
	ElementList *top = NULL;
	setlocale(LC_ALL, "Rus");
	int amount = 0; 
	int gap = 0;
	cout << "\nКоличество воинов > ";
	cin >> amount;
	cout << "\nШаг > ";
	cin >> gap;
	gameWar(top, amount, gap);
	deleteList(top);
	system("pause");
	return 0;
}

