// CSCI 1300 Fall 2019
// Author: Weige Wong
// Recitation: 203 - Soumyajyoti Bhattacharya
// Project 1 - Problem 1

#include <iostream>
#include <math.h>
#include <iomanip>
#include <string>
using namespace std;

/*
1. Create a main function that takes a user input for a string
2. Create a void function that checks the user input for an empty string, if it is isn't, then the function should go letter by letter and print out each letter on a new line
Input: user input (string type)
Output: letters of a word (char type)
Return: nothing
*/

void printCharInString(string s)
{
    if (s == "")                                        //checks to see if user entered string is empty or not
    {
        cout << "Given string is empty!" << endl;
    }
    
    else 
    {
        for (int i = 0; i < s.size(); i++)              //goes letter by letter in a string and outputs the characters 
        {
            cout << s[i] << endl;
        }
    }
}

int main()
{
    string s = "";
    
	cout << "Enter a word." << endl;
	cin >> s;
	
	printCharInString(s);
	cout << endl;
	
	//Test 1
	//Input: ""
	//Ouput: Given string is empty!
	printCharInString("");
	cout << endl;
	
	//Test 2
	//Input: Uncharted
	//Output:U c h a r t e d but each letter on a new line
	printCharInString("Uncharted");
}