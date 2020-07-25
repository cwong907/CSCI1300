#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
using namespace std;

/*
Write a function maxTemp which takes a filename as string argument and returns the maximum temperature as float type for the week. 
Input file will contain temperature readings for each day of the week. Your function should read each line from 
the given filename, parse and process the data, and return the required information. Your function should return the highest temperature for the whole week.  
Empty lines do not count as entries, and should be ignored. If the input file cannot be opened, return -1. Remember temperature readings can be decimal and negative numbers.
*/

double maxTemp(string filename)
{
    string line = "";
    double max = 0;
    ifstream file(filename);
    
    if(file.is_open())
    {
        while(getline(file, line))
        {
            if(line != "")
            {
                string items[2];
                split(line, ',', items, 2);
                
                if(stod(items[1]) > max)
                {
                    max = (stod(items[1]));        
                }
            }
        }
        return max;
    }
    
    else
    {
        return -1;
    }
}

int main()

{
    cout<<setprecision(2)<<fixed;

    cout << maxTemp("temperatures.txt") << endl;
}