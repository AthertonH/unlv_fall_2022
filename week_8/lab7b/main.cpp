/*
    Name: Harrison Atherton, 5005662748, 1019, #7B
    Description: Program to look through a text file, organize it into an array,
    and use that array to determine the lowest temperature, highest temperature, average
    low temperature, and average high temperature
    Input: User will be prompted to enter in a file name. If the file cannot be found, 
    the user will be asked again.
    Output: The city and year will be displayed, with calculations of the lowest
    temperature, highest temperature, average low temperature, and average high 
    temperature.
*/

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

// Declare constants for array
int const MONTHS = 12;
int const TEMPS = 2;

int main()
{
    // Declare variables
    ifstream iFile;
    string fileName = "";

    string city = "";
    int year = 0;
    double arr[MONTHS][TEMPS] = {0,0};
    double lowestTempYear = 100;
    double highestTempYear = 0;
    double lowTempSum = 0;
    double highTempSum = 0;

    // Open the file
    do
    {
        cout << "Enter file name\n**";
        cin >> fileName;
        iFile.open(fileName);

        if(!iFile.is_open())
        {
            cout << "\nError: Invalid file name\n";
        }
    } while(!iFile.is_open());

    // Grab the city as a string, and the year as an integer
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
    for(int i = 0; i < MONTHS; i++)
    {
        for(int j = 0; j < TEMPS; j++)
        {
            // Determine if lowest temp is lowest overall
            if(arr[i][0] < lowestTempYear)
            {
                lowestTempYear = arr[i][j];
            }
            // Determine if highest temp is highest overall
            if(arr[i][1] > highestTempYear)
            {
                highestTempYear = arr[i][j];
            }
        }
        // Add lowest and highest temp to seperate sums
        lowTempSum += arr[i][0];
        highTempSum += arr[i][1];
    }

    // Output results to terminal
    cout << fixed << setprecision(2) << endl << city << " " << year << endl
         << "Lowest temperature of the year was " << lowestTempYear << "° F." << endl
         << "Highest temperature of the year was " << highestTempYear << "° F." << endl
         << "Average low temperature of the year was " << lowTempSum/MONTHS << "° F." << endl
         << "Average high temperature of the year was " << highTempSum/MONTHS << "° F." << endl;
    
    return 0;
}
