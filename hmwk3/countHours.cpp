// CSCI 1300 Fall 2019
// Author: Weige Wong
// Recitation: 203 - Soumyajyoti Bhattacharya
// Homework 3 - Question 5

#include <iostream>
#include <math.h>
#include <cmath>
using namespace std;

/*
1. Write a main function that asks for user input for the number associated with the month in a year
2. Write a countHours function that takes that integer and uses a switch statement that categorizes what month it is
3. Once the categorization is done, multiply the number of days in that month by 24 and return that to the main
Input: number (int type)
Output: hours (int type)
Return: h

*/

int countHours (int month)
{
    int h;
    switch (month)                  //switch statement where each month of the year corresponds with a number starting a January with 1
    {
        case 1:
            h = (31) * 24;          //takes the days in that month and mulitplies it by 24 hours to get hours in the month, each case below corresponds to the days in that month
            return h;
            break;
        case 2:
            h = 28 * 24;
            return h;
            break;
        case 3:
            h = 31 * 24;
            return h;
            break;
        case 4:
            h = 30 * 24;
            return h;
            break;
        case 5:
            h = 31 * 24;
            return h;
            break;
        case 6:
            h = 30 * 24;
            return h;
            break;
        case 7:
            h = 31 * 24;
            return h;
            break;
        case 8:
            h = 31 * 24;
            return h;
            break;
        case 9:
            h = 30 * 24;
            return h;
            break;
        case 10:
            h = 31 * 24;
            return h;
            break;
        case 11:
            h = 30 * 24;
            return h;
            break;
        case 12:
            h = 31 * 24;
            return h;
            break;
    }
}

int main()
{
    int month;
    
	cout << "Enter a month number (ex. January would be 1, November would be 11)." << endl;
	cin >> month;
	
	cout << countHours(month) << endl;
	
	//Test 1
	//Input: 2
	//Expected Output: 672
	cout << countHours(2) << endl;
	
	//Test 2
	//Input: 11
	//Expected Output: 720
	cout << countHours(11) << endl;
}