// CSCI 1300 Fall 2019
// Author: Weige Wong
// Recitation: 203 - Soumyajyoti Bhattacharya
// Homework 6 - Problem 6

#include <iostream>
#include <fstream>
#include <string>
#include "Book.h"
using namespace std;
/*
1. Copy and paste the printBooksByAuthor and modify it and the main function to take a Book class books array, the number of books, and the author
2. Then have it search through the books array and use getAuthor to compare it to the author we are looking for and count the number of times it matches
3. If they match then at that index use getTitle to get that title and print it
4. The rest of the function stays the same as it originally was
Input: books[], numOfBooks, author (Book, int, string)
Output: A list of titles that are written by the author we are looking for or no books by the author
Return: nothing
*/

void printBooksByAuthor(Book books[], int numOfBooks, string author)
{
    int counter = 0;
    
    if(numOfBooks <= 0)                                                         //checks if the number of books is under 0
    {
        cout << "No books are stored" << endl;
        return;
    }
    
    for(int i = 0; i < numOfBooks; i++)                                         //loops through the authors array to check if there are any matches
    {
        if(books[i].getAuthor() == author) 
        counter++;
    }
    
    if(counter < 1)                                                             //checks to see if there are no matches
    {   
        cout << "There are no books by " << author << endl;
    }
    
    else
    {
        cout << "Here is a list of books by " << author << endl;
        
        for(int i = 0; i < numOfBooks; i++)                                     //loops through the authors array to check for matches and prints the titles that match with the index of the authors array
        {
            
            if(books[i].getAuthor() == author)
            {
                cout << books[i].getTitle() << endl;
            }
        }
    }
}

int main()
{
    //Test 1
    //Input: books[], "Author C"}, 3, Author A
    //Output: Book 1
    Book books[3];
    books[0] = Book("Book 1", "Author A");
    books[1] = Book("Book 2", "Author B");
    books[2] = Book("Book 3", "Author A");
    int numOfBooks = 3;
    string author = "Author A";
    printBooksByAuthor(books, numOfBooks, author);
    
    //Test 2
    //Input: book[], 0, Author
    //Output: No books are stored
    Book book[1];
    book[0] = Book("Title 1", "Author");
    int numOfBook = 0;
    string name = "Author";
    printBooksByAuthor(book, numOfBook, name);
}