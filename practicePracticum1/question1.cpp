#include <iostream>
#include <math.h>
#include <iomanip>
#include <string>
using namespace std;

double CoffeeCost(int cups, double price)
{
    if(cups > 12)
    {
        int deal = (cups / 12);
        
        int new_cups = cups - deal;
        
        double final = new_cups * price;
        
        return final;
    }
    
    else 
    {
        double total = cups * price;
        
        return total;
    }
}

int main()
{
    int cups = 27;
    double price = 1.5;
    
    cout << coffeeCost(cups, price) << endl;
}