#include <iostream>
#include "list.h"

using namespace std;

void main()
{
	ElmentList* book = nullptr;
	readFile(book);
	int x = 0;
	do
	{
		cout << "\n1. Sort by number" << endl;
		cout << "2. Sort by name" << endl;
		cout << "3. Show list" << endl;
		cout << "0. Exit" << endl << endl;
		cout << "Number of operation : ";
		cin >> x;
		switch (x)
		{
		case 1:
			MergeSort(&book, 2);
			break;
		case 2:
			MergeSort(&book, 1);
			break;
		case 3:
			cout << endl;
			printList(book);
			break;
		}
	} while (x != 0);
	deleteList(book);
}