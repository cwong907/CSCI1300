#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

/*
1. Write a main function that houses 2 int type vectors
2. Write a vector<int> suffle function that takes those 2 functions
3. The shuffle function should make sure that the both vectors aren't empty
4. If the vectors are the same size then starting with the first vector, alternating between the first and second vectors take each value from them and place it in a third vector
5. If one of the vectors is bigger than the other, then start with the bigger one until the smaller one runs out and add the rest of the left over values
Input: vector<int> 
Output: vector<int>
Return: vector<int>
*/

vector<int> shuffle(vector<int> v1, vector<int> v2)
{
    vector<int> v3;
    int counter = 0;
    
    if(v1.size() == 0 && v2.size() == 0)
    {
        return v3;
    }
    
    else if(v1.size() == v2.size())
    {
        for(int i = 0; i < v1.size(); i++)
        {
            v3.push_back(v1[i]);
            v3.push_back(v2[i]);
        }
        return v3;
    }
    
    else if(v1.size() < v2.size())
    {
        for(int j = 0; j < v1.size(); j++)
        {
            v3.push_back(v2[j]);
            v3.push_back(v1[j]);
            counter++;
        }
        
        for(int k = counter; k < v2.size(); k++)
        {
            v3.push_back(v2[k]);
        }
    }
    
    else if(v2.size() < v1.size())
    {
        for(int j = 0; j < v1.size(); j++)
        {
            v3.push_back(v1[j]);
            
            if(j < v2.size())
            {
                v3.push_back(v2[j]);
            }
        }
    }
}

int main()
{
    vector<int> v3;
    
    //Test 1
    //Input: v1 = {1, 3, 5, 7, 9}; v2 = {2, 4, 6, 8}
    //Output:123456789
    vector<int> v1 = {1, 3, 5, 7, 9};
    vector<int> v2 = {2, 4, 6, 8};
    v3 = shuffle(v1, v2);
    for(int i = 0; i < v3.size(); i++)
    {
        cout << v3[i];
    }
    cout << endl;
    
    //Test 2
    //Input: v5 = {1, 3, 5}; v4 = {2, 4, 6, 8}
    //Output:2143658
    vector<int> v5 = {1, 3, 5};
    vector<int> v4 = {2, 4, 6, 8};
    v3 = shuffle(v5, v4);
    for(int i = 0; i < v3.size(); i++)
    {
        cout << v3[i];
    }
}