#include <iostream>
#include <string>
#include <sstream>
#include <string>
#include "workWithStack.h"
#include "stack.h"

using namespace std;

void main()
{
	Stack *stack = new Stack;
	stack->Head = NULL;
	string s;
	cout << "wtite <\n";
	cin >> s;
	if (check(stack, s))
	{
		cout << "Correct" << endl;
	}
	else
	{
		cout << "Not correct" << endl;
	}
	delete stack->Head;
	delete stack;
}