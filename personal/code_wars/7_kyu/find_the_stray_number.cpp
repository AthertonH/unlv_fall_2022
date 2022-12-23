// You are given an odd-length array of integers, in which all of them are the same, 
// except for one single number.

// Complete the method which accepts such an array, and returns that single 
// different number.

// The input array will always be valid! (odd-length >= 3)
#include <iostream>
#include <vector>
using namespace std;

/*
My solution didn't work
int stray(vector<int> numbers) 
{
    int strayNumber = numbers[0];
    for(unsigned int i = 0; i < numbers.size(); i++)
    {
        if(strayNumber != numbers[i])
            return strayNumber = numbers[i];
    }
    return 1;
}
*/

// This is the solution I found on codewars
int stray(vector<int> numbers) 
{
    int res = 0;
    for(int n: numbers) res ^= n;
    return res;
}

int main()
{
    vector<int> test = {1, 1, 1, 4, 1, 1, 1};

    cout << stray(test);

    return 0;
}