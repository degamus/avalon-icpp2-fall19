#include <iostream>

using namespace std;

long long ISBN;
int N;

void checker(long long ISBNNum)
{	
	long long sum = 0;
	long long checkDigit = ISBNNum % 10;
	long long result = 0;
	int countable = 1;
	ISBNNum = ISBNNum / 10;
	while (ISBNNum > 0)
	{
		if (countable % 2 != 0)
		{
			sum += (ISBNNum % 10) * 3;
			ISBNNum = ISBNNum / 10;
			countable++;
		}
		else
		{
			sum += (ISBNNum % 10) * 1;
			ISBNNum = ISBNNum / 10;
			countable++;
		}
	}

	result = sum % 10;

	if (checkDigit + result == 10)
	{
		cout << "ISBN is correct!" << endl;
	}
	else
	{
		cout << "ISBN is invalid" << endl;
	}

}

int main()
{
	cout << "How many codes you want to check?" << endl;
	cin >> N;
	cout << "Enter 13-digit ISBN code(s):" << endl;
	for (int i = 0; i <= N; i++)
	{ 
		cin >> ISBN;
		checker(ISBN);
	}
}