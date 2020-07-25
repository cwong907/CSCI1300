#include<iostream>
#include<fstream>
using namespace std;

void printIneligiblePlayers(string names[], double ages[], int length)
{
    for(int i = 0; i < length; i++)
    {
        if(ages[i] > 6 || ages[i] < 4)
        {
            cout << names[i] << " " << ages[i] << endl;
        }
    }
}

int main()
{
    string names[] = {"Joe", "Jack", "Amy", "Bob"};
    double ages[] = {3.4, 5.6, 6.0, 4.2};
    int length = 4;
    
    printIneligiblePlayers(names, ages, length);
}