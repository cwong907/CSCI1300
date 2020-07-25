// CSCI 1300 Fall 2019
// Author: Weige Wong
// Recitation: 203 - Soumyajyoti Bhattacharya
//Homework 2 - Question 7

#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

/*
1. Create main function that takes user input for amount of seconds
2. Create void function that calculates the number of hours, minutes, and seconds from the user input of seconds by using divison and the modulo function
3. Have the void function print out the number of hours, minutes, and seconds
*/

void convertSeconds (int seconds)                   //void function that calculates the number of hours, minutes, and seconds and outputs those calculation to console
{
 int hours;
 int minutes;
 int sec;
 
 hours = seconds/3600;                              //calculates hours
 minutes = (seconds%3600)/60;                       //calculates minutes using modulo (modulo gives us remainder of hours which is divided 60 to get min)
 sec = seconds%60;                                  //calculates seconds using modulo
 
 cout << hours << " hour(s) " << minutes << " minute(s) " << sec << " second(s)" << endl;   
}

int main()                                          //main function that takes a user input for seconds
{
    int seconds;
	
	cout << "Enter a number of seconds." << endl;   //prompt for the user to input a number of seconds
	cin >> seconds;
	
	convertSeconds(seconds);
	
	//Test 1 
	//Input: 4321
	//Expected Output: 1 hour 5 min 21 sec
	convertSeconds(4321);     
	
	//Test 2
	//Input: 9876
	//Expected Output: 2 hours 44 min 36 sec
	convertSeconds(9876);
}