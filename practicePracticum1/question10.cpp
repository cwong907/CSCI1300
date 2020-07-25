#include <iostream>
#include <math.h>
#include <iomanip>
#include <string>
using namespace std;

void stepSizePrint(int start, int end, int step) {
    if (step > 0) {
        if (end > start) {
            for (int i = start; i < end; i += step) {
                cout << i << endl;
            }
        } else {
            cout << "Wrong settings!" << endl;
        }
    } else if (step < 0) {
        if (end < start) {
            for (int i = start; i > end; i += step) {
                cout << i << endl;
            }
        } else {
            cout << "Wrong settings!" << endl;
        }
    } else {
        cout << "Step size cannot be zero." << endl;
    }
}

int main()
{
    int day = 5;
    
    DayOfWeek(day);
}