#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main()
{
    vector<vector<string>> vec;
    string row = " ";
    int hashLocation = 0;
    string currentWord = "";
    ifstream iFile;
    iFile.open("level1.txt");

    while(getline(iFile, row))
    {
        vec.push_back(vector<string>());

        while(row.find("#") != string::npos)
        {
            hashLocation = row.find("#");
            currentWord = row.substr(0, hashLocation);
            vec[vec.size()-1].push_back(currentWord);
            row = row.substr(hashLocation+1, row.length());
        }
        vec[vec.size()-1].push_back(row);
    }

    for(int i = 0; i < vec.size(); i++)
    {
        for(int j = 0; j < vec[i].size(); j++)
        {
            cout << vec[i][j]
                 << ((j != vec[i].size() - 1) ? "#" : "\n");
        }
    }
}