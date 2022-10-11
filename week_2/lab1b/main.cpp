/*
    Name: Harrison Atherton, 5005662748, 1018, 1B#
    Description: This simple program requests user input, asking for both integers 
    (longs) and doubles. The program will then take the user input, and output 
    integral expressions.
    Input: The user should be prompted to enter the input values of both integers 
    (longs) and doubles.
    Output: Output will include the users inputted integers (longs) and doubles. 
    The program will tell the user a number of equations, including +, -, /, *, 
    and % for both integers and doubles.
*/

#include <iostream>

using namespace std;

int main()
{
    long long1 = 0;
    long long2 = 0;
    double double1 = 0;
    double double2 = 0;

    cout << "Enter an integer" << endl << "**";
    cin >> long1;
    cout << endl << "Enter another integer" << endl << "**";
    cin >> long2;

    long sum = long1 + long2;
    long sub = long1 - long2;
    long mult = long1 * long2;
    long div = long1 / long2;
    long rem = long1 % long2;

    cout << endl << long1 << " + " << long2 << " = " << sum << endl;
    cout << long1 << " - " << long2 << " = " << sub << endl;
    cout << long1 << " * " << long2 << " = " << mult << endl;
    cout << long1 << " / " << long2 << " = " << div << endl;
    cout << long1 << " % " << long2 << " = " << rem << endl;

    cout << endl << "Enter a double" << endl << "**";
    cin >> double1;
    cout << endl << "Enter another double" << endl << "**";
    cin >> double2;

    double double_div = double1 / double2;

    cout << endl << double1 << " / " << double2 << " = " << double_div;

}