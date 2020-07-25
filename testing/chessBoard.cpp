// CSCI 1300 Fall 2019
// Author: Weige Wong
// Recitation: 203 - Soumyajyoti Bhattacharya
// Homework 3 - Question 3

#include <iostream>
#include <math.h>
using namespace std;


void chessBoard(string letter, int number)
{
	if (letter > "h" || number > 8) 
	{
		cout << "Chessboard squares can only have letters between a-h and numbers between 1-8." << endl;
		return;
	}
	
	if (letter > "H" && letter < "Z")												//ascii value of capital vs lowercase (lowercase always has a higher numeric value assigned to it)
	{
		cout << "Chessboard squares can only have letters between a-h and numbers between 1-8." << endl;
		return;
	}			
		
	if ((letter == "a") || (letter == "A") || (letter == "c") || (letter == "C") || (letter == "e") || (letter == "E") || (letter == "g") || (letter == "G"))
	{
		if (number % 2 > 0)
		{
			cout << "Black" << endl;
		}
	}
	
	if ((letter == "b") || (letter == "B") || (letter == "d") || (letter == "D") || (letter == "f") || (letter == "F") || (letter == "h") || (letter == "H"))
	{
		if (number % 2 == 0)
		{
			cout << "Black" << endl;
		}
	}
	
	if ((letter == "a") || (letter == "A") || (letter == "c") || (letter == "C") || (letter == "e") || (letter == "E") || (letter == "g") || (letter == "G"))
	{
		if (number % 2 == 0)
		{
		cout << "White" << endl;
		}
	}
	
	if ((letter == "b") || (letter == "d") || (letter == "f") || (letter == "h"))
	{
		if (number % 2 > 0)
		{
		cout << "White" << endl;
		}
	}
}

int main()
{
    string letter;
    int number;
    
	cout << "Please enter a letter." << endl;
	cin >> letter;
	
	cout << "Please enter a number." << endl;
	cin >> number;
	
	chessBoard(letter, number);
}