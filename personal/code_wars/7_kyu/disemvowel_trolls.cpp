/*
https://www.codewars.com/kata/52fba66badcd10859f00097e/train/cpp

Trolls are attacking your comment section!

A common way to deal with this situation is to remove all of the 
vowels from the trolls' comments, neutralizing the threat.

Your task is to write a function that takes a string and return a new 
string with all vowels removed.

For example, the string "This website is for losers LOL!" would become 
"Ths wbst s fr lsrs LL!".

Note: for this kata y isn't considered a vowel.
*/

#include <iostream>
#include <string>
using namespace std;

string disemvowel(const string& str) 
{
    string newString = "";
    for(int i = 0; i < str.length(); i++)
    {
        if(tolower(str[i]) != 'a' &&
           tolower(str[i]) != 'e' &&
           tolower(str[i]) != 'i' &&
           tolower(str[i]) != 'o' &&
           tolower(str[i]) != 'u') 
           newString += str[i];
    }
    return newString;
}

int main()
{

    string test = "This website is for losers LOL!";

    cout << disemvowel(test);

    return 0;
}