#include <iostream>
#include <math.h>
#include <iomanip>
#include <cmath>
#include <assert.h>
#include <vector>
#include <fstream>
using namespace std;

void printTriangle(int sideLength)
{
    if(sideLength >= 1)                             //always needs stopping condition
    {
        printTriangle(sideLength - 1);
    
        for(int i = 0; i < sideLength; i++)
        {
            cout << "[]";
        }
        cout << endl;
    }
}

int main()
{
    printTriangle(4);
}

/*int handshake(int n)
{
    if(n == 0)
    {
        return 0;
    }
    
    if(n == 1)
    {
        return 0;
    }
    
    if(n == 2)
    {
        return 1;
    }
    
    return (n - 1) + handshake(n - 1);
}

int main()
{
    cout << handshake(4) << endl;
}*/

/*class Question
{
    public:
    void set_text(string text){this->text=text;}
    void set_answer(string text){this->answer=text;}
    bool check_answer(){return answer==response;}
    void get_response(){cin >> response;}
    void display(){cout << text << endl;}
    
    Question(string text, string answer){this->text=text; this->answer=answer;}
    
    protected:
    string text;
    string answer;
    string response;
};

class choiceQuestion : public Question
{
    public:
    choiceQuestion(string text, string answer, vector<string> choices) : Question(text, answer)
    {
        this->choices=choices;
    }
    
    void display()
    {
        Question::display();
        for(int i =0; i < choices.size(); i++)
        {
            cout << i + 1 << ") " << choices[i] << endl;
        }
    }
    
    private:
    vector<string> choices;
};

int main()
{
    vector<Question> questions;
    
    questions.push_back(choiceQuestion("What's your favorite class?", "CSCI1300", ))
    //Question q1("What's your favorite class?", "CSCI1300");
    
    q1.display();
    q1.get_response();
    cout << q1.check_answer() << endl;
}*/