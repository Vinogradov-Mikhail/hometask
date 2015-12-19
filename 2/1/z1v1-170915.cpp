#include <iostream>

using namespace std;

int fibonacci(int number1)
{
	if (number1 == 1 || number1 == 2) {
		return 1;
	}
	else {
		return  fibonacci(number1 - 1) + fibonacci(number1 - 2);
	}
}

int main()
{
	int number = 0;
	cout << "enter the number";
	cin >> number;
	cout << fibonacci(number);
	return 0;
}