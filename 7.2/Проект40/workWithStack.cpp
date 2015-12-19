#include <iostream>
#include <string>
#include <sstream>
#include "workWithStack.h"
#include "stack.h"

using namespace std;

Stack *createStack()
{
	Stack *stack = new Stack;
	stack->head = nullptr;
	return stack;
}

void push(int x, Stack *stack)
{
	StackElement *temp = new StackElement;
	temp->number = x;
	temp->next = stack->head;
	stack->head = temp;
}

int pop(Stack *stack)
{
	int num = stack->head->number;
	StackElement *temp = stack->head->next;
	delete stack->head;
	stack->head = temp;
	return num;
}

void showResult(Stack *stack)
{
	StackElement *temp = stack->head;
	while (temp != NULL)
	{
		cout << temp->number << " ";
		temp = temp->next;
	}
}

void delStack(Stack *&stack)
{
	while (stack->head->next)
	{
		pop(stack);
	}
	delete stack->head;
	delete stack;
}