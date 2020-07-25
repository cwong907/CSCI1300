// CSCI 1300 Fall 2019
// Author: Weige Wong
// Recitation: 203 - Soumyajyoti Bhattacharya
// Homework 5 - Problem 1

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*
1. Write a main function that stores an array, the length of said array, and will pass up the name of a file to open and read
2. Write a function that accepts those variables and then opens up the file specified in the main function and checks if the file opened correctly
    a. If it didn't return -1
3. If it does open then go through each line of the file with a while loop and check if the lines are blank
    a. If they are, then don't do anything
4. If the lines have something in them then convert the line (which is a string) to an integer and check if it is between a certain number range
5. If it does then set a variable equal to whatever value was read from that line (which is from the file opened earlier)
6. Place that value into an array at the first index and increment from there which each line value being a new index in the array
7. Return the number of values read from the file
Input: fileName, array, length (txt, int, int types)
Output: i (int type)
Return: i
*/

int getLinesFromFile(string fileName, int array[], int length)                  //gets file name to open, renames it fileName and other variables
{
    string line = ""; 
    int i = 0;
    
    ifstream in_file(fileName);                                                 //says to input file and what file is being inputed and to open file

    if(in_file.is_open())                                                       //checks if file is opened
    {
        while(getline(in_file, line))                                           //goes line by line through file and assigns variable line to that value
        {
            if(line != "")                                                      //checks if the line in that file is blank
            {
                if(stoi(line) >= 0 && stoi(line) < 10000 && i < length)         //converts the value in the file to an int and checks to see if i is less than the length of the array
                {   
                    int x = stoi(line);                                         //assigns x to the int in the line of the file
                    array[i] = x;                                               //assigns x to a spot in the array that increments with i++ in the line below
                    i++;            
                }
            }
        }
        return i;
    }
    
    else                                                                        //if the file can't be opened
    {
        return -1;
    }
    
    in_file.close();
}

int main()
{
    //Test 1
    //Input: array[2], 2, "fileName.txt"
    //Output: 2
    int array[2] = {};
    int length = 2;
    cout << getLinesFromFile("fileName.txt", array, length) << endl;
    
    //Test 2
    //Input: arr[3], 3, "fileName1.txt"
    //Output: -1 (since the file can't be opened)
    int arr[3];
    int len = 3;
    cout << getLinesFromFile("fileName1.txt", arr, len) << endl;
}