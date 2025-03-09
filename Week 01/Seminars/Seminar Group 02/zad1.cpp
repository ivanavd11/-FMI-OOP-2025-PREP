#include <iostream>

const int MAX_TITLE = 64;
const int MAX_NAME = 32;
const int MAX_BOOKS = 10;

enum class Status {
	Available,
	Borrowed,
	Reserved
};

struct Book {
	char title[MAX_TITLE];
	char authot[MAX_NAME];
	int publicationYear;
	Status status;
};

struct Library {
	char name[MAX_NAME];
	Book books[MAX_BOOKS];
	int bookCount = 0;
};

Book createBook(const char* title, const char* author, int year)
{
	if (!title || !author)
	{
		return {};
	}

	Book book;
	strcpy(book.title, title);
	strcpy(book.authot, author);
	book.publicationYear = year;
	book.status = Status::Available;

	return book;
}

void addBook(Library& library, const char* title, const char* author, int year)
{
	if (!title || !author)
	{
		return;
	}

	if (library.bookCount >= MAX_BOOKS)
	{
		return;
	}

	library.books[library.bookCount++] = createBook(title, author, year);

}

void borrowBook(Book& book)
{
	if (!book.title || !book.authot)
	{
		return;
	}
	if (book.status == Status::Available)
	{
		book.status = Status::Borrowed;
	}
}

void reserveBook(Book& book)
{
	if (!book.title || !book.authot)
	{
		return;
	}
	if (book.status == Status::Available)
	{
		book.status = Status::Reserved;
	}
}

void printStatus(Status s)
{
	switch (s)
	{
	case Status::Available:
		std::cout << "Available"; break;
	case Status::Borrowed:
		std::cout << "Borrowed"; break; 
	case Status::Reserved:
		std::cout << "Reserved"; break;
	default:
		std::cout << "Unknown";
	}
}

void printBook(const Book& book)
{
	std::cout << book.title << " by " <<
		book.authot << ", " << book.publicationYear << ", ";
	printStatus(book.status);
	std::cout << std::endl;

}

void printLibrary(const Library& library)
{
	std::cout << "Library: " << library.name << std::endl;
	for (int i = 0; i < library.bookCount; i++)
	{
		std::cout << "Book " << i + 1 << ": ";
		printBook(library.books[i]);
	}
}

int main()
{

}