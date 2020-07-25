#include "Player.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

int splits(string temp[], char delimiter, int length, string line)
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

Player::Player()
{
    username = "";
    pokeball = 10;
    badges = 0;
    points = 0;
    numPokemon = 0;
    playerLocationX = 0;
    playerLocationY = 0;
}

void Player::setUsername(string n)
{
    username = n;
}

void Player::setPlayerX(int x)
{
    playerLocationX = x;
}

void Player::setPlayerY(int y)
{
    playerLocationY = y;
}

void Player::activatePokemon(int index, bool b)
{
    for(int f = 0; f < playerPokemon.size(); f++)
    {
        if(playerPokemon[f].getActive() == "(Active)")
        {
            playerPokemon[f].setActivePokemon(false);
        }
    }
    
    playerPokemon[index].setActivePokemon(b);
}

int Player::findActive()
{
    for(int f = 0; f < playerPokemon.size(); f++)
    {
        if(playerPokemon[f].getActive() == "(Active)")
        {
            return f;
        }
    }
}

void Player::printActivePokemon()
{
    for(int f = 0; f < playerPokemon.size(); f++)
    {
        if(playerPokemon[f].getActive() == "(Active)")
        {
            cout << "Your ACTIVE Pokémon is:" << endl;
            cout << "Name: " << playerPokemon[f].getPokemonName() << playerPokemon[f].getActive() << " HP: " << playerPokemon[f].getHp() << " A: " << playerPokemon[f].getAttack() << " D: " << playerPokemon[f].getDefense() << " S: " << playerPokemon[f].getSpeed() << " M: " << playerPokemon[f].getMax() << endl;
        }
    }    
}

void Player::newPokemon(string name)
{
    string line = "";
    
    ifstream pokeFile("pokemon.txt");
    
    if(pokeFile.is_open())                                                                      //checks if the file opened properly
    {
        while(getline(pokeFile, line))                                                          //goes line by line through the file
        {
            if(line != "" && line != "#,Pokémon,HP,Attack,Defense,Speed,Max,Type,")             //checks if the line is empty
            {
                Pokemon myPokemon;
                int length = 9;
                char delimiter = ',';
                string temp[9];
                int count = 0;
                bool b = false;
                                   
                count = splits(temp, delimiter, length, line);                                  //calls the split function
                            
                if(temp[1] == name)                                                             //checks if the pokemon at that line is equal to the pokemon name that's been passed in that we're looking for
                {
                    myPokemon.setPokemonName(temp[1]);
                    myPokemon.setHp(stoi(temp[2]));
                    myPokemon.setMaxHP(stoi(temp[2]));
                    myPokemon.setAttack(stoi(temp[3]));
                    myPokemon.setDefense(stoi(temp[4]));
                    myPokemon.setSpeed(stoi(temp[5]));
                    myPokemon.setMax(stoi(temp[6]));
                    myPokemon.setActivePokemon(b);
                                
                    if(count > 8)
                    {
                        myPokemon.setType(temp[7]);
                        myPokemon.setType(temp[8]);
                    }
                            
                    else
                    {
                        myPokemon.setType(temp[7]);
                    }
                            
                    playerPokemon.push_back(myPokemon);
                    break;
                }
            }
        }
    }
}

int Player::updatePokedex(string names)
{
    /*
    When a pokemon is caught, it searches through the vector <Pokemon> allPokemon until it finds the pokemon and pushes it back into the playerPokedex vector so it's a new pokemon
    */
    
    string line = "";
    
    ifstream pokeFile("pokemon.txt");
    
    if(pokeFile.is_open())                                                                          //checks if the file opened properly
    {
        while(getline(pokeFile, line))                                                              //goes line by line through the file
        {
            if(line != "" && line != "#,Pokémon,HP,Attack,Defense,Speed,Max,Type,")                 //checks if the line is empty
            {
                if(line == "1,Bulbasaur,45,49,49,45,65,Grass,Poison" && names == "Bulbasaur")       //checks if the line that we've got from the file is Bulbasaur 
                {
                    Pokemon myPokemon;
                    int length = 9;
                    char delimiter = ',';
                    string temp[9];
                    int count = 0;
                        
                    count = splits(temp, delimiter, length, line);                                  //calls the split function
                
                    myPokemon.setPokemonName(temp[1]);
                    myPokemon.setHp(stoi(temp[2]));
                    myPokemon.setMaxHP(stoi(temp[2]));
                    myPokemon.setAttack(stoi(temp[3]));
                    myPokemon.setDefense(stoi(temp[4]));
                    myPokemon.setSpeed(stoi(temp[5]));
                    myPokemon.setMax(stoi(temp[6]));
                    
                    if(count > 8)
                    {
                        myPokemon.setType(temp[7]);
                        myPokemon.setType(temp[8]);
                    }
                    
                    else
                    {
                        myPokemon.setType(temp[7]);
                    }
                    
                    playerPokemon.push_back(myPokemon);
                    //cout << temp[1] << endl;
                    break;
                }
                
                else if(line == "4,Charmander,39,52,43,65,50,Fire," && names == "Charmander")       //same idea but for Charmander
                {
                    Pokemon myPokemon;
                    int length = 9;
                    char delimiter = ',';
                    string temp[9];
                    int count = 0;
                        
                    count = splits(temp, delimiter, length, line);                                  //calls the split function
                
                    myPokemon.setPokemonName(temp[1]);
                    myPokemon.setHp(stoi(temp[2]));
                    myPokemon.setMaxHP(stoi(temp[2]));
                    myPokemon.setAttack(stoi(temp[3]));
                    myPokemon.setDefense(stoi(temp[4]));
                    myPokemon.setSpeed(stoi(temp[5]));
                    myPokemon.setMax(stoi(temp[6]));
                    
                    if(count > 8)
                    {
                        myPokemon.setType(temp[7]);
                        myPokemon.setType(temp[8]);
                    }
                    
                    else
                    {
                        myPokemon.setType(temp[7]);
                    }
                    
                    playerPokemon.push_back(myPokemon);
                    //cout << temp[1] << endl;
                    break;
                }
                
                else if(line == "7,Squirtle,44,48,65,43,50,Water," && names == "Squirtle")          //checks to see if we've found Squirtle
                {
                    Pokemon myPokemon;
                    int length = 9;
                    char delimiter = ',';
                    string temp[9];
                    int count = 0; 
                      
                    count = splits(temp, delimiter, length, line);                                  //calls the split function
                    myPokemon.setPokemonName(temp[1]);
                    myPokemon.setHp(stoi(temp[2]));
                    myPokemon.setMaxHP(stoi(temp[2]));
                    myPokemon.setAttack(stoi(temp[3]));
                    myPokemon.setDefense(stoi(temp[4]));
                    myPokemon.setSpeed(stoi(temp[5]));
                    myPokemon.setMax(stoi(temp[6]));
                    
                    if(count > 8)
                    {
                        myPokemon.setType(temp[7]);
                        myPokemon.setType(temp[8]);
                    }
                    
                    else
                    {
                        myPokemon.setType(temp[7]);
                    }
                    
                    playerPokemon.push_back(myPokemon);
                    //cout << temp[1] << endl;
                    break;
                }
                
                else if(line == "25,Pikachu,35,55,30,90,50,Electric," && names == "Pikachu")        //checks to see if we've found Pikachu
                {
                    Pokemon myPokemon;
                    int length = 9;
                    char delimiter = ',';
                    string temp[9];
                    int count = 0;
                       
                    count = splits(temp, delimiter, length, line);                                  //calls the split function
                
                    myPokemon.setPokemonName(temp[1]);
                    myPokemon.setHp(stoi(temp[2]));
                    myPokemon.setMaxHP(stoi(temp[2]));
                    myPokemon.setAttack(stoi(temp[3]));
                    myPokemon.setDefense(stoi(temp[4]));
                    myPokemon.setSpeed(stoi(temp[5]));
                    myPokemon.setMax(stoi(temp[6]));
                    
                    if(count > 8)
                    {
                        myPokemon.setType(temp[7]);
                        myPokemon.setType(temp[8]);
                    }
                    
                    else
                    {
                        myPokemon.setType(temp[7]);
                    }
                    
                    playerPokemon.push_back(myPokemon);
                    break;
                }
            }
        }
    }
}

void Player::getPlayerPokemon()                                         //cout's all the pokemon that the player has caught
{
    if(playerPokemon.size() < 6)                                        //if the player has less than 6 pokemon total then it prints all of them
    {
        for(int i = 0; i < playerPokemon.size(); i++)
        {
            cout << "Name: " << playerPokemon[i].getPokemonName() << playerPokemon[i].getActive() << " HP: " << playerPokemon[i].getHp() << " A: " << playerPokemon[i].getAttack() << " D: " << playerPokemon[i].getDefense() << " S: " << playerPokemon[i].getSpeed() << " M: " << playerPokemon[i].getMax() << endl;
        }
    }
    
    else if(playerPokemon.size() >= 6)                                  //if the player has more than 6 pokemon the it prints out the first 6
    {
        cout << "You have more than 6 Pokemon, the active roster (6 Pokemon) is shown." << endl;
        for(int i = 0; i < 6; i++)
        {
            cout << "Name: " << playerPokemon[i].getPokemonName() << playerPokemon[i].getActive() << " HP: " << playerPokemon[i].getHp() << " A: " << playerPokemon[i].getAttack() << " D: " << playerPokemon[i].getDefense() << " S: " << playerPokemon[i].getSpeed() << " M: " << playerPokemon[i].getMax() << endl;
        }
    }
}

int Player::getMaxPokeHP(int index)                                     //this retrieves the maxHP stat which is set when the Pokemon is first added and is used for the rest function 
{
    playerPokemon[index].getMaxHP();
}

int Player::getPokemonHP(int health)
{
    playerPokemon[health].getHp();
}

int Player::getPokeSpeed(int index)
{
    return playerPokemon[index].getSpeed();
}

void Player::addHP(int idx)                                             //this is the heal function for resting Pokemon
{
    playerPokemon[idx].heal();
}

void Player::subtractPokeball()
{
    pokeball--;
}

string Player::getUsername()
{
    return username;
}

int Player::getNumPokemon()
{
    return playerPokemon.size();
}

int Player::getBadges()
{
    return badges;
}

int Player::getPoints()
{
    return points;
}

int Player::getPokeball()
{
    return pokeball;
}

int Player::getplayerLocationX()
{
    return playerLocationX;
}

int Player::getPlayerLocationY()
{
    return playerLocationY;
}

void Player::healAll()
{
    for(int i = 0; i < playerPokemon.size(); i++)
    {
        playerPokemon[i].resetMaxHP();
    }
}

void Player::printAllPokemon()
{
    for(int i = 0; i < playerPokemon.size(); i++)
    {
        cout << (i + 1) << ". " << playerPokemon[i].getPokemonName() << endl;
    }
}

void Player::swapPokemon(int g, int h)
{
    Pokemon tempPokemon;
    
    tempPokemon = playerPokemon[(h - 1)];
    playerPokemon[(h - 1)] = playerPokemon[(g - 1)];
    playerPokemon[(g - 1)] = tempPokemon;
}

void Player::printFirstSix()
{
    if(playerPokemon.size() < 6)
    {
        for(int i = 0; i < playerPokemon.size(); i++)
        {
            cout << (i + 1) << ". " << playerPokemon[i].getPokemonName() << endl;
        }
    }
    
    else if(playerPokemon.size() > 6)
    {
        for(int i = 0; i < 7; i++)
        {
            cout << (i + 1) << ". " << playerPokemon[i].getPokemonName() << endl;
        }
    }
}