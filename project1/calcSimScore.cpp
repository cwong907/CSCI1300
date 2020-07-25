// CSCI 1300 Fall 2019
// Author: Weige Wong
// Recitation: 203 - Soumyajyoti Bhattacharya
// Project 1 - Problem 4

#include <iostream>
#include <math.h>
#include <iomanip>
#include <string>
using namespace std;


/*
1. Write a main function that asks the user to enter 2 strings for sequence 1 and 2
2. Write a double function that first checks to see if either sequence is empty or if their lengths are uneven 
	a. If they are output 0
3. If they past the tests then iterate through each string letter by letter and check to see where they are not similar and add the time they are
4. Take the amount of times they are not similar and subtract it from the lenght of the string and divide it by the string lenght and output it
Input: user input (string type)
Output: match as a decimal (double type)
Return: simScore
*/

double calcSimScore(string s1, string s2)
{
	if(s1 == "" || s2 == "" || (s1.length() != s2.length()))												//checks for empty string inputs or uneven string lengths
	{
		int a = 0;
		return a;
	}
	
	else
	{
		double hamming_distance;														
		for(int i = 0; i < s1.length(); i++)																//for loop goes through each letter of both strings
		{
			if(s1.substr(i, 1) != s2.substr(i, 1))															//this if statement checks each letter at position i (i being dictated by the for loop) and sees if they don't match
			{
				hamming_distance++;																			//adds up the time they don't match
			}
		} 
		double simScore = ((double) s1.length() - (double)hamming_distance) / (double)s1.length();			//equation for match percentage as a decimal
		return simScore;
	}
}

int main()
{
	string s1 = "";
	string s2 = "";
	
	cout << "Enter Sequence 1." << endl;
	cin >> s1;
	
	cout << "Enter Sequence 2." << endl;
	cin >> s2;
	
	calcSimScore(s1, s2);
	cout << calcSimScore(s1, s2) << endl;
	
	//Test 1
	//Input: "", "BBAA"
	//Output: 0
	cout << calcSimScore("", "BBAA") << endl;
	
	//Test 2 
	//Input: "GATTACA", ""
	//Output: 0
	cout << calcSimScore("GATTACA", "") << endl;
	
	//Test 3
	//Input: "ABBA", "AB"
	//Output: 0
	cout << calcSimScore("ABBA", "AB") << endl;
	
	//Test 4
	//Input: "ABBA", "ABBC"
	//Output: 0.75
	cout << calcSimScore("ABBA", "ABBC") << endl;
}