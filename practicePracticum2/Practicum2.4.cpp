#include<iostream>
#include<fstream>
#include<cmath>
#include<iomanip>
#include<string>
using namespace std;

int split(string temp[], char delimiter, int length, string line)
{
	int count = 0;
	string word = "";
	
	if(line == "")									    	//checks for a blank sentence
	{
		return 0;
	}
	
	else
	{
		line = line + delimiter;	        				//adds the delimiter to the end of the sentence so that the code can count the last word
	
		for(int i = 0; i < line.length(); i++)		    	//loops through the sentence
		{
			if(count >= length)								//checks if the sentence is broken up into more chunks than the array size
			{
				return -1;
			}
			
			if(line[i] == delimiter)				    	//checks if the sentence character is equal to the delimited 
			{
			    if(word != "")								//checks if the word is blank
			    {
			     	temp[count] = word;				    	//assigns the word to an index in the array
    				count++;								//counts to move to the next array
    				word = "";								//resets word to a blank string
			    }
			}
			
			else											//if a sentence character doesn't equal the delimiter then it adds the character to the string word, as the loop goes through each character it builds the word again until it sees the delimiter
			{
				word = word + line[i];
			}
		}
		return count;
	}
}

int calcCost(string fileName)
{
    float total;
    float x;
    int counter = 0;
    string line = "";
    
    ifstream file(fileName);
    
    if(file.is_open())
    {
        while(getline(file, line))
        {
            if(line != "")
            {
                string words[3];
                int max_words = 3;
                split(words, ',', max_words, line);
                
                
                
                total = stod(words[1]) * stod(words[2]);
                cout << words[0] << ": " << total << endl;
                x += total;
                counter++;
            }
        }
        cout << "Total: " << x << endl;
        return counter;
    }
    
    else
    {
        return -1;
    }
}

int main()
{
    cout<<setprecision(2)<<fixed;
    calcCost("testing.txt");
}