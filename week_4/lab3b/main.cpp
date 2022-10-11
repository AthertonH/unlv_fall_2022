/*
    Name: Harrison Atherton, 5005662748, 1018, #3B
    Description: Ask user for a letter grade, switch statement
    will look through the possible cases and output the grade range.
    Input: A letter grade "A, B, C, D, E, F"
    Output: Notify user of grade range, if they did not enter in a
    correct data type, default will be sent to the terminal.
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    char letterGrade = '\0';

    cout << "Enter a letter grade\n**";
    cin >> letterGrade;
    cout << "\n";
    
    // Switch statement to output grade range
    switch(towlower(letterGrade))
    {
        case 'a':
            cout << "Grade range is 90 - 100";
            break;
        case 'b':
            cout << "Grade range is 80 - 89.99";
            break;
        case 'c':
            cout << "Grade range is 70 - 79.99";
            break;
        case 'd':
            cout << "Grade range is 60 - 69.99";
            break;
        case 'f':
            cout << "Grade range is 0 - 59.99";
            break;
        default:
            cout << "Error: \'" << letterGrade 
            << "\' is not a valid letter grade";
    }

return 0;
}
