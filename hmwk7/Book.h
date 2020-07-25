#include <iostream>
#ifndef BOOK_H
#define BOOK_H
using namespace std;

class Book
{
    private:
    string title;
    string author;
    
    public:
    Book();
    Book(string, string);
    
    string getTitle();
    void setTitle(string);
    string getAuthor();
    void setAuthor(string);
};
#endif