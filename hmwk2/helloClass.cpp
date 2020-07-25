// CSCI 1300 Fall 2019
// Author: Weige Wong
// Recitation: 203 - Soumyajyoti Bhattacharya
//Homework 2 - Question 2

/*
1. Ask the user to input a CS course number.
2. Take the user input and output to the console with the, "Hello, CS ... World!"
Inputs: CS Course Number (int type)
Output: "Hello, CS ... World!"
Return: Nothing
*/

#include <iostream>
using namespace std;

int main()

{
    int csciClass;
    
    cout << "Enter a CS course number:" << endl;    //user inputs CS course number
    cin >> csciClass;                              
    
    cout << "Hello, CS " << csciClass << " World!" <<endl;  //outputs CS course number with text
}