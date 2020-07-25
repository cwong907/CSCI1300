#include <iostream>
#include <string>
#ifndef USER_H
#define USER_H
using namespace std;

class User
{
    private:
    string username;
    int ratings[50];
    int numRatings;
    int size = 50;
    
    public:
    User();
    User(string, int rate[], int);
    
    void setUsername(string);
    string getUsername();
    int getRatingAt(int);
    int setRatingAt(int, int);
    void setNumRatings(int);
    int getNumRatings();
    int getSize();
};
#endif 