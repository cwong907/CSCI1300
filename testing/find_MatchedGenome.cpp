#include <iostream>
#include <math.h>
#include <iomanip>
#include <string>
using namespace std;

double findMatchedGenome(string g1, string g2, string g3, string s)
{
	if(g1.length() == 0 || g2.length() == 0 || g3.length() == 0 || s.length() == 0)
	{
		cout << "Genomes or sequence is empty." << endl;
	}
	
	if(g1.length() != g2.length() || g1.length() != g3.length() || g2.length() != g3.length())
	{
		cout << "Lengths of genomes are different." << endl;
	}
	
	else
	{
		double maxScore1 = 0;
		double maxScore2 = 0;
		double maxScore3 = 0;
		double score = 0;
		double match = 0;
		
		for(int i = 0; i < (g1.length() - s.length() + 1); i++)
		{
			match = 0;
			string g1sub = g1.substr(i, s.length());
			
			for(int j = 0; j < s.length(); j++)
			{
				if(g1sub[j] == s[j])
				{
					match++;
				}
			}
			score = (double) match / (double) s.length();
			
			if(score > maxScore1)
			{
				maxScore1 = score;
			}
		}
			
		for(int i = 0; i < (g2.length() - s.length() + 1); i++)
		{
			match = 0;
			string g2sub = g2.substr(i, s.length());
			
			for(int j = 0; j < s.length(); j++)
			{
				if(g2sub[j] == s[j])
				{
					match++;
				}
			}
			score = (double) match / (double) s.length();
			
			if(score > maxScore2)
			{
				maxScore2 = score;
			}
		}
			
		for(int i = 0; i < (g3.length() - s.length() + 1); i++)
		{
			match = 0;
			string g3sub = g3.substr(i, s.length());
			
			for(int j = 0; j < s.length(); j++)
			{
				if(g3sub[j] == s[j])
				{
					match++;
				}
			}
			score = (double) match / (double) s.length();
			
			if(score > maxScore3)
			{
				maxScore3 = score;
			}
		}
		
		if(maxScore1 > maxScore2 && maxScore1 > maxScore3)
		{
			cout << "Genome 1 has the best match." << endl;
		}
		
		if(maxScore2>)
	}
}

int main()
{
	/*string g1, g2, g3 = "";
	string s = "";
	
	cout << "Enter genome. (ex. Genome 1 >> Genome 2 >> Genome 3)" << endl;
	cin >> g1 >> g2 >> g3;
	
	cout << "Enter sequence." << endl; 
	cin >> s;
	
	findMatchedGenome(g1, g2, g3, s);
	
	cout << findMatchedGenome(g1, g2, g3, s) << endl;*/
	
	findMatchedGenome("ABB", "BAX", "AAC", "AB");
}