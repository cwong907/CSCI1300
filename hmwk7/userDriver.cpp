// CSCI 1300 Fall 2019
// Author: Weige Wong
// Recitation: 203 - Soumyajyoti Bhattacharya
// Homework 7 - Problem 1

#include <iostream>
#include "User.h"
using namespace std;

/*
1. Write a User.h header file and User.cpp implementation file
2. Populate the header file with variable names and function names
3. Populate the implementation file with what the functions do and constructors
4. Write a main function to use the header and implementation file and test functions
Input: username, number of ratings, size, an array, index (string, int, int, int, int types)
Output: username, rating, number of ratings, size (string, int, int, int types)
Return: username, rating, number of ratings, size (string, int, int, int types)
*/

int main()
{
    User localUser;
    
    //Test 1
    //Input: "Alaska", 4, 3
    //Output: Alaska, 3
    localUser.setUsername("Alaska");
    localUser.setRatingAt(4, 3);
    cout << localUser.getUsername() << endl;
    cout << localUser.getRatingAt(4) << endl;
    
    //Test 2
    //Input: 25
    //Output:25, 50
    localUser.setNumRatings(25);
    cout << localUser.getNumRatings() << endl;
    cout << localUser.getSize() << endl;
}