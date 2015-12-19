#pragma once

struct StackElement
{
	int number;
	StackElement *next;
};

struct Stack
{
	StackElement *head;
};
