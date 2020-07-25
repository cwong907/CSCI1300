// CSCI 1300 Fall 2019
// Author: Weige Wong
// Recitation: 203 - Soumyajyoti Bhattacharya
// Homework 4 - Problem 1

/*
1. Write a fuction that uses arrays to store:
	a. 10 temperature values
	b. 5 color names
	c. numbers 1 through 100
	d. all letters of the English alphabet (both upper and lowercase)
2. Then output what's stored in the arry
Input: number (double type), color (string), numbers (int type), letters (char)
Output: same as input
Return: nothing
*/

#include <iostream>
#include <math.h>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
	double temps[] = {-459.67, -459.67, -459.67, -459.67, -459.67, -459.67, -459.67, -459.67, -459.67, -459.67};		//array of temps
	
	string colors[] = {"Red", "Blue", "Green", "Cyan", "Magenta"};														//array of colors
	
	int sequence[100];																									//array of numbers 1-100 but I'm only saying that it has 100 things to put inside it
	
	char letters[26];																									//array for lowercase letters
	char letter[26];																									//array for uppercase letters
	

    for(int i = 0; i < 10; i++)																							//this for loop goes through every index of the temp array and prints it out all the things stored in that array
    {
	cout << temps[i] << endl;
    }
    cout << endl;
    
    for(int i = 0; i < 5; i++)																							//this for loop does the same thing as the one above but goes through the color array
    {
    	cout << colors[i] << endl;
    }
    cout << endl;
    
    for(int i = 1; i <= 100; i++)																						//so this loop populates the sequence array with numbers from 1 to 100 by using the i counter in the for loop to enter values into the array
	{
		sequence[i] = i;
	}
    for(int i = 1; i <= 100; i++)																						//this for loop then prints the sequence array by going through the index (that was populated earlier by the previous for loop)
	{
		cout << sequence[i] << endl;
	}
	cout << endl;
	
	for(int i = 0; i < 26; i++)																							//this for loop repeats 26 times because there are 26 letters in the English alphabet
	{
		letter[i] = (char) 65 + i;																						//this array has the char type for individual letters and each number corresponds with a letter in the ascii table; each time it loops through once, it adds one to the number to get the next letter and populates the array with letters
		letters[i] = (char) 97 + i;																						//the letter array has capitals and the letters array has lowercase
	}
	for(int i = 0; i < 26; i++)																							//this loop prints the contents of both arrays
	{
		cout << letter[i] << " " << letters[i] << endl;
	}
}