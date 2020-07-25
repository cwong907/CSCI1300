#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>
#include "Team.h"
#include "Player.h"

using namespace std;

/*
1. Write a Team.h and Team.cpp class that has functions that sets the team name, vector<Player>, and team roster from a file name
2. The filename should store a name and its points and one of the functions in the Team class should fill the Player vector with those names and their points
3. Write a main function that calls and tests those cases
Input: team name, file name, points (string, int)
Output: team name, player name, player points, number of players (string, int)
Return: team name, player name, player points, number of players (string, int)
*/

int main()
{
    //Test 1
    //Input: A Team, roster3.txt
    //Output: 4, A Team, the team member names and their points
    Team Team1;
    Team1.setTeamName("A Team");
    Team1.readRoster("roster3.txt");
    
    cout << Team1.getNumPlayers() << endl;
    cout << Team1.getTeamName() << endl;
    for(int i = 0; i < Team1.getNumPlayers(); i++)
    {
        cout << Team1.getPlayerName(i) << endl;
        cout << Team1.getPlayerPoints(i) << endl;
    }
    cout << endl;
    
    //Test 2
    //Input: B Team, roster4.txt
    //Output: team member names their points, and ERROR
    Team Team2;
    Team2.setTeamName("B Team");
    Team2.readRoster("roster4.txt");
    for(int i = 0; i < Team1.getNumPlayers(); i++)
    {
        cout << Team2.getPlayerName(i) << endl;
        cout << Team2.getPlayerPoints(i) << endl;
    }
}