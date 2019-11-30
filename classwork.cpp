#include <iostream>
#include <fstream>

using namespace std;

struct Point
{
	int x;
	int y;
};

Point operator * (Point point, int mult)
{
	return Point{ point.x * mult, point.y * mult };
}

Point operator * (int mult, Point point)
{
	return point * mult;
}

// перегрузка оператора вывода
ostream& operator << (ostream& out, Point point)
{
	out << point.x << " " << point.y;
	return out;
}

// перегрузка оператора ввода
istream& operator >> (istream& in, Point& point)
{
	in >> point.x >> point.y;
	return in;
}

int main()
{
	ifstream fileData("pointsdata.txt", iostream::app);
	if (!fileData.is_open())	// проверка успешности открыти€ файла
	{
		cout << "Cannot open file" << endl;
		return 1;
	}


	ofstream fileForPoints;
	fileForPoints.open("points.txt", iostream::ate);

	if (!fileForPoints.is_open())	// проверка успешности открыти€ файла
	{
		cout << "Cannot open file" << endl;
		return 1;
	}

	fileForPoints << "Hello world!" << endl;
	
	Point point{ 5,6 };
	Point newPoint = point * 2; // {10,12}
	Point newPoint2 = 2 * point; // {10, 12}

	fileForPoints << point << endl;
	fileForPoints << newPoint << endl;
	fileForPoints << newPoint2 << endl;

	fileForPoints.close();

	fileData >> point;
	cout << point << endl;
	fileData >> point;
	cout << point << endl;
	fileData >> point;
	cout << point << endl;
}