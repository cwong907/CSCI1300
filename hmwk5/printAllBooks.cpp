// CSCI 1300 Fall 2019
// Author: Weige Wong
// Recitation: 203 - Soumyajyoti Bhattacharya
// Homework 5 - Problem 3

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*
1. Take the readBooks program and write another function that takes the titles and authors arrays and i (basically the number of lines/number of books counted from the readBooks program)
2. Check if the number of books is equal to or less than 0
    a. If it is, say no books are stored
3. If not, then loop through the titles and authors array (populated using titles from the books.txt file in the readBooks program) and print each book and author
Input: titles and authors arrays, i (string and int types)
Output: titles and authors (string type)
Return: nothing
*/

void printAllBooks(string titles[], string authors[], int i)                    //takes the titles and authors array and i (the number of books)
{
    if(i <= 0)                                                                  //checks if the number of books is 0 or less
    {
        cout << "No books are stored" << endl;        
    }
    
    else
    {
        cout << "Here is a list of books" << endl;                  
        
        for(int j = 0; j < i; j++)                                              //iterates through each array and prints them
        {
            cout << titles[j] << " by " << authors[j] << endl;
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

int readBooks(string fileName, string titles[], string authors[], int numBookStored, int size)
{
    string line = "";
    int i = numBookStored;
    
    ifstream in_file(fileName);
    
    if(in_file.is_open())
    {
        if(i >= size)
        {
            return -2;
        }
        
        while(getline(in_file, line))
        {
            if(line != "")
            {
                if(i == size)
                {
                    printAllBooks(titles, authors, i);
                }
            
                string temp[2];
                int length = 2;
                char delimiter = ',';
                
                split(temp, delimiter, length, line);
                
                authors[i] = temp[0];
                titles[i] = temp[1];
                i++;
            }
        }
        printAllBooks(titles, authors, i);
        return i;
    }
    
    else
    {
        return -1;
    }
}

int main()
{
    //Test 1
    //Input: books.txt, titles[], authors[], numOfBooks, size
    //Output: a list of books and their respective authors from the arrays
    string titles[51];
    string authors[51];
    int numOfBooks = 0;
    int size = 51;
    readBooks("books.txt", titles, authors, numOfBooks, size);
    cout << endl;
    
    //Test 2
    //Input: testbook.txt, title[], author[], numOBooks, sizes
    //Output: a list of books and their respective authors from the arrays
    string title[2];
    string author[2];
    int numOBooks = 0;
    int sizes = 2;
    readBooks("testbook.txt", title, author, numOBooks, sizes);
}