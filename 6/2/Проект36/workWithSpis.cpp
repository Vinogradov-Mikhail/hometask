
#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>
#include <conio.h> 
#include "workWithSpis.h"

using namespace std;

struct ElementList
{
	int data;
	ElementList *next;
	ElementList *prev;
};

void addList(ElementList *&top, int number)
{
	ElementList *node = new ElementList;
	node->data = number;
	if (top == NULL)
	{
		node->next = node;
		node->prev = node;
		top = node;
	}
	else
	{
		ElementList *past = top;
		past = past->next;
		past->prev->next = node;
		node->prev = past->prev;
		node->next = past;
		past->prev = node;
	}
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
		ElementList *temp = top;
		for (int i = position; i > 1; i--)
		{
			temp = temp->next;
		}
		if (temp == top)
		{
			top = temp->next;
		}
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		delete temp;
	}
	return 1;
}

void searchForDel(ElementList *&top, int number)
{
	ElementList *temp = top;
	int i = 1;
	do
	{
		ElementList *pot = temp;
		if (temp->data == number)
		{
			if (top == top->next)
			{
				delete top;
				top = NULL;
			}
			else
			{
				if (temp == top)
				{
					top = temp->next;
				}
				temp->prev->next = temp->next;
				temp->next->prev = temp->prev;
				pot = temp->prev;
				delete temp;
			}
		}
		temp = pot->next;
	} while (temp != top);
}


void sortList(ElementList *&top)
{

	ElementList * list = top; 
	for (ElementList *node = list; node->next != top; node = node->next)
	{
		for (ElementList *node2 = list; node2->next != top; node2 = node2->next)
		{
			if (node2->data > node2->next->data)
			{
				int i = node2->data;
				node2->data = node2->next->data;
				node2->next->data = i;
			}
		}
	}
}

void printList(ElementList *top)
{
	if (top == NULL)
	{
		cout << "\nСписок пуст\n\n";
	}
	else
	{
		ElementList *temp = top;
		cout << "\nЭлементы списка: ";
		do
		{
			cout << temp->data << " ";
			temp = temp->next;
		} while (temp != top); 
		cout << endl << endl;
	}
}

void deleteAll(ElementList *top)
{
	do
	{
		deleteList(top, 1);
	} while (top != NULL);
}