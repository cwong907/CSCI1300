#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>
#include <cmath>
#include "Player.h"
#include "Pokemon.h"
//#include "Battles.h"
#include "Map.h"
#include "gameManager.h"

using namespace std;

int main()
{
    gameManager myGame;
    
    myGame.initialize();
    
    /*
    From here it calls the startGame() function to initialize the game
    Goes through the "main menu" (basically the one that moves, rests, etc)
    Goes into the battles menu if the situation requires
    */
}