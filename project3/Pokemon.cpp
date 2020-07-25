#include "Pokemon.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>
#include <math.h>

using namespace std;

Pokemon::Pokemon()
{
    pokemonName = "";
    hp = 0;
    attack = 0;
    defense = 0;
    speed = 0;
    max = 0;
    level = 0;
}
    
void Pokemon::setPokemonName(string pokename)
{
    pokemonName = pokename;
}

void Pokemon::setHp(int h)
{
    hp = h;
    maxHP = h;                                                                  //when the first Pokemon is read in this gets set
}

void Pokemon::setAttack(int a)
{
    attack = a;
}

void Pokemon::setDefense(int d)
{
    defense = d;
}

void Pokemon::setSpeed(int s)
{
    speed = s;
}

void Pokemon::setMax(int m)
{
    max = m;
}

void Pokemon::setLevel(int l)
{
    level = l;
}

void Pokemon::setActivePokemon(bool b)
{
    active = b;
}

void Pokemon::setType(string type)
{
   types.push_back(type);
}

void Pokemon::heal()                                                            //the heal function used in the rest function to add 1 hp to all Pokemon
{
    hp++;
}

string Pokemon::getActive()
{
    if(active == true)
    {
        return "(Active)";
    }
    
    else
    {
        return "(Inactive)";
    }
}
    
string Pokemon::getPokemonName()
{
    return pokemonName;
}

vector<string> Pokemon::getTypeAt(int)
{
    /*
    Based on an int index that corresponds to the pokemon in the pokemon vector, this goes into the types vector to retrieve the pokemon type
    */
}

int Pokemon::getHp()
{
    return hp;
}

int Pokemon::getMaxHP()
{
    return maxHP;
}

int Pokemon::getAttack()
{
    return attack;
}

int Pokemon::getDefense()
{
    return defense;
}

int Pokemon::getSpeed()
{
    return speed;
}

int Pokemon::getMax()
{
    return max;
}

int Pokemon::getLevel()
{
    return level;
}

void Pokemon::setMaxHP(int h)
{
    maxHP = h;
}

void Pokemon::resetMaxHP()
{
    hp = maxHP;
}