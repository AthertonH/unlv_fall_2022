#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <cstdlib>
using namespace std;

void openLevel();
bool playAgain();

int main()
{
    vector<vector<string>> vec;
    string row = " ";
    int hashLocation = 0;
    string currentWord = "";

    do
    {
        openLevel();
        playAgain();
    } while (playAgain());


}

void openLevel()
{
    ifstream iFile;
    string fileName = "";
    
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

    int hashLocation = 0;
    string currentWord = "";
    string row = "";
    vector<vector<string>> vec;

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


void closeLevel()
{
    
}

bool playAgain()
{
    char answer = ' ';

    do
    {
        cout << "Would you like to play again? Y/N";
        cin >> answer;
        if(answer == 'Y' || answer == 'y')
            return true;
        else if(answer == 'N' || answer == 'n')
            return false;
        else
            cout << "Invalid entry, try again";
    } while (!cin.fail());
}
