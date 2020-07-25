// CSCI 1300 Fall 2019
// Author: Weige Wong
// Recitation: 203 - Soumyajyoti Bhattacharya
// Homework 6 - Problem 2

#include <iostream>
#include "Planet.h"
using namespace std;

/*
1. Write a main driver function that populates an array with "Planet" objects (basically each index in the array is filled with parameters stored inside the Planets class)
2. Write a function that takes the planet array and its size and first checks if the size of the array is 0 or less
	a. If it is, return -1
3. If not, loop through each index of the array and use the getRadius function from the class definition to get the radius of each planet and compare them
4. If the radius is bigger than the previous one then store it and the index it was stored in
5. Return the index
Input: planet array, size (Planet class (string and doubles stored in each index of the array), int types)
Output: counter (int type)
Return: counter (int type)
*/

double maxRadius(Planet planets[], int size)			//planet is now a type so it allows us to access Planet.cpp and Planet.h with the array
{
	if(size <= 0)										//checks array size
	{
		return -1;
	}
	
	else 
	{
		double max = 0;
		int counter = 0;
		
		for(int i = 0; i < size; i++)					//loops through every index of the array
		{
			if(max < planets[i].getRadius())			//gets the planet radius to compare to 
			{
				max = planets[i].getRadius();			//sets the max to the biggest radius
				counter = i;							//keeps track of the index
			}
		}
		return counter;
	}
}

int main()
{
	//Test 1
	//Input: planets[] = {Jupiter; Earth, 43441; 3958.8}, 2; (Planet class (string and double type), int types)
	//Output: 0
	Planet planets[2];
	planets[0] = Planet("Jupiter", 43441);
	planets[1] = Planet("Earth", 3958.8);
	int size = 2;
	cout << maxRadius(planets, size) << endl;
	
	//Test 2
	//Input: planets[], 0; (Planet class (string and double type), int types)
	//Output: -1
	Planet planet[0];
	int sizes = 0;
	cout << maxRadius(planet, sizes) << endl;
}