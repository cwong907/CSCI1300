#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>
#include <cmath>
#ifndef BATTLES_H
#define BATTLES_H

using namespace std;

class Battles
{
    private:
    string trainerName;
    int index;
    int numTrainPoke;
    vector<Pokemon> trainerPokemons;
    vector<int> xTLocation;
    vector<int> yTLocation;
    
    public:    
    void battleTrainerTracker();
    
    // vector<int> getXLocation();
    // vector<int> getYLocation();
    
    string getTrainerName();
    
    void setTrainerName(string);
    void setNumTPoke(int);
    void setTrainerPokemon(string);
    void setIndex(int);
};
#endif