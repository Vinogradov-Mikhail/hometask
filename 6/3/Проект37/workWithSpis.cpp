#include "workWithSpis.h"
#include <iostream>
#include <stdio.h>
#include <conio.h>

using namespace std;

struct ElementList
{
	int data;
	ElementList *next;
};


void add(ElementList *&top, int num)
{
	ElementList *newList = new ElementList;
	newList->data = num;
	if (top)
	{
		newList->next = top->next;
		top->next = newList;
	}
	else
	{
		newList->next = newList;
	}
	top = newList;
}

void del(ElementList *&top, int amount, int gap)
{
	ElementList *temp = top;
	if (top == NULL)
	{
		cout << "\nСписок пуст\n\n";
		return;
	}
	int k = 0;
	while (temp->next != temp)
	{
		++k;
		if (k % gap == 0)
		{
			if (temp->next == top)
			{
				top = temp;
			}
			ElementList* delelem = temp->next;
			temp->next = temp->next->next;
			delete delelem;
			print(temp);
		}
		else
		{
			temp = temp->next;
		}
	}
}

void print(ElementList *top)
{
	ElementList *temp = top;
	cout << "\nОстанется воинs под номероми : ";
	do
	{
		temp = temp->next;
		cout << temp->data << " ";
	} while (temp != top);
	cout << endl << endl;

}

void deleteList(ElementList *&top)
{
	while (top != NULL)
	{
		if (top == NULL)
		{
			cout << "спиок пуст!" << endl;
		}
		else
		{
			ElementList *p = top;
			top = top->next;
			delete p;
		}
	}
}