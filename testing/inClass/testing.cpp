#include <iostream>
#include <cmath>
#include <iomanip>
#include <assert.h>
#include <vector>
#include <string>

using namespace std;

/*class Counter
{
	public:
	int read();
	void count();
	void clear();
	
	private:
	int counter = 10;
};

int Counter::read()
{
	return counter;
}

void Counter::count()
{
	counter++;
}

void Counter::clear()
{
	counter = 0;
}

int main()
{
	Counter mycounter;
	cout << mycounter.read() << endl;
	mycounter.count();
	cout << mycounter.read() << endl;
}*/

class Book
{
	public:
	string getTitle() const;						//Accessors
	string getAuthor() const;
	void setTitle(string t);						//Mutators
	void setAuthor(string a);
	
	private:
	string title = "East of Eden";
	string author = "John Steinbeck";
};

string Book::getTitle() const
{
	return title;
}

string Book::getAuthor() const
{
	return author;
}

void Book::setAuthor(string a)
{
	author = a;
}

void Book::setTitle(string t)
{
	title = t;
}

class Shelf
{
	public:
	void add(Book abook);
	Book get(int index);
	
	private:
	vector<Book> books;
};

void Shelf::add(Book abook)
{
	books.push_back(abook);
}

Book Shelf::get(int index)
{
	return books[index];
}

int main()
{
	Shelf mybookshelf;
	Book oneofmybooks;
	
	cout << oneofmybooks.getTitle() << endl;
	
	mybookshelf.add(oneofmybooks);
	cout << mybookshelf.get(0).getAuthor();
}