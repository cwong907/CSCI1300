#include <iostream>
using namespace std;

string removeDoubleChars(string input)
{
    string result = "";
    int charcount[26];
    for(int i = 0; i < 26; i++)
    {
        charcount[i] = 0;
    }
    for(int i = 0; i < input.length(); i++)
    {
        if(input[i] >= 65)
        {
            charcount[(int) input[i]-65]++;
            if(charcount[(int) input[i] - 65] <= 1) 
            {
                result += input[i];
            }
        }    
    }
    // for(int i= 0; i < 26; i++)
    // {
    //     cout << charcount[i];
    // }
    
    return result;
}

bool isCharInString(string text, char c)
{
    for(int i = 0; i < text.length(); i++)
    {
        if(text[i] == c)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

string codeGenerator(string code)
{
    string result = code;
    for(char c = 'Z'; c >= 'A'; c--)
    {
        if(isCharInString(code, c))
        {
            result =+ c;
        }
    }
}

int main()
{
    cout << removeDoubleChars("HELLO WORLD!") << endl;
}