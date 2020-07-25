// CSCI 1300 Fall 2019
// Author: Weige Wong
// Recitation: 203 - Soumyajyoti Bhattacharya
// Project 2 - Problem 0-12

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
        ratings[i] = 0;                                                         //sets all ratings in the array to 0
    }
}

User::User(string user, int rate[], int num)
{
    username = user;
    numRatings = num;
    for(int i = 0; i < size; i++)                                               //takes the ratings from the rate array and places the values stored in the same spot in the ratings array as long as it doesn't over run the array size
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
    if(idx >= 50 || idx < 0)                                                    //makes sure the spot exists in the array
    {
        return -1;
    }
    
    else
    {
        return ratings[idx];                                                    //get the rating
    }
}

int User::setRatingAt(int idx, int value)
{
    if((idx <= 50) && (value <= 5 && value >= 0))                               //makes sure the spot exists and the rating is valid
    {
        ratings[idx] = value;                                                   //sets the rating
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