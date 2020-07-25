// CSCI 1300 Fall 2019
// Author: Weige Wong
// Recitation: 203 - Soumyajyoti Bhattacharya
// Project 1 - Problem 6

#include <iostream>
#include <math.h>
#include <iomanip>
#include <string>
using namespace std;

/*
1. Write a main function that takes 4 strings, 3 for genome and 1 for a sequence
2. First check that all inputs aren't empty
3. If they pass then check to make sure all genome lenghts are the same
4. If they pass that then take each genome individually and compare it to the sequence to see if they match 
	a. Do this by passing each genome and sequence pairing up to the findBestSimScore function
5. After the scores have been calculated compare them to each other to see which ones match best
Input: genome and sequence (string type)
Output: which genome is the best match
Return: nothing to the main
*/

double findBestSimScore(string g, string s)															//helper function from findBestSimScore.cpp
{
	if(s.length() > g.length())
	{
		return 0;
	}
	
	else
	{
		double maxScore = 0;
		double score = 0;
		double match = 0;
		
		for(int i = 0; i < (g.length() - s.length() + 1); i++)
		{
			match = 0;
			string gsub = g.substr(i, s.length());
			
			for(int j = 0; j < s.length(); j++)
			{
				if(gsub[j] == s[j])
				{
					match++;
				}
			}
			score = (double) match / (double) s.length();
			
			if(score > maxScore)
			{
				maxScore = score;
			}
		}
		return maxScore;
	}
}

void findMatchedGenome(string g1, string g2, string g3, string s)
{
	if(g1.length() == 0 || g2.length() == 0 || g3.length() == 0 || s.length() == 0)						//if and else if statements check if the genomes and sequence are empty or of different lengths
	{
		cout << "Genomes or sequence is empty." << endl;
	}
	
	else if(g1.length() != g2.length() || g1.length() != g3.length() || g2.length() != g3.length())
	{
		cout << "Lengths of genomes are different." << endl;
	}
	
	else
	{
		double v1 = findBestSimScore(g1, s);															//passes a genome sequence pairing up to a helper function
		double v2 = findBestSimScore(g2, s);
		double v3 = findBestSimScore(g3, s);
		
		if(v1 > v2 && v1 > v3)																			//each if and else if statement from here on down checks each similarity score between the genomes to see which one or ones are the best fit
		{
			cout << "Genome 1 is the best match." << endl;
		}
		
		else if(v2 > v1 && v2 > v3)
		{
			cout << "Genome 2 is the best match." << endl;
		}
		
		else if(v3 > v1 && v3 > v2)
		{
			cout << "Genome 3 is the best match." << endl;
		}
		
		else if(v1 == v2 && v1 != v3)
		{
			cout << "Genome 1 is the best match." << endl;
			cout << "Genome 2 is the best match." << endl;
		}
		
		else if(v2 == v3 && v1 != v3)
		{
			cout << "Genome 2 is the best match." << endl;
			cout << "Genome 3 is the best match." << endl;
		}
		
		else if ((v1 == v2) && (v2 == v3) && (v1 == v3))
		{
			cout << "Genome 1 is the best match." << endl;
			cout << "Genome 2 is the best match." << endl;
			cout << "Genome 3 is the best match." << endl;
		}
	}
}

int main()
{
	string g1, g2, g3 = "";
	string s = "";
	
	cout << "Enter genome. (ex. Genome 1 >> Genome 2 >> Genome 3)" << endl;
	cin >> g1 >> g2 >> g3;
	
	cout << "Enter sequence." << endl; 
	cin >> s;
	
	findMatchedGenome(g1, g2, g3, s);

	//Test 1
	//Input: "", "A", "B", "C"
	//Output: Genomes or sequence is empty.
	findMatchedGenome("" , "A", "B", "C");
	
	//Test 2
	//Input: "A", "", "B", "C"
	//Output: Genomes or sequence is empty.
	findMatchedGenome("A" , "", "B", "C");
	
	//Test 3
	//Input: "A", "B", "", "C"
	//Output: Genomes or sequence is empty.
	findMatchedGenome("A" , "B", "", "C");
	
	//Test 4
	//Input: "A", "B", "C", ""
	//Output: Genomes or sequence is empty.
	findMatchedGenome("A" , "B", "C", "");
	
	//Test 5
	//Input: "AB", "A", "AC", "C"
	//Output: Lengths of genomes are different.
	findMatchedGenome("AB", "A", "AC", "C");
	
	//Test 6
	//Input: "AB", "AC", "A", "C"
	//Output: Lengths of genomes are different.
	findMatchedGenome("AB", "AC", "A", "C");
	
	//Test 7
	//Input: "ABB", "BAX", "AAC", "AB"
	//Output: Genome 1 is the best match.
	findMatchedGenome("ABB", "BAX", "AAC", "AB");
	
	//Test 8
	//Input: "ABB", "BAX", "AAC", "AX"
	//Output: Genome 2 is the best match.
	findMatchedGenome("ABB", "BAX", "AAC", "AX");
	
	//Test 9
	//Input: "ABB", "BAX", "AAC", "AA"
	//Output: Genome 3 is the best match.
	findMatchedGenome("ABB", "BAX", "AAC", "AA");
	
	//Test 10
	//Input: "ABB", "ABX", "AAC", "AA"
	//Output: Genome 1 and 2 is the best match.
	findMatchedGenome("ABB", "ABX", "AAC", "AB");
	
	//Test 11
	//Input: "AB", "BX", "BX", "BX"
	//Output: Genome 2 & 3 is the best match.
	findMatchedGenome("AB", "BX", "BX", "BX");
	
	//Test 12
	//Input: "ABB", "ABX", "ABX", "BX"
	//Output: Genome 1, 2, & 3 is the best match.
	findMatchedGenome("ABB", "ABX", "ABX", "AB");
}