#include <iostream>
#include <fstream>
#include <string>

using namespace std;
ifstream fin("books.bin", std::istream::in | std::istream::binary);
ofstream fout("books.bin", std::ostream::in | std::ostream::binary);

struct Book
{
	static const int BUFFER_SIZE = 20;
	int Id;
	char Title[BUFFER_SIZE];
	char Author[BUFFER_SIZE];
	float Price;
	int Quantity;
};

ostream & operator << (std::ostream& out, Book book)
{
	out << book.Id << ". " << book.Title << "by " << book.Author << ", $" << book.Price << "(" << book.Quantity << " available)";
	return out;
}

void BookSwap(Book& FirstBook, Book& SecondBook)
{
	Book temp;
	temp = FirstBook;
	FirstBook = SecondBook;
	SecondBook = temp;
}

void BookSort(Book *arr, int size)
{
		for (int i = 0; i < 10; i++) {
			bool flag = true;
			for (int j = 0; j < 10 - (i + 1); j++) {
				if (arr[j].Author >= arr[j + 1].Author && arr[j].Title > arr[j + 1].Title) {
					flag = false;
					swap(arr[j], arr[j + 1]);
				}
			}
			if (flag) {
				break;
			}
		}
}

void AddBooks()
{
	int size;
	Book tempBook;
	char Title[Book::BUFFER_SIZE];
	char Author[Book::BUFFER_SIZE];
	float Price;
	int Quantity;

	cout << "Enter the title of the book you want to add" << endl;
	cin >> tempBook.Title;
	cout << "Enter the author of the book you want to add" << endl;	
	cin >> tempBook.Author;
	cout << "Enter the price of the book you want to add" << endl;
	cin >> tempBook.Price;
	cout << "Enter the quantity of the book you want to add" << endl;
	cin >> tempBook.Quantity;


	fin.open("books.bin", istream::in | istream::binary);
	fin.seekg(0, std::istream::end);
	size = (fin.tellg() / sizeof(Book));
	fin.close();
	 
	int tempId = size + 1;

	fout.open("books.bin", istream::out | istream::binary);
	fout.write(reinterpret_cast<char*>(&tempBook), sizeof(Book));
	fout.close();
}

void ListOfBooks()
{	
	int size;
	fin.seekg(0, std::istream::end);
	size = (fin.tellg() / sizeof(Book));
	Book* books = new Book[size];

	for (int i = 0; i < size; i++)
	{
		fin.read(reinterpret_cast<char*>(books), sizeof(Book) * size);
	}

	fin.close();

	/*BookSort(books, size);*/

	for (int i = 0; i < size; ++i)
	{
		cout << books[i] << endl;
	}
}

int main()
{
	int i = 0;
	int choice;
	while (i == 0)
	{
		cout << "Choose the necessary function:" << endl;
		cout << "1. List of available books." << endl;
		cout << "2. Add new books to the list." << endl;

		cin >> choice;
		switch (choice)
		{
		case 1:
			ListOfBooks();
			break;
		case 2:
			AddBooks();
			break;
		}
	}
}
