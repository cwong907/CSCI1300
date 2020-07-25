// CSCI 1300 Fall 2019
// Author: Weige Wong
// Recitation: 203 - Soumyajyoti Bhattacharya
// Homework 7 - Problem 4

/*
1. Write a main function that has a username, users, storeUsers, storeBooks
2. Write a function that accepts those arguments
3. Check if there are no users or if there are no books stored first
3. If they exist, loop through all the users in the users array and check if any of those match the username we're looking for
4. If it does store that index
5. At that user index loop through all the ratings and count the number of ratings that are not 0
Input: username, users, storeUsers, storeBooks (string, User, int, int)
Output: count (int type)
Return: count (int type)
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

int getCountReadBooks(string userName, User users[], int storeUsers, int storeBooks)
{
	int count = 0;
	int id1 = 0;
	int counter1 = 0; // user found
	int id2 = 0;
	int counter2 = 0;
	
	for(int i = 0; i < storeUsers; i++)											//loops through all the users
	{
		if(convertToLower(users[i].getUsername()) == convertToLower(userName))	//converts to lowercase and then compares to see if the username matches
		{
			id1 = i;															//keeps track of the index
			counter1++;															//stays at 0 if there are no matches
			break;
		}
	}
	
	if(counter1 == 0 || storeBooks == 0)                                        // user or book not in the list
	{
		return -3;
	}
	
	else
	{
		for(int k = 0; k < storeBooks; k++)										//goes through all the book ratings stored in the array (uses stored books since that directly correlates with the number of book ratings)
		{
			if(users[id1].getRatingAt(k) != 0)									//checks if the rating for that user at that point isn't 0
			{
				count++;
			}
		}
		return count;
	}
}


int main()
{
	
	
	//Test 1
	//Input: joan
	//Output: 46
	string username = "joan";
	User users[50];
	int storeUsers = 50;
	int storeBooks = 50;
	
	//Test 2
	//Input:ASD
	//Output: -3
	string usernames = "ASD";
	User uses[50];
	int storeUser = 50;
	int storeBook = 50;
	
	int numUsersStored = 0;
	int userArrSize = 50;
	int maxCol = 50;
	int a = readRatings("ratings.txt", users, numUsersStored, userArrSize, maxCol);
	
	cout << getCountReadBooks(username, users, storeUsers, storeBooks) << endl;
	cout << getCountReadBooks(usernames, uses, storeUser, storeBook) << endl;
}