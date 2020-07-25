// CSCI 1300 Fall 2019
// Author: Weige Wong
// Recitation: 203 - Soumyajyoti Bhattacharya
// Homework 7 - Problem 5

/*
1. Write a main function that has a users array, books array, number of users stored, number of books stored, book title
2. Write a function that accepts those arguments
3. Check if there are no users or if there are no books stored first
3. If they exist, loop through all the book titles in the books array and check if any of those match the book title we're looking for
4. If it does store that index
5. At that book index, loop through all the ratings and count the number of ratings that are not 0
6. Also, as it loops through the ratings, add all the non-0 ones up and divide it by the number of non-0 ratings
Input: users, books, usersStored, booksStored, title (User, Book, int, int, string)
Output: average (double type)
Return: average (double type)
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
	
	for(int i = 0; i < word.length(); i++)
	{
		a = tolower(word[i]);
		newWord += a;
	}
	return newWord;
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
        if(convertToLower(books[i].getTitle()) == convertToLower(title))        //loops through all the book titles to see if they match
        {
            arrayId = i;                                                        //stores the index where the book was found
            checkTitle++;                                                       
        }
    }
    
    if(checkTitle == 0 || usersStored <= 0)                                     //checks if there are no users or books found
    {
        return -3;
    }
    
    for(int j = 0; j < usersStored; j++)
    {
        if(users[j].getRatingAt(arrayId) != 0)                                  //loops through all the users but gets the book rating at the same index for every user and checks if it isn't 0
        {
            sum += users[j].getRatingAt(arrayId);                               //sums up the ratings
            counter++;                                                          //counts the number of ratings
        }
    }
    
    if(counter == 0)
    {
        return 0;
    }
    
    else
    {
        average = ((double)sum / (double)counter);                              //calculates the average
    }
    
    return average;
}

int main()
{
    //Test 1
    //Input: Watership Down
    //Output: 2.75325
	string title = "Watership Down";
	User users[100];
	Book books[50];
	int usersStored = 100;
	int booksStored =  50;
	
	//Test 2
	//Input: The golden Compass
	//Output: 3.28571
	string titles = "The golden Compass";
	
	int numBookStored = 0;
	int booksArrSize = 50;
	int b = readBooks("books.txt", books, numBookStored, booksArrSize);
	
	int numUsersStored = 0;
	int userArrSize = 100;
	int maxCol = 50;
	int a = readRatings("ratings.txt", users, numUsersStored, userArrSize, maxCol);
	
	cout << calcAverageRating(users, books, usersStored, booksStored, title) << endl;
	cout << calcAverageRating(users, books, usersStored, booksStored, titles) << endl;
}