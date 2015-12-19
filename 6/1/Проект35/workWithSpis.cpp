
#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>
#include <conio.h> 
#include "workWithSpis.h"

using namespace std;

struct ElementList
{
	string data;
	string num;
	ElementList *next;
	ElementList *prev;
};

void addList(ElementList *&top, string const name, string const number, int const position)
{
	ElementList *node = new ElementList;
	node->data = name;
	node->num = number;
	if (top == NULL)
	{
		node->next = node;
		node->prev = node;
		top = node;
	}
	else
	{
		ElementList *past = top;
		for (int i = position; i > 1; i--)
		{
			past = past->next;
		}
		if (past == top)
		{
			node->next = top;
			top = node;
		}
		past->prev->next = node;
		node->prev = past->prev;
		node->next = past;
		past->prev = node;
	}
}

int readFile(ElementList *&top)
{
	string name;
	string number;
	ifstream file("accounts.txt", ios::in);
	if (!file)
	{
		cout << "Файл не найден" << endl;
		return 1;
	}
	ElementList *node = new ElementList;
	while (!file.eof())
	{
		string subString;
		getline(file, subString);
		string subString2;
		int check = 0;
		for (int i = 0; i < subString.size(); ++i)
		{
			if (subString[i] == ' ')
			{
				++check;
				if (check % 2 != 0)
				{
					name = subString2;
					subString2 = "";
				}
				else
				{
					number = subString2;
					addList(top, name, number, 1);
					subString2 = "";
				}
			}
			else
			{
				subString2 += subString[i];
			}
		}
	}
	file.close();
	return 0;
}

int deleteList(ElementList *&top, int position)
{
	if (top == NULL)
	{
		cout << "\nСписок пуст\n\n";
		return 0;
	}
	if (top == top->next)
	{
		delete top;
		top = NULL;
	}
	else
	{
		ElementList *a = top;
		for (int i = position; i > 1; i--)
		{
			a = a->next;
		}
		if (a == top)
		{
			top = a->next;

		}
		a->prev->next = a->next;
		a->next->prev = a->prev;
		delete a;
	}
	return 0;
}

void searchName(ElementList *top, string const name)
{
	ElementList *elem = top;
	cout << "Такие номера найдены на это имя :" << endl;
	do
	{
		if (elem->data == name)
		{
			cout << "--" << elem->num << endl;
		}
		elem = elem->next;
	} while (elem != top);
	cout << endl << endl;
}

void searchNumber(ElementList *top, string const number)
{
	ElementList *elem = top;
	cout << "Такие имена найдены на этот номер :" << endl;
	do
	{
		if (elem->num == number)
		{
			cout << "--" << elem->data << endl;
		}
		elem = elem->next;
	} while (elem != top);
	cout << endl << endl;
}

void rewrite(ElementList *top)
{
	ofstream file("accounts.txt");
	ElementList *elem = top;
	cout << "\nЭлементы списка: ";
	do
	{
		file << elem->data;
		file << " ";
		file << elem->num;
		file << " ";
		elem = elem->next;
	} while (elem != top);
	file.close();
}

void deleteAll(ElementList *top)
{
	do
	{
		deleteList(top, 1);
	} while (top != NULL);
}