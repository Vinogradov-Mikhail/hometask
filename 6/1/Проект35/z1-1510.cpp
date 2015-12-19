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
	ElementList *top = nullptr;
	string name;
	string number;
	int x = 0;
	readFile(top);
	do
	{
		cout << "1. Добавить элемент" << endl;
		cout << "2. Найти номер по имени" << endl;
		cout << "3. Найти имя по номеру" << endl;
		cout << "4. сохранить текущие данные в файл" << endl;
		cout << "0. Выйти" << endl << endl;
		cout << "Номер операции : ";
		cin >> x;
		switch (x)
		{
		case 1:
			cout << "Имя :  ";
			cin >> name;
			cout << "Номер : ";
			cin >> number;
			addList(top, name, number, 1);
			break;
		case 2:
			cout << " Имя для поиска : ";
			cin >> name;
			searchName(top, name);
			break;
		case 3:
			cout << " Телефон для поиска : ";
			cin >> number;
			searchNumber(top, number);
			break;
		case 4:
			rewrite(top);
			cout << "Файл обновлен" << endl;
		}
	} while (x != 0);
	deleteAll(top);
}

