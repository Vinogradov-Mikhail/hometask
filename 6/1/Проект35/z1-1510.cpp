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
		cout << "1. �������� �������" << endl;
		cout << "2. ����� ����� �� �����" << endl;
		cout << "3. ����� ��� �� ������" << endl;
		cout << "4. ��������� ������� ������ � ����" << endl;
		cout << "0. �����" << endl << endl;
		cout << "����� �������� : ";
		cin >> x;
		switch (x)
		{
		case 1:
			cout << "��� :  ";
			cin >> name;
			cout << "����� : ";
			cin >> number;
			addList(top, name, number, 1);
			break;
		case 2:
			cout << " ��� ��� ������ : ";
			cin >> name;
			searchName(top, name);
			break;
		case 3:
			cout << " ������� ��� ������ : ";
			cin >> number;
			searchNumber(top, number);
			break;
		case 4:
			rewrite(top);
			cout << "���� ��������" << endl;
		}
	} while (x != 0);
	deleteAll(top);
}

