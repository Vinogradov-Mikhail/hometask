#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");
	ifstream file("accounts.txt", ios::in);
	if (!file)
	{
		cout << "���� �� ������" << endl;
		return 1;
	}
	int notNullString = 0;
	while (!file.eof())
	{
		string subString;
		getline(file, subString);
		int check = 0;
		for (int i = 0; i < subString.size(); ++i)
		{
			if ((subString[i] != ' ') && (subString[i] != '\n') && (subString[i] != '\t'))
			{
				++check;
			}
		}
		if (check > 0)
		{
			++notNullString;
		}
	}
	file.close();
	cout << "� ������ ����� " << notNullString << " �� ������ ������. " << endl;
	return 0;
}