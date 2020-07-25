// CSCI 1300 Fall 2019
// Author: Weige Wong
// Recitation: 203 - Soumyajyoti Bhattacharya
// Homework 3 - Question 10

#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

/*
1. Write a main function that takes user input for the amount of rows and columns for a grid
2. Write a printGrid function that takes that user input and ouputs it
    a. First write a for loop that prints the "structure" for the columns and repeats until we reach user input amount of times
    b. Then have a "bigger" for loop that the a. rests inside of that repeates a. to create the rows
Input: user input (int type)
Output: a grid with user input amount of rows and columns
Return: nothing
*/

int printGrid(int number)
{
    if (number <= 0)                                                    //checks if user input is equal to or greater than 0
    {
        cout << "The grid can only have a positive number of rows and columns." << endl;
    }

    else 
    {
        int r;  //rows
        int c;  //columns
        
        for (r = 0; r < number; r++)                                    //this bigger for loop repeats the smaller for loops inside of it user input amount of times to create the rows
        {
            for (c = 0; c < number; c++)                                //for loop creates the columns and repeats until user input amount of times
            {
                cout << "+--";
            }
            cout << "+" << endl;                                        //these sit outside the loop so they finish the column structure
            
            for (c = 0; c < number; c++)
            {
                cout << "|  ";
            }
            cout << "|" << endl;                                        //these sit outside the loop so they finish the column structure
        }
        for (c = 0; c < number; c++)                                    //this finishes the grid with the +-- part
        {
            cout << "+--";
        }
        cout << "+" << endl; 
    }
}

int main()
{
	int number;
	
	cout << "Enter a number." << endl;
	cin >> number;

	printGrid(number);
	
	//Test 1
	//Input: 1
	//Expected Output: A grid with 1 rows and columns
	cout << printGrid(1) << endl;
	
	//Test 2
	//Input: 3
	//Expected Output: A grid with 3 rows and columns
	cout << printGrid(3) << endl;
}