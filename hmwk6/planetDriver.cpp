// CSCI 1300 Fall 2019
// Author: Weige Wong
// Recitation: 203 - Soumyajyoti Bhattacharya
// Homework 6 - Problem 1

#include <iostream>
#include "Planet.h"
using namespace std;

/*
1. Create a header file that declares a class, the private variables, and the public functions and constructors
2. Create a cpp file that defines what each function is/does and what the constructors do
3. Write a driver (main function) that calls the functions declared in the cpp file and passes in parameters for variables (like the radius and planet name)
Input: planet name and radius (string and double type)
Output: planet name, radius, and volume (string, and double types)
Return: planet volume, radius, and name  (double and string types)
*/

int main()
{
	Planet aPlanet;									//creates a name for the class inside the main function
	
	//Test 1
	//Input: "Earth", 3958.8
	//Output: "Earth", 3958.8, 2.59884e+11
	aPlanet.setName("Earth");						//passes a planet name so it is now defined
	aPlanet.setRadius(3958.8);						//same but for the radius 
    cout << "Test 1" << endl;
	cout << aPlanet.getName() << endl;				//gets planet name, radius, and volume from Planet.cpp
	cout << aPlanet.getRadius() << endl;
	cout << aPlanet.getVolume() << endl;
	cout << endl;
	
	//Test 2
	//Input: "Tiny Planet", 5
	//Output: "Tiny Planet", 5, 523.599
	aPlanet.setName("Tiny Planet");
	aPlanet.setRadius(5);
	cout << "Test 2" << endl;
	cout << aPlanet.getName() << endl;
	cout << aPlanet.getRadius() << endl;
	cout << aPlanet.getVolume() << endl;
}