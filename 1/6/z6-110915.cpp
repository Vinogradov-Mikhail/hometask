#include "iostream"
using namespace std;
int main()
{

	int amount = 0;
	for (int l = 1; l < 28; ++l) {
		int comb = 0;
		for (int i = 1; i < 10; ++i) {
			for (int j = 1; j < 10; ++j) {

				for (int k = 1; k < 10; ++k) {
					if ((i + k + j) == l) {
						++comb;
					}

				}

			}
		}
		amount += comb * comb;
	}
	cout << "You have " << amount << " lucky tickets" << endl;
	
	s
	return 0;

}