/*
https://www.codewars.com/kata/54ff3102c1bad923760001f3/train/cpp

Return the number (count) of vowels in the given string.

We will consider a, e, i, o, u as vowels for this Kata (but not y).

The input string will only consist of lower case letters and/or spaces.
*/
#include <iostream>
#include <string>
int getCount(const std::string& inputStr)
{
    int count = 0;
    for(int i = 0; i <= inputStr.length(); i++)
    {
        if(inputStr[i] == 'a' ||
           inputStr[i] == 'e' ||
           inputStr[i] == 'i' ||
           inputStr[i] == 'o' ||
           inputStr[i] == 'u')
            count++;
    }
    return count;
}

int main()
{
    std::cout << getCount("hello my name is harrison");
}