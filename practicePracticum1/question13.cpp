#include <iostream>
#include <math.h>
#include <iomanip>
#include <string>
using namespace std;

double TuitionCost(int units, double cost)
{
    double total;
    
    if(units < 0 || cost < 0)
    {
        return -1;
    }
    
    else if(units <= 16)
    {
        total = units * cost;
    }
    
    else if(units > 16)
    {
        total = cost * 16 + ((units - 16) * (cost / 2));
    }
    
    return total;
}

int main()
{
    int day = 5;
    
    DayOfWeek(day);
}