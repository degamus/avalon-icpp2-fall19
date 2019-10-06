#include <iostream>
#include "random.hpp"
#include <string>
using namespace ext;
using namespace std;
const int N = 100;

struct Student
{
	int Id;
	int Graid;
	string Name;
};

void Generator(Student data[], int size)
{
	for (int i = 0; i < size; i++)
	{
		data[i].Id = GetRandomValue(1, 1000);
	}
		
	for (int i = 0; i < size; i++)
	{
		data[i].Graid = GetRandomValue(0, 100);;
	}


	for (int i = 0; i < size; ++i)
	{
		int length = GetRandomValue(3, 6);
		char letter = GetRandomValue('A', 'Z');
		data[i].Name += letter;

		for (int j = 1; j < length; ++j)
		{
			data[i].Name += GetRandomValue('a', 'z');
		}
	}
}

void Sort(Student data[], int size, int setting)
{
	if (setting == 1)
	{
		for (int i = 0; i < size - 1; i++)
		{
			for (int j = 0; j < size - 1 - i; j++)
			{
				if (data[j].Id > data[j + 1].Id)
				{
					int temp = data[j].Id;
					data[j].Id = data[j + 1].Id;
					data[j + 1].Id = temp;
				}
			}
		}
	}
	if (setting == 2)
	{
		for (int i = 0; i < size - 1; i++)
		{
			for (int j = 0; j < size - 1 - i; j++)
			{
				if (data[j].Graid > data[j + 1].Graid)
				{
					int temp = data[j].Graid;
					data[j].Graid = data[j + 1].Graid;
					data[j + 1].Graid = temp;
				}
			}
		}

	}
	if (setting == 3)
	{

	}
}


int main()
{
	int SortSetting = 0;
	Student datapack[N];

	Generator(datapack, N);

	cout << "Choose the setting you need" << endl;
	cout << "1 - Sort by ID" << endl << "2 - Sort by Grades" << endl << "3 - Sort by Name" << endl;
	cin >> SortSetting;
	if (SortSetting == 1)
	{
		Sort(datapack, N, 1);

	}
	else
		if (SortSetting == 2)
		{
		Sort(datapack, N, 2);
		}
		else 
			if (SortSetting == 3)
			{
				Sort(datapack, N, 3);
			}
			else
			{
				cout << "You chose incorrect setting. Please try again." << endl;
			}

}