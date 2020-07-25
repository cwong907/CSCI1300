// CSCI 1300 Fall 2019
// Author: Weige Wong
// Recitation: 203 - Soumyajyoti Bhattacharya
// Homework 7 - Problem 6

/*
1. Write a function that gives a user 6 options
2. Loop the menu and operations until option 6 is selected
3. If the user runs option 1 then run readBooks
4. If the user picks option 2 then run readRatings
5. If the user picks option 3 then run getRatings
6. If the user picks option 4 then run getCountReadBooks
7. If the user picks option 5 then run calcAvgRatings
8. If the user picks option 6 then quit
9. If the user enters an invalid option then output invalid option
Input: 1, 2, 3, 4, 5, or 6
Output: the values that each respective function returns
Return: the values that each function returns
*/

#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <ctype.h>
#include <iostream>
#include "User.h"
#include "Book.h"
using namespace std;

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
		return count;
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

int readRatings(string fileName, User users[],  int numUsersStored, int usersArrSize, int maxCol)
{
	int j = numUsersStored;
    int count = 0;
    string line = "";
    ifstream inFile(fileName);													//open file and declares it
    
    if(j >= usersArrSize)														//checks if the number of users is equal to or greater than the maximum number of rows
    {
   		return -2;
   	}
    
    else if(inFile.is_open())													//check if the file opens properly
    {
         while(getline(inFile, line))											//goes line by line
        {
        	if(line != "")														//checks for an empty line
        	{
        		string temp[51];
	            char delimiter = ',';
	            int length = 51;
	            
	            count = split(temp, delimiter, length, line);					//calls the split function
	            
	            users[j].setUsername(temp[0]);									//since names will always be the index 0 set the users[] array at whatever index equal to temp at 0
	           
	            //cout << "Test 3" << endl;
	            for(int i = 1; i < count; i++)								//the for loop goes through each column and sets it equal to the split array (starting at index 1 and going from there)
	            {
	            	users[j].setRatingAt(i-1, stoi(temp[i]));						//numUsers goes through each row but only gets added to once the line is done (basically each iteration of the while loop)
	            }
	            j++;
	            
	            if(j == usersArrSize)								//checks if the array is maxed out
			    {
			    	return j;
			    }
        	}
        }
        return j;
    }
    
    else
    {
        return -1;
    }
}

string convertToLower(string word)
{
	string newWord = "";
	string a;
	
	for(int i = 0; i < word.length(); i++)
	{
		a = tolower(word[i]);
		newWord += a;
	}
	return newWord;
}

int getRating(string userName, string title, User users[], Book books[], int userNum, int booksNum)
{
	int id1 = 0;
	int foundUser = 0; // user found
	int id2 = 0;
	int foundBook = 0;
	
	for(int i = 0; i < userNum; i++)
	{
		if(convertToLower(users[i].getUsername()) == convertToLower(userName))
		{
			id1 = i;
			foundUser++;
			break;
		}
	}
	
	for(int j = 0; j < booksNum; j++)
	{
		if(convertToLower(books[j].getTitle()) == convertToLower(title))
		{
			id2 = j;
			foundBook++;
			break;
		}
	}
	
	if(foundUser == 0 || foundBook == 0) // user or book not in the list
	{
		return -3;
	}
	
	else
	{
		users[id1].setNumRatings(50);
		return users[id1].getRatingAt(id2);
	}
}

int getCountReadBooks(string userName, User users[], int storeUsers, int storeBooks)
{
	int count = 0;
	int id1 = 0;
	int counter1 = 0; // user found
	int id2 = 0;
	int counter2 = 0;
	
	for(int i = 0; i < storeUsers; i++)
	{
		if(convertToLower(users[i].getUsername()) == convertToLower(userName))
		{
			id1 = i;
			counter1++;
			break;
		}
	}
	
	cout << counter1 << endl;
	
	if(counter1 == 0 || storeBooks == 0) // user or book not in the list
	{
		return -3;
	}
	
	else
	{
		for(int k = 0; k < storeBooks; k++)
		{
			if(users[id1].getRatingAt(k) != 0)
			{
				count++;
			}
		}
		return count;
	}
}

double calcAverageRating(User users[], Book books[], int usersStored, int booksStored, string title)
{
    int checkTitle = 0;
    int arrayId = 0;
    int sum = 0;
    int counter = 0;
    double average = 0;
    
    for(int i = 0; i < booksStored; i++)
    {
        
        if(convertToLower(books[i].getTitle()) == convertToLower(title))
        {
            arrayId = i;
            checkTitle++;
        }
    }
    
    if(checkTitle == 0 || usersStored <= 0)
    {
        return -3;
    }
    
    for(int j = 0; j < usersStored; j++)
    {
        if(users[j].getRatingAt(arrayId) != 0)
        {
            sum += users[j].getRatingAt(arrayId);
            counter++;
        }
    }
    
    if(counter == 0)
    {
        return 0;
    }
    
    else
    {
        average = ((double)sum / (double)counter);
    }
    
    return average;
}

void hw7()
{
    string n = "9";
    
    string bookFile;
    Book books[50];
    int numBookStored = 0;
    int booksArrSize = 50;
    int fr;
    
    
    string userFile;
    User users[100];
    int numUsersStored = 0; 
    int usersArrSize = 100;
    int maxCol = 50;
    int ur;
    
    string userName;
    string title;
    //int userNum = 100;
    int booksNum = 50;
    int c;
    
    string userN;
    int storeUsers = 50;
    int storeBooks = 50;
    int d;
    
    string btitle;
    //int usersStored = 100;
    int booksStored = 50;
    double e;
    
//  int numBookStore = 0;
// 	int booksArraySize = 50;
// 	int x = readBooks("books.txt", books, numBookStore, booksArraySize);                    //populates books array so we can skip options 1 and 2 in the menu to test
	
// 	int numUserStore = 0;
// 	int userArrSize = 100;
// 	int maxColumn = 50;
// 	int z = readRatings("ratings.txt", users, numUserStore, userArrSize, maxColumn);        //populates users array so we can skip options 1 and 2 in the menu to test
    //cout << "Test 2" << endl;
    
    while(stoi(n) != 6)
    {
        cout << "======Main Menu=====" << endl;
        cout << "1. Read books" << endl;
        cout << "2. Read ratings" << endl;
        cout << "3. Get rating" << endl;
        cout << "4. Find number of books user rated" << endl;
        cout << "5. Get average rating" << endl;
        cout << "6. Quit" << endl;
        
        getline(cin, n);                                                                            //so we can cin and ignore spaces
        
        //cout << "Test 1" << endl;
        
        switch(stoi(n))                                                                             //converts what we entered to int
        {
            case 1:
                cout << "Enter a book file name:" << endl;
                getline(cin, bookFile);                                                             //prompts for a username
                
                fr = readBooks(bookFile, books, numBookStored, booksArrSize);                       //sets fr to the number of books returned by readBooks
                //cout << fr << endl;
                    
                if(fr == -1)                                                                        //if we get a -1 from the function
                {
                    cout << "No books saved to the database." << endl;
                }
                
                else if(fr == -2)                                                                   //checks if we got a -2 from the function
                {
                    cout << "Database is already full. No books were added." << endl;
                }
                
                else if(fr == booksArrSize)                                                         //if the array is filled to exactly 50
                {
                    numBookStored = 50;                                                             //sets numBooksStored to 50 so we can keep track of the full array
                    cout << "Database is full. Some books may have not been added." << endl;
                }
                    
                else
                {
                    numBookStored = numBookStored;                                                  //sets numBookStored to numBookStored so we can keep track of the number of books stored in the array
                    cout << "Total books in the database: " << fr << endl;
                }
                break;
            
            case 2:
                cout << "Enter a user file name:" << endl;
                getline(cin, userFile);
                
                ur = readRatings(userFile, users, numUsersStored, usersArrSize, maxCol);            //same deal as fr just with a different function
                
                if(ur == -1)
                {
                    cout << "No users saved to the database." << endl;
                    break;
                }
                
                else if(ur == -2)
                {
                    cout << "Database is already full. No users were added." << endl;
                    break;
                }
                
                else if(ur == usersArrSize)
                {
                    numUsersStored = 100;
                    cout << "Database is full. Some users may have not been added." << endl;
                    break;
                }
                
                else
                {
                    numUsersStored = ur;
                    cout << "Total users in the database: " << ur << endl;
                }
                break;
                
            case 3:
                cout<< "Enter a user name:" << endl;
                getline(cin, userName);
                
                cout << "Enter a book title:" << endl;
                getline(cin, title);
                
                c = getRating(userName, title, users, books, numUsersStored, booksNum);
                
                if(c == 0)
                {
                    cout << userName << " has not rated " << title << endl;
                    break;
                }
                
                else if(c == -3)
                {
                    cout << userName << " or " << title << " does not exist." << endl;
                    break;
                }
                
                else
                {
                    cout << userName << " rated " << title << " with " << c << endl;
                }
                break;
                
            case 4:
                cout << "Enter a user name:" << endl;
                getline(cin, userN);
                
                d = getCountReadBooks(userN, users, numUsersStored, storeBooks);
                
                if(d == 0)
                {
                    cout << userN << " has not rated any books." << endl;
                    break;
                }
                
                else if(d == -3)
                {
                    cout << userN << " does not exist." << endl;
                    break;
                }
                
                else 
                {
                    cout << userN << " rated " << d << " books." << endl;
                }
                break;
            
            case 5:
                cout << "Enter a book title:" << endl;
                getline(cin, btitle);
                
                e = calcAverageRating(users, books, numUsersStored, numBookStored, btitle);
                
                if(e == -3)
                {
                    cout << btitle << " does not exist." << endl;
                    break;
                }
                
                else
                {
                    cout << "The average rating for " << btitle << " is " << (double) e << endl;
                }
                break;
            
            case 6:
                cout << "Good bye!" << endl;
                break;
            
            default:
                cout << "Invalid input." << endl;
                break;
        }
    }
}

int main()
{
    hw7();
}