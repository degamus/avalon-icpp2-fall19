#include <iostream>
#include "extention.hpp"
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

struct Agent
{
	int monthlySales[12];
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

	cout << "To be better than 25% you need to get at least" << SortedDataPack[(N / 4) + 1].Graid << endl;
	cout << "To be better than 50% you need to get at least" << SortedDataPack[(N / 2) + 1].Graid << endl;
	cout << "To be better than 75% you need to get at least" << SortedDataPack[(N - (N / 4)) + 1].Graid << endl;

}

int main()
{
	int SortSetting = 0;
	int max = 0;
	int LostMonths;
	int counter = 0;
	Student datapack[N];
	Agent ListOfAgents[10];
	int Median[10];

	for (int i = 0; i < 10; i++)
	{
		LostMonths = GetRandomValue(1, 12);
		for (int j = 0; j < 12; j++)
		{
			if (j >= LostMonths)
			{
				ListOfAgents[i].monthlySales[j] = -1;
			}
			else
			{
				ListOfAgents[i].monthlySales[j] = GetRandomValue(100, 1000);
			}
		}
	}

	for (int i = 0; i < 10; i++)
	{
		for (int k = 1; k < 12; k++)
		{
			for (int j = 0; j < 11; j++)
			{

				if (ListOfAgents[i].monthlySales[j] < ListOfAgents[i].monthlySales[j+1])
				{
					int temp = ListOfAgents[i].monthlySales[j];
					ListOfAgents[i].monthlySales[j] = ListOfAgents[i].monthlySales[j + 1];
					ListOfAgents[i].monthlySales[j + 1] = temp;

				}
			}
		}
	}

	for (int i = 0; i < 10; i++)
	{

		for (int j = 0; j < 12; j++)
		{
			if (ListOfAgents[i].monthlySales[j] != -1)
			{
				counter++;
			}
		}
		
		if (counter % 2 != 0)
		{
			Median[i] = ListOfAgents[i].monthlySales[counter / 2];
		}
		else
		{
			Median[i] = (ListOfAgents[i].monthlySales[counter / 2] + ListOfAgents[i].monthlySales[(counter / 2) - 1]) /2;
		}
		counter = 0;
	}

	for (int i = 0; i < 10; i++)
	{

		if (Median[i] > max)
		{
			max = Median[i];
		}
	}

	cout << max;


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
