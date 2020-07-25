// CSCI 1300 Fall 2019
// Author: Weige Wong
// Recitation: 203 - Soumyajyoti Bhattacharya
// Homework 5 - Problem 2

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*
1. Write a main function that stores 2 arrays, the size of the array, a file name (books.txt), and the number of books stored.
2. Write a function that takes those arguments, and first opens and reads the file specified in the main
3. If the file doesn't open correctly then return -1
4. If it does, then check if the number of books stored is bigger than the size of the array
    a. If it is then return the size of the array
5. If not, then go through the file line by line and pass each line up to the split function
    a. The split function goes through each line and puts the author and book title into an array
6. After that take the readBooks function goes through that array and puts authors and titles into their own arrays and count the number of times it does that
7. It returns the number of times it does that
Input: 2 arrays, number of books stored, size of the arrays (string, int, int types)
Output: i (int type6)
Return: i (int type)
*/

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

int readBooks(string fileName, string titles[], string authors[], int numBookStored, int size)
{
    string line = "";
    int i = numBookStored;
    
    ifstream in_file(fileName);                                                 //open files
    
    if(in_file.is_open())                                                       //checks if the file opened properly
    {
        if(i >= size)                                                           //checks if the number of books is already larger than the array size
        {
            return -2;
        }
        
        while(getline(in_file, line))                                           //goes line by line through the file
        {
            if(line != "")                                                      //checks if the line is empty
            {
                if(i == size)                                                   //i is the counter for the number of lines and this checks if it becomes equal to the size of the array
                {
                    return i;
                }
                
                string temp[2];                                                 //declares variables used for the split function
                int length = 2;
                char delimiter = ',';
                
                split(temp, delimiter, length, line);                           //calls the split function
                
                authors[i] = temp[0];                                           //since the author always comes first, it is in the 0 index of the temp array and the title is always in index 1 of the array so the function just takes those values and places it in the authors and titles array
                titles[i] = temp[1];                                            //here i stands for the number of lines in the file and the number of indexes in the array since they both match
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

int main()
{
    //Test 1
    //Input: "books.txt", titles[51], authors[51], numBooksStored, size
    //Output: 50
    string titles[51];
    string authors[51];
    int numBookStored = 0;
    int size = 51;
    cout << readBooks("books.txt", titles, authors, numBookStored, size) << endl;
    
    //Test 2
    //Input: "books.txt", titles[51], authors[51], numBooksStored, size
    //Output: 42
    string title[42];
    string author[42];
    int numBookStore = 0;
    int sizes = 42;
    cout << readBooks("books.txt", title, author, numBookStore, sizes);
}