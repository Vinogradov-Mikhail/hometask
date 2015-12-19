#include "Stack.h"

StackElement *makeElementofS(char value, StackElement *next)
{
	StackElement *newStackElement = new StackElement;
	newStackElement->value = value;
	newStackElement->next = next;
	return newStackElement;
}

Stack *createStack()
{
	Stack *newStack = new Stack;
	newStack->head = makeElementofS(0, nullptr);
	return newStack;
}

void addInStack(char value, Stack *stack)
{
	StackElement *newStackElement = makeElementofS(value, stack->head->next);
	stack->head->next = newStackElement;
}

char deleteStackEl(Stack *stack)
{
	char result = stack->head->next->value;
	StackElement *stackElement = stack->head->next;
	stack->head->next = stack->head->next->next;
	delete stackElement;
	return result;
}

char returnStackElement(Stack *stack)
{
	return stack->head->next->value;
}

bool stackEmpty(Stack *stack)
{
	return stack->head->next == nullptr;
}

void deleteStack(Stack *stack)
{
	while (!stackEmpty(stack))
		deleteStackEl(stack);
	delete stack->head;
	delete stack;
}
