// CSCI 1300 Fall 2019
// Author: Weige Wong
// Recitation: 203 - Soumyajyoti Bhattacharya
// Homework 3 - Question 6

#include <iostream>
#include <math.h>
#include <cmath>
using namespace std;

/*
1. Write a main function that takes user input for a year
2. Write a bool function that checks if the user entered year is a leap year or not and returns its findings to the main function
	a. Within the bool function, first check if the year is less than 1582. If it is, then divide the year by 4, if there is no remainder, then tell the main function that that year is a leap year
	b. If the user entry is greater than 1582 then first check if it is perfectly divisble by 100
		i. If it is not then check if it is perfectly divisible by 400 or 4
		ii. If it matches either case stated above, then it is a leap year, otherwise it is not
	d. If the user entry is perfectly divisible by 100 then also check if it is perfectly divisble by 400 or 4
		i. If it passes either of the aforementioned cases, then it is a leap year, if it fails both cases then it is not a leap year
Input: years (int type)
Output: 1 or 0 (true or false)
Return: true or false
*/

bool checkLeapYear (int year)							//bool function that checks the use entered year for if it is a leap year or not
{
    if (year < 1582)									//first check to see if it is less than 1582
    {
        if (year % 4 == 0)								//leap years before 1582 are divisible by 4
        {
        	return true;
        }
        return false;
    }
    
	if (year >= 1582)									//second check to see if entered year is greater than 1582
    {
    	if (year % 100 != 0)							//checks to see if year has a remainder when divided by 100 (for leap years like 1600 )
    	{
    		if (year % 400 == 0 || year % 4 == 0)		//or check to see if year is divisble by 400 or 4
    		{
    			return true;	
    		}
    		return false;	
    	}
    	
    	if(year % 100 == 0)								//checks to see if entered year is perfectly divisible by 100
    	{
    		if ((year % 400 == 0) && (year % 4 == 0))	//and check to see if year is divisble by 400 or 4
    		{
    			return true;	
    		}
    		return false;	
    	}
    }
}

int main()
{
    int year;
    
	cout << "Enter a year." << endl;
	cin >> year;
	
	if (checkLeapYear(year) == 0)						//if else statements that take the return of the bool and cout's a confirmation on leap year or not
	{
	    cout << "This year is not a leap year." << endl;
	}
	else 
	{
	    cout << "This year is a leap year." << endl;
	}
	
	//Test 1
	//Input: 2000
	//Expected Output: 1 (which means true)
	cout << checkLeapYear(2000) << endl;
	
	//Test 2
	//Input: 1880
	//Expected Output: 0 (which means false)
	cout << checkLeapYear(1771) << endl;
}