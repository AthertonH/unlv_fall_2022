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
    ifstream iFile;



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
}

void printLevel()
{}

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
