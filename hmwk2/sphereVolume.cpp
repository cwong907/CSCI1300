// CSCI 1300 Fall 2019
// Author: Weige Wong
// Recitation: 203 - Soumyajyoti Bhattacharya
//Homework 2 - Question 5

#include <iostream>
#include <math.h>
using namespace std;

/*
1. Create a main function that takes a user input and stores it as the radius
2. Create a void function that calculates the volume of the sphere
3. Have the main function take that radius and send it to the void function
4. Void function calculates the volume of a sphere and outputs it to the console
Test case just places a value (9) for radius and calculates from there
Input: Radius (int type)
Output: Volume (double type)
Return: Nothing
*/


void sphereVolume (double radius)                   //This is the void function that takes a variable from the main and calculates the volume
{
    double volume;                                  //declares volume as a double
    
    volume = (4.0/3.0) * M_PI * pow(radius, 3);     //equation for volume of sphere
    
    cout << "volume: " << volume << endl;           //outputs calculation
}


int main()                                          //main function
{
    double radius;                                  //declares radius as a double type
    
    
    cout << "Enter a radius." << endl;              //prompts user to enter a radius
    cin >> radius;
         
	sphereVolume (radius);
	
	//Test 1
	//Input: 9
	//Expected output: 3053.63
	sphereVolume(9.0);     
	
	//Test 2
	//Input: 4
	//Expected output: 268.08
	sphereVolume(4);
}