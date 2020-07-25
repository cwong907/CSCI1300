#include <iostream>
#include <math.h>
#include <iomanip>
#include <string>
using namespace std;

void LeavesPerTree(double p)
{
    double leaves = p / (0.001 * 1031);
    
    if(leaves > 10000)
    {
        cout << leaves << endl;
        cout << "More leaves than last year" << endl;
    }
    
    else 
    {
        cout << leaves << endl;
    }
}

int main()
{
    int day = 5;
    
    DayOfWeek(day);
}