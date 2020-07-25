#include<iostream>
using namespace std;

/*
Write a function, CountVowels, that takes a string as input and count the number 
of vowels (a,e,i,o,u either upper or lower case) alphabetic characters. 
The function returns an integer value for the number of vowels.
*/

int CountVowels(string word)
{
    if(word == "")
    {
        return -1;
    }
    
    else
    {
        int count = 0;
        for(int i = 0; i < word.length(); i++)
        {
            char c = tolower(word[i]);
            if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
            {
                count++;
            }
        }
        return count;
    }
}

int main()
{
    cout << CountVowels("One1, Two2") << endl;
}