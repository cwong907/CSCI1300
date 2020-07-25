#include <iostream>
#ifndef PLANET_H
#define PLANET_H
using namespace std;

class Planet
{
    private:
    string planetName;                                  //class variables 
    double planetRadius;
    
    public:
    Planet();                                           //constructors
    Planet(string, double);
    
    void setName(string);                               //functions (types and input types)
    string getName();
    void setRadius(double);
    double getRadius();
    double getVolume();
};
#endif