#pragma once
#include <string> 

int const amount = 1000;

struct DictionaryElement
{
	std::string name;
	int phone;
	DictionaryElement *next;
};

struct Dictionary
{
	DictionaryElement *array[amount];
};
