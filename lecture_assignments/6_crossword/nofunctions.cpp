#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <cctype>
using namespace std;

int main()
{
    ifstream iFile;
    string fileName = "";
    vector<vector<string>> answers;
    vector<vector<string>> questions;
    string row = " ";
    int hashLocation = 0;
    string currentWord = "";
    int remainingGuesses = 0;

    // Open the level
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

    // Create the vector containing the answers
    while(getline(iFile, row))
    {
        answers.push_back(vector<string>());

        while(row.find("#") != string::npos)
        {
            hashLocation = row.find("#");
            currentWord = row.substr(0, hashLocation);
            answers[answers.size()-1].push_back(currentWord);
            row = row.substr(hashLocation+1, row.length());
        }
        answers[answers.size()-1].push_back(row);
    }

    // Copy the vector containing the questions
    questions = answers;


    // Print the vector containing the questions
    for(int i = 0; i < answers.size(); i++)
    {
        for(int j = 0; j < answers[i].size(); j++)
        {
            if(answers[i][j] != "#" && answers[i][j] != " ")
            {
                cout << "_";
            }
            else
            {
                cout << ((j != answers[i].size() - 1) ? "#" : "\n");
            }
        }
    }

    cout << endl << endl;

    // Print out vector containing the answers
    for(int i = 0; i < answers.size(); i++)
    {
        for(int j = 0; j < answers[i].size(); j++)
        {
            cout << answers[i][j]
                 << ((j != answers[i].size() - 1) ? "#" : "\n");
        }
    }


}