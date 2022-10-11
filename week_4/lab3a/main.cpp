/*
    Name: Harrison Atherton, 5005662748, 1018, #3A
    Description: Ask for user input (floating point and string), use
    an if statement to determine largest of the two.
    Input: Input two floating numbers and two strings.
    Output: Output a prompt to the user, and then send the results
    to the terminal.
*/

#include <iostream>

using namespace std;

int main()
{
    // Initialize variables
    float float1 = 0;
    float float2 = 0;
    string string1 = "";
    string string2 = "";

    cout << "Enter a floating point number\n**";
    cin >> float1;
    cout << "\nEnter another floating point number\n**";
    cin >> float2; 

    // Output information
    cout << "\nYou entered " << float1 << " and " << float2 << endl;
    cout << "The largest is ";
    if(float1 > float2)
    {
        cout << float1;
    } else {
        cout << float2;
    }
    
    cout << "\n\nEnter a string\n**";
    cin >> string1;
    cout << "\nEnter a second string\n**";
    cin >> string2;

    // Output information
    cout << "\nYou entered \"" << string1 << "\" and \"" << string2 << "\"\n";
    cout << "The largest is \"";
    if(string1 > string2)
    {
        cout << string1;
    } else {
        cout << string2;
    }
    cout << "\"";

return 0;
}
