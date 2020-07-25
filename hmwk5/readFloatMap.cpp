// CSCI 1300 Fall 2019
// Author: Weige Wong
// Recitation: 203 - Soumyajyoti Bhattacharya
// Homework 5 - Problem 6

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*
1. Write a main function that has a 2D array, a file to read, and the number of rows
2. Write a function that takes those arguments
3. First open the file and check if opened correctly
	a. If it didn't return -1
4. Then check if the line is empty in the file
	a. If it is, return 0
5. If not call the split function to take each number in the file and store it in an array
6. Then convert the array in the split file to a double and populate a double array with the values
7. Count each line that program goes through and return it
Input: a file, an array, and an number (string, double, int types)
Output: counter (int type)
Return: counter (int type)
*/

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
	}
}

int readFloatMap(string fileName, double arr[][4], int rows)
{
    int counter = 0;
    string line = "";
    ifstream inFile(fileName);													//declares and opens a file
    
    if(inFile.is_open())														//checks if the file is open
    {
        while(getline(inFile, line))											//goes through each line in the file
        {
        	if(line == "")														//checks for blank lines
        	{
        		return 0;	
        	}
        	
            string temp[4];
            char delimiter = ',';
            int length = 4; 
            
            split(line, delimiter, temp, length);								//calls split function
            
            for(int i = 0; i < 4; i++)
            {
                arr[counter][i] = stod(temp[i]);								//the for loop sets the column index and the temp index and puts the value in temp into the index of the arr
            }
            counter++;															//dicates the rows and keeps track of the lines
        }
        return counter;
    }
    
    else
    {
        return -1;
    }
}

int main()
{
	//Test 1
	//Input: arr[2][4], rows, floatMap.txt
	//Output: 2
    double arr[2][4];
    int rows = 2;
    cout << readFloatMap("floatMap.txt", arr, rows) << endl;
    
    //Test 2
	//Input: array[2][4], row, floatMap.1.txt
	//Output: 0
    double array[2][4];
    int row = 2;
    cout << readFloatMap("floatMap.1.txt", array, row) << endl;
}