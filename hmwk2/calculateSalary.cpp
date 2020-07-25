// CSCI 1300 Fall 2019
// Author: Weige Wong
// Recitation: 203 - Soumyajyoti Bhattacharya
// Homework 2 - Question 10

#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

/*
Algorithm:
1. Create main function that takes user input for the amount of rainy, cold, and sunny days
2. Create void function that takes the user inputs from main and calculates the salary for the worker 
3. Return the salary value to the main function
4. Output via the main function
Input: days (int type)
Output: salary (int type)
Return: salary (int type)
*/

int calculateSalary(int r, int c, int s)        //int function that calculates salary based off of rainy, sunny, cold days worked, hours worked per day, and dollars paid per hour 
{
    int rainy, cold, sunny, salary;
    
    rainy = r * 5;                              //number of hours worked in total based off of rainy days worked and hours worked per rainy day
    cold = c * 4;                               //number of hours worked in total based off of cold days worked and hours worked per cold day
    sunny = s * 8;                              //number of hours worked in total based off of sunny days worked and hours worked per sunny day
    
    salary = (rainy + cold + sunny) * 10;       //net salary, total hours worked times dollars per hour
    return salary;                              //returns salary to main function
}

int main()
{
    int r, c, s;
    
    cout << "Enter rainy days." << endl;        //user enters amount of rainy, cold, and sunny days
    cin >> r;
    
    cout << "Enter cold days." << endl;
    cin >> c;
    
    cout << "Enter sunny days." << endl;
    cin >> s;
    
    cout << "Your salary is $" << calculateSalary(r, c, s) << endl;
    
    //Test 1
    //Input: 1, 2, 3
    //Expected Output: Your salary is $370
    cout << "Your salary is $" << calculateSalary(1, 2, 3) << endl;
    
    //Test 2
    //Input: 9, 9, 9
    //Expected Output: Your salary is $1530 
    cout << "Your salary is $" << calculateSalary(9, 9, 9) << endl;
}