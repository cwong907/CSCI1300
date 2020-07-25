#include <iostream>
using namespace std;

void conversion (float celsius)
{
    float Faren_Convert = (celsius/5)*9 + 32;
    
    cout << Faren_Convert << endl;
}


int main()
{
    float celsius = 38.0;
    conversion(celsius);
    
    cout << "All Done." << endl;
}