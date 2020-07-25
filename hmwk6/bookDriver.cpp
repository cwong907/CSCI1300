// CSCI 1300 Fall 2019
// Author: Weige Wong
// Recitation: 203 - Soumyajyoti Bhattacharya
// Homework 6 - Problem 3

#include <iostream>
#include "Book.h"
using namespace std;
/*
1. Create a header file that declares a class, the private variables, and the public functions and constructors
2. Create a cpp file that defines what each function is/does and what the constructors do
3. Write a driver (main function) that calls the functions declared in the cpp file and passes in parameters for variables
Input: title, author (string types)
Output: title, author (string types)
Return: title, author (string type)
*/

int main()
{
	Book bookReader;											//names a local name for to call the class with
	
	//Test 1
	//Input: "East of Eden", "John Steinbeck"
	//Output: "East of Eden", "John Steinbeck"
	bookReader.setTitle("East of Eden");						//passes book title and author names into the class variables
	bookReader.setAuthor("John Steinbeck");
    cout << "Test 1" << endl;
	cout << bookReader.getTitle() << endl;	
	cout << bookReader.getAuthor() << endl;
	cout << endl;
	
	//Test 2
	//Input: "Old Man and The Sea", "Ernest Hemingway"
	//Output: "Old Man and The Sea", "Ernest Hemingway"
	bookReader.setTitle("Old Man and The Sea");
	bookReader.setAuthor("Ernest Hemingway");
	cout << "Test 2" << endl;
	cout << bookReader.getTitle() << endl;
	cout << bookReader.getAuthor() << endl;
}