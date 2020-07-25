#include <iostream>
#include <math.h>
#include <iomanip>
#include <string>
using namespace std;

void calculator(double n1, double n2, char x)
{
    double result;
    switch(x)
    { 
        case '+':
        result = n1 + n2;
        cout << n1 << " " << x << " " << n2 << " " << "= " << setprecision(2) << result << endl;
        break;
         
        case '-':
        result = n1 - n2;
        cout << n1 << " " << x << " " << n2 << " " << "= " << setprecision(2) << result << endl;
        break;
         
        case '*':
        result = n1 * n2;
        cout << n1 << " " << x << " " << n2 << " " << "= " << setprecision(2) << result << endl;
        break;
         
        case '/':
        result = n1 / n2;
        cout << n1 << " " << x << " " << n2 << " " << "= " << setprecision(2) << result << endl;
        break;
         
        default:
        cout << "Invalid operator!" << endl;
        return;
    }
}

int main()
{
    double n1 = 4.29;
    double n2 = 5;
    char x = '+';
    
    calculator(n1, n2, x);
}