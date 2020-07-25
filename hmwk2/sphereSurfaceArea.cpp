// CSCI 1300 Fall 2019
// Author: Weige Wong
// Recitation: 203 - Soumyajyoti Bhattacharya
//Homework 2 - Question 6 

#include <iostream>
#include <math.h>
using namespace std;

/*
1.Create a main function that takes user input for the radius
2.Create a void function that calculates the surface area of a sphere
3.Have the void function output the surface area
Input: radius (double type)
Output: surface area (double type)
Return: nothing
*/


void sphereSurfaceArea (double radius)                  //void function for surface area of a sphere
{
    double surfaceArea;
    
    surfaceArea = 4.0 * M_PI * pow(radius, 2);          //equation for a surface area for a sphere
    
    cout << "surface area: " << surfaceArea << endl;
}


int main()                                              //main function that takes user input
{
    double radius;
    
    
    cout << "Enter a radius." << endl;                  //user prompt
    cin >> radius;
    
	sphereSurfaceArea(radius);                          //pipes value of radius to surface area function
	
	//Test 1
	//Input: 9
	//Expected Output: 1017.88
	sphereSurfaceArea(9.0);
	
	//Test 2
	//Input: 2
	//Expected Output: 50.2655
	sphereSurfaceArea(2);
}
