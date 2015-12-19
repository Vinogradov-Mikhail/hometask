
#include <stdio.h>
#include <iostream>
#include "Stack.h"
#include "Queue.h"
#include "changer.h"

using namespace std;

int main()
{
	setlocale(LC_CTYPE, "Russian");
	Stack *stack = createStack();
	Queue *queue = createQueue();
	char string = '0';
	cout << "¬ведите выражение:  ";
	changeForm(stack, queue, string);
	deleteQueue(queue);
	deleteStack(stack);
	system("pause");
}