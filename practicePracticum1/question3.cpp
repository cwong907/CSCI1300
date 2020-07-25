#include <iostream>
#include <math.h>
#include <iomanip>
#include <string>
using namespace std;

void DayOfWeek(int day)
{
    if(day > 6 || day < 0)
    {
        cout << "INVALID" << endl;
    }
    
    else if(day == 5)
    {
        cout << "FUNDAY" << endl;
    }
    
    else if(day == 0 || day == 6)
    {
        cout << "SLEEPDAY" << endl;
    }
    
    else if(day == 2 || day == 3 || day == 4)
    {
        cout << "WORKDAY" << endl;
    }
    
    else if(day == 1)
    {
        cout << "MONDAY" << endl;
    }
}

int main()
{
    int day = 5;
    
    DayOfWeek(day);
}