// CSCI 1300 Fall 2019
// Author: Weige Wong
// Recitation: 203 - Soumyajyoti Bhattacharya
// Homework 5 - Problem 7

/*
1. Write a main function that an array, a 2D array, number of users, max number of rows and columns, and a file name
2. Write a function that accepts those arguments
3. Have the function open the file and check if it opened it correctly
	a. If it didn't return -1
4. If it did, then go through each line in the file and check if it is not blank
5. Then call the split function to place the first line of the file in an array (the username is the first index and every index after that are the book ratings)
6. Then set value and the first index the users array equal to the first value and index of the array from split
7. Using a for loop, set the values after the first index in the split array to the values of the ratings array (also after the first index)
8. Check if the number of users is equal to the max number of rows
	a. If it is, stop and return the number of users counted up till that point
Input: users[], ratings[][], numUsers, maxRows, maxColumns, ratings.txt (string, int, int, int, int)
Output: count (int type)
Return: numUsers (int type)
*/

#include <iostream>
#include <fstream>
#include <string>
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

int readRatings(string fileName, string users[], int ratings[][50], int numUsers, int maxRows, int maxColumns)
{
    int counter = 0;
    string line = "";
    ifstream inFile(fileName);													//open file and declares it
    
    if(numUsers >= maxRows)														//checks if the number of users is equal to or greater than the maximum number of rows
    {
   		return -2;
   	}
    
    else if(inFile.is_open())													//check if the file opens properly
    {
        while(getline(inFile, line))											//goes line by line
        {
        	if(line != "")														//checks for an empty line
        	{
        		string temp[100];
	            char delimiter = ',';
	            int length = 100; 
	            
	            if(numUsers == maxRows)											//checks if the array is maxed out
	            {
	            	return numUsers;
	            }
	            
	            counter = split(line, delimiter, temp, length);					//calls the split function

	            users[numUsers] = temp[0];										//since names will always be the index 0 set the users[] array at whatever index equal to temp at 0
	            
	            for(int i = 1; i < counter; i++)								//the for loop goes through each column and sets it equal to the split array (starting at index 1 and going from there)
	            {
	            	ratings[numUsers][i - 1] = stoi(temp[i]);					//numUsers goes through each row but only gets added to once the line is done (basically each iteration of the while loop)
	            }
	            numUsers++;
        	}
        }
        return numUsers;
    }
    
    else
    {
        return -1;
    }
}

int main()
{
	//Test 1
	//Input: users, ratings, numUsers, maxRows, maxColumns, ratings.txt
	//Output: 86
    string users[100];
    int ratings[100][50];														
    int numUsers = 0;
    int maxRows = 100;
    int maxColumns = 50;
    cout << readRatings("ratings.txt", users, ratings, numUsers, maxRows, maxColumns) << endl;
    
    //Test 2
    //Output: user, rating, numUser, maxRow, maxColumn, ratings.txt 
    //Input: -2
    string user[100];
    int rating[100][50];
    int numUser = 101;
    int maxRow = 100;
    int maxColumn = 50;
    cout << readRatings("ratings.txt", user, rating, numUser, maxRow, maxColumn);
}