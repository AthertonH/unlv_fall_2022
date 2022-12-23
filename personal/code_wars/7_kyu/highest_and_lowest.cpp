/*
https://www.codewars.com/kata/554b4ac871d6813a03000035/train/cpp

In this little assignment you are given a string of space separated 
numbers, and have to return the highest and lowest number.

Examples
highAndLow("1 2 3 4 5");  // return "5 1"
highAndLow("1 2 -3 4 5"); // return "5 -3"
highAndLow("1 9 3 4 -5"); // return "9 -5"
Notes
All numbers are valid Int32, no need to validate them.
There will always be at least one number in the input string.
Output string must be two numbers separated by a single space, 
and highest number is first.
*/
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

string highAndLow(const string& numbers)
{
    stringstream iss(numbers);
    int number;
    vector<int> numbersV;

    while(iss >> number)
        numbersV.push_back(number);
    
    int min = *max_element(numbersV.begin(), numbersV.end());
    int max = *min_element(numbersV.begin(), numbersV.end());
    return to_string(min) + " " + to_string(max);
}

int main()