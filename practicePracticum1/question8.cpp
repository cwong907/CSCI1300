#include <iostream>
#include <math.h>
#include <iomanip>
#include <string>
using namespace std;

double PizzaParty(int pizzaNumber, double cost, double discount)
{
    double total;
    
    if(pizzaNumber < 10)
    {
        total = (pizzaNumber * cost) + 10;
    }
    
    else if(pizzaNumber >= 10)
    {
        total = pizzaNumber * (cost -(discount * cost));
    }
}

int main()
{
    int day = 5;
    
    DayOfWeek(day);
}