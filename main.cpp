#include <iostream>
#include "charArray.hpp"


using namespace std;
using namespace ext;

int countLength(charArray str)
{
	int length = 0;
	while (str[length] != '\0')
	{
		++length;
	};

	return length;
}

char characterAt(charArray str, int letter)
{
	int length = countLength(str);
	char result;
	if (letter <= length && letter > -1)
	{
		if (letter == 0)
		{
			result = str[0];
		}
		else
		{
			result = str[letter - 1];
		}
		return result;
	}
	else
	{
		cout << "There was an error. Try checking the number you entered." << endl;
	}

}

void concatenate(charArray& first, charArray second)
{
	int lengthFirst = countLength(first);
	int lengthSecond = countLength(second);

	charArray result = new char[lengthFirst + lengthSecond + 1];

	for (int i = 0; i < lengthFirst; ++i)
	{
		result[i] = first[i];
	}
	for (int i = 0; i < lengthSecond; ++i)
	{
		result[i] = second[i];
	}
	result[lengthFirst + lengthSecond] = '\0';
	delete[] first;
	first = result;
}

int main()
{
	
	charArray first = new char[6]{ "Hello" };
	charArray second = new char[7]{ " world" };


	cout << characterAt(first, 2) << endl;
}
