/*
    Name: Harrison Atherton, 5005662748, 1019, #6A
    Description: Ask user to input a text file. THey will then receive the amount
    of elements read, the numbers organized in various ways, and different calculations
    with said numbers
    Input: File name
    Output: Display the amount of elements read, the numbers forwards, the numbers
    backwards, the minimum, maximum, sum, and average. Also notify user if there
    is an invalid input in the file.

    How do billboards talk?
    Sign language.
*/

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

const int ARRAYSIZE = 100;

int main()
{
    ifstream fileReader;
    string fileName = "";

    // Declare variables
    double nums[ARRAYSIZE] = {0};
    int count = 0;
    double sum = 0.0;

    // Set precision to ensure 2 decimals are outputted
    cout << fixed << setprecision(2);

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

    cout << endl;

    // Will output any errors if the line is not an integer/double
    while(!fileReader.eof())
    {
        fileReader >> nums[count];
        if(!fileReader && fileReader.eof())
        {
            continue;
        }
        if(!fileReader)
        {
            fileReader.clear();
            fileReader.ignore(256, '\n');
            cout << "Error: Invalid input in file.\n";
            continue;
        }
        count++;
    }
    fileReader.close(); 

    cout << "\nAmount of Elements Read In: " << count;

    // Count elements forward
    cout << "\nForwards: ";
    for(int i = 0; i < count; i++)
    {
        if(i != count-1)
        {
            cout << nums[i] << ", ";
        }
        else
        {
            cout << nums[i];
        }
    }

    // Count elements backwards
    cout << "\nBackwards: ";
    for(int i = count-1; i >= 0; i--)
    {
        if(i != 0)
        {
            cout << nums[i] << ", ";
        }
        else
        {
            cout << nums[i];
        }
        
    }

    // Find sum of the array and min/max
    double min = nums[0];
    double max = nums[0];
    for(int i = 0; i < count; i++)
    {
        sum += nums[i];
        if(nums[i] < min)
        {
            min = nums[i];
        }
        if(nums[i] > max)
        {
            max = nums[i];
        }
    }
    // Determine average
    double average = sum / count;

    // Output results to terminal
    cout << "\nMinimum: " << min;
    cout << "\nMaximum: " << max;
    cout << "\nSum: " << sum;
    cout << "\nAverage: " << average;
}
