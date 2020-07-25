//#include "Pokemon.h"
// #include "Player.h"
#include "Battles.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

class gameManager
{
    private:
    string map[27][16];
    vector<Pokemon> allPokemon;
    vector<Pokemon> wildPokemon;
    vector<Battles> Trainers;
    vector<int> xPLocation;
    vector<int> yPLocation;
    int numPokemon;
    int countb = 0;
    
    public:
    void pokemonScatter();
    void trainerScatter();
    void startGame(int);
    void turns();
    void printWholeMap();
    void printMiniMap();
    void initialize();
    char travelMenu();
    void travel(char, string map[][16]);
    void rest();
    void tryYourLuck();
    void aWildPokemonAppeared(int, int);
    void pokeCenter();
    void pokeGym();
    void readWildPokemon(int);
    void fight(int, int, int);
    void run(int, int, int);
    void switchA();
    void rescatterPokemon(int, int, int);
    
    Player myPlayer;
    
};
#endif