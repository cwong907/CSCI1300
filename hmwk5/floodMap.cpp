// CSCI 1300 Fall 2019
// Author: Weige Wong
// Recitation: 203 - Soumyajyoti Bhattacharya
// Homework 5 - Problem 5

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*
1. Write a main function that houses a 2D array, rows, and water level
2. Write a function that takes those arguments
3. Use for loops to iterate through the 2D array and compare each value to see if it is equal or less than the water level
4. If it is, print a *
5. If not, then print _
Input: array[][], rows, water level (double, int, double)
Output: *, _ (string)
Return: nothing
*/

void floodMap(double array[][4], int rows, double water)
{
    for(int i = 0; i < rows; i++)                                               //loops through the rows
    {
        for(int j = 0; j < 4; j++)                                              //loops through the columns
        {
            if(array[i][j] <= water)                                            //checks if the value in that index is equal to or less than the water level
            {
                cout << "*";
            }
            
            else
            {
                cout << "_";
            }
        }
        cout << endl;
    }
}

int main()
{
    //Test 1
    //Input: array[2][4] = {{0.2, 0.8, 0.8, 0.2}, {0.2, 0.2, 0.8, 0.5}}, rows, water
    //Output: *__*, **__ 
    double array[2][4] = {{0.2, 0.8, 0.8, 0.2}, {0.2, 0.2, 0.8, 0.5}};
    int rows = 2;
    double water = 0.3;
    floodMap(array, rows, water);
    cout << endl;
    
    //Test 2
    //Input: array2[2][4] = {{1.0, 2.5, 1.0, 2.2}, {1.2, 3.1, 4.2, 0.5}}, row, level
    //Output: *_*_, ___*
    double array2[2][4] = {{1.0, 2.5, 1.0, 2.2}, {1.2, 3.1, 4.2, 0.5}};
    int row = 2;
    double level = 1.1;
    floodMap(array2, row, level);
}