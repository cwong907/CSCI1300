#include "Planet.h"
#include <math.h>
#include <iostream>
using namespace std;



Planet::Planet()                                                                //sets value directly 
{
    planetName = "";
    planetRadius = 0;
}

Planet::Planet(string a, double r)                                              //sets variable names to input variables from setName and setRadius
{
    planetName = a;
    planetRadius = r;
}

void Planet::setName(string a)
{
    planetName = a;
}

string Planet::getName()
{
    return planetName;
}

void Planet::setRadius(double r)
{
    planetRadius = r;
}

double Planet::getRadius()
{
    return planetRadius;
}

double Planet::getVolume()
{
    double volume = (4.0/3.0) * M_PI * (double) pow(planetRadius, 3.0);         //calculates the volume of a planet based on what the planetRadius is set to
    return volume;
}
