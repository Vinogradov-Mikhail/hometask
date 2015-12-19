#include <iostream>
#include <string>
#include <sstream>
#include "workWithStack.h"
#include "stack.h"

using namespace std;

void addElement(string num, Stack *&stack)
{
	Stack *temp = new Stack;
	temp->number = num;
	temp->Next = stack->Head;
	stack->Head = temp;
}

void delElement(Stack *stack)
{
	Stack *temp = stack->Head->Next;
	delete stack->Head;
	stack->Head = temp;
}

bool check(Stack *stack, string str)
{
	for (int i = 0; i < str.size(); ++i)
	{
		if ((str[i] == '(') || (str[i] == '{') || (str[i] == '['))
		{
			string str2;
			str2 = str[i];
			addElement(str2, stack);
		}
		else
		{ 
			if (stack->Head == NULL)
			{
				return false;
			}
			string temp = stack->Head->number; 
			delElement(stack);
			if (((temp[0] == '(') && (str[i] != ')')) || ((temp[0] == '{') && (str[i] != '}')) || ((temp[0] == '[') && (str[i] != ']')))
			{
				return false;
			}
		}
	}
	return (stack->Head == NULL);
}

void delStack(Stack*& stack)
{
	while (stack->Head->Next)
	{
		delElement(stack);
	}
	delete stack->Head;
	delete stack;
}