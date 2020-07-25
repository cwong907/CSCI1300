// CSCI 1300 Fall 2019
// Author: Weige Wong
// Recitation: 203 - Soumyajyoti Bhattacharya
// Homework 6 - Problem 5

#include <iostream>
#include <fstream>
#include <string>
#include "Book.h"
using namespace std;

/*
1. Take the modified readBooks program and write another modified function that takes the Book class books array and i (basically the number of lines/number of books counted from the readBooks program)
2. Check if the number of books is equal to or less than 0
    a. If it is, say no books are stored
3. If not, then loop through the array use the getTitle and getAuthor functions from the Book class and print each book and author
Input: books array, number of books stored, and array size (string and int types)
Output: titles and authors (string type)
Return: nothing
*/

void printAllBooks(Book books[], int i)                    //takes the titles and authors array and i (the number of books)
{
    if(i <= 0)                                                                  //checks if the number of books is 0 or less
    {
        cout << "No books are stored" << endl;        
    }
    
    else
    {
        cout << "Here is a list of books" << endl;                  
        
        for(int j = 0; j < i; j++)                                              //iterates through the array and prints them by accessing the title and author
        {
            cout << books[j].getTitle() << " by ";
            cout << books[j].getAuthor() << endl;

        }
    }
}

int split(string temp[], char delimiter, int length, string line)
{
	int count = 0;
	string word = "";
	
	if(line == "")									    	//checks for a blank sentence
	{
		return 0;
	}
	
	else
	{
		line = line + delimiter;	        				//adds the delimiter to the end of the sentence so that the code can count the last word
	
		for(int i = 0; i < line.length(); i++)		    	//loops through the sentence
		{
			if(count >= length)								//checks if the sentence is broken up into more chunks than the array size
			{
				return -1;
			}
			
			if(line[i] == delimiter)				    	//checks if the sentence character is equal to the delimited 
			{
			    if(word != "")								//checks if the word is blank
			    {
			     	temp[count] = word;				    	//assigns the word to an index in the array
    				count++;								//counts to move to the next array
    				word = "";								//resets word to a blank string
			    }
			}
			
			else											//if a sentence character doesn't equal the delimiter then it adds the character to the string word, as the loop goes through each character it builds the word again until it sees the delimiter
			{
				word = word + line[i];
			}
		}
	}
}

int readBooks(string fileName, Book books[], int numBookStored, int booksArrSize)
{
    string line = "";
    int i = numBookStored;
    
    ifstream in_file(fileName);                                                 //open files
    
    if(i >= booksArrSize)                                                           //checks if the number of books is already larger than the array size
    {
        return -2;
    }
    
    else if(in_file.is_open())                                                       //checks if the file opened properly
    {
        while(getline(in_file, line))                                           //goes line by line through the file
        {
            if(line != "")                                                      //checks if the line is empty
            {
                if(i == booksArrSize)                                                   //i is the counter for the number of lines and this checks if it becomes equal to the size of the array
                {
                    return i;
                }
                
                string temp[2];                                                 //declares variables used for the split function
                int length = 2;
                char delimiter = ',';
                
                split(temp, delimiter, length, line);                           //calls the split function
                
                books[i].setAuthor(temp[0]);
                books[i].setTitle(temp[1]);
                i++;
            }
        }
        printAllBooks(books, i);
        return i;
        
    }
    
    else                                                                        //if the file fails to open
    {
        return -1;
    }
}

int main()
{
    //Test 1
    //Input: books[], numBookStored, booksArrSize, books.txt
    //Output: list of 50 books and their authors
    Book books[50];
	int numBookStored = 0;
	int booksArrSize = 50;
	readBooks("books.txt", books, numBookStored, booksArrSize);
	//Test 2
	//Input: book[], numBookStore, booksArr, books.txt
	//Output: -2
	Book book[50];
	int numBookStore = 0;
	int booksArr = 0;
    cout << readBooks("books.txt", book, numBookStore, booksArr);
}