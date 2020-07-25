#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>
#include <cmath>
#include "Pokemon.h"
#ifndef MAP_H
#define MAP_H

using namespace std;

class Map
{
    private:
    string map[25][16];
    //vector<Pokemon>;
    
    public:
    Map();
    
    string populateMap(string);
    char printMap();
    char printVisible();
};
#endif