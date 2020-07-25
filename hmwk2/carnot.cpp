// CSCI 1300 Fall 2019
// Author: Weige Wong
// Recitation: 203 - Soumyajyoti Bhattacharya
// Homework 2 - Question 9

#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

/*
1. Create a main function that takes user input for the cold and hot temperatures
2. Create a double function that takes the user inputs and uses the carnot efficiency equation to calculate the carnot efficiency 
3. Return the value for the carnot efficiency back to the main function
4. Output the carnot efficiency from the main function
Input: t_C, t_H (int type)
Output: n (double type)
Return: n (double type)
*/

double carnot(int t_C, int t_H)                         //declared variable data type in function has to match the variable type that is in the main
{                                                       //returns n as a double
    double n;
    
    return n = 1 - ((double) t_C / (double) t_H);       //function that calculate the carnot efficiency
    
}

int main()
{
    int t_C, t_H;
    
    cout << "Enter a cold temp." << endl;               //user enter hot and cold temps
    cin >> t_C;
    
    cout << "Enter a hot temp." << endl;
    cin >> t_H;
	
	cout << carnot(t_C, t_H) << endl;
	
	//Test 1
	//Input: 160, 1100 for cold and hot respectively
	//Expected Output: 0.854545
	cout << carnot(160, 1100) << endl;
	
	//Test 2
	//Input: 200, 2000 for cold and hot respectively
	//Expected Output: 0.9
	cout << carnot(200, 2000) << endl;
}