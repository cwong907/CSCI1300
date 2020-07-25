#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>
#ifndef PLAYER_H
#define PLAYER_H

using namespace std;

class Player
{
    private:
    string name;
    double points;
    
    public:
    Player();
    Player(string, double);
    
    string getName();
    double getPoints();
    void setName(string);
    void setPoints(double);
};
#endif