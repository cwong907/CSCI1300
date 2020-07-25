#include <iostream>
#include <math.h>
#include <iomanip>
#include <string>
using namespace std;

/*double solarCharge(double time, double panelPower, double batteryCapacity)
{
    double t2c = (panelPower / batteryCapacity) * 1.6;
    
    double percentCharge = (time / t2c) * 100;
    
    if(percentCharge > 100)
    {
        return 100;
    }
    
    else
    {
        return percentCharge;
    }
}

int main()
{
    double time = 200;
    double panelPower = 10;
    double batteryCapacity = 5; 
    
    cout << solarCharge(time, panelPower, batteryCapacity) << "%" << endl;
}*/

int main()
{
    double x = 75;
    double y = 80;
    
    double z = x/y;
    
    cout << z << endl;
}