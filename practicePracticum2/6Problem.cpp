#include<iostream>
using namespace std;

/*
Write a function, RemoveHashTag, that takes a string as input and removes all the hashtags (#) characters. The function returns a string value without the hashtag characters.
*/

string RemoveHashTag(string input)
{
    string result;
    for(int i = 0; i < input.length(); i++)
    {
        if(input[i] != '#')
        {
            result += input[i];
        }
    }
    return result;
}

int main()
{
    cout << RemoveHashTag("###A###") << endl;
}