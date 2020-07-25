#include "gameManager.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>
#include <math.h>
#include <stdio.h> 
#include <stdlib.h> 
#include <bits/stdc++.h> 

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

void gameManager::pokemonScatter()
{
    /*
    Using the rand function, the function will randomly select 20 numbers between 1 and 150 and store them. The numbers represent the index of the pokemon in a pokemon vecotr that holds every one
    Then it will randomly pick 20 spots within the 2D array and assign the spots to the pokemon index as it does that
    The locations will be stored so the game knows where the pokemon are
    */
    
    int count = 0;
    bool ID = false;
    vector<int> tempv;
    srand(time(NULL));
    // vector<int> tempXPLoc;
    // vector<int> tempYPLoc;
    // bool check = false;
    int counter = 0;
    
    while(count < 20)                                                           //ensures that we have randomly generated and scattered 20 wild Pokemon
    {
        int a = rand() % 151;                                                   //randomly picks a number between 0 and 150 which corresponds to an index in the allPokemon vector
        
        if(tempv.size() == 0)                                                   //makes sure we the first Pokemon always gets added to the vector
        {
            tempv.push_back(a);
            count++;
        }
        
        else
        {
            for(int i = 0; i < tempv.size(); i++)                               //every subsequent pokemon index is checked to see if it exists in the tempv vector before being added in
            {
                if(tempv[i] == a)
                {
                    ID = true;    
                }
            }
            
            if(ID == false)                                                     //if the index doesn't exist already then it adds it
            {
                //cout << a << endl;
                tempv.push_back(a);
                count++;
            }
        }
        
        ID = false;                                                             //resets ID to false
    }
    
    for(int b = 0; b < 20; b++)
    {
        wildPokemon.push_back(allPokemon[tempv[b]]);                            //accesses the temp to get the index, passes it to the allPokemon vector and that Pokemon at that index is pushed into the wildPokemon vector
    }
    
    for(int i = 0; i < allPokemon.size(); i++)
    {
        for(int p = 0; p < wildPokemon.size(); p++)
        {
            if(wildPokemon[p].getPokemonName() == allPokemon[i].getPokemonName())   //compares the Pokemon at every index of the wildPokemon vector to the every index of the allPokemon vector and if there is a match it deletes it from the allPokemon vector to ensure no duplicates
            {
                allPokemon.erase(allPokemon.begin() + i);
            }
        }
    }
    
    // for(int b = 0; b < 20; b++)
    // {
    //     cout << wildPokemon[b].getPokemonName() << endl;
    // }
    
    //cout << myPlayer.getplayerLocationX() << endl;                            //test to see if the values are being stored and passed correctly
    
    while(counter < 20)
    {
        //cout << counter << endl;
        int YPLoc = rand() % 25;                                                //randomly assigns an x coordinate
        int XPLoc = rand() % 16;                                                //does the same for y
        bool variableName = false;
        
        if((map[YPLoc][XPLoc] == "* ") && (XPLoc != myPlayer.getplayerLocationX()) && (YPLoc != myPlayer.getPlayerLocationY()))     //checks to see if the randomly generated location is a land tile and not the player's location
        {
            if(xPLocation.size() == 0)
            {
                xPLocation.push_back(XPLoc);                                        //stores them
                yPLocation.push_back(YPLoc);
                map[YPLoc][XPLoc] = "P ";                                           //sets the map at these coordinates to P
                counter++;
            }
            
            else
            {
                for(int w = 0; w < yPLocation.size(); w++)
                {
                    if((xPLocation[w] == XPLoc) && (yPLocation[w] == YPLoc))
                    {
                        variableName = true;
                        w--;
                    }
                }
                
                if(variableName == false)
                {
                    xPLocation.push_back(XPLoc);                                        //stores them
                    yPLocation.push_back(YPLoc);
                    map[YPLoc][XPLoc] = "P ";                                           //sets the map at these coordinates to P
                    counter++;
                }
            }
        }
    }
    
    // for(int i = 0; i < xPLocation.size(); i++)
    // {
    //     cout << xPLocation[i] << " " << yPLocation[i] << endl;
    // }
}

void gameManager::trainerScatter()
{
    int numTrainPoke = 0;
    string trainerN = "";
    int counter = 0;
    int ID = 0;
    vector<int> temp;
    bool checker = false;
    int c = 0;
    
    while(counter < 15)                                                         //for 15 trainers
    {
        Battles localBattle;                                                    //makes an instance of Battle for 15 trainers
        
        numTrainPoke = rand() % 6 + 1;                                          //this randomly picks a number of Pokemon each trainer will have
        trainerN = "Trainer " + to_string(counter);                             //creates the name for 15 trainers
        
        //cout << trainerN << endl;
        
        for(int i = 0; i < numTrainPoke; i++)
        {
            ID = rand() % (allPokemon.size() - 1);                              //this randomly generates the index of the Pokemon in the all Pokemon vector
            
            if(temp.size() == 0)
            {
                temp.push_back(ID);                                             //for the first index generated, it automatically gets stored
            }
            
            else
            {   
                for(int j = 0; j < temp.size(); j++)                            //for every index after it loops through all of the temp vector and compares it to the new index         
                {
                    if(ID == temp[j])
                    {
                       checker = true;                                          //if an index is repeated
                       i--;                                                     //subtracts one from i so each individual trainer has all the Pokemon they were assigned
                    }                                                
                }
            
                if(checker == false)
                {
                    temp.push_back(ID);                                         //if that index is new it gets pushed back
                }
            }
        }
        
        localBattle.setTrainerName(trainerN);                                   //sets info for the trainer
        localBattle.setIndex(counter);
        localBattle.setNumTPoke(numTrainPoke);
        
        // for(int i = 0; i < temp.size(); i++)                                 //a test loop
        // {
        //     cout << temp[i] << endl;
        // }
        
        for(int i = 0; i < numTrainPoke; i++)                                   //gets the index from temp and uses it to find a pokemon's name from the allPokemon vector
        {
            string pName = allPokemon[temp[i]].getPokemonName();                
            localBattle.setTrainerPokemon(pName);                               //the string Pokemon name is passed to a function that finds and sets the Pokemon
        }
        
        vector<string> vect;
        string n;
        
        for(int i = 0; i < temp.size(); i++)
        {
            n = allPokemon[temp[i]].getPokemonName();                           //gets the name of all the Pokemon in the temp vector and stores it in vect
            vect.push_back(n);
        }
        
        for(int i = 0; i < vect.size(); i++)
        {
            for(int p = 0; p < allPokemon.size(); p++)
            {
                if(vect[i] == allPokemon[p].getPokemonName())                   //searches the allPokemon vector and sees if any Pokemon in the allPokemon match
                {
                    allPokemon.erase(allPokemon.begin() + i);                   //deletes it
                }
            }
        }
        
        Trainers.push_back(localBattle);                                        //all of this is stored under an instance of localBattle which is stored in the Trainers vector
        counter++;
        temp.clear();                                                                       
    }
    
    // for(int i = 0; i < allPokemon.size(); i++)
    // {
    //     cout << allPokemon[i].getPokemonName() << endl;                      //another test loop
    // }
}

void gameManager::pokeCenter()
{
    string answer = "";
    string swap = "";
    string other = "";
    string active = "";
    bool check = false;
    
    myPlayer.healAll();
    cout << endl;
    cout << "Welcome to the Pokémon Center. All Pokémon in your party have been healed. Do you want to change the members of your party? (Y/N):" << endl;
    getline(cin, answer);
    
    if(answer == "Y" || answer == "y")
    {
        while(swap != "Q" && swap != "q")
        {   
            cout << "Here are all the Pokémon in your Pokédex. Select a single Pokemon you want to swap into your roster (the roster are the first 6 Pokemon shown). Enter Q or q to quit. Please enter the Pokemon you wish to swap (you MUST enter a number shown next to a Pokemon):" << endl;
            myPlayer.printAllPokemon();
            getline(cin, swap);
            //int k = stoi(swap);
            
            if(swap != "Q" && swap != "q")
            {
                cout << "Now please select which of the first 6 Pokemon you wish to swap it with." << endl;
                myPlayer.printFirstSix();
                getline(cin, other);
                //int h = stoi(other);
                
                if((stoi(swap) > 0 && stoi(swap) < 152) && (stoi(other) > 0 && stoi(other) < 7))
                {
                    myPlayer.swapPokemon(stoi(swap), stoi(other));
                }
                
                else
                {
                    cout  << endl;
                    cout << "Invalid numerical option. Please try again." << endl;
                    pokeCenter();
                }
            }
        }
        
        while(check != true)
        {
            cout << endl;
            cout << "You have chosen the 6 Pokémon below. Please choose which one should be the ACTIVE Pokémon (select a number shown next to the Pokemon):" << endl;
            myPlayer.printFirstSix();
            getline(cin, active);
                
            if(stoi(active) > 0 && stoi(active) <= myPlayer.getNumPokemon())
            {
                check = true;
                int f = (stoi(active) - 1);
                myPlayer.activatePokemon(f, true);
                myPlayer.printActivePokemon();
            }
                    
            else
            {
                cout << endl;
                cout << "Invalid option. Please try again." << endl;
            }
        }
    }
    
    else if(answer == "N" || answer == "n")
    {
        turns();
    }
    
    else
    {
        cout << endl;
        cout << "Invalid option. Please read the directions again." << endl;
        pokeCenter();
    }
}

void gameManager::readWildPokemon(int i)                                        //prints out the wild Pokemon in an encounter
{
    cout << "Name: " << wildPokemon[i].getPokemonName() << " HP: " << wildPokemon[i].getHp() << " A: " << wildPokemon[i].getAttack() << " D: " << wildPokemon[i].getDefense() << " S: " << wildPokemon[i].getSpeed() << " M: " << wildPokemon[i].getMax() << endl;
}

void gameManager::rescatterPokemon(int i, int yAxis, int xAxis)
{
    int check = 0;
    map[yAxis][xAxis] = "* ";
    
    while(check != 1)
    {
        int YPLoc = rand() % 25;                                                //randomly assigns an x coordinate
        int XPLoc = rand() % 16;                                                //does the same for y
            
        if((map[YPLoc][XPLoc] == "* ") && (XPLoc != myPlayer.getplayerLocationX()) && (YPLoc != myPlayer.getPlayerLocationY()))     //checks to see if the randomly generated location is a land tile and not the player's location
        {
            if((xPLocation[i] != XPLoc) || (yPLocation[i] != YPLoc))
            {
                xPLocation.insert(xPLocation.begin() + i, XPLoc);                                        //stores them
                yPLocation.insert(yPLocation.begin() + i, YPLoc);
                map[YPLoc][XPLoc] = "P ";                                           //sets the map at these coordinates to P
                check++;
            }
        }
    }
    
    turns();
}

void gameManager::run(int i, int yAxis, int xAxis)
{
    int e = myPlayer.findActive();
    int w = wildPokemon[i].getSpeed();
    int p = myPlayer.getPokeSpeed(e);
    int countFlee = 1;
        
    if(w < p)
    {
        cout << endl;
        cout << "You have successfully run away!" << endl;
        //nearestCenter();
    }
        
    else
    {
        double r = (w / 4) % 256;
        double s = (p * 32);
        double f = ((s / r) + 30) * countFlee;
        
        if(f > 255)
        {
            cout << endl;
            cout << "You have successfully run away!" << endl;
            //nearestCenter();
        }
        
        else
        {
            int t = rand() % 255;
            
            if(t < f)
            {
                cout << endl;
                cout << "You have successfully run away!" << endl;
                //nearestCenter();
            }
            
            else
            {
                cout << endl;
                cout << "Escape unsuccessful. The fight continues." << endl;
                aWildPokemonAppeared(yAxis, xAxis);
            }
        }
    }
}

void gameManager::fight(int i, int yAxis, int xAxis)
{
    int flee = rand() % 100;
    
    if(flee <= 60)
    {
        int found = myPlayer.findActive();
        int w = wildPokemon[i].getSpeed();
        int p = myPlayer.getPokeSpeed(found);
        
        if(w > p)
        {
            cout << "Fight" << endl;
        }
        
        else
        {
            cout << "Else" << endl;
        }
    }
    
    else if(flee > 60)
    {
        int e = myPlayer.findActive();
        int w = wildPokemon[i].getSpeed();
        int p = myPlayer.getPokeSpeed(e);
        int countFlee = 1;
            
        if(w > p)
        {
            cout << endl;
            cout << "The wild Pokemon has run away!" << endl;
            rescatterPokemon(i, yAxis, xAxis);
        }
            
        else
        {
            double r = (w / 4) % 256;
            double s = (p * 32);
            double f = ((s / r) + 30) * countFlee;
            
            if(f > 255)
            {
                cout << endl;
                cout << "The wild Pokemon has run away!" << endl;
                rescatterPokemon(i, yAxis, xAxis);
            }
            
            else
            {
                int t = rand() % 255;
                
                if(t < f)
                {
                    cout << endl;
                    cout << "The wild Pokemon has run away!" << endl;
                }
                
                else
                {
                    cout << endl;
                    cout << "The wild Pokemon has failed to escape! You automatically capture it!" << endl;
                    
                    for(int i = 0; i < wildPokemon.size(); i++)
                    {
                        if((xPLocation[i] == xAxis) && (yPLocation[i] == yAxis))                                                //loops through all the wildPokemon locations until it finds the one that matches the "P " location
                        {
                            myPlayer.newPokemon(wildPokemon[i].getPokemonName());                                           //updates player's Pokemon vector
                            wildPokemon.erase(wildPokemon.begin() + i);
                            xPLocation.erase(xPLocation.begin() + i);
                            yPLocation.erase(yPLocation.begin() + i);                                                       //erases the pokemon to remove duplicates and updates the map
                            map[yAxis][xAxis] = "* ";
                            turns();
                        }
                    }
                }
            }
        }
    }
}

void gameManager::switchA()
{
    bool looper = false;
    string pick = "";
    
    cout << "Pick another Active Pokemon(numbers 1 through 6 if applicable):" << endl;
    myPlayer.printFirstSix();
    getline(cin, pick);
    
    
    if(stoi(pick) > 0 && stoi(pick) < 7)
    {
        myPlayer.activatePokemon((stoi(pick) - 1), true);
        myPlayer.printActivePokemon();
    }
    
    else
    {
        cout << "Invalid option. Please try again." << endl;
        switchA();
    }
}

void gameManager::aWildPokemonAppeared(int yAxis, int xAxis)
{
    for(int i = 0; i < wildPokemon.size(); i++)
    {
        if((xPLocation[i] == xAxis) && (yPLocation[i] == yAxis))                                                //loops through all the wildPokemon locations until it finds the one that matches the "P " location
        {
            if(countb < 2)                                                                                      //the first 2 wild Pokemon encounters are freebies
            {
                countb++;
                cout << "You ran into a wild Pokémon!" << endl;
                cout << "The first 2 wild Pokemon you encounter automatically join your party!" << endl;
                
                myPlayer.newPokemon(wildPokemon[i].getPokemonName());                                           //updates player's Pokemon vector
                wildPokemon.erase(wildPokemon.begin() + i);
                xPLocation.erase(xPLocation.begin() + i);
                yPLocation.erase(yPLocation.begin() + i);                                                       //erases the pokemon to remove duplicates and updates the map
                map[yAxis][xAxis] = "* ";
                turns();
            } 
            
            else if(countb >= 2)
            {
                string r = "";
                
                cout << endl;
                cout << "You ran into a wild Pokémon!" << endl;                                                 //the fight menu for subsequent encounters
                readWildPokemon(i);
                cout << endl;
                cout << "Your Pokemon." << endl;
                myPlayer.getPlayerPokemon();
                cout << endl;
                cout << "What do you want to do (pick 1, 2, or 3):" << endl;
                cout << "1. Fight" << endl;
                cout << "2. Switch Active Pokémon" << endl;
                cout << "3. Run" << endl;
                getline(cin, r);
                
                switch(stoi(r))
                {
                    case 1:
                        fight(i, yAxis, xAxis);
                        break;
                        
                    case 2:
                        switchA();
                        aWildPokemonAppeared(yAxis, xAxis);
                        break;
                        
                    case 3:
                        run(i, yAxis, xAxis);
                        break;
                        
                    default:
                        cout << endl;
                        cout << "Invalid option. Pick again." << endl;
                        cout << endl;
                        aWildPokemonAppeared(yAxis, xAxis);                                                         //recursion pt.2 Electric Boogaloo
                        break;
                }
            }
        }
    }
}

char gameManager::travelMenu()
{
    /*
    Is initialized when the player picks a started pokemon in the form of the coordinates on the 2D array
    Adds or subtracts one from the coordinates and updates the variables
    */
    
    string d;
    char direction;
    
    cout << endl;
    cout << "Please choose a direction to travel in:" << endl;
    cout << "1. North" << endl;
    cout << "2. East" << endl;
    cout << "3. South" << endl;
    cout << "4. West" << endl;
    getline(cin, d);
    
    if(d == "1")                                                                //based on user input calles the travel function with the appropriate variables
    {
        direction = 'n';
        travel(direction, map);
    }
    
    else if(d == "2")
    {
        direction = 'e';
        travel(direction, map);
    }
    
    else if(d == "3")
    {
        direction = 's';
        travel(direction, map);
    }
    
    else if(d == "4")
    {
        direction = 'w';
        travel(direction, map);
    }
    
    else
    {
        cout << "Invalid option. Please try again." << endl;
        travelMenu();
    }

    return direction;
}

void gameManager::travel(char direction, string map[][16])
{
    int y = myPlayer.getPlayerLocationY();
    int x = myPlayer.getplayerLocationX();
    char dir;
    if(direction == 'n')
    {
        if((map[y - 1][x] != "~ ") && ((y - 1 >= 0) && (y - 1 < 25)))                           //checks to see if the tile isn't water or the out of bounds then sets the new location for the player
        {
            myPlayer.setPlayerY(y - 1);
        }
        
        else
        {
            cout << endl;
            cout << "You cannot travel in that direction. Pick another direction." << endl;
            cout << endl;
            dir = travelMenu();                                                                 //recursion baby
            travel(dir, map);
        }
    }
    
    else if(direction == 'e')
    {
        if((map[y][x + 1] != "~ ") && ((x + 1 >= 0) && (x + 1 < 16)))
        {
            myPlayer.setPlayerX(x + 1);
        }
        
        else
        {
            cout << endl;
            cout << "You cannot travel in that direction. Pick another direction." << endl;
            cout << endl;
            dir = travelMenu();
            travel(dir, map);
        }
    }
    
    else if(direction == 'w')
    {
        if((map[y][x - 1] != "~ ") && ((x - 1 >= 0) && (x - 1 < 16)))
        {
            myPlayer.setPlayerX(x - 1);
        }
        
        else
        {
            cout << endl;
            cout << "You cannot travel in that direction. Pick another direction." << endl;
            cout << endl;
            dir = travelMenu();
            travel(dir, map);
        }
    }
    
    else
    {
        if((map[y + 1][x] != "~ ") && ((y + 1 >= 0) && (y + 1 < 25)))
        {
            myPlayer.setPlayerY(y + 1);
        }
        
        else
        {
            cout << endl;
            cout << "You cannot travel in that direction. Pick another direction." << endl;
            cout << endl;
            dir = travelMenu();
            travel(dir, map);
        }
    }
    
    if(map[myPlayer.getPlayerLocationY()][myPlayer.getplayerLocationX()] == "G ")       //checks to see if the player landed on a gym or PokeCenter
    {
        //call PokeGym function
    }
    
    else if(map[myPlayer.getPlayerLocationY()][myPlayer.getplayerLocationX()] == "C ")
    {
        pokeCenter();
    }
    
    else
    {
        int w = myPlayer.getplayerLocationX();                                          //after the movement phase it searches a 6 by 6 region around to player and looks for "P "
        int z = myPlayer.getPlayerLocationY();
        
        for(int yAxis = z - 2; yAxis <= z + 2; yAxis++)
        {
            for(int xAxis = w - 2; xAxis <= w + 2; xAxis++)
            {
                if(((yAxis >= 0) && (yAxis <= 25)) && ((xAxis >= 0) && (xAxis < 16)))
                {
                    if(map[yAxis][xAxis] == "P ")
                    {
                        aWildPokemonAppeared(yAxis, xAxis);                                 //if found it calls this function with the coordinates
                    }
                }
            }
        }
        
        turns();
    }
}

void gameManager::rest()
{
    bool check = false;
    
    for(int h = 0; h < myPlayer.getNumPokemon(); h++)                                   //loops through all the player Pokemon 
    {   
        if(myPlayer.getPokemonHP(h) < myPlayer.getMaxPokeHP(h))                         //checks if their current health is lower than their full health
        {
            if(myPlayer.getPokeball() == 0)                                             //checks if the player is out of Pokeballs
            {
                cout << "You are out of Pokeballs. You cannot rest." << endl;
            }
        
            else
            {
                myPlayer.addHP(h);                                                      //calls a function that adds one to the pokemon hp
                check = true;
            }
        }
        
        if(check == true)
        {
            myPlayer.subtractPokeball();                                
        }
        
        if(check == false)
        {
            cout << endl;
            cout << "You were charged no pokeballs. This pokemon is at full health." << endl;
        }
    }
    turns();
}

void gameManager::tryYourLuck()
{
    int w = myPlayer.getplayerLocationX();
    int z = myPlayer.getPlayerLocationY();
    int c = 0;
    
    for(int yAxis = z - 3; yAxis <= z + 3; yAxis++)
    {
        for(int xAxis = w - 3; xAxis <= w + 3; xAxis++)                             //searches a 7 by 7 area for "P "
        {
            if((yAxis >= 0 && yAxis <= 25) && (xAxis >= 0 && xAxis < 16))
            {
                if(map[yAxis][xAxis] == "P ")
                {
                    // for(int i = 0; i < 20; i++)
                    // {
                    //     cout << wildPokemon[i].getPokemonName() << endl;             //test loop
                    // }
                    
                    for(int i = 0; i < wildPokemon.size(); i++)
                    {
                        c++;
                        if((xPLocation[i] == xAxis) && (yPLocation[i] == yAxis))        //loops through the xPLocation and xPLocation vectors until it finds matching coordinates
                        {
                            int l = rand() % 100;                                       //to give us a 50/50 chance
                            
                            if(l < 50)
                            {
                                cout << "Unlucky try." << endl;
                                cout << endl;
                                turns();
                            }
                            
                            else if(l >= 50)
                            {
                                string pokeName = wildPokemon[i].getPokemonName();      //if lucky it gets the Pokemon name and adds it to the player vector and then erases it from wildPokemon and updates the map
                                myPlayer.newPokemon(pokeName);
                                map[yAxis][xAxis] = "* ";
                                wildPokemon.erase(wildPokemon.begin() + i);
                                turns();
                                
                                // for(int i = 0; i < wildPokemon.size(); i++)
                                // {
                                //     cout << wildPokemon[i].getPokemonName() << endl;                 //test to see if the selected pokemon was deleted from the wildPokemon vector
                                // }
                            }    
                        }
                    }
                }
            }
        }
    }
    
    if(c == 0)
    {
        cout << "No Pokemon in area." << endl;
        cout << endl;
        turns();
    }
}

void gameManager::turns()
{
    /*
    Loops through and calls on functions that are responsible for things other than battles
    Presents the options to travel, rest, try your luck, and quit
    Based on what the player selects, the function will run that until some external condition forces it to do other wise(like a battle for example)
    */
    string c = "10";
    
    cout << endl;
    cout << "The sun is shining, " << myPlayer.getUsername() << "! " << "It’s a beautiful day, you have " << myPlayer.getPokeball() << " Pokéball(s) left and your Pokémon are strong." << endl;
    cout << endl;
        
    myPlayer.getPlayerPokemon();                                                //prints player Pokemon
    cout << endl;
    printMiniMap();
    
    while(stoi(c) < 1 || stoi(c) > 4)
    {
        cout << endl;
        cout << "Please choose from the following options:" << endl;            //based on player choice, it calls the appropriate function
        cout << "1. Travel" << endl;
        cout << "2. Rest" << endl;
        cout << "3. Try your luck" << endl;
        cout << "4. Quit the game" << endl;
        getline(cin, c);
        
        switch(stoi(c))
        {  
            case 1:
                travelMenu();
                break;
                
            case 2:
                rest();
                break;
                
            case 3:
                tryYourLuck();
                break;
                
            case 4:
                
                break;
                
            default:
                cout << "Invalid option. Please try again." << endl;
                break;
        }
    }
}

void gameManager::printMiniMap()
{
    int x = myPlayer.getplayerLocationX();
    int y = myPlayer.getPlayerLocationY();
    int a = 0;
    int b = 0;
    for(b = y - 3; b <= y + 3; b++)
    {
        for(a = x - 3; a <= x + 3; a++)                                         //prints a 7 by 7 area around the player based off of their location
        {
            if(((b < 0) || (b >= 25)) || (a < 0) || (a > 15))             //out of bounds
            {
                cout << "! ";
            }
            
            else if((a == x) && (b == y))                                            //if at the point in the nested for loops equals the player coordinates then it prints @
            {
                cout << "@ ";
            }
            
            else if(map[b][a] == "~ ")                                          //these print out the map markers
            {
                cout << "~ ";
            }
            
            else if(map[b][a] == "* ")
            {
                cout << "* ";
            }
            
            else if(map[b][a] == "P ")
            {
                cout << "P ";
            }
            
            else if(map[b][a] == "G ")
            {
                cout << "G ";
            }
            
            else if(map[b][a] == "C ")
            {
                cout << "C ";
            }
        }
        cout << endl;
    }
}

void gameManager::printWholeMap()
{
    for(int k = 0; k < 25; k++)
    {
        for(int l = 0; l < 16; l++)
        {
            cout << map[k][l];
        }
        cout << endl;
    }
}

void gameManager::initialize()
{
    string n = "10";
    string username;
    
    while(stoi(n) < 1 || stoi(n) > 4)
    {
        cout << "Welcome to Pokémon!" << endl;
        cout << endl;
        
        cout << "Please state your name:" << endl;
        getline(cin, username);
        cout << endl;
        myPlayer.setUsername(username);
       
        cout << "Welcome, " << username << "! " << "Before you can begin your Pokémon adventure, you must choose a starting Pokémon, courtesy of the Professor." << endl;
        cout << endl;
        cout << "Please choose from the following Pokémon (you MUST enter an integer associated with each pokemon):" << endl;
        cout << "1. Bulbasaur" << endl;
        cout << "2. Charmander" << endl;
        cout << "3. Squirtle" << endl;
        cout << "4. Pikachu" << endl;
        getline(cin, n);
        startGame(stoi(n));                                                     //start menu calls the startGame function with the user input
        cout << endl;
    }
}

void gameManager::startGame(int n)
{
    /*
    Reads the pokemon file and populates the pokemon vector with pokemon objects for every pokemon
    Reads the map file and populates the 2D array with the file contents
    Initializes the start of the game up till the pokemon selection
    */
    
    //Player Player1;
    
    int count = 0;
    string line = "";
    string temp[9];
    int i = 0;
    
    int counta = 0;
    string linea = "";
    string tempa[16];
    int j = 0;
    
    ifstream pokeFile("pokemon.txt");
    
    if(pokeFile.is_open())                                                      //checks if the file opened properly
    {
        while(getline(pokeFile, line))                                          //goes line by line through the file
        {
            if(line != "" && line != "#,Pokémon,HP,Attack,Defense,Speed,Max,Type,")     //checks if the line is empty and skips the first one
            {
                //cout << line << endl;
                Pokemon myPokemon;
                int length = 9;
                char delimiter = ',';
                    
                count = split(temp, delimiter, length, line);                           //calls the split function
            
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
                
                i++;                                                                    //for every Pokemon it sets all the stats and stores it in the allPokemon vector under an instance of myPokemon
                allPokemon.push_back(myPokemon);
            }
        }
        // for(int i = 0; i < allPokemon.size(); i++)
        // {
        //      cout << allPokemon[0].getHp() << endl;
        // }
    }
    
    ifstream pokeMap("mapPoke.txt");
    
    if(pokeMap.is_open())                                                       //checks if the file opened properly
    {
        while(getline(pokeMap, linea))                                          //goes line by line through the file
        {
            if(linea != "")                                                      //checks if the line is empty
            {
                int lengtha = 16;
                char delimitera = ',';
                    
                counta = split(tempa, delimitera, lengtha, linea);              //calls the split function
                
                for(int k = 0; k < counta; k++)                                 //for every column in a row it sets the appropriate tile symbol
                {
                    map[j][k] = tempa[k];
                    
                    if(map[j][k] == "w")
                    {
                        map[j][k] = "~ ";
                    }
                    
                    if(map[j][k] == "p")
                    {
                        map[j][k] = "* ";
                    }
                    
                    if(map[j][k] == "G")
                    {
                        map[j][k] = "G ";
                    }
                    
                    if(map[j][k] == "C")
                    {
                        map[j][k] = "C ";
                    }
                }
                j++;                                                            //this counts up the rows
            }
        }
    }
    //printWholeMap();                                                          //test make sure everything looks ok

    switch(n)
    {
        case 1:
            myPlayer.setPlayerX(6);                                             //sets starting location
            myPlayer.setPlayerY(12);
            //myPlayer.setPlayerX(10);                                             //sets starting location
            //myPlayer.setPlayerY(2);
            myPlayer.updatePokedex("Bulbasaur");                                //sets starting Pokemon
            myPlayer.activatePokemon(0, true);                                  //activates the Pokemon and deletes it from allPokemon
            allPokemon.erase(allPokemon.begin() + 0);
            pokemonScatter();                                                   //calls the randomize and scatter function for Pokemon and Trainers
            trainerScatter();
            turns();
            break;
        
        case 2:
            myPlayer.setPlayerX(7);
            myPlayer.setPlayerY(12);
            myPlayer.updatePokedex("Charmander");
            allPokemon.erase(allPokemon.begin() + 3);
            myPlayer.activatePokemon(0, true);
            pokemonScatter();
            trainerScatter();
            turns();
            break;
        
        case 3:
            myPlayer.setPlayerX(8);
            myPlayer.setPlayerY(12);
            myPlayer.updatePokedex("Squirtle");
            allPokemon.erase(allPokemon.begin() + 7);
            myPlayer.activatePokemon(0, true);
            pokemonScatter();
            trainerScatter();
            turns();
            break;
        
        case 4:
            myPlayer.setPlayerX(9);
            myPlayer.setPlayerY(12);
            myPlayer.updatePokedex("Pikachu");
            allPokemon.erase(allPokemon.begin() + 26);
            myPlayer.activatePokemon(0, true);
            pokemonScatter();
            trainerScatter();
            turns();
            break;
        
        default:
            cout << "Invalid Option. Please try again." << endl;
            allPokemon.clear();
            break;
    }
}