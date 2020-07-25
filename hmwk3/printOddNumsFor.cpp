// CSCI 1300 Fall 2019
// Author: Weige Wong
// Recitation: 203 - Soumyajyoti Bhattacharya
// Homework 3 - Question 9

#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

/*
1. Write a main function that takes user input
2. Write a printOddNumsFor function that uses if statements and for loops to print all odd numbers starting at 1 up to user input
	a. The printOddNumsFor function should check if user input is odd or even
    b. If it is even, subract one from the user input, start counting up from 1 add 2 to 1 until the number is less than or equal to user input - 1
    c. If it is odd, start at 1 and add 2 to 1 until the number is less than or equal to user input
Input: user input (int type)
Output: 1 ... (then every odd number until the user input number is reached)
Return: nothing
*/

int printOddNumsFor(int number)								//takes user input                        
{
	if(number > 0)											//checks if number is greater than 0
	{
		if (number % 2 == 0)								//checks if user input is odd or even
		{
			number - number - 1;							//subracts one to make user input odd
		
			for(int i = 1; i <= number; i = i + 2)			//for loop starts at 1 and adds 2 until i is equal to or less than user input - 1
    		{
    			cout << i << endl;
    		} 
		}
	
		else
		{
			for(int i = 1; i <= number; i = i + 2)			//if user input is odd same parameters as the for loop above
    		{
    			cout << i << endl;
    		}
		cout << endl;
		}
	}
}

int main()
{
	int number;
	
	cout << "Enter a number: ";
	cin >> number;

	printOddNumsFor(number);
	
	//Test 1
	//Input: 3
	//Expected Output: 1 3
	printOddNumsFor(3);
	
	//Test 2
	//Input: 4
	//Expected Output: 1 3
	printOddNumsFor(4);
}