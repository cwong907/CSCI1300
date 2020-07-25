#include <iostream>
#include <math.h>
#include <iomanip>
#include <string>
using namespace std;

void numberDigits(int x)
{
   int count = 0, val = x;
   
   if(x == 0)
   {
      count = 1;
   }
   
   else
   {
      while(x!=0)
      {
         x = x / 10;
         count++;
      }
   }
   cout<<"The number " << val << " has " << count << " digits."<<endl;
}

int main()
{
    int day = 5;
    
    DayOfWeek(day);
}