// CSCI 1300 Fall 2019
// Author: Weige Wong
// Recitation: 203 - Soumyajyoti Bhattacharya
// Project 1 - Problem 7

#include <iostream>
#include <math.h>
#include <iomanip>
#include <string>
using namespace std;

/*
1. Create a main function that calls the analyzeDNA function
2. First output a menu of options for the user to choose
3. Based on which option the user chooses, execute the case that is assigned to the numerical option in the menu
4. If case 1 is chosen, then find the best similarity score based on user input
5. If case 2 is chosen, then find the best similarity score based on user entered genome and sequence
6. If case 3 is chosen find which genome fits best using the findMatchedGenome helper function based off of 3 user entered genomes and 1 user entered sequence
7. If case 4 is chosen then quit
8. If an invalid number (not 1-4) is chosen then output and invalid option choice
9. Repeat until 4 is chosen
Input: number (int type for menu), word (string type for case 1-3)
Output: a menu, a similarity score (double type), best similarity score (double type), which genome(s) fit best, a quit option, or a invalid choice option
Return: 0, maxScore (int type, and double type for case 3)
*/

double findBestSimScore(string g, string s3)
{
	if(s3.length() > g.length())
	{
		return 0;
	}
	
	else
	{
		double maxScore = 0;
		double score = 0;
		double match = 0;
		
		for(int i = 0; i < (g.length() - s3.length() + 1); i++)
		{
			match = 0;
			string gsub = g.substr(i, s3.length());
			
			for(int j = 0; j < s3.length(); j++)
			{
				if(gsub[j] == s3[j])
				{
					match++;
				}
			}
			score = (double) match / (double) s3.length();
			
			if(score > maxScore)
			{
				maxScore = score;
			}
		}
		return maxScore;
	}
}

void findMatchedGenome(string g1, string g2, string g3, string s3)
{
	if(g1.length() == 0 || g2.length() == 0 || g3.length() == 0 || s3.length() == 0)
	{
		cout << "Genomes or sequence is empty." << endl;
	}
	
	else if(g1.length() != g2.length() || g1.length() != g3.length() || g2.length() != g3.length())
	{
		cout << "Lengths of genomes are different." << endl;
	}
	
	else
	{
		double v1 = findBestSimScore(g1, s3);
		double v2 = findBestSimScore(g2, s3);
		double v3 = findBestSimScore(g3, s3);
		
		if(v1 > v2 && v1 > v3)
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
		
		else if(v2 == v3 && v2 != v1)
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

void analyzeDNA()
{
    int n = 0;
    string s1 = "";
    string s2 = "";
    string g = "";
	string s = "";
	string g1, g2, g3 = "";
    string s3 = "";
    
    while(n != 4)
    {
        cout << "Select a numerical option:" << endl;
        cout << "=== menu ===" << endl;
        cout << "1. Find similarity score" << endl;
        cout << "2. Find the best similarity score" << endl;
        cout << "3. Analyze the genome sequences" << endl;
        cout << "4. Quit" << endl;
        
        cin >> n;
        
        switch(n)
        {
            case 1:
                cout << "Enter sequence 1:" << endl;
                cin >> s1;
                
                cout << "Enter sequence 2:" << endl;
                cin >> s2;
                
                if(s1 == "" || s2 == "" || (s1.length() != s2.length()))
                {
                    cout << "Similarity score: 0" << endl;
                }
	
                else
	            {
		            double hamming_distance;
		            for(int i = 0; i <= s1.length(); i++)
		            {
			            if(s1.substr(i, 1) != s2.substr(i, 1))
			            {
				            hamming_distance++;
			            }
		            }
		            double simScore = ((double) s1.length() - (double)hamming_distance) / (double)s1.length();
		            cout << "Similarity score: " << simScore << endl;
			    }
		        break;
		    
		    case 2:
	            cout << "Enter genome:" << endl;
	            cin >> g;
	
	            cout << "Enter sequence:" << endl;
	            cin >> s;
	            
	            if(s.length() > g.length())
                {
	                cout << "Best similarity score: 0" << endl;
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
		            cout << "Best similarity score: " << maxScore << endl;
		           
	            }
		        break;
		    
		    case 3:
	            cout << "Enter genome 1:" << endl;
	            cin >> g1;
	            cout << "Enter genome 2:" << endl;
	            cin >> g2;
	            cout << "Enter genome 3:" << endl;
	            cin >> g3;
	
	            cout << "Enter sequence:" << endl; 
	            cin >> s3;
	            
	            findMatchedGenome(g1, g2, g3, s3);
		        break;
		    
		    case 4:
		        cout << "Good bye!" << endl;
		        break;
		    
		    default:
		        cout << "Invalid option." << endl;
		        break;
        }
    }
}

int main()
{
	analyzeDNA();
}