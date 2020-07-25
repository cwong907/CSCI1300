#include "User.h"
#include <math.h>
#include <iostream>
#include <string>
using namespace std;

User::User()
{
    username = "";
    numRatings = 0;
    size = 50;
    
    for(int i = 0; i < size; i++)
    {
        ratings[i] = 0;
    }
}

User::User(string user, int rate[], int num)
{
    username = user;
    numRatings = num;
    for(int i = 0; i < size; i++)
    {
        if(i < numRatings)
        {
            ratings[i] = rate[i];
        }
        
        else
        {
            ratings[i] = 0;
        }
    }
}

void User::setUsername(string user)
{
    username = user;
}

string User::getUsername()
{
    return username;
}

int User::getRatingAt(int idx)
{
    if(idx >= 50 || idx < 0)
    {
        return -1;
    }
    
    else
    {
        return ratings[idx];
    }
}

int User::setRatingAt(int idx, int value)
{
    if((idx <= 50) && (value <= 5 && value >= 0))
    {
        ratings[idx] = value;
        return true;
    }
    
    else
    {
        return false;
    }
}

void User::setNumRatings(int num) 
{
    numRatings = num;        
}

int User::getNumRatings()
{
    return numRatings;
}

int User::getSize()
{
    return size;
}