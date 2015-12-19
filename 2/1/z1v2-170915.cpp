#include <iostream>

using namespace std;

int main()
{
	int num = 0;
	cout << "Enter the number";
	cin >> num;
	if (num == 0) {
		cout << "it is " << 0;
		return 0;
	}
	else {
		int FibonacciNumber = 1;
		int oldFibonacciNumber = 1;
		for (int i = 2; i <= num; ++i)
		{
			if ((i == 1) || (i == 2))
			{
				FibonacciNumber = 1;
				oldFibonacciNumber = 1;
			}
			else {
				int Change = 0;
				Change = FibonacciNumber;
				FibonacciNumber = FibonacciNumber + oldFibonacciNumber;
				oldFibonacciNumber = Change;
			}

		}
		cout << "it is " << FibonacciNumber;
	}
	return 0;
}