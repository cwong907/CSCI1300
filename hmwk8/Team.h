#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>
#include "Player.h"
#ifndef TEAM_H
#define TEAM_H

using namespace std;

class Team
{
    private:
    string teamName;
    vector<Player> players;
    
    public:
    Team();
    Team(string);
    
    void setTeamName(string);
    void readRoster(string);
    string getPlayerName(int);
    double getPlayerPoints(int);
    int getNumPlayers();
    string getTeamName();
};
#endif