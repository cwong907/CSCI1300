// CSCI 1300 Fall 2019
// Author: Weige Wong
// Recitation: 203 - Soumyajyoti Bhattacharya
// Homework 9 - Problem 1  

#include <iostream>
#include <math.h>
#include <iomanip>
#include <cmath>
//#include <bits/stdc++.h>
using namespace std;

/*
1. Write a main function that passes an integer
2. Write a function that takes that integer and checks if it is 0
    a. If it is, return 0
3. If not, then it:
    a. Uses the modulo to divide the input number by 2
    b. Then divide the number by an int 2 
    c. Takes that remainder, converts it to string, and add it to a blank string b
4. It repeats this until the number is 0
5. Return that string
Input: number (int type)
Output: binary conversion of that number (string type)
Return: reversed binary order (string type)
*/

string decimalToBinaryIterative(int number)
{
    int a = number;
    string b = "";
    
    if(number == 0)                         //checks for 0
    {
        return "0";
    }
        
    while(number != 0)                      //since int division truncates, it will loop until number/2 is 0
    {
        a = number % 2;                     //modulo remainder gives us the binary
        number = number / 2;                //when this equals 0 it's our cue to stop
        b = to_string(a) + b;               //adds with a going first to reverse the string
    }
    //reverse(b.begin(), b.end());
    
    
    return b;
}

int main()
{
    //Test 1
    //Input: 26
    //Output: 11010
    cout << decimalToBinaryIterative(26) << endl;
    
    //Test 2
    //Input: 0
    //Output: 0
    cout << decimalToBinaryIterative(0) << endl;
}