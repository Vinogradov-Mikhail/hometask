#pragma once

struct StackElement
{
	char value;
	StackElement *next;
};

struct Stack
{
	StackElement *head;
};

StackElement *makeElementofS(char value, StackElement *next);

Stack *createStack();

void addInStack(char value, Stack *stack);

char deleteStackEl(Stack *stack);

char returnStackElement(Stack *stack);

bool stackEmpty(Stack *stack);

void deleteStack(Stack *stack);
