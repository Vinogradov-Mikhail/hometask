#include <iostream> 
#include <string> 
#include <fstream>
#include "List.h"

using namespace std;

void push(DictionaryElement *&element, string name)
{
	DictionaryElement *&currentEl = element;
	if (currentEl == nullptr)
	{
		DictionaryElement *newElement = new DictionaryElement;
		newElement->name = name;
		newElement->phone = 1;
		newElement->next = nullptr;
		currentEl = newElement;

	}
	else
	{
		DictionaryElement *newElement = new DictionaryElement;
		newElement->name = name;
		newElement->phone = 1;
		newElement->next = nullptr;
		currentEl->next = newElement;
	}
}

int hashFunction(string element)
{
	int symb = 0;
	for (int i = 0; i < element.length(); i++)
	{
		symb += element[i];

	}
	return symb % amount;
}

Dictionary *createDic()
{
	Dictionary *dic = new Dictionary;
	for (int i = 0; i < amount; i++)
	{
		dic->array[i] = nullptr;
	}
	return dic;
}

void addition(Dictionary *dictionary, string const &name)
{
	int currentHash = hashFunction(name);
	DictionaryElement *&currHash = dictionary->array[currentHash];
	while (currHash)
	{
		if (currHash->name == name)
		{
			currHash->phone += 1;
			return;
		}
		currHash = currHash->next;
	}
	push(currHash, name);
}

void print(Dictionary *dictionary)
{
	for (int i = 1; i < amount; ++i)
	{
		DictionaryElement *currHash = dictionary->array[i];
		while (currHash)
		{
			cout << currHash->name << "---" << currHash->phone << endl;
			currHash = currHash->next;
		}
	}
}

void read(Dictionary *dict)
{
	ifstream file("test.txt", ios::in);
	if (!file)
	{
		cout << "Файл не найден" << endl;
		return;
	}
	while (!file.eof())
	{
		string subString;
		string subString2;
		getline(file, subString);
		for (int i = 0; i < subString.size(); ++i)
		{
			if ((subString[i] == ' ') || (subString[i] == '\n') || (subString[i] == '.') || (subString[i] == ',') 
					|| (subString[i] == '(') || (subString[i] == ')') || (subString[i] == ',') || (subString[i] == '"'))
			{
				addition(dict, subString2);
				subString2 = "";
			}
			else
			{
				if ((subString[i] != ' ') && (subString[i] != '(') && (subString[i] != '"'))
				{
					subString2 += subString[i];
				}
			}
		}
	}
	file.close();
}

void deleteDicElem(DictionaryElement *&elem)
{
	while (elem)
	{
		DictionaryElement *node = elem;
		elem = elem->next;
		delete node;
	}
}

void deleteDic(Dictionary *elem)
{
	for (int i = 0; i < amount; ++i)
	{
		deleteDicElem(elem->array[i]);
	}
	delete elem;
}