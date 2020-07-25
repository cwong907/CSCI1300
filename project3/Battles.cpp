#include "Battles.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>
#include <math.h>

using namespace std;

int split2(string temp[], char delimiter, int length, string line)
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

// vector<int> Battles::getXLocation()
// {
//     return 0;
// }

// vector<int> Battles::getYLocation()
// {
//     return 0;
// }

void Battles::setTrainerName(string name)
{
    trainerName = name;
}

void Battles::setIndex(int trainerLocation)
{
    index = trainerLocation;
}

void Battles::setNumTPoke(int numPoke)
{
    numTrainPoke = numPoke;
}

void Battles::setTrainerPokemon(string s)
{
    ifstream pokeFile("pokemon.txt");
    
    string line = "";
    int count = 0;
    string temp[9];
    
    if(pokeFile.is_open())                                                              //checks if the file opened properly
    {
        while(getline(pokeFile, line))                                                  //goes line by line through the file
        {
            if(line != "" && line != "#,Pokémon,HP,Attack,Defense,Speed,Max,Type,")     //checks if the line is empty and ignores the first line
            {
                Pokemon myPokemon;                                                      //instance of pokemon 
                int length = 9;
                char delimiter = ',';
                int i = 0;
                    
                count = split2(temp, delimiter, length, line);                          //calls the split function
                
                if(temp[1] == s)                                                        //array at index 1 stores the 
                {
                    myPokemon.setPokemonName(temp[1]);                                  //every location in the temp array stores the information of each pokemon so each setter accesses that and sets it for that instance of myPokemon
                    myPokemon.setHp(stoi(temp[2]));
                    myPokemon.setAttack(stoi(temp[3]));
                    myPokemon.setDefense(stoi(temp[4]));
                    myPokemon.setSpeed(stoi(temp[5]));
                    myPokemon.setMax(stoi(temp[6]));
                    
                    if(count > 8)                                                       //this checks if the pokemon has 2 types
                    {
                        myPokemon.setType(temp[7]);
                        myPokemon.setType(temp[8]);
                    }
                    
                    else
                    {
                        myPokemon.setType(temp[7]);
                    }
                
                    trainerPokemons.push_back(myPokemon);
                }
            }
        }
    }
}

string Battles::getTrainerName()
{
    return trainerName;
}