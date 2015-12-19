#include <iostream>
#include <string>
#include <sstream>
//#include "stack.h"
#include "workWithStack.h"

using namespace std;

void algebra(string elemnt, Stack *&stack)
{
	int num = 0;
	for (int i = 0; i < elemnt.size(); ++i)
	{
		if ((elemnt[i] == '+') || (elemnt[i] == '-') || (elemnt[i] == '*') || (elemnt[i] == '/'))
		{
			switch (elemnt[i])
			{
			case '+':
			{
				int sum = pop(stack) + pop(stack);
				push(sum, stack);
				break;
			}
			case '-':
			{
				int num1 = pop(stack);
				int num2 = pop(stack);
				int  diff = num2 - num1;
				push(diff, stack);
				break;
			}
			case '*':
			{
				int mult = pop(stack) * pop(stack);				
				push(mult, stack);
				break;
			}
			case '/':
			{
				int num1 = pop(stack);
				int num2 = pop(stack);
				int degree = num2 / num1;
				push(degree, stack);
				break;
			}
			}
		}
		else
		{
			string sub;
			sub = elemnt[i];
			istringstream ist(sub);
			ist >> num;
			push(num, stack);
		}
	}
}

int main()
{
	Stack *stack = createStack();
	string str;
	cout << "Write expression <\n";
	cin >> str;
	algebra(str, stack);
	cout << "=";
	showResult(stack);
	delStack(stack);
}