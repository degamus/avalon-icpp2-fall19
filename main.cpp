#include <iostream>

using namespace std;

long long ISBN;
int N;
int version;

void checker10(long long ISBNNum)
{
	long long checkDigit = ISBNNum % 10;
	long long sum = 0;
	long long result = 0;
	int multiplier = 2;
	ISBNNum = ISBNNum / 10;
	while (ISBNNum > 0)
	{
		sum += (ISBNNum % 10) * multiplier;
		ISBNNum = ISBNNum / 10;
		multiplier++;
	}	

	result = sum % 11;

	if (checkDigit + result == 11)
	{
		cout << "ISBN is correct!" << endl;
	}
	else
	{
		cout << "ISBN is invalid" << endl;
	}

}


void checker13(long long ISBNNum)
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
	int correctVersion = 0;

	while (correctVersion == 0)
	{
		cout << "Choose ISBN version (1 - ISBN13, 2 - ISBN10):" << endl;
		cin >> version;

		if (version == 1)
		{
			cout << "How many codes you want to check?" << endl;
			cin >> N;
			cout << "Enter 13-digit ISBN code(s):" << endl;
			for (int i = 0; i <= N; i++)
			{
				cin >> ISBN;
				checker13(ISBN);
			}
			correctVersion = 1;
		}
		else if (version == 2)
		{
			cout << "Enter 10-digit ISBN code:" << endl;
			cin >> ISBN;
			checker10(ISBN);
			correctVersion = 1;
		}
		else
		{
			cout << "Incorrect choice, please try again." << endl;
		}
	}

}
