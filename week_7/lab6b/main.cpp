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

    string userName;
    int userNameCount = 0;
    int count = 0;
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

    cout << "\nEnter a name to search\n**";
    cin >> userName;

    // Increment count, store name and scores into arrays
    while(!fileReader.eof())
    {
        fileReader >> names[count];
        fileReader >> scores[count];
        if(names[count] == userName)
        {
            userNameCount++;
        }
        count++;
    }
    fileReader.close();
    cout << endl;

    // Names forward
    cout << "Names Forward: ";
    for(int i = 0; i < count-1; i++)
    {
        // Determine if it's the last value in array
        if(i != count - 2)
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
    for(int i = 0; i < count-1; i++)
    {
        // Determine if it's the last value in array
        if(i != count - 2)
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
    for(int i = count - 2; i >= 0; i--)
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
    for(int i = count - 2; i >= 0; i--)
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

    // Results for searched username
    cout << userNameCount << " results for " << userName << endl;

    // Find sum of the array and min/max
    double minimum = scores[0];
    double maximum = scores[0];
    for(int i = 0; i < count; i++)
    {
        // Determine if their name matches with the user inputted name
        if(names[i] == userName)
        {
            sum += scores[i];
            if(scores[i] < minimum)
            {
                minimum = scores[i];
            }
            if(scores[i] > maximum)
            {
                maximum = scores[i];
            }
        }
    }
    // Display results for Minimum, ensure that precision is set to 2
    cout << fixed << setprecision(2)
         << "Minimum: " << minimum << endl
         << "Maximum: " << maximum << endl
         << "Sum:     " << sum << endl
         << "Average: " << sum/(userNameCount) << endl;
}
