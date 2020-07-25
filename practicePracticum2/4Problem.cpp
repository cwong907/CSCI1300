#include<iostream>
using namespace std;

/*
Create a function named PrintStudents, which takes a string input filename and an integer minimum score value and a string output file name as a parameters.  
The function will read the student scores and names from the file and output the names of the students with scores greater than or equal to the value given.  
This function returns the integer number of entries read from the file.  If the input file cannot be opened, return -1 and do not print anything to the file.
*/

int PrintStudents(string inFile, int minScore, string outFile)
{
    ifstream inf;
    ofstream ouf;
    int n = 0;
    string line = "";
    
    inf.open(inFile);
    
    if(inf.fail()) 
    {
        return -1;
    }
    
    else
    {
        ouf.open(outFile);
        
        while(getline(inf, line))
        {
            string elements[3];
            
            split(line, ',', elements, 3);
            
            if(stoi(elements[1]) >= minScore)
            {
                ouf << elements[0] << ", " << elements[2] << endl;
            }
            n++;
        }
        
        inf.close();
        ouf.close();
        return n;
    }
    
}

int main()
{
    
}