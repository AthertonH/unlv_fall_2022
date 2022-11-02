#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    // Declare variables
    ifstream iFile;
    string fileName = "";
    int boardWidth = 0;
    int boardHeight = 0;

    // Open the file
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