#include <iostream>
#include <math.h>
#include <iomanip>
#include <string>
using namespace std;

int prodDigits(int n)
{
   int p = 1;
   if(n == 0)
   {
       return 0;
   }
   else
   {
    while(n!=0)
    {
        p = p * (n%10);
        n = n / 10;
    }
   }
   return p;
}

int main()
{
    int day = 5;
    
    DayOfWeek(day);
}