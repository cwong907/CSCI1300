#include <iostream>
#include "Player.h"

using namespace std;

/*
1. Write a Player.h and Player.cpp class that has functions that sets the player name, player points, and gets them
2. Write a main function that calls and tests those cases
Input: name, points (string, int)
Output: name, points (string, int)
Return: name, points (string, int)
*/

int main()
{
    //Test 1
    //Input: "Williwaw", 42.0
    //Output: "Williwaw", 42.0
    Player player1("Williwaw", 42.0);
    cout << player1.getName() << endl;
    cout << player1.getPoints() << endl;
    
    //Test 2
    //Input: "Cody", 88.5
    //Output: "Cody", 88.5
    Player Player1;
    Player1.setName("Cody");
    Player1.setPoints(88.5);
    cout << Player1.getName() << endl;
    cout << Player1.getPoints() << endl;
    
   
}