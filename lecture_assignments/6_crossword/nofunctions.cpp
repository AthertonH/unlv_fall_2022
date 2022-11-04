#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <cstdlib>
using namespace std;

int main()
{
    ifstream iFile;
    string fileName = "";
    vector<vector<string>> vec;
    string row = " ";
    int hashLocation = 0;
    string currentWord = "";
    int remainingGuesses = 0;

    do
    {
        cout << "Enter level to play:\n";
        cin >> fileName;
        iFile.open(fileName);

        if(!iFile.is_open())
        {
            cout << "Invalid Entry!\n";
        }
    } while(!iFile.is_open());

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
            if(vec[i][j] > 'a' && vec[i][j] < 'z')
            {
                
            }


            // cout << vec[i][j]
            //      << ((j != vec[i].size() - 1) ? "#" : "\n");
        }
    }
}