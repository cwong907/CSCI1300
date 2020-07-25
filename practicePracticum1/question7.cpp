#include <iostream>
#include <math.h>
#include <iomanip>
#include <string>
using namespace std;

float PaintHouse(int width, int depth, int winDoor)
{
    float perimeter, wallCost, doorCost, totalCost;
    
    perimeter = 2 * (width + depth);
  
    if((width < 0) || (depth < 0) || (winDoor < 0)) 
    {
        return -1;
    }
    
    if(perimeter <= 100)
    {
        wallCost = perimeter * 8;
    }
    
    else if (perimeter > 100 && perimeter <= 200)
    {
        wallCost = (100 * 8) + ((perimeter - 100) * 10);
    }
    
    else if (perimeter > 200)
    {
        wallCost = (100 * 8) + ((100) * 10) + (perimeter - 200) * 15;
    }
  
    doorCost = winDoor * 6.75;
  
    totalCost = wallCost + doorCost;
    return totalCost;
}

int main()
{
    int day = 5;
    
    DayOfWeek(day);
}