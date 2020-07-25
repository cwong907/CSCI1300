#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>
#include <cmath>
#include "Pokemon.h"
#ifndef PLAYER_H
#define PLAYER_H

using namespace std;    

class Player
{
    private:
    vector<Pokemon> playerPokemon;
    vector<Pokemon> pokedex;
    int playerLocationX;
    int playerLocationY;
    int pokeball;
    int badges;
    int points;
    string username;
    int numPokemon;
    
    public:
    Player();
    
    void setUsername(string);
    void setPlayerX(int);
    void setPlayerY(int);
    void activatePokemon(int, bool);
    int updatePokedex(string);
    
    void addHP(int);
    void subtractPokeball();
    
    string getUsername();
    int getPokemonHP(int);
    int getMaxPokeHP(int);
    void getPlayerPokemon();
    int getNumPokemon();
    int getBadges();
    int getPoints();
    int getPokeball();
    int getplayerLocationX();
    int getPlayerLocationY();
    int getPokeSpeed(int);
    void newPokemon(string);
    void healAll();
    void printFirstSix();
    void printAllPokemon();
    void swapPokemon(int, int);
    void printActivePokemon();
    int findActive();
};
#endif