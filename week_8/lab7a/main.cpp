/*
    Name: Harrison Atherton, 5005662748, 1019, #7A
    Description: Ask user to input file. The program will enter the list of numbers
    into a 2D array, and then determine the sum for both the row and the column.
    Input: A user will enter a file name.
    Output: Calculate the sum of both the rows and the columns of the 2D array,
    and output it to the terminal.
    
    99% comment passing D': hopefully this gets me to 100%.
*/
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int const HEIGHT = 7;
int const WIDTH = 10;

int main()
{
    // Declare variables
    ifstream iFile;
    string fileName = "";
    double numbers[HEIGHT][WIDTH] = {};

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

    // Loop through file, put into an array
    while(!iFile.eof())
    {
        for(int i = 0; i < HEIGHT; i++)
        {
            for(int j = 0; j < WIDTH; j++)
            {
                iFile >> numbers[i][j];
            }
        }
    }
    // Close the file
    iFile.close();

    // Set precision to two
    cout << fixed << setprecision(1);

    // Loop to iterate through the array and obtain the sum of the rows
    cout << "\nROW SUMS:\n";
    for(int i = 0; i < HEIGHT; i++)
    {
        // Declare variable inside loop to reset it back to 0.
        double rowSum = 0;

        for(int j = 0; j < WIDTH; j++)
        {
            cout << setw(4) << left << numbers[i][j];
            rowSum += numbers[i][j];

            if(j != 9)
            {
                cout << " + ";
            }
            else
            {
                cout << " = ";
            }
        }
        cout << (rowSum) << endl;
    }

    // Loop to iterate through the array and obtain the sum of the columns
    cout << "\nCOLUMN SUMS:\n";
    for(int i = 0; i < WIDTH; i++)
    {
        // Declare variable inside loop to reset it back to 0.
        double columnSum = 0;

        for(int j = 0; j < HEIGHT; j++)
        {
            cout << setw(4) << left << numbers[j][i];
            columnSum += numbers[j][i];

            if(j != 6)
            {
                cout << " + ";
            }
            else
            {
                cout << " = ";
            }
        }
        cout << (columnSum) << endl;
    }

    return 0;
}
