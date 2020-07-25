#include<iostream>
using namespace std;

/*
Write a function, ReplaceHashTag, that takes a string as input and replaces all the hashtags (#) characters with @ character. 
The function returns a string representing input string containing # character replaced with @ character.
*/

string ReplaceHashTag(string input)
{
    string result;
    
    for(int i = 0; i < input.length(); i++)
    {
        if(input[i] == '#')
        {
            result += '@';
        }
        
        else
        {
            result += input[i];
        }
    }
    return result;
}

int main()
{
    cout << ReplaceHashTag("###B###") << endl;
}