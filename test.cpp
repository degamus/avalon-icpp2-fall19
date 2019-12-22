#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

struct Book
{
	static const int BUFFER_SIZE = 20;
	int Id;
	char Title[BUFFER_SIZE];
	char Author[BUFFER_SIZE];
	float Price;
	int Quantity;
};

ostream & operator << (ostream& out, Book book)
{
	out << book.Id << ". " << book.Title << " by " << book.Author << ", $" << book.Price << " (" << book.Quantity << " available)" << endl;
	return out;
}

istream& operator >> (istream& in, Book book)
{
	in >> book.Id >> book.Title >> book.Author >> book.Price >> book.Quantity;
	return in;
}

void BookSwap(Book& FirstBook, Book& SecondBook)
{
	Book temp;
	temp = FirstBook;
	FirstBook = SecondBook;
	SecondBook = temp;
}




void BookStats()
{
	int size = 0;
	int AmountOfBooks = 0;
	float SummedPrice = 0;
	Book tempBook = {};

	ifstream fin("books.bin", istream::in | istream::binary);
	fin.seekg(0, istream::end);
	size = (fin.tellg() / sizeof(Book));
	fin.seekg(0);

	for (int i = 0; i < size; i++)
	{
		fin.read(reinterpret_cast<char*>(&tempBook), sizeof(Book));
		AmountOfBooks += tempBook.Quantity;
		SummedPrice += tempBook.Price;
	}

	cout << "The value of the book collection: " << SummedPrice << endl;
	cout << "Amount of the books in the library: " << AmountOfBooks << endl;
	fin.close();
}

void AddBooks()
{
	int size = 0;
	Book tempBook = {};
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


	ifstream fin("books.bin", istream::in | istream::binary);
	fin.seekg(0, istream::end);
	size = (fin.tellg() / sizeof(Book));
	fin.close();
	 
	int tempId = size + 1;
	tempBook.Id = tempId;

	ofstream fout("books.bin", istream::out | istream::binary | ostream::app);
	fout.write(reinterpret_cast<char*>(&tempBook), sizeof(Book));
	fout.close();
}

void SortedListOfBooks()
{	
	int size = 0;
	Book tempBook1;

	ifstream fin("books.bin", istream::in | istream::binary);

	fin.seekg(0, ios_base::end);
	size = fin.tellg();
	int count = size / sizeof(Book);
	fin.seekg(0, ios_base::beg);

	Book* books = new Book[count];
	fin.read(reinterpret_cast<char*>(books), sizeof(Book) * count);
	fin.close();

	for (int i = 0; i < count; i++) {
		for (int j = 0; j < count; j++) {
			if (books[j].Author > books[j+1].Author) {
				swap(books[j], books[j+1]);
			}
		}
	}

	for (int i = 0; i < count; i++) {
		for (int j = 0; j < count; j++) {
			if (books[j].Author == books[j+1].Author && books[j].Title > books[j+1].Title) {
				swap(books[j], books[j+1]);
			}
		}
	}

	for (int i = 0; i < count; i++)
	{
		cout << books[i] << endl;
	}

}

void EditBook()
{
	int id;
	int size;
	int left, right, position;
	bool success = false;
	Book tempBook;
	Book copyBook;

	ifstream fin("books.bin", istream::binary | istream::in);
	fin.seekg(0, istream::end);
	size = fin.tellg() / sizeof(Book);

	cin >> id;
	left = 0;
	right = size - 1;

	while (left <= right)
	{
		fin.seekg(sizeof(Book) * ((left + right)/2));
		fin.read(reinterpret_cast<char*>(&tempBook), sizeof(Book));
		if (id == tempBook.Id)
		{
			position = sizeof(Book) * ((left + right) / 2);
			success = true;
			break;
		}
		else
		{
			if (id > tempBook.Id)
			{
				left = (left + right) / 2 + 1;
			}
			else
			{
				right = (left + right) / 2 - 1;
			}
		}
	}
	fin.close();

	if (success)
	{
		ifstream fin2("books.bin", istream::binary | istream::in);
		fin2.read(reinterpret_cast<char*>(&copyBook), sizeof(Book));
		fin2.close();

		ofstream fout("books.bin", istream::out | istream::binary | istream::ate);
		fout.seekp(position);

		cout << "New title:" << endl;
		cin >> copyBook.Title;
		cout << "New author:" << endl;
		cin >> copyBook.Author;
		cout << "New price:" << endl;
		cin >> copyBook.Price;
		cout << "New Quantity:" << endl;
		cin >> copyBook.Quantity;

		fout.write(reinterpret_cast<char*>(&copyBook), sizeof(Book));
		fout.close();
	}
	else
	{
		cout << "Book with such ID wasn't found" << endl;
	}
}

void BookSearch()
{
	int size = 0;
	bool found = false;
	string Title;
	Book tempBook;
	getline(cin, Title);


	ifstream fin("books.bin", istream::binary | istream::in);
	fin.seekg(0, istream::end);
	size = (fin.tellg() / sizeof(Book));
	fin.seekg(0);

	for (int i = 0; i < size; i++)
	{
		fin.read(reinterpret_cast<char*>(&tempBook), sizeof(Book));
		if (Title == string(tempBook.Title))
		{
			found = true;
			break;
		}
	}
	if (found)
	{
		cout << "Book with name " << Title << " was found:" << endl;
		cout << tempBook << endl;
	}

	fin.close();
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
		cout << "3. Book statistics." << endl;
		cout << "4. Search a book." << endl;
		cout << "5. Edit a book." << endl;

		cin >> choice;
		cin.ignore(100, '\n');
		switch (choice)
		{
		case 1:
			SortedListOfBooks();
			break;
		case 2:
			AddBooks();
			break;
		case 3:
			BookStats();
			break;
		case 4:
			BookSearch();
			break;
		case 5:
			EditBook();
			break;
		}
	}
}
