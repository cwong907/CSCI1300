// CSCI 1300 Fall 2019
// Author: Weige Wong
// Recitation: 203 - Soumyajyoti Bhattacharya
// Homework 3 - Question 7

#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

/*
Function should output the next numbers in the collatz step based off of user input 
1. Write a main function that takes user input for a number
2. Write int function that takes that input and checks if it is divisible by 2 or not
    a. If it is divisible by 2 then take the user input and divide it by 2
    b. If it is not then multiply it by 3 and add 1
    c. If the number is 0 or less, then say invalid number
Input: number (int type)
Output: a list of numbers greater than 1 while following the rules of the collatz step
Return: a calculation based off of whether the starting number is even or not following the collatz step
*/


int collatzStep(int number)                 //the int collatzStep function that reads user input that is sent from printCollatz and checks if it is even or not 
{
    int a, b;

    if (number % 2 == 0)                    //if it is even then divide user input by 2 and return that quotient to the printCollatz function
    {
        a = number / 2;
        return a;
    }
   
   if (number % 2 > 0)                      //if it is odd then multiply user input by 3 and and add 1 and return to the printCollatz function
    {    
        b = (3 * number) + 1;
        return b;
    }
}

int printCollatz(int number)                //takes the user input and checks if it is larger or smaller than 0                      
{
    if (number <= 0)                        //if it is less than 0 then say invalid number
    {
        cout << "invalid number" << endl;
    }
    
    else                                    //else cout the starting number so we know what we start with
    {
        cout << number << " ";
        do                                  //do loop takes the user input and sends it to the collatzStep function to check and calculate the next value it does this while that next/calculated value is greater than 1
        {
            number = collatzStep(number);   //sends user input to collatzStep redefined as number so that we can output the next numbers in the collatz step
            cout << number << " ";
        } 
        while (number > 1);                 //when to stop doing the do loop since we want to stop at 1 for the collatz step patter.
    }
    cout << endl;
}

int main()
{
	int number;
	
	cout << "Enter a number." << endl;
	cin >> number;

	printCollatz(number);
	
	//Test 1
	//Input: 2
	//Expected Output: 2 1
	//cout << printCollatz(2) << endl;
	printCollatz(2);
	
	//Test 2
	//Input: 3
	//Expected Output: 3 10 5 16 8 4 2 1
	//cout << printCollatz(3) << endl;
	printCollatz(3);
}