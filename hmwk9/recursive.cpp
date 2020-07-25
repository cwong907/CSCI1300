// CSCI 1300 Fall 2019
// Author: Weige Wong
// Recitation: 203 - Soumyajyoti Bhattacharya
// Homework 9 - Problem 2  

#include <iostream>
#include <math.h>
#include <iomanip>
#include <cmath>
using namespace std;

/*
1. Write a main function that passes an integer
2. Write a function that takes that integer and:
    a. Uses the modulo to divide the input number by 2
    b. Takes that remainder, converts it to string, and add it to a blank string b
    c. Then returns a call to itself plus the string b
3. When the function makes that call, beginning with the passed integer, it will divide the entered number by int 2 until it equals 0 (the stop case)
4. Since the first binary number is added first, and every number after that is added to the string, it will reverse the order for us
5. Return that string
Input: number (int type)
Output: binary conversion of that number (string type)
Return: binary order (string type)
*/

string decimalToBinaryRecursive(int number)
{
    if(number != 0)                                                     //the stop condition    
    {
        int a = number % 2;                                             //modulo remainder gives us the binary
        string b = to_string(a);                                        //string conversion
        
        return decimalToBinaryRecursive(number / 2) + b;                //returns the function call with the division so we don't go on forever and the addition of the b at the end is binary; since recursion works backwards it will return the binary in reverse order
    }
    
    else                                                                //the else
    {
        return "0";
    }
    
}

int main()
{
    //Test 1
    //Input: 5
    //Output: 0101
    cout << decimalToBinaryRecursive(5) << endl;
    
    //Test 2
    //Input: 26
    //Output: 011010
    cout << decimalToBinaryRecursive(26) << endl;
}