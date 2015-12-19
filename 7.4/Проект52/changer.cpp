#define _CRT_SECURE_NO_WARNINGS
#include "changer.h"
#include <stdio.h>
#include <iostream>

using namespace std;

bool plusMinus(Stack *&storage)
{
	return (returnStackElement(storage) == '-' || returnStackElement(storage) == '+');
}

bool umnoDelete(Stack *&storage)
{
	return (returnStackElement(storage) == '*' || returnStackElement(storage) == '/');
}

void changeForm(Stack *&stack, Queue *&queue, char string)
{
	bool check = true;
	while (string != '\n')
	{
		scanf("%c", &string);
		if ((string >= '0') && (string <= '9'))
		{
			addQueue(string, queue);
		}
		if (string == '(')
		{
			addInStack(string, stack);
		}
		if (string == '*' || string == '/')
		{
			while (!stackEmpty(stack) && umnoDelete(stack))
			{
				addQueue(deleteStackEl(stack), queue);
			}
			if (stackEmpty(stack) || plusMinus(stack) || returnStackElement(stack) == '(')
			{
				addInStack(string, stack);
			}
		}
		if (string == '+' || string == '-')
		{
			while (!stackEmpty(stack) && (umnoDelete(stack) || plusMinus(stack)))
			{
				addQueue(deleteStackEl(stack), queue);
			}
			if (stackEmpty(stack) || returnStackElement(stack) == '(')
			{
				addInStack(string, stack);
			}
		}
		if (string == ')')
		{
			while (!stackEmpty(stack) && (umnoDelete(stack) || plusMinus(stack)))
			{
				addQueue(deleteStackEl(stack), queue);
			}
			if (stackEmpty(stack))
			{
				cout << "не соблюдается баланс скобок\n\n";
				check = false;
				break;
			}
			if (returnStackElement(stack) == '(')
			{
				deleteStackEl(stack);
			}
		}
		if (string == '\n')
		{
			while (!stackEmpty(stack) && (umnoDelete(stack) || plusMinus(stack)))
			{
				addQueue(deleteStackEl(stack), queue);
			}
			if (!stackEmpty(stack) && returnStackElement(stack) == '(')
			{
				cout << "не соблюдается баланс скобок\n\n";
				check = false;
				break;
			}
		}
	}
	if (check)
	{
		cout << "\nПостфиксная запись: ";
		while (!queueEmpty(queue))
		{
			cout << deleteQueueEl(queue);
		}
		cout << endl << endl;
	}
}