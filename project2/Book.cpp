#include "Book.h"
#include <math.h>
#include <iostream>
using namespace std;

Book::Book()                                                                //sets value directly 
{
    title = "";
    author = "";
}

Book::Book(string a, string b)
{
    title = a;
    author = b;
}

void Book::setTitle(string a)
{
    title = a;
}

string Book::getTitle()
{
    return title;
}

void Book::setAuthor(string b)
{
    author = b;
}

string Book::getAuthor()
{
    return author;
}