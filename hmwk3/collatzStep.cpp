// CSCI 1300 Fall 2019
// Author: Weige Wong
// Recitation: 203 - Soumyajyoti Bhattacharya
// Homework 3 - Question 1

#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

/*
1. Write a main function that takes user input
2. Write a collatzStep function that calculates the next number in the series based on if user input is odd or even
    a. If user input is even, then divide by 2
    b. If it is odd multiply by 3 and add 1
Input: number (int type)
Output: number (int type)
Return: a, b, c
*/

int collatzStep(int number)         //the int collatzStep function that reads user input
{
    int a;
    
    if (number % 2 == 0)            //checks if user input is even
    {
        a = number / 2;             //if it is divide it by 2
        return a;
    }
   
   if (number % 2 > 0)              //checks if user input is odd
    {    
        a = (3 * number) + 1;       //if it is multiply by 3 and add 1
        return a;
    }
  
    if (number < 0)                 //checks if user input is less than 0
    {
        a = 0;                      //if it is then just output 0
        return a;
    }
}

int main()
{
	int number;
	
	cout << "Enter a number." << endl;
	cin >> number;
	
	
	collatzStep(number);
	cout << collatzStep(number) << endl;
	
	//Test 1
	//Input: 4
	//Expected Output: 2
	cout << collatzStep(4) << endl;
	
	//Test 2
	//Input: 7
	//Expected Output: 22
	cout << collatzStep(7) << endl;
}