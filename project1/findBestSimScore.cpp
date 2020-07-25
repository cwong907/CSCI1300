// CSCI 1300 Fall 2019
// Author: Weige Wong
// Recitation: 203 - Soumyajyoti Bhattacharya
// Project 1 - Problem 5

#include <iostream>
#include <math.h>
#include <iomanip>
#include <string>
using namespace std;

/*
1. Write a main function that takes user input for a genome and sequence
2. Write a double function that first checks to see if the sequence is longer than the genome
	a. If it is output 0
3. If not, create a substring from the genome with the same length as the sequence and loop through and check each substring permutation 
4. Take each substring and check letter by letter to see if they are equal, if they are count the number of times per substring
5. Then once done checking each substring, compared it with the previous one to see which has more matches and keep the one with the highest one
Input: genome and sequence (string types)
Output: decimal indicating the best match (double type)
Return: maxScore
*/

double findBestSimScore(string g, string s)
{
	if(s.length() > g.length())												//checks to see if the sequence is longer than the genome
	{
		return 0;
	}
	
	else
	{
		double maxScore = 0;
		double score = 0;
		double match = 0;
		
		for(int i = 0; i < (g.length() - s.length() + 1); i++)				//loops through the genome and stops when the there is "s.length" characters are left so you don't go past the last letter of the genome
		{
			match = 0;														//resets matches to 0 so you don't save the variable from each previous loop
			string gsub = g.substr(i, s.length());							//creates a substring from that genome that starts at i (determined by the for loop) and is s.length long
			
			for(int j = 0; j < s.length(); j++)								//loops though each letter of the substring and checks if they are equal and adds it up
			{
				if(gsub[j] == s[j])
				{
					match++;
				}
			}
			score = (double) match / (double) s.length();					//calculates the match percentage as a decimal
			
			if(score > maxScore)											//checks to see if this substring's match is higher and if it is it replaces that score to store it
			{
				maxScore = score;
			}
		}
		return maxScore;
	}
}

int main()
{
	string g = "";
	string s = "";
	
	cout << "Enter genome." << endl;
	cin >> g;
	
	cout << "Enter sequence." << endl;
	cin >> s;
	
	findBestSimScore(g, s);
	
	cout << findBestSimScore(g, s) << endl;
	
	//Test 1
	//Input: "ABB", "ACCC"
	//Output: "0"
	cout << findBestSimScore("ABB", "ACCC") << endl;
	
	//Test 2
	//Input: "ABBAC", "BAX"
	//Output: "0.666667"
	cout << findBestSimScore("ABBAC", "BAX") << endl;
}