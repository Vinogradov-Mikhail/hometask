#include <iostream> 
#include "hash.h"

using namespace std;

void main()
{
	Dictionary *dict = createDic();
	read(dict);
	print(dict);
	deleteDic(dict);
	cin.get();
	cin.get();
}