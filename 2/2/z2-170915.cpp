#include <iostream>

using namespace std;

long degreeLog(int number, int power)
{
	long result = 1;
	if (power == 1)
	{
		return number;
	}
	if (power % 2 == 1)
	{
		result *= number;
	}
	long halfDegree = degreeLog(number, power / 2);
	result *= halfDegree * halfDegree;
	return result;
}

long degreeLine(int number, int power)
{
	if (power == 0)
	{
		return 1;
	}
	int result = number;
	for (int i = 1; i < power; ++i)
	{
		result *= number;
	}
	return result;
}

int main()
{
	int number = 0;
	int power = 0;
	cout << "enter the number" << endl;
	cin >> number;
	cout << "enter degree" << endl;
	cin >> power;
	//cout << "Result = " << degreeLog(number, power) << endl;
	cout << "Result = " << degreeLine(number, power) << endl;
	return 0;
}