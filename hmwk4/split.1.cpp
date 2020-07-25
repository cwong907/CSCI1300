// CSCI 1300 Fall 2019
// Author: Weige Wong
// Recitation: 203 - Soumyajyoti Bhattacharya
// Homework 4 - Problem 6

/*
1. Write a fuction that has a sentence, a character that, when seen will be an indication to split the sentence at that point, a array to fill with sentence chunks, and length of that array
2. Write a function that takes those parameters and first checks if the sentence is empty
	a. If it is, then return 0
3. If not, then it adds the delimiter character to the end of the sentence
4. Then it loops through every character of the sentence and as it does that it checks to see if the character is the same as the delimiter
5. If it isn't then it adds the letter it is currently looking at to a string variable word to rebuild a word/words from the original sentence letter by letter
6. If the character in the original sentence is equal to the delimiter then it checks to see if it is empty
7. If that character isn't empty then it assigns a number (starting at 0 at the beginning of the loop) for the size of the array and takes the word variable from step 5 to the first index of the array
8. It then sets word back to an empty string and adds one to count
9. 
Input: sentence (string type), delimited (char type), array[] (string type), length (int type)
Output: number (int type), 
Return: nothing
*/
#include <iostream>
#include <string>
using namespace std;

int split(string sentence, char delimiter, string array[], int length)
{
	int count = 0;
	string word = "";
	
	if(sentence == "")										//checks for a blank sentence
	{
		return 0;
	}
	
	else
	{
		sentence = sentence + delimiter;					//adds the delimiter to the end of the sentence so that 
	
		for(int i = 0; i < sentence.length(); i++)
		{
			if(sentence[i] == delimiter)
			{
			    if(word != "")
			    {
			     	array[count] = word;
    				count++;
    				word = "";   
			    }
			}
			
			else
			{
				word = word + sentence[i];
			}
		}
		return count;
	}
}

int main()
{
	//Test 1
	//Input: Ad Astra, ' ', array[] = {}, 2
	//Expected Output: 
	string sentence = "Ad Astra";
	char delimiter = ' ';
	string array[] = {};
	int length = 2;
	
	cout << split("Ad Astra", delimiter, array, 2) << endl;
	
	//Test 2
	//Input:
	//Expected Output:
	// string
	// char
	// string
	// int
	
	// cout << split() << endl;
}