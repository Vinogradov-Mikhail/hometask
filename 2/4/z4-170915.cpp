#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
	int mas[10];
	for (int i = 0; i < 10; ++i)
	{
		mas[i] = rand() % 100;
	}

	int k = 1;
	for (int i = 1; i < 10; ++i)
	{
		if (mas[i] <= mas[0])
		{
			swap(mas[k], mas[i]);
			++k;
		}
	}

	for (int i = 0; i < 10; ++i)
	{
		cout << i + 1 << " --- " << mas[i] << endl;
	}
	
	return 0;
}