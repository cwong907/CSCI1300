#include <iostream>
#include <math.h>
#include <iomanip>
#include <cmath>
#include <assert.h>
using namespace std;

/*double doublepower(double a, double b)
{
    double intpower()
    {
        
    }
}

int main()
{
    
}


bool failure = true;
bool it_it_bad = true;

int main()
{
    cout << "Failure mode: ";
   
    if (failure == true) 
    {
        cout << "true" << endl;  
    }
    
    else
    {
        cout << "false" << endl;
    }
}
*/

int main(){
    int desired_floor, actual_floor;
    
    cout << "Enter floor: ";
    cin >> desired_floor;
    assert(desired_floor !=13);
    
    if (desired_floor > 13)
    {
        actual_floor= desired_floor-1;
    }
    
    else
    {
        actual_floor = desired_floor;
    }
 
    cout << "Actual floor " << actual_floor << endl;
}