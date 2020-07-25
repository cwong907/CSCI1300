#include <iostream>
#include <math.h>
#include <iomanip>
#include <string>
using namespace std;

int addOddMinusEven(int n1, int n2)
{
    int sumOdd = 0;
    int sumEven = 0;
    int oddMinusEven;
    
    while(n1 < n2)
    {
        if(n1 % 2 == 0)
        {
            sumEven = sumEven + n1;
        }
        
        if((n1 % 2 == 1) || (n1 % 2 ==-1))
        {
            sumOdd = sumOdd + n1;
        }
        
        n1++;
    }
    
    oddMinusEven = sumOdd - sumEven;
    return oddMinusEven;
}

int main()
{
    int day = 5;
    
    DayOfWeek(day);
}