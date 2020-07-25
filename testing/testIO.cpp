#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream myfile;
    myfile.open ("testing.txt");
    
    if(myfile.is_open())
    {
        string line = "";
        int lineidx = 0;
        
        while (getline(myfile, line))
        {
            cout << lineidx << ": " << line << endl;
            lineidx++;
        }
    }
    else
    {
        cout << "Failed" << endl;
    }
    
    myfile.close();
}