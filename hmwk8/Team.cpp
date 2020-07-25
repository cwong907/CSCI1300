#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>
#include "Team.h"
#include "Player.h"

using namespace std;

int split(string temp[], char delimiter, int length, string line)
{
    int count = 0;
    string word = "";
	
	if(line == "")									    	                    //checks for a blank sentence
	{
	    return 0;
	}
	
	else
	{
	    line = line + delimiter;	        				                    //adds the delimiter to the end of the sentence so that the code can count the last word
	    
	    for(int i = 0; i < line.length(); i++)		    	                    //loops through the sentence
	    {
		    if(count >= length)								                    //checks if the sentence is broken up into more chunks than the array size
			{
			   	return -1;
			}
			
			if(line[i] == delimiter)				    	                    //checks if the sentence character is equal to the delimiter 
			{
			    if(word != "")								                    //checks if the word is blank
			    {
    			    temp[count] = word;				    	                    //assigns the word to an index in the array
        			count++;								                    //counts to move to the next array
        			word = "";							                    	//resets word to a blank string
			    }
			}
			  
    	  	else										                    	//if a sentence character doesn't equal the delimiter then it adds the character to the string word, as the loop goes through each character it builds the word again until it sees the delimiter
    		{
    		    word = word + line[i];
    		}
	    }
	    return count;
	}
}

string convertToLower(string word)
{
    string newWord = "";
	string a;
	
	for(int i = 0; i < word.length(); i++)                                      //loops through the length of the word
	{
		a = tolower(word[i]);                                                   //gets each character and converts it to lowercase
		newWord += a;                                                           //rebuilds the word
	}
	return newWord;
}

Team::Team()
{
    teamName = "";
}

Team::Team(string x)
{
    teamName = x;
}

void Team::setTeamName(string y)
{
    teamName = y;
}

void Team::readRoster(string fileName)
{
    Player player1;
    
    string line = "";
    
    ifstream myFile;
    myFile.open(fileName);
    
    while(getline(myFile, line))
    {
        string temp[2];                                                 //declares variables used for the split function
        int length = 2;
        char delimiter = ',';
                    
        split(temp, delimiter, length, line);
        
        player1.setName(temp[0]);                                       //takes the name and respective points from the temp array and stores it as Player object
        player1.setPoints(stod(temp[1]));
        
        players.push_back(player1);                                     //takes the names and store it as a player object in the player array
    }
}

string Team::getPlayerName(int i)
{
    if(i < 0 || i >= players.size())                                    //checks if the index is too big or small
    {
        return "ERROR";
    }
    
    else
    {
        return players[i].getName();                                    //gets the name at a spot in the players vector
    }
}

double Team::getPlayerPoints(int j)
{
    if(j < 0 || j >= players.size())                                    //checks if the index is too big or small
    {
        return -1;
    }
    
    else
    {
        return players[j].getPoints();                                  //gets the name at a spot in the players vector
    }
}

int Team::getNumPlayers()
{
    return players.size();
}

string Team::getTeamName()
{
    return teamName;
}
