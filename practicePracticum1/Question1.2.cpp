#include <iostream>
#include <math.h>
#include <iomanip>
#include <string>
using namespace std;

void aminoAcid (char letter)
{
    switch(letter)
    {
        case 'A':
            cout << "Amino Acid " << letter << ": Adenine" << endl;
            break;
            
        case 'C':
            cout << "Amino Acid " << letter << ": Cytosine" << endl;
            break;
            
        case 'T':
            cout << "Amino Acid " << letter << ": Thymine" << endl;
            break;
        
        case 'G':
            cout << "Amino Acid " << letter << ": Guanine" << endl;
            break;
            
        default:
            cout << "Amino Acid " << letter << ": Invalid" << endl;
    }
}

int main()
{
    char letter = 'A';
    aminoAcid('A');
}