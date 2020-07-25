// CSCI 1300 Fall 2019
// Author: Weige Wong
// Recitation: 203 - Soumyajyoti Bhattacharya
//Homework 2 - Question 3

#include <iostream>
using namespace std;

/*
1. Create a main function that will take user input (an int variable) as the CSCI course number
2. Create a void function that's named "classGreeting" that will receive the int variable from the main 
3. Once the main function recieves the user input (the CSCI course number) have it pipe that number into the "classGreeting" function under the variable "courseNumber"
4. When the "courseNumber" is piped to "classGreeting" it will run the function
Input: Class number (int type)
Output: "Hello, CS "courseNumber" World!
Returns: nothing
*/

void classGreeting (int courseNumber)                           //our function with a declared variable, "courseNumber" and data type, "int"
{
    cout << "Hello, CS " << courseNumber << " World!" << endl;  //once it receives the variable from main it runs this function
}

int main()                                                      //this runs first since it's main
{
    int courseNumber;                                           
    
    cout << "Enter a CSCI course number." << endl;              //ask the user to enter CSCI course number as a int variable
    cin >> courseNumber;                    
    
    classGreeting(courseNumber);
     //Test 1
     //Input: 2019
     //Expected Output: "Hello, CS 2019 World!"
    classGreeting(2019);
    
    //Test 2
    //Input: 123456
    //Expected Output: "Hello, CS 123465 World!"
    classGreeting(12134567);                                    
}