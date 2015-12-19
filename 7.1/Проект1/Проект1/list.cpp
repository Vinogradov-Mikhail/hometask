#include "list.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

struct ElmentList
{
	int data;
	std::string name;
	ElmentList* next;
};

void printList(ElmentList *book)
{
	while (book != NULL)
	{
		cout << "number: " << book->data << " name: " << book->name << endl;
		book = book->next;
	}
}

void push(ElmentList*& book, string name, int number)
{
	ElmentList *newElement = new ElmentList;
	newElement->data = number;
	newElement->name = name;
	newElement->next = book;
	book = newElement;
}


int readFile(ElmentList*& book)
{
	ifstream file("accounts.txt", ios::in);
	if (!file)
	{
		cout << "Файл не найден" << endl;
		return 1;
	}
	while (!file.eof())
	{
		string subString;
		getline(file, subString);
		string subString2;
		string name;
		int number;
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
					istringstream ist(subString2);
					ist >> number;
					push(book, name, number);
					subString2 = "";
					name = "";
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

ElmentList* SortedMerge(ElmentList* first, ElmentList* last, int check)
{
	ElmentList* result = NULL;
	if (first == NULL)
	{
		return last;
	}
	else
	{
		if (last == NULL)
		{
			return first;
		}
	}
	if (check == 1)
	{
		if (first->name <= last->name)
		{
			result = first;
			result->next = SortedMerge(first->next, last, 1);
		}
		else
		{
			result = last;
			result->next = SortedMerge(first, last->next, 1);
		}
	}
	else
	{
		if (first->data <= last->data)
		{
			result = first;
			result->next = SortedMerge(first->next, last, 2);
		}
		else
		{
			result = last;
			result->next = SortedMerge(first, last->next, 2);
		}
	}
	return result;
}

void FrontBackSplit(ElmentList* book, ElmentList** front, ElmentList** back)
{
	ElmentList* fast;
	ElmentList* slow;
	if (book == NULL || book->next == NULL)
	{
		*front = book;
		*back = NULL;
	}
	else
	{
		slow = book;
		fast = book->next;
		while (fast != NULL)
		{
			fast = fast->next;
			if (fast != NULL)
			{
				slow = slow->next;
				fast = fast->next;
			}
		}
		*front = book;
		*back = slow->next;
		slow->next = NULL;
	}
}



void MergeSort(ElmentList** mind, int variant)
{
	ElmentList* head = *mind;
	ElmentList* a;
	ElmentList* b;
	if ((head == NULL) || (head->next == NULL))
	{
		return;
	}
	FrontBackSplit(head, &a, &b);
	MergeSort(&a, variant);
	MergeSort(&b, variant);
	*mind = SortedMerge(a, b, variant);
}

void deleteList(ElmentList*& book) //удалить все элементы списка
{
	while (book != NULL)
	{
		ElmentList *p = book;
		book = book->next;
		delete p;
	}
}