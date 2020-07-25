// CSCI 1300 Fall 2019
// Author: Weige Wong
// Recitation: 203 - Soumyajyoti Bhattacharya
// Homework 5 - Problem 4

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
/*
1. Write a main function that has 2 arrays, number of books, and a an author name
2. Write a function that takes those arguments
3. First check if the number of books are equal to or less than 0
    a. If it is, say no books are stored
4. If not then go through every author in the authors array and check if they match the name of the author mentioned earlier
    a. If they are then add 1 to a counter
5. If the counter is 0 or less, then say they are no books by "author name"
6. If not that, then print the book titles from the titles array at the same indexes where the authors index matches with the author name the program is looking for
Input: titles[], authors[], numOfBooks, name (string, int, string)
Output: A list of titles that are written by the author we are looking for or no books by the author
Return: nothing
*/

void printBooksByAuthor(string titles[], string authors[], int numOfBooks, string name)
{
    int counter = 0;
    
    if(numOfBooks <= 0)                                                         //checks if the number of books is under 0
    {
        cout << "No books are stored" << endl;
        return;
    }
    
    for(int i = 0; i < numOfBooks; i++)                                         //loops through the authors array to check if there are any matches
    {
        if(authors[i] == name) 
        counter++;
    }
    
    if(counter < 1)                                                             //checks to see if there are no matches
    {   
        cout << "There are no books by " << name << endl;
    }
    
    else
    {
        cout << "Here is a list of books by " << name << endl;
        
        for(int i = 0; i < numOfBooks; i++)                                     //loops through the authors array to check for matches and prints the titles that match with the index of the authors array
        {
            
            if(authors[i] == name)
            {
                cout << titles[i] << endl;
            }
        }
    }
}

int main()
{
    //Test 1
    //Input: titles[3] = {"Book 1", "Book 2", "Book 3"}, authors[3] = {"Author A", "Author B", "Author C"}, 3, Author A
    //Output: Book 1
    string titles[3] = {"Book 1", "Book 2", "Book 3"};
    string authors[3] = {"Author A", "Author B", "Author C"};
    int numOfBooks = 3;
    string name = "Author A";
    printBooksByAuthor(titles, authors, numOfBooks, name);
    cout << endl;
    
    //Test 2
    //Input: title[3] = {"Book 1", "Book 2", "Book 3"}, author[3] = {"Author A", "Author B", "Author A"}, 3, Author B
    //Output: Book 1, Book 2
    string title[3] = {"Book 1", "Book 2", "Book 3"};
    string author[3] = {"Author B", "Author B", "Author A"};
    int numOfBook = 3;
    string names = "Author B";
    printBooksByAuthor(title, author, numOfBook, names);
}