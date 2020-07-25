// CSCI 1300 Fall 2019
// Author: Weige Wong
// Recitation: 203 - Soumyajyoti Bhattacharya
// Homework 4 - Problem 2

/*
1. Write a fuction that contains an array with numbers in that array as well as a separate value for the length of the array
2. Write a function that takes those variables and prints the array in reverse
Input: an array with numbers (int type), length of the array (int type)
Output: numbers (int type)
Return: nothing
*/

#include <iostream>
#include <math.h>
#include <iomanip>
#include <string>
using namespace std;

void printArrReverse(int array[], int length)				
{
	for(int i = length - 1; i >= 0; i--)				//this for loop starts at length - 1 to get the last number stored in the array and counts backwards until it reaches 0 to access the array in reverse order
	{
		cout << array[i] << endl;
	}
}

int main()
{
	//Test 1
	//Input: 0, 1, 2, 3
	//Expected Output: 3, 2, 1, 0
	int array[] = {0, 1, 2, 3};
	int length = 4;
	
	printArrReverse(array, length);
	cout << endl;
	
	//Test 2
	//Input: 3, 2, 1
	//Expected Output: 1, 2, 3
	int array2[] = {3, 2, 1};
	int lenghts = 3;
	
	printArrReverse(array2, lenghts);
}