#include <iostream>
#include <math.h>
#include <iomanip>
#include <string>
using namespace std;

int sumOfMultiples(int seed, int cap)
{
   int i = 1, sum = 0;
   while(seed * i <= cap)
   {
      sum += seed * i;
      i++;
   }
   return sum;
}

int main()
{
    int day = 5;
    
    DayOfWeek(day);
}