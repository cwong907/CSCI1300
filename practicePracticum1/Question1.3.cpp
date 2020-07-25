#include <iostream>
#include <math.h>
#include <iomanip>
#include <string>
using namespace std;

double smallestNumber (double x, double y, double z)
{
    double smallest;
    
    if(x < y)
    {
        if(x < z)
        {
            smallest = x;
            return smallest;
        }
    }
    
    else if(y < x)
    {
        if(y < z)
        {
            smallest = y;
            return smallest;
        }
    }
    
    else if(z < x)
    {
        if(z < y)
        {
            smallest = z;
            return smallest;
        }
    }
}

int main()
{
    int x = 4;
    int y = 9;
    int z = 2.5;
    
    cout << smallestNumber(x, y, z) << endl;
}