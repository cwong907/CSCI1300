 while(counter < 20)
    {
        int YPLoc = rand() % 25;                                                //randomly assigns an x coordinate
        int XPLoc = rand() % 16;                                                //does the same for y
        
        if(tempXPLoc.size() == 0 && tempYPLoc.size() == 0)
        {
            tempXPLoc.push_back(XPLoc);
            tempYPLoc.push_back(YPLoc);
            counter++;
        }
        
        else
        {
            /*for(int i = 0; i < tempXPLoc.size(); i++)                         
            {
                if((tempXPLoc[i] == XPLoc) && (tempYPLoc[i] == YPLoc))
                {
                    check = true;
                }
            }*/
            
            if(/*(check == false) &&*/ (map[YPLoc][XPLoc] == "* ") && (XPLoc != myPlayer.getplayerLocationX()) && (YPLoc != myPlayer.getPlayerLocationY()))
            {
                tempXPLoc.push_back(XPLoc);
                tempYPLoc.push_back(YPLoc);
                counter++;
            }
        }
    }
    
    
/*void gameManager::trainerScatter()
{
    /*
    Looks at each location where there is a G on the map and assigns a trainer to that location
    
    
    int randID = 0;
    int counter = 0;
    int index = 0;
    int pokemons = allPokemon.size();
    int numPoke4Train = 0;
    string trainerName = "";
    vector<int> tempIndex;
    
    
    while(counter < 15)                                                         //should create 15 instances of the Battles(aka trainers) class
    {
        Battles localBattle;
        
        numPoke4Train = rand() % 6 + 1;                                     //this number randomly creates the number of pokemon each trainer will have
        trainerName = "Trainer " + to_string(counter);                               //trainer names for each time the while loop repeats
        
        for(int i = 0; i < numPoke4Train; i++)                                  //this loop generates the index (relative to the allPokemon vector) of each pokemon that will belong to the trainer
        {
            randID = rand() % pokemons;                                         //randomly generates a number which corresponds to the index location of a pokemon
            tempIndex.push_back(randID);                                        //for this instance of a trainer, it stores the indexes in an temp vector
        }
        
        localBattle.setTrainerName(trainerName);                               //sets trainer names
        localBattle.setIndex(counter);
        localBattle.setNumTPoke(numPoke4Train);
        
        for(int i = 0; i < numPoke4Train; i++)                                  
        {
            string pName = allPokemon[tempIndex[i]].getPokemonName();
            localBattle.setTrainerPokemon(pName);
            allPokemon.erase(allPokemon.begin() + tempIndex[i]);
        }
        
        Trainers.push_back(localBattle);
        counter++;
        tempIndex.clear();
    }
}*/