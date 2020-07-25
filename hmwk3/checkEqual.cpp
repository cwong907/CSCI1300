// CSCI 1300 Fall 2019
// Author: Weige Wong
// Recitation: 203 - Soumyajyoti Bhattacharya
// Homework 3 - Question 2

#include <iostream>
#include <math.h>
using namespace std;

/*
1. Write a main function that asks for 3 numbers
2. Write a checkEqual function that compares the 3 and sees if they are all equal or all different or neither
Input: 3 user inputs (int type)
Output: All same, all different, or neither
Return: Nothing
*/

void checkEqual(int x, int y, int z)                    //takes the 3 ints that are user inputs     
{
    if (x == y && y == z)                               //checks if x is equal to y and if y is equal to z
    {
        cout << "All same" << endl;
    }
    
    else if (x != y && y != z && x != z)                //checks if x is not equal to y and if y is not equal to z and if x is not equal to z
    {
        cout << "All different" << endl;
    }
    
    else                                                //if none of those cases match
    {
        cout << "Neither" << endl;
    }
}

int main()
{
    int x, y, z;
    
	cout << "Please input a number for x." << endl;
	cin >> x;
	
	cout << "Please input a number for y." << endl;
    cin >> y;
    
    cout << "Please input a number for z." << endl;
    cin >> z;
    
    checkEqual(x, y, z);
    
    //Test 1
    //Input: 1, 1, 1
    //Expected Output: All same
    checkEqual(1, 1, 1);
    
    //Test 2
    //Input: 1, 2, 3
    //Expected Output: All different
    checkEqual(1, 2, 3);
}