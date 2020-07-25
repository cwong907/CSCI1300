// CSCI 1300 Fall 2019
// Author: Weige Wong
// Recitation: 203 - Soumyajyoti Bhattacharya
// Homework 7 - Problem 2

/*
1. Write a main function that a users array (of the class Users), number of users stored, the size of the array, the maximum columns, the file name
2. Write a function that accepts those arguments
3. If the number of users stored is greater than the array size return -2
3. Have the function open the file and check if it opened it correctly
	a. If it didn't return -1
4. If it did, then go through each line in the file and check if it is not blank
5. Then call the split function
6. Then set assign a username to an incrementing (beginning at 0) index in the users array by assigning the value of the first index of the temp array to it
7. Using a for loop, set the values after the first index in the split array to the values of the users array 
8. Check if the number of users is equal to the max number of rows
	a. If it is, stop and return the number of users counted up till that point
Input: users[], "ratings.txt", numUsersStored, usersArrSize, maxCol (User, string, int, int, int)
Output: number of users who rated a book (int type)
Return: j (int type)
*/

#include <iostream>
#include <fstream>
#include <string>
#include "User.h"
using namespace std;

int split(string line, char delimiter, string temp[], int length)
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

int readRatings(string fileName, User users[],  int numUsersStored, int usersArrSize, int maxCol)
{
	int j = numUsersStored;
    int counter = 0;
    string line = "";
    ifstream inFile(fileName);													//open file and declares it
    
    if(j >= usersArrSize)														//checks if the number of users is equal to or greater than the maximum number of spaces in the array
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
	            
	            counter = split(line, delimiter, temp, length);					//calls the split function
	            
	            users[j].setUsername(temp[0]);									//since names will always be the index 0 set the users[] array at whatever index equal to temp at 0
	           
	            for(int i = 1; i < counter; i++)								//the for loop goes through each column and sets it equal to the split array (starting at index 1 and going from there)
	            {
	            	users[j].setRatingAt(i-1, stoi(temp[i]));					//at users[j] where j is counted only everytime we get a new line from the file, we set the rating starting at position 0 of the array and take the value from the temp array
	            }
	            j++;															//counts users who rated
	            
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

int main()
{
	//Test 1
	//Input: users, numUsersStored, usersArrSize, maxCol, ratings.txt
	//Output: 10
    User users[10];
    int numUsersStored = 0;
    int usersArrSize = 10;
    int maxCol = 50;
    cout << readRatings("ratings.txt", users, numUsersStored, usersArrSize, maxCol) << endl;
    
    //Test 2
	//Input: users, numUsersStored, usersArrSize, maxCol, ratings.txt
	//Output: 86
    User user[86];
    int numUsersStoreds = 0;
    int usersArrSizes = 86;
    int maxCols = 50;
    cout << readRatings("ratings.txt", user, numUsersStoreds, usersArrSizes, maxCols) << endl;
}