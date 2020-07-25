#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>
#include "Team.h"
#include "Player.h"

using namespace std;

/*
1. Write a function that takes 2 team objects that are filled with Player vectors
2. The function should first check that the teams have at least 4 players
3. Then it should get the total points accumulated from both teams by looping through each player on that team and add their points
4. If the points for both teams are the same then it should return draw
5. If not, print the team with the bigger score
Input: team objects that have players and points stored in a player vector (Team)
Output: team name with the highest score (string)
Return: team name (string)
*/

string game(Team team1, Team team2)
{
    int total1 = 0;
    int total2 = 0;
    
    if(team1.getNumPlayers() < 4 || team2.getNumPlayers() < 4)                  //checks if the team is at least 4
    {
        return "forfeit";
    }
    
    else
    {
        for(int i = 0; i < 4; i++)                                              //sums the points for each player for team 1
        {
            total1 += team1.getPlayerPoints(i);
        }
        
        for(int j = 0; j < 4; j++)                                              //sums the points for each player for team 2
        {
            total2 += team2.getPlayerPoints(j);
        }
        
        if(total1 == total2)                                                    //if the point totals from both teams are equal
        {
            return "draw";
        }
        
        else if(total1 > total2)                                                //if team 1's points are greater than team 2
        {
            return team1.getTeamName();
        }
        
        else if(total2 > total1)                                                //vice versa
        {
            return team2.getTeamName();
        }
    }
}

int main()
{
    
    Team team1("Team 1");
    team1.readRoster("roster1.txt");
    Team team2("Team 2");
    team2.readRoster("roster2.txt");
    string a = game(team1, team2);

    if(a == "forfeit")
    {
        cout << "The winner is: " << a << endl;
    }
    
    else if(a == "draw")
    {
        cout << "The winner is: " << a << endl;
    }
    
    else
    {
        cout << "The winner is: " << a << endl;
    }
  
    Team team3("Team 3");
    team3.readRoster("roster3.txt");
    Team team4("Team 4");
    team4.readRoster("roster4.txt");
    a = game(team3, team4);

    if(a == "forfeit")
    {
        cout << "The winner is: " << a << endl;
    }
    
    else if(a == "draw")
    {
        cout << "The winner is: " << a << endl;
    }
    
    else
    {
        cout << "The winner is: " << a << endl;
    }
    
}