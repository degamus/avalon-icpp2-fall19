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
	printf(" %-38s |", "             Значение");
	printf(" %-16s |\n", "  Количество");
	printf(" %-24s |", " ");
	printf(" %-15s |", "     байт");
	printf(" %-19s |", "    Минимальное");
	printf(" %-16s |", "  Максимальное");
	printf(" %-16s |\n", " значимых бит");
	printf("---------------------------------------------------------------------------------------------------------\n");
	printf(" %-24s |", "bool");
	printf(" %15d |\n", sizeof(bool));
	printf(" %-24s |", "unsigned short");
	printf(" %15d |\n", sizeof(unsigned short));
	printf(" %-24s |", "short");
	printf(" %15d |\n", sizeof(short));
	printf(" %-24s |", "unsigned int");
	printf(" %15d |\n", sizeof(unsigned int));
	printf(" %-24s |", "int");
	printf(" %15d |\n", sizeof(int));
	printf(" %-24s |", "long");
	printf(" %15d |\n", sizeof(long));
	printf(" %-24s |", "unsigned long long");
	printf(" %15d |\n", sizeof(unsigned long long));
	printf(" %-24s |", "long long");
	printf(" %15d |\n", sizeof(long long));
	printf(" %-24s |", "char");
	printf(" %15d |\n", sizeof(char));
	printf(" %-24s |", "float");
	printf(" %15d |\n", sizeof(float));
	printf(" %-24s |", "double");
	printf(" %15d |\n", sizeof(double));



}
