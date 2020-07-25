#include <iostream>
#include <math.h>
#include <iomanip>
#include <string>
using namespace std;

double GasBill(double x)
{
    double total;
    
    if(x < 0)
    {
        cout << "Incorrect input" << endl;
    }
    
    else if(x == 0)
    {
        return 0;
    }
    
    else if(x >= 100)
    {
        total = 100.0 * 1.23;
        
        if(x < 200)
        {
            total = total + (x - 100) * 1.14; 
        }
        
        else
        {
            total = total + 100 * 1.14 + (x - 200) * 1.08;
        }
    }
    
    else
    {
        total = x * 1.23;
    }
    
    return total;
}

int main()
{
    int day = 5;
    
    DayOfWeek(day);
}