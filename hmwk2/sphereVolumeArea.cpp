// CSCI 1300 Fall 2019
// Author: Weige Wong
// Recitation: 203 - Soumyajyoti Bhattacharya
//Homework 2 - Question 4

#include <iostream>
#include <math.h>
using namespace std;


/*
1. Have user enter a value for radius
2. Using the value entered for radius, calculte volume and surface area of a sphere using their respective equations
3. Take those values and output to console
Input: radius (int type)
Output: surface area and volume (double type)
Return: none
*/

int main()

{
    double radius;                                      //declare variables for radius, volume, and surfaceArea
    double volume;
    double surfaceArea;
    
    cout << "Enter a radius: " << endl;                 //have user enter a number for the radius of a sphere
    cin >> radius;
   
    volume = (4.0/3.0) * M_PI * pow(radius, 3);         //equation for volume of a sphere
    surfaceArea = 4.0 * M_PI * pow(radius, 2);          //equation for surface area of a sphere
    
    cout << "volume: " << volume << endl;               //outputs the calculations to console
    cout << "surface area: " << surfaceArea << endl;
}