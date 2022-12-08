#include <iostream>
#include <vector>
using namespace std;

// You are given an odd-length array of integers, in which all of them are the same, 
// except for one single number.

// Complete the method which accepts such an array, and returns that single 
// different number.

// The input array will always be valid! (odd-length >= 3)

int stray(vector<int> numbers) 
{
    for(unsigned int i = 0; i < numbers.size(); i++)
    {
        if(i == i+1)
            continue;
        else
            return i;
    }
}

int main()
{
    vector<int> = {1, 1, 1,}


    return 0;
}