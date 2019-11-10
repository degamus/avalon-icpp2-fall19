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
		for (int i = 0; i < size; i++)
		{
			cout << data[i].Id << " " << data[i].Name << " " << data[i].Graid << endl;
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
		for (int i = 0; i < size; i++)
		{
			cout << data[i].Id << " " << data[i].Name << " " << data[i].Graid << endl;
		}
	}
	if (setting == 3)
	{
		for (int i = 0; i < size - 1; i++)
		{
			for (int j = 0; j < size - 1 - i; j++)
			{
				if (data[j].Name > data[j + 1].Name)
				{
					string temp = data[j].Name;
					data[j].Name = data[j + 1].Name;
					data[j + 1].Name = temp;
				}
			}
		}
		for (int i = 0; i < size; i++)
		{
			cout << data[i].Id << " " << data[i].Name << " " << data[i].Graid << endl;
		}
	}
}

void BetterTheBest(Student data[], int size)
{
	Student SortedDataPack[N];
	Sort(data, size, 2);

	for (int i = 0; i < size; i++)
	{
		SortedDataPack[i].Id = data[i].Id;
		SortedDataPack[i].Graid = data[i].Graid;
		SortedDataPack[i].Graid = data[i].Graid;
	}

	cout << "To be better than 25% you need to get " << SortedDataPack[(N / 4) + 1].Graid << endl;
	cout << "To be better than 50% you need to get " << SortedDataPack[(N / 2) + 1].Graid << endl;
	cout << "To be better than 75% you need to get " << SortedDataPack[(N - (N / 4)) + 1].Graid << endl;

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
	cout << "" << endl;
	BetterTheBest(datapack, N);
}
