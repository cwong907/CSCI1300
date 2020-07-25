// CSCI 1300 Fall 2019
// Author: Weige Wong
// Recitation: 203 - Soumyajyoti Bhattacharya
// Homework 6 - Problem 7

#include <iostream>
#include <fstream>
#include <string>
#include "Book.h"
using namespace std;

/*
1. Write a function that calls the bookProgram function
2. Write a function that prompts the user to select one of 4 options via a menu (it should keep asking until option 4 is selected)
3. If option 1 is selected, then ask the user to enter a file name and pass it to the readBooks function
    a. Then run the readBooks function
4. If option 2 is selected, then run the printAllBooks function using the books array that was populated if/when option 1 was selected
5. If option 3 is selected, then have the user enter an author name and pass it into the printBooksByAuthor function
    a. Run the printBooksByAuthor function
6. If option 4 is selected quit and print Good Bye!
7. The default option should be if a number that isn't 1-4 is selected and should print Invalid input
Input: number, author name, file name (int, string types)
Output: a menu, the number of books in file (or that can be held in an array) (int type), the list of books and authors in the books array (string type), the titles of books that match a user entered author (string type)
Return: i (int type)
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

void printAllBooks(Book books[], int i)                    //takes the titles and authors array and i (the number of books)
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
                
                books[i].setAuthor(temp[0]);
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

void bookProgram()
{
    string n = "9";                                                                 
    string fileName;
    string author;
    Book books[50];
    int size = 50;
    int numBooks = 0;
    
    while(stoi(n) != 4)                                                                             //repeats until 4 is selected
    {
        cout << "======Main Menu=====" << endl;
        cout << "1. Read books" << endl;
        cout << "2. Print all books" << endl;
        cout << "3. Print books by author" << endl;
        cout << "4. Quit" << endl;
        
        getline(cin, n);                                                                            //getline allows us to enter strings without worrying about spaces
        
        switch(stoi(n))                                                                             //since we enter inputs as string this changes it to ints 
        {       
            case 1:
                cout << "Enter a book file name:" << endl;
                getline(cin, fileName); 
                numBooks = readBooks(fileName, books, numBooks, size);                              //sets the number readBooks returns to numBooks so we only have to read the file once
                
                if (numBooks == size)                                                               //checks if the array size is the same the number of books in the array
                {   
                    cout << "Database is full. Some books may have not been added." << endl;
                    break;  
                }
                
                if(numBooks == -1)                                                                  //checks if there are no books in the file
                {
                    cout << "No books saved to the database." << endl;
                }
                
                else if(numBooks == -2)                                                             //checks if the array is already full
                {
                    cout << "Database is already full. No books were added." << endl;
                }
                
                else
                {
                    cout << "Total books in the database: " << numBooks << endl;
                }
                break;
            
            case 2:
                printAllBooks(books, numBooks);
                break;
            
            case 3:
                cout << "Enter name of author:" << endl;
                getline(cin, author);
                printBooksByAuthor(books, numBooks, author);
                break;
                
            case 4:
                cout << "Goodbye" << endl;
                break;
            
            default:
                cout << "Invalid input." << endl;
                break;
        }
    }
}

int main()
{
   bookProgram();
}