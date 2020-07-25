// CSCI 1300 Fall 2019
// Author: Weige Wong
// Recitation: 203 - Soumyajyoti Bhattacharya
// Homework 2 - Question 8

#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

/*
1. Create main function that takes user input for inital population and returns the calculations for total population after a year from the int fuction
2. Create int function that calculates the total population in a year after factoring in death, birth, and immigration rate
Input: population (int type) 
Output: population after 1 year (int type)
Return: popTotal (int type)
*/

int population(int pop)                                                         //int is the type of value to be returned to the main function after the calculations are complete
{
    double annualBirths, annualImmigration, annualDeaths, annualGrowth, popTotal;
    
   annualBirths = (1.0 / 8.0) * (86400.0) * (365.0);                            //equation for number of births in a year
   annualImmigration = (1.0 / 27.0) * (86400.0) * (365.0);                      //equation for number of immigrants in a year
   annualDeaths = (1.0 / 12.0) * (86400.0) * (365.0);                           //equation for number of deaths in a year
   annualGrowth = (annualBirths + annualImmigration) - (annualDeaths);          //net population growth of the US in a year
 
   popTotal = (pop + annualGrowth);                                             //total population of the US after 1 year
   return popTotal;                                                             //returns popTotal to main function
}   

int main()
{
    int pop;
    
    cout << "Enter a population." << endl;                                      //user prompt to enter a population amount
    cin >> pop;
    
    
    cout << population(pop) << endl; 
    
    //Test 1
    //Input: 12345678
    //Expected Output: 14847478
    cout << population(12365478) << endl;
    
    //Test 2
    //Input: 200000
    //Expected Output: 2682000
    cout << population(200000) << endl;
}