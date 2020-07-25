#include<iostream>
using namespace std;

/*
Write a function printTotalMedals that takes an array for Olympic sports and arrays for gold, silver, and bronze medals and prints the total number of medals by discipline.
*/

void printTotalMedals(string disciplines[], int gold[], int silver[], int bronze[], int size)
{
    if(size < 1)
    {
        cout << "Invalid size. Size must be at least 1." << endl;
    }
    
    else
    {
        for(int i = 0; i < size; i++)
        {
            cout << disciplines[i] << ": " << gold[i]+silver[i]+bronze[i] << endl; 
        }
    }
}

int main()
{
    
}