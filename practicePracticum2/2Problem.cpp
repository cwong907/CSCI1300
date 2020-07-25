#include<iostream>
using namespace std;

/*
Write a function, IsAllLower, that takes a string as input and returns true if all the alphabetic characters in the string are lowercase alphabetic characters. 
The function returns false otherwise. 
If input string contains non-alphabetic character, return false.
*/

bool IsAllLower(string word)
{
    for(int i = 0; i < word.size(); i++)
    {
        if(word[i] < 'a' || word[i] > 'z')              ///uses ASCII table
        {
            return false;
        }
        //i++;
    }
    return true;
}

int main()
{
    cout << IsAllLower("onetwo") << endl;
    
    cout << IsAllLower("onEtwo") << endl;
    
    cout << IsAllLower("^#$%123") << endl;
    
    cout << IsAllLower("") << endl;
}