/*
    Name: Harrison Atherton, 5005662748, 1019, #6B
    Description: Ask user to input file. The program will open and read the file,
    use loops to create arrays, and use loops to determine calulations
    Input: File name
    Output: Display the names of the users forward, backwards, their scores forwards,
    backwards, the amount of results for the given name, their minimum, maximum,
    sum, and average scores.

    How do you find Will Smith in an avalanche?
    You look for fresh prints.

    Did you hear about the claustrophobic astronaut?
    He just needed a little space.

    I need to add lines, maybe my code is too long but I don't know what else to comment
    without the code looking cluttered so I'm putting this here
    :)
*/

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

// Declare global constant
const int ARRAY_SIZE = 100;

int main()
{
    // Declare variables
    ifstream fileReader;
    string fileName;

    string names[ARRAY_SIZE] = {};
    double scores[ARRAY_SIZE] = {};

    string toFind;
    int userNameCount = 0;
    int foundCount = 0;
    double sum = 0;

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

    // Prompt user to enter a name to find
    cout << "\nEnter a name to search\n**";
    cin >> toFind;

    // Increment count, store name and scores into arrays
    while(!fileReader.eof())
    {
        fileReader >> names[foundCount];
        fileReader >> scores[foundCount];
        if(names[foundCount] == toFind)
        {
            userNameCount++;
        }
        foundCount++;
    }
    fileReader.close();
    cout << endl;

    // Names forward
    cout << "Names Forward: ";
    for(int i = 0; i < foundCount-1; i++)
    {
        // Determine if it's the last value in array
        if(i != foundCount - 2)
        {
            cout << names[i] << ", ";
        }
        else
        {
            cout << names[i];
        }
    }
    cout << endl;

    // Scores forward
    cout << "Scores Forward: ";
    for(int i = 0; i < foundCount-1; i++)
    {
        // Determine if it's the last value in array
        if(i != foundCount - 2)
        {
            cout << scores[i] << ", ";
        }
        else
        {
            cout << scores[i];
        }
    }
    cout << endl;

    // Names reverse
    cout << "Names Reverse: ";
    for(int i = foundCount - 2; i >= 0; i--)
    {
        // Determine if it's the last value in array
        if(i != 0)
        {
            cout << names[i] << ", ";
        }
        else
        {
            cout << names[i];
        }
    }
    cout << endl;

    // Scores reverse
    cout << "Scores Reverse: ";
    for(int i = foundCount - 2; i >= 0; i--)
    {
        // Determine if it's the last value in array
        if(i != 0)
        {
            cout << scores[i] << ", ";
        }
        else
        {
            cout << scores[i];
        }
    }
    cout << endl;

    /* 
    Find sum of the array and min/max
    Hardcoding this to work. Don't understand how to set the lowest variable to
    each person. Tried getting TA help and couldn't figure it out.
    */
    double min = 10000;
    double max = -10000;
    for(int i = 0; i < foundCount; i++)
    {
        // Determine if their name matches with the user inputted name
        if(names[i] == toFind)
        {
            sum += scores[i];
            if(scores[i] < min)
            {
                min = scores[i];
            }
            if(scores[i] > max)
            {
                max = scores[i];
            }
        }
    }

    // Determine if user is found in the list or not
    cout << fixed << setprecision(2);
    if(userNameCount == 0)
    {
        cout << "Error: " << toFind << " is not a student in the list";
    }
    else
    {
        // Print results if user is found in list
        cout
        << userNameCount << " results for " << toFind << endl
        << "Minimum: " << min << endl
        << "Maximum: " << max << endl
        << "Sum:     " << sum << endl
        << "Average: " << sum/(userNameCount) << endl;
    }
}
