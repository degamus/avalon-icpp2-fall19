#include "CharString.hpp"
#include <iostream>

using namespace ext;
using namespace std;

int main()
{
	charString* s1 = new charString{ 'h' };
	charString* s2 = new charString{ 'e' };
	charString* s3 = new charString{ 'l' };

	charString* ptr = nullptr;
	ptr = s1;
	s1->nextSymbol = s2;
	s2->nextSymbol = s3;

	append(ptr, 'l');
	print(ptr);
	cout << "" << endl;
	characterAt(ptr, 4);
}
