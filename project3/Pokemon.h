#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>
#include <cmath>
#ifndef POKEMON_H
#define POKEMON_H

using namespace std;

class Pokemon
{
    private:
    string pokemonName;
    bool active;
    vector<string> types;
    int hp;
    int maxHP;
    int attack;
    int defense;
    int speed;
    int max;
    int level;

    public:
    Pokemon();
    
    void heal();
    
    void setActivePokemon(bool);
    void setPokemonName(string);
    void setHp(int);
    void setAttack(int);
    void setDefense(int);
    void setSpeed(int);
    void setMax(int);
    void setLevel(int);
    void setType(string);
    void setMaxHP(int);
    void resetMaxHP();
    
    string getPokemonName();
    vector<string> getTypeAt(int);
    int getHp();
    int getMaxHP();
    int getAttack();
    int getDefense();
    int getSpeed();
    int getMax();
    int getLevel();
    string getActive();
    
};
#endif