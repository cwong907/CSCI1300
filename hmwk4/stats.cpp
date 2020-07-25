// CSCI 1300 Fall 2019
// Author: Weige Wong
// Recitation: 203 - Soumyajyoti Bhattacharya
// Homework 4 - Problem 3

/*
1. Write a fuction that has an array populated with numbers and stores the length of the array as a separate variable
2. Write a function that takes that array and length variable and uses the numbers stored in the array to:
	a. calculates the minimum value
	b. calculates the maximum value
	c. calculates the average value
Input: an array with numbers (int type), length of the array (int type)
Output: Min, Max, Avg (double type)
Return: nothing
*/

#include <iostream>
#include <math.h>
#include <iomanip>
#include <string>
using namespace std;

void stats(double array[], int length)
{
	cout << fixed;
	cout <<setprecision(2);						//this sets the amount of decimal places we go to when cout-ing our calculated values
	
	double max = 0;								//initializes max and tot variables
	double min = array[0];						//initializes min to be the first number in the array so that we can start with a pre-existing number in the array so we're always comparing to numbers in the array
	double tot = 0;
	for(int i = length - 1; i >= 0; i--)		//loops through the array
	{
		if(min > array[i])						//as the for loop goes through every number in the array, it checks to see if that number is less than the previous one in the array, if it is it sets min to that number
		{
			min = array[i];
		}
		
		if(max < array[i])						//as the for loop goes through every number in the array, it checks to see if that number is greater than the previous one in the array, if it is it sets max to that number
		{
			max = array[i];
		}
		
		tot = array[i] + tot;					//every time the for loop goes through the numbers stored in the array, it adds them together
	}
	cout << "Min: " << min << endl;
	cout << "Max: " << max << endl;
	
	double ave = tot / length;					//calculates the average value
	cout << "Avg: " << ave << endl;
}

int main()
{
	//Test 1
	//Input: 0.1, 1.05, 4.23, 3.98; 4
	//Expected Output: Min: 0.10, Max: 4.23, Avg: 2.34
	double array[] = {0.1, 1.05, 4.23, 3.98};
	int length = 4;
	stats(array, length);
	cout << endl;
	
	
	//Test 2
	//Input: 1, 2, 3, 4, 5, 6; 6
	//Expected Output: Min: 1.00, Max: 6.00, Avg: 3.50
	double array2[] = {1, 2, 3, 4, 5, 6};
	int length2 = 6;
	stats(array2, length2);
}