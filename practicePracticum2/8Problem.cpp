#include<iostream>
using namespace std;

/*
Write a function similarity that takes in 2 arrays of int type and their sizes and returns true if the two arrays are identical and returns false if two arrays are not same.
*/

bool similarity(int arr1[], int size1, int arr2[], int size2)
{
    if(size1!=size2)
    {
        return false;
    }
    
    else
    {
        for(int i = 0; i < size1; i++)
        {
            if(arr1[i] != arr2[i])
            {
                return false;
            }
        }
        return true;
    }
}

int main()
{
    
}