#include <iostream>
#include <conio.h>
#include "workWithTr.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	Trees *Tree = NULL;  
	add(4, Tree);
	add(2, Tree);
	add(1, Tree);
	add(3, Tree);
	add(6, Tree);
	add(5, Tree);
	add(7, Tree);
	int x = 0;
	int num = 0;
	do
	{
		cout << "\n1. Добавить элемент" << endl;
		cout << "2. Удалить элемент" << endl;
		cout << "3. Вывести по убыванию" << endl;
		cout << "4. Вывести по возрастанию" << endl;
		cout << "5. Поиск элемента" << endl;
		cout << "0. Выйти" << endl;
		cout << "\nНомер операции > ";
		cin >> x;
		switch (x)
		{
		case 1:
			cout << "\nВведите значение > ";
			cin >> num;
			add(num, Tree);
			break;
		case 2:
			cout << "\nВведите значение > ";
			cin >> num;
			delElem(num, Tree);
			break;
		case 3:
			cout << endl;
			show(2, Tree);
			cout << endl;
			break;
		case 4:
			cout << endl;
			show(1, Tree);
			cout << endl;
			break;
		case 5:
			cout << "\nВведите значение > ";
			cin >> num;
			if (search(num, Tree))
			{
				cout << "\nЭлемент найден";
			}
			else
			{
				cout << "\nЭлемент не найден\n";
			}
		}
	} while (x != 0);
	cout << '\n';
	delTree(Tree);
}