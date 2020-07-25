// CSCI 1300 Fall 2019
// Author: Weige Wong
// Recitation: 203 - Soumyajyoti Bhattacharya
// Project 1 - Problem 3

#include <iostream>
#include <math.h>
#include <iomanip>
#include <string>
using namespace std;

/*
1. Write a main function that calls the hire score function
2. Write a hire score function that first outputs a menu that gives the user 4 options to choose from, 3 animals, and 1 for quit
3. Have each numerical option tied to an animal and ask the user to enter a number
4. Based on which number the user enters, ask the user to enter 2 numbers for 2 attributes that are tied to each animal
5. Compute the hire score based on the given numbers and output.
Input: number (int type, double type) 
Output: Hire score (double type)
Return: nothing
*/

void hireScore()
{
	int n;
    while(n!=4)											//repeats the while loop until 4 is selected
    {
        cout<<"Select a numerical option:"<<endl;		//menu
        cout<<"=== menu ==="<<endl;
        cout<<"1. Fox"<<endl;
	    cout<<"2. Bunny"<<endl;
	    cout<<"3. Sloth"<<endl;
	    cout<<"4. Quit"<<endl;
	    
	    cin >> n;
	    
	    switch (n)
	    {
	        case 1:											//case 1 is for a fox and has 2 attributes: agility and strength; which the user enters values for
	        {
	            double a, s;
	            cout << "Enter agility:" << endl;
	            cin >> a;
	            
	            cout << "Enter strength:" << endl;
	            cin >> s;
	            
	            double score = (2.16*s) + (1.8*a);			//equation to calculate the hire score
	            cout << "Hire Score: " << score << endl;
	            break;
	        }
	        
	        case 2:											//case 2 is for a bunny and has 2 attributes: agility and speed
	        {
	            double a, p;
	            cout << "Enter agility:" << endl;
	            cin >> a;
	            
	            cout << "Enter speed:" << endl;
	            cin >> p;
	            
	            double score = (1.8 * a) + (3.24 * p);		//equation to calculate score
	            cout << "Hire Score: " << score << endl;
	            break;
	        }
	        
	        case 3:											//case 3 is for a sloth and has 2 attributes: strength and speed
	        {
	            double s, p;
	            cout << "Enter strength:" << endl;
	            cin >> s;
	            
	            cout << "Enter speed:" << endl;
	            cin >> p;
	            
	            double score = (2.16 * s) + (3.24 * p);		//equation to calculate the score
	            cout << "Hire Score: " << score << endl;	
	            break;
	        }
	        	
	        case 4:											//case 4 ends the loop
	        {
	           cout << endl;
	           break;
	        }
	    }
    }
}

int main()
{
    hireScore();
}