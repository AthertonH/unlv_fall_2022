/*
https://www.codewars.com/kata/57cebe1dc6fdc20c57000ac9/train/cpp

Simple, given a string of words, return the length of the shortest word(s).

String will never be empty and you do not need to account for different 
data types.
*/
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int find_short(string str)
{
    vector<string> strSeperated = {};
    int shortestStr = -1;

    stringstream s_stream(str);
    while(s_stream.good())
    {
        string substr;
        getline(s_stream, substr, ' ');
        strSeperated.push_back(substr);
    }
    for(unsigned int i = 0; i < strSeperated.size(); i++)
    {
        if(strSeperated[i].length() < shortestStr)
            shortestStr = strSeperated[i].length();
    }
    return shortestStr;
}

int main()
{

    cout << find_short("Hello this is my test sentence");

}