// CSCI 1300 Fall 2019
// Author: Weige Wong
// Recitation: 203 - Soumyajyoti Bhattacharya
// Homework 4 - Problem 4

/*
1. Write a fuction that has an array populated with numbers and stores the length of the array as a separate variable
2. Write a function that takes the array and its length and takes the first number in the array and sets it to the last one and takes the last number and swaps it into the first one of the array
Input: an array with numbers (int type), length of the array (int type)
Output: numbers (int type)
Return: nothing
*/

#include <iostream>
#include <math.h>
#include <iomanip>
#include <string>
using namespace std;

void swapFirstLast(int array[], int length)
{
	int x = array[0];									//declares the variable x to be the first number in the array
	
	array[0] = array[length - 1];						//takes the first number in the array and sets it to the last one
	array[length - 1] = x;								//takes the last number in the array and sets it to x
	
	for(int i = 0; i <= length - 1; i++)				//prints the array
	{
		cout << array[i] << endl;
	}
}

int main()
{
	//Test 1
	//Input: 4, 2, 3, 1, 89; 5
	//Expected Output: 89, 2, 3, 1, 4
	int array[] = {4, 2, 3, 1, 89};
	int length = 5;
	swapFirstLast(array, length);
	cout << endl;
	
	//Test 2
	//Input: 1, 2
	//Expected Output: 2, 1
	int array2[] = {1, 2};
	int length2 = 2;
	swapFirstLast(array2, length2);
}