/*
    Name: Harrison Atherton, 5005662748, 1019, #7B
    Description:
    Input:
    Output:
*/

#include <iostream>
#include <fstream>
using namespace std;

int const MONTHS = 12;
int const TEMPS = 2;

int main()
{
    // Declare variables
    ifstream iFile;
    string fileName = "";

    string city = "";
    int year = 0;
    double arr[MONTHS][TEMPS];

    // Open the file
    do
    {
        cout << "Enter a file name\n**";
        cin >> fileName;
        iFile.open(fileName);

        if(!iFile.is_open())
        {
            cout << "\nError: Invalid file name\n";
        }
    } while(!iFile.is_open());

    getline(iFile, city, ' ');
    iFile >> year;

    // Loop through file, put into an array
    while(!iFile.eof())
    {
        for(int i = 0; i < MONTHS; i++)
        {
            for(int j = 0; j < TEMPS; j++)
            {
                iFile >> arr[i][j];
            }
        }
    }
    // Close the file
    iFile.close();


    // Sort the array
    
    

    cout << city << endl << year;
    

}
