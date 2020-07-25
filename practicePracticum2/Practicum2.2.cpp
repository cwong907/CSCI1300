#include<iostream>
#include<fstream>
using namespace std;

string removeDigits(string input)
{
    string result;
    for(int i = 0; i < input.length(); i++)
    {
        if((input[i] >= 'A' && input[i] <= 'Z' || input[i] == ' ') || (input[i] >= 'a' && input[i] <= 'z' || input[i] == ' '))
        {
            result += input[i];
        }
    }
    return result;
}

int main()
{
    cout << removeDigits("Hello World") << endl;
}