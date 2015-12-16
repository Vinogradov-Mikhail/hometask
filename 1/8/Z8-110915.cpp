#include <iostream>
using namespace std;

int main()
{
	char s[1000];
	char s1[1000];
	cout << "Write string";
	cin >> s;
	cout << "Write substring";
	cin >> s1;
	int lgth = strlen(s);
	int lgth1 = strlen(s1);
	int amount = 0;
    for (int i = 0; i < lgth; ++i) {
			int k = lgth1;
			for (int j = 0; j < lgth1; ++j) {
				if (s[j + i] == s1[j]) {
					--k;
				}
			}
			if (k == 0) {
				++amount;
			}
		}
	
	cout << "You have " << amount << " matches lines" << endl;
	system("pause");
	return 0;
}