// CSCI 1300 Fall 2019
// Author: Weige Wong
// Recitation: 203 - Soumyajyoti Bhattacharya
// Homework 3 - Question 8

#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

/*
1. Write a main function that takes user input as a number and sends it to the printOddNumsWhile function
2. Write an printOddNumsWhile function that takes user input and prints every odd number from 1 up till that number regardless of if it is an even or odd number
    a. The printOddNumsWhile function has to use only if statements or while loops to "count up" the odd numbers
    b. The printOddNumsWhile function should check if user input is odd or even
    c. If it is even, subract one from the user input, start counting up from 1 add 2 to 1 until the number is less than user input - 1
    d. If it is odd, start at 1 and add 2 to 1 until the number is less than user input
Input: user input (int type)
Output: 1 ... (then every odd number until the user input number is reached)
Return: nothing
*/

int printOddNumsWhile(int number)           //takes user input                        
{
    if (number > 0)                         //first check to see if user input is greater than 0
    {
        if ((number % 2 == 0))              //check to see if user input is even
        {
            number = number - 1;            //subtracts 1 from user input to get closest odd number
            int x = 1;                      //we start counting up from 1
            cout << x << endl;              //outputs our starting value of 1
        
            while (x < number)              //while loop basically does the calculation in brackets until we reach user input
            {
                x = x + 2;                  //calculates odd numbers that are less than the user input
                cout << x << endl;
            }
        }
    
        else                                //if the number is odd
        {
            int x = 1;                      //we start counting odd numbers up from 1
            cout << x << endl;              //so we start with 1
        
            while (x < number)              //while loop repeats until the value of x reaches the value of the user input
            {
                x = x + 2;
                cout << x << endl;
            }
        }
    }
}

int main()
{
	int number;
	
	cout << "Enter a number: ";
	cin >> number;

	printOddNumsWhile(number);
	cout << endl;
	
	//Test 1
	//Input: 3
	//Expected Output: 1 3
	printOddNumsWhile(3);
	cout << endl;
	
	//Test 2
	//Input: 10
	//Expected Output: 1 3 5 7 9
	printOddNumsWhile(10);
}