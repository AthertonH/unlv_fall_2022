/*
https://www.codewars.com/kata/54ba84be607a92aa900000f1

An isogram is a word that has no repeating letters, consecutive or 
non-consecutive. Implement a function that determines whether a string 
that contains only letters is an isogram. Assume the empty string is an isogram. 
Ignore letter case.

Example: (Input --> Output)

"Dermatoglyphics" --> true "aba" --> false "moOse" --> false (ignore letter case)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool is_isogram(string str) 
{
    vector<char> checkIsogram = {};
    for(int i = 0; i <= str.length(); i++)
    {
        if(count(checkIsogram.begin(), checkIsogram.end(), (tolower(str[i]))))
            return false;
        checkIsogram.push_back(tolower(str[i]));
    }
    return true;
}

int main()
{
    string test = "mose";

    cout << is_isogram(test);

    return 0;
}