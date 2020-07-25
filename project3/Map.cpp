#include "Map.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>
#include <math.h>

using namespace std;

Map::Map()
{
    // for(int i = 0; i < 25; i++)
    // {
    //     for(int j = 0; j < 16; j++)
    //     {
    //         map[i][j] = 0;
    //     }
    // }
}

char Map::printMap()
{
    for(int i = 0; i < 25; i++)
    {
        for(int j = 0; j < 16; j++)
        {
            cout << map[i][j];
        }
    }
}

char Map::printVisible()
{
    /*
    Same concept as the printMap function except that it takes where the player is and then adds 3 to left and right and top and bottom of the index of th player's location
    It stores the location of the corners and prints everything inside that
    */
}