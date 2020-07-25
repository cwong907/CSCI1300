// CSCI 1300 Fall 2019
// Author: Weige Wong
// Recitation: 203 - Soumyajyoti Bhattacharya
// Homework 6 - Problem 4

#include <fstream>
#include <string>
#include <iostream>
#include "Book.h"
using namespace std;

/*
1. Write a main driver function that stores an array (of Book class), number of books, the array size, and the file name
2. Copy and paste the readBooks function and modify it to accept the variables in the new main function
3. In the new readBooks function have it take the title and author stored in the temp array from the split function and store it in an index in the Book class books array
4. Count each time you add a book/author combo and return it
Input: array, number of books stored, array size, file name (Book, int, int, txt type)
Output: i (int type)
Return: i (int type)
*/

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
		//return count;
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
                
                books[i].setAuthor(temp[0]);									//sets the author and title stored in the temp array into an index of the books array (which is a Books object)
                books[i].setTitle(temp[1]);
                i++;
            }
        }
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
    //Input: books[50], 0, 50 
    //Output: 50
	Book books[50];
	int numBookStored = 0;
	int booksArrSize = 50;
	cout << readBooks("books.txt", books, numBookStored, booksArrSize) << endl;
	
	//Test 2
	//Input: book[42], 0, 42
	//Output: 42
	Book book[42];
	int numBook = 0;
	int booksArr = 42;
	cout << readBooks("books.txt", book, numBook, booksArr) << endl;
}