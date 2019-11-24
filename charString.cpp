#include "CharString.hpp"
#include <iostream>

namespace ext
{
	void append(charString*& str, char symbol)
	{
		charString* ptr = new charString{ symbol };

		if (str == nullptr)
		{
			str = ptr;
			return;
		}

		charString* temp = str;

		while (temp->nextSymbol != nullptr)
		{
			temp = temp->nextSymbol;
		}
		temp->nextSymbol = ptr;
	}

	void characterAt(charString* str,int position)
	{
		int temp_position = position;
		int i = 2;
		if (position < 1)
		{
			temp_position = 1;
		}

		charString* temp = str;

		for (int i = 2; i <= temp_position; i++)
		{
				temp = temp->nextSymbol;
		}
		std::cout << temp->symbol << std::endl;
	}

	void print(charString* str)
	{
		while (str != nullptr)
		{
			std::cout << str->symbol;
			str = str->nextSymbol;
		}
	}
}
