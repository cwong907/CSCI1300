// CSCI 1300 Fall 2019
// Author: Weige Wong
// Recitation: 203 - Soumyajyoti Bhattacharya
// Homework 4 - Extra Credit

/*
1. Write a fuction that has an array, a variable that corresponds to the size of the array, and the number of shifts for each element in the array
2. Write another function that takes those inputs and takes each element in the array and shifts them over the number of times that was declared for the variable shifts
3. If the number of shifts is 0 or less then output No shifts
4. If the number of shifts is greater than the number of elements then:
	a. Take the number of shifts and divide it by the number of elements and only take the remainder and set that to be your number of shifts
Input: array (int type), elements (int type), shifts (int type)
Output: array (int type), or No shift
Return: nothing
*/

#include <iostream>
#include <string>
using namespace std;

void shiftElements(int array[], int elements, int shifts)
{

	if(shifts <= 0)											//checks if the number of shifts are equal to or less than 0
	{
		cout << "No shift" << endl;
	}
	
	else if(shifts > elements)								//checks if the number of shifts are greater than the elements
	{
		shifts = shifts % elements;							//sets shifts to equal shifts mod elements to get the remainder
		
		int n = 0;
		
		while(n < shifts)									//so basically everything in this while loop moves each element over one and the while loop repeats this "shift", n amount of times where n is the user defined amount of times to shift an element
		{
			int x = array[elements - 1];					//this sets the last thing in the array to x

			for(int i = elements - 1; i >= 0; i--)			//starts at the last index of the array and works backwards
			{
				array[i] = array[i - 1];					//this sets and index to the left of i to be i (where position i is determined by the for loop)
			}
			array[0] = x;									//since we're only moving over by one in this whole for loop, the last element in the array can be set to the last one
			n++;											//adds one to n so the program can keep track of how many times to repeat the while loop
		}
		
		for(int i = 0; i <= elements - 1; i++)				//ouputs the new array organization 
		{
			cout << array[i] << endl;
		}
	}
	
	else
	{
		int n = 0;
		
		while(n < shifts)									//this is the same as above the only difference is that this case is for when the number of shifts is less than the number of elements
		{
			int x = array[elements - 1];

			for(int i = elements - 1; i >= 0; i--)
			{
				array[i] = array[i - 1];
			}
			array[0] = x;
			n++;
		}
		
		for(int i = 0; i <= elements - 1; i++)
		{
			cout << array[i] << endl;
		}
	}
}

int main()
{
	
	//Test 1
	//Input: {2, 3}, 2, 5
	//Output: 3, 2
	int array[] = {2, 3};
	int elements = 2;
	int shifts = 5;
	shiftElements(array, elements, shifts);
	cout << endl;
	
	
	//Test 2
	//Input: {1, 2, 3}, 3, 2
	//Output: 2, 3, 1
	int array2[] = {1, 2, 3};
	int elements2 = 3;
	int shifts2 = 2;
	shiftElements(array2, elements2, shifts2);
}