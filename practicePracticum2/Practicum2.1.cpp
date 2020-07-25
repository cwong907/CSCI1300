#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
using namespace std;

int CountLower(string word)
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
            if(word[i] <= 'z' && word[i] >= 'a')
            {
                count++;
            }
            //cout << count << endl;
        }
        
        if(count == 0)
        {
            return -2;
        }
        
        else
        {
            return count;
        }
    }
}

int main()
{
    cout << CountLower("a zebra") << endl;
}