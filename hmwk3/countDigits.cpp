// CSCI 1300 Fall 2019
// Author: Weige Wong
// Recitation: 203 - Soumyajyoti Bhattacharya
// Homework 3 - Question 4

#include <iostream>
#include <math.h>
#include <cmath>
using namespace std;

/*
1. Write a main function that takes user input as an integer
2. Write a countDigits function that takes the absolute value of that user input and checks if it is 0
3. If user input is 0 then output 1
4. If not use a while loop to count the number of digits in the user input
Input: x (int type)
Output: number (int type)
Return: c
*/

int countDigits(int x)
{
    x = abs(x);                         //takes the absolute value so negatives don't matter
    
    if (x == 0)                         //checks if user input is 0
    {
        int c = 1;
        return c;
    }
    else                            
    {
        int c = 0;                      //c is the variable we are going to assing when we count the number of digits in user input
        while (x != 0)                  //while user input is no 0 so the while loops knows when to stop
        {
            c = c + 1;                  //every time the loop repeats we add 1 to c, the loop repeats the same amount of times as there are digits in user input 
            x = x / 10;                 //when we divide by 10, since we are using int data types, it truncates the last digit from user input each loop which gives us the amount of times to execute the loop
        }
    
    return c;
    }
}

int main()
{
    int x;
    
	cout << "Enter an integer." << endl;
	cin >> x;
	
	cout << countDigits(x) << endl;
	
	//Test 1
	//Input: 0
	//Expected Output: 1
	cout << countDigits(0) << endl;
	
	//Test 2
	//Input: 1234
	//Expected Output: 4
	cout << countDigits(1234) << endl;
}