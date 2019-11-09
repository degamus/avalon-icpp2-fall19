#include <iostream>
#include <string>
#include <stdio.h>
#include <limits>

using namespace std;

int main()
{
	setlocale(0, "");
	printf(" %-24s |", "Тип переменной");
	printf(" %-15s |", "    Размер,");
	printf(" %-46s |", "             Значение");
	printf(" %-16s |\n", "  Количество");
	printf(" %-24s |", " ");
	printf(" %-15s |", "     байт");
	printf(" %-23s |", "    Минимальное");
	printf(" %-20s |", "  Максимальное");
	printf(" %-16s |\n", " значимых бит");
	printf("-----------------------------------------------------------------------------------------------------------------\n");
	printf(" %-24s |", "bool");
	printf(" %15d |", sizeof(bool));
	printf(" %23d |", numeric_limits<bool>::min());
	printf(" %20d |", numeric_limits<bool>::max());
	printf(" %16d |\n", numeric_limits<bool>::digits);
	printf(" %-24s |", "unsigned short");
	printf(" %15d |", sizeof(unsigned short));
	printf(" %23d |", numeric_limits<unsigned short>::min());
	printf(" %20d |", numeric_limits<unsigned short>::max());
	printf(" %16d |\n", numeric_limits<unsigned short>::digits);
	printf(" %-24s |", "short");
	printf(" %15d |", sizeof(short));
	printf(" %23d |", numeric_limits<short>::min());
	printf(" %20d |", numeric_limits<short>::max());
	printf(" %16d |\n", numeric_limits<short>::digits);
	printf(" %-24s |", "unsigned int");
	printf(" %15d |", sizeof(unsigned int));
	printf(" %23u |", numeric_limits<unsigned int>::min());
	printf(" %20u |", numeric_limits<unsigned int>::max());
	printf(" %16d |\n", numeric_limits<unsigned int>::digits);
	printf(" %-24s |", "int");
	printf(" %15d |", sizeof(int));
	printf(" %23d |", numeric_limits<int>::min());
	printf(" %20d |", numeric_limits<int>::max());
	printf(" %16d |\n", numeric_limits<int>::digits);
	printf(" %-24s |", "long");
	printf(" %15d |", sizeof(long));
	printf(" %23d |", numeric_limits<long>::min());
	printf(" %20d |", numeric_limits<long>::max());
	printf(" %16d |\n", numeric_limits<long>::digits);
	printf(" %-24s |", "unsigned long long");
	printf(" %15d |", sizeof(unsigned long long));
	printf(" %23llu |", numeric_limits<unsigned long long>::min());
	printf(" %20llu |", numeric_limits<unsigned long long>::max());
	printf(" %16d |\n", numeric_limits<unsigned long long>::digits);
	printf(" %-24s |", "long long");
	printf(" %15d |", sizeof(long long));
	printf(" %23lli |", numeric_limits<long long>::min());
	printf(" %20lli |", numeric_limits<long long>::max());
	printf(" %16d |\n", numeric_limits<long long>::digits);
	printf(" %-24s |", "char");
	printf(" %15d |", sizeof(char));
	printf(" %23d |", numeric_limits<char>::min());
	printf(" %20d |", numeric_limits<char>::max());
	printf(" %16d |\n", numeric_limits<char>::digits);
	printf(" %-24s |", "float");
	printf(" %15d |", sizeof(float));
	printf(" %23f |", numeric_limits<float>::min());
	printf(" %20s |", "");
	printf(" %16d |\n", numeric_limits<float>::digits);
	printf(" %-24s |", "double");
	printf(" %15d |", sizeof(double));
	printf(" %23lf |", numeric_limits<double>::min());
	printf(" %20s |", "");
	printf(" %16d |\n", numeric_limits<double>::digits);



}
