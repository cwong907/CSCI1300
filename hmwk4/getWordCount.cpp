// CSCI 1300 Fall 2019
// Author: Weige Wong
// Recitation: 203 - Soumyajyoti Bhattacharya
// Homework 4 - Problem 5

/*
1. Write a fuction that takes a sentence as a string
2. Write a function that takes the string and counts the words in that string sentence
	a. If the string is empty then return 0
Input: sentence (string type)
Output: number (int type)
Return: 0 or number (of words (int type))
*/

#include <iostream>
#include <math.h>
#include <iomanip>
#include <string>
using namespace std;

int getWordCount(string words)
{
	int count = 0;
	
	if(words == "")										//checks if string is empty
	{
		return 0;
	}
	
	else
	{
		for(int j = 0; j < words.length(); j++)			//loops through the string 
		{
			if(words[j] == ' ')							//goes through each index of the string and checks for a char space
			{
				count++;								//if it sees a space it adds 1
			}
		}
	}
	return count + 1;									//takes the spaces + 1 to get the amount of words
}

int main()
{
	//Test 1
	//Input: The rat the cat the dog bit chased escaped
	//Expected Output: 9
	string word = "The rat the cat the dog bit chased escaped";
	
	cout << getWordCount(word) << endl;
	
	//Test 2
	//Input: Long way home
	//Expected Output: 3
	string word2 = "Long way home";
	
	cout << getWordCount(word2) << endl;
	

}