#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>
#include "Player.h"

using namespace std;

Player::Player()
{
    name = "";
    points = 0;
}

Player::Player(string n, double p)
{
    name = n;
    points = p;
}

void Player::setName(string n)
{
    name = n;
}

void Player::setPoints(double p)
{
    points = p;
}

string Player::getName()
{
    return name;
}

double Player::getPoints()
{
    return points;
}