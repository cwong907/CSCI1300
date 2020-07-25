// CSCI 1300 Fall 2019
// Author: Weige Wong
// Recitation: 203 - Soumyajyoti Bhattacharya
// Homework 7 - Problem 3

/*
1. Write a main function that has a username, title, users array, books array, users array size, and books array size
2. Write a function that takes those inputs and checks for the username in the users array
3. If it finds it then keep track of that index and then look for the book title in the books array and if that is found then keep track of that index
4. Return the username's rating of that book by searching through the users array
5. If neither the book nor the title can be found then return -3
Input: userName, title, users, books, userNum, booksNum (string, string, Users, Books, int, int)
Output: rating (int type)
Return: rating (int type)
*/

#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <ctype.h>
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
	}
	return count;
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

int readRatings(string fileName, User users[],  int numUsersStored, int usersArrSize, int maxCol)
{
	int j = numUsersStored;
    int counter = 0;
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
	            
	            counter = split(temp, delimiter, length, line);					//calls the split function

	            users[j].setUsername(temp[0]);									//since names will always be the index 0 set the users[] array at whatever index equal to temp at 0
	    		
	            
	            for(int i = 1; i < counter; i++)								//the for loop goes through each column and sets it equal to the split array (starting at index 1 and going from there)
	            {
	            	users[j].setRatingAt((i-1), stoi(temp[i]));						//numUsers goes through each row but only gets added to once the line is done (basically each iteration of the while loop)
	            }
	            j++;
	            
	            if(j == usersArrSize)											//checks if the array is maxed out
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
	
	for(int i = 0; i < word.length(); i++)																//iterates through the word by character
	{
		a = tolower(word[i]);																			//sets a to the lowercase letter
		newWord += a;																					//rebuilds the word
	}
	return newWord;
}

int getRating(string userName, string title, User users[], Book books[], int userNum, int booksNum)
{
	int id1 = 0;
	int foundUser = 0; // user found
	int id2 = 0;
	int foundBook = 0;
	
	for(int i = 0; i < userNum; i++)																	//goes through the entire users array in the Users class
	{
		if(convertToLower(users[i].getUsername()) == convertToLower(userName))							//calls the convertToLower function while also checking if the username stored in the users array is the same as the username we're looking for
		{
			id1 = i;																					//marks what index it's at
			foundUser++;																				//my weird version of a bool
			break;
		}
	}
	
	for(int j = 0; j < booksNum; j++)																	//loops through the stored books array
	{
		if(convertToLower(books[j].getTitle()) == convertToLower(title))								//converts titles to lowercase while checking if it matches our search query
		{
			id2 = j;																					//marks the index where title was found
			foundBook++;																				//my weird version of a bool
			break;
		}
	}
	
	if(foundUser == 0 || foundBook == 0)																// user or book not in the list if the counter increments to 1
	{
		return -3;
	}
	
	else
	{
		users[id1].setNumRatings(50);																	//sets the number of ratings
		return users[id1].getRatingAt(id2);																//gets the user and their rating
	}
}


int main()
{
	//Test 1
	//Input: diane, Watership Down
	//Output: 1
	string userName = "diane";
	string title = "Watership Down";
	User users[100];
	Book books[50];
	int userNum = 100;
	int booksNum =  50;
	
	//Test 2
	//Input: Cynthia, The Golden Compass
	//Output: 4
	string userNames = "cynthia";
	string titles = "The Golden Compass";
	int userNums = 100;
	int booksNums =  50;
	
	int numBookStored = 0;
	int booksArrSize = 50;
	readBooks("books.txt", books, numBookStored, booksArrSize);									//populates the books array so we have something to look for
	
	int numUsersStored = 0;
	int userArrSize = 100;
	int maxCol = 50;
	readRatings("ratings.txt", users, numUsersStored, userArrSize, maxCol);						//populates the users array so we can look for something in the first place
	
	cout << getRating(userName, title, users, books, userNum, booksNum) << endl;
	cout << getRating(userNames, titles, users, books, userNums, booksNums) << endl;
}