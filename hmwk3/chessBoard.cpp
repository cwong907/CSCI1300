// CSCI 1300 Fall 2019
// Author: Weige Wong
// Recitation: 203 - Soumyajyoti Bhattacharya
// Homework 3 - Question 3

#include <iostream>
#include <math.h>
using namespace std;

/*
1. Write a main function that asks for user input for a letter and a number
2. Write a chessBoard function that uses if statements to check if user entered letters are a-h, if they aren't or if they are A-H then it tells the user to enter valid characters
3. chessBoard function also checks that the number entered is 1-8, if not it tells the user to enter a valid number
4. If the letters and numbers are valid, then the function looks to see if it is a, c, e, or g and if they are it checks if the number is not divisible by 2; if both are ture then it is a black square
5. The function looks to see if user entered letter is b, d, f, or h and if it is divisible by 2; if both are true then it is a black square
6. The function looks to see if user entered letter is a, c, e, or g and if it is divisible by 2; if both are true then it is a white square
7. The function looks to see if user entered letter is b, d, f, or h and if it is not divisible by 2; if both are true then it is a white square
Input: letter and number (char and int type)
Output: black, white, or Chessboard squares can only have letters between a-h and numbers between 1-8.
Return: nothing
*/

void chessBoard(char letter, int number)    //can use a compare but have to put single quotes aroud letter
{
	//checks if user entered letter is A-H or if user number is less than 1 or greater than 8
	if (letter == 'A' || letter == 'B' || letter == 'C' || letter == 'D' || letter == 'E' || letter == 'F' || letter == 'G' || letter == 'H' || number < 1 || number > 8) 
	{
		cout << "Chessboard squares can only have letters between a-h and numbers between 1-8." << endl;
	}
	
	//checks if user entered letter is I-Z
	if (letter == 'I' || letter == 'J' || letter == 'K' || letter == 'L' || letter == 'M' || letter == 'N' || letter == 'O' || letter == 'P' || letter == 'Q' || letter == 'R' || letter == 'S' || letter == 'T' || letter == 'U' || letter == 'V' || letter == 'W' || letter == 'X' || letter == 'Y' || letter == 'Z') 
	{
		cout << "weChessboard squares can only have letters between a-h and numbers between 1-8." << endl;	
	}
	
	//checks if user entered letter is i-z
	if (letter == 'i' || letter == 'j' || letter == 'k' || letter == 'l' || letter == 'm' || letter == 'n' || letter == 'o' || letter == 'p' || letter == 'q' || letter == 'r' || letter == 's' || letter == 't' || letter == 'u' || letter == 'v' || letter == 'w' || letter == 'x' || letter == 'y' || letter == 'z') 
	{
		cout << "Chessboard squares can only have letters between a-h and numbers between 1-8." << endl;	
	}
	
	//checks if letter is a-h and if number is less than 8 and greater than 1
	if ((letter == 'a' || letter == 'b' || letter == 'c' || letter == 'd' || letter == 'e' || letter == 'f' || letter == 'g' || letter == 'h') && (number <= 8 && number >= 1)) 
	{
		//checks if letter is a, c, e, or g and if number is not divisible by 2 to see if it is a black square
		if ((letter == 'a') || (letter == 'c') || (letter == 'e') || (letter == 'g'))
		{
			if (number % 2 > 0)
			{
				cout << "black" << endl;
			}
		}
		
		//checks if letter is b, d, f, or h and if number is divisible by 2 to see if it is a black square
		if ((letter == 'b') || (letter == 'd') || (letter == 'f') || (letter == 'h'))
		{
			if (number % 2 == 0)
			{
				cout << "black" << endl;
			}
		}
		//checks if letter is a, c, e, or g and if number is divisible by 2 to see if it is a white square	
		if ((letter == 'a') || (letter == 'c') || (letter == 'e') || (letter == 'g'))
		{
			if (number % 2 == 0)
			{
				cout << "white" << endl;
			}
		}
		
		//checks if letter is b, d, f, or h and if number is not divisible by 2 to see if it is a white square
		if ((letter == 'b') || (letter == 'd') || (letter == 'f') || (letter == 'h'))
		{
			if (number % 2 > 0)
			{
				cout << "white" << endl;
			}
		}
	}
}

int main()
{
    char letter, a, j;
    int number;
    
	cout << "Please enter a letter." << endl;
	cin >> letter;
	
	cout << "Please enter a number." << endl;
	cin >> number;
	
	chessBoard(letter, number);
	
	//Test 1
	//Input: a, 5
	//Expected Output: black
	chessBoard('a', 5);
	
	//Test 2
	//Input: j, 1
	//Expected Output: "Chessboard squares can only have letters between a-h and numbers between 1-8."
	chessBoard('j', 1);
}
