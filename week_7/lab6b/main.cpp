#include <iostream>
#include <fstream>

using namespace std;

const int ARRAY_SIZE = 100;

int main()
{
    ifstream fileReader;
    string fileName;

    string names[ARRAY_SIZE] = {};
    int scores[ARRAY_SIZE] = {};

    string userName;

    // Do...while loop to ensure user enters a file name
    do
    {
        cout << "Enter a file name\n**";
        cin >> fileName;
        fileReader.open(fileName);

        if(!fileReader.is_open())
        {
            cout << "\nError: Invalid file name.\n";
        }
    } while(!fileReader.is_open());


    cout << "\nEnter a name to search\n**";
    cin >> userName;

    while(!fileReader.eof())
    {
        for(int i = 0; i < 100; i++)
        {
            fileReader >> names[i];
            fileReader >> scores[i];
        }
    }
    fileReader.close();

    cout << names;


}