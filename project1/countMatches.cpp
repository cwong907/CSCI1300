// CSCI 1300 Fall 2019
// Author: Weige Wong
// Recitation: 203 - Soumyajyoti Bhattacharya
// Project 1 - Problem 2

#include <iostream>
#include <math.h>
#include <iomanip>
#include <string>
using namespace std;

/*
1. Write main function that takes user input for a word and a substring 
2. Write an int function that first checks if either the user entered word or substring are empty
3. If neither are empty then that function should should go letter by letter through the user entered word but stop when there are "substring" amount of letters left in the word
    a. As it goes letter by letter through the word, it should pull out a substring from the word that is length of the user entered substring and check it against the substring the user entered and see how many letters match
Input: user input (string type)
Output: matches (int type)
Return: a or matches (both int type)
*/

int countMatches(string s, string m)
{
    if (s == "" || m == "")                                     //checks to see if user input for word or substring is empty
    {
        int a =-1;
        return a;                                               //returns a value of -1 if either condition is met
    }
    
    int matches = 0;
    for (int i = 0; i < s.length() - m.length() + 1; i++)       //it takes the substring length and subtracts it from the string length so we don't search past the string's length
    {
        if(s.substr(i, m.length()) == m)                        //if the substring of the string (starting at index i with length of the user entered substring) is equal to/has the same character at the same index as the user entered substring then add one to match
        {
            matches++;
        }
    }
    return matches;                                             //return the total amount of matches.
}

int main()
{
    string s = "";
    string m = "";
    
	cout << "Enter a word." << endl;
	cin >> s;
	
	cout << "Enter a substring." << endl;
	cin >> m;
	
	countMatches(s, m);
	cout << countMatches(s, m) << " matches" << endl;
	
	//Test 1
	//Input: "", "pp"
	//Output: -1
	cout << countMatches("", "pp") << " matches" << endl;
	
	//Test 2
	//Input: "Log", ""
	//Output: -1
	cout << countMatches("Log", "") << " matches" << endl;
	
	//Test 3
	//Input: "Skiing", "f"
	//Output: 0 matches
	cout << countMatches("Skiing", "f") << " matches" << endl;
	
	//Test 4
	//Input: "Hippo", "po"
	//Output: 1 matches
	cout << countMatches("Hippo", "po") << " matches" << endl;
}