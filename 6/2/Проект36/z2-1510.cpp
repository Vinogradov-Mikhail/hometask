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
		cout << "1. �������� �������" << endl;
		cout << "2. ������� �������" << endl;
		cout << "3. ������� ������" << endl;
		cout << "0. �����" << endl;
		cout << "\n����� �������� > "; 
		cin >> x;
		switch (x)
		{
		case 1:
			cout << "�������� > "; 
			cin >> value;
			addList(top, value); 
			sortList(top);
			break;
		case 2:
			cout << "�������� > "; 
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