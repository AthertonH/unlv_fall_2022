/*
    Name: Harrison Atherton, 5005662748, 1018, #4A
    Description: Prompt user with 3 variables, increment variables
    by given amount, with starting to ending number
    Input: Input 3 integers
    Output: Output the starting to ending number, incremented by
    the given amount from user
*/

#include <iostream>
#include <cmath>

using namespace std;

int main()
{

    // Initialize variables
    int startingNumber = 0;
    int endingNumber = 0;
    int incrementValue = 0;

    // Starting number
    cout << "Enter a starting number\n**";
    cin >> startingNumber;
    if(cin.fail()){
        cout << endl << "Error: invalid entry.";
        return 0;
    }

    // Ending number
    cout << "\nEnter an ending number\n**";
    cin >> endingNumber;
    if(cin.fail()){
        cout << endl << "Error: invalid entry.";
        return 0;
    } if(endingNumber < startingNumber){
        cout << "\nError: end must be greater than start.";
        return 0;
    }

    // Increment value
    cout << "\nEnter a value to increment by\n**";
    cin >> incrementValue;
    cout << endl;
    if(cin.fail()){
        cout << "Error: invalid entry.";
        return 0;
    }

    // For loop to return numbers to user by given increment
    for(int i = startingNumber; i <= endingNumber; i += incrementValue){
        cout << i << " ";
    }

    return 0;
}