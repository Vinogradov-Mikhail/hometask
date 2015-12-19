#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>
#include <conio.h> 
#include "workWithSpis.h"

using namespace std;

void main()
{

	setlocale(LC_ALL, "Rus");
	ElementList *top = NULL;
	int value = 0;
	int x = 0;
	do
	{
		cout << "1. Добавить элемент" << endl;
		cout << "2. Удалить элемент" << endl;
		cout << "3. Вывести список" << endl;
		cout << "0. Выйти" << endl;
		cout << "\nНомер операции > "; 
		cin >> x;
		switch (x)
		{
		case 1:
			cout << "Значение > "; 
			cin >> value;
			addList(top, value); 
			sortList(top);
			break;
		case 2:
			cout << "Значение > "; 
			cin >> value;
			searchForDel(top, value);
			//deleteList(top, value);
			break;
		case 3: 
			printList(top); 
			break;
		}
	} while (x != 0);
	deleteAll(top);
}