/*
    Name: Harrison Atherton, 5005662748, 1018, 2A#
    Description: Receive user input to calculate it into radians, sin, cos, tan.
    The user will then receive the output calculation.
    Input: User inputs in degrees
    Output: Output the calculations to the interface.

    There are three types of people in the world.
    Those who can count and those who can't.
*/

#include <iostream>
#include <cmath>

using namespace std;

const double PI = 3.141592;

int main()
{
    double degrees = 0;
    
    // Prompt for user input
    cout << "Enter an angle value, in degrees" << endl << "**";
    cin >> degrees;
    cout << endl;

    // Convert degrees into radians 
    double radians = (degrees*PI)/180;

    // Output calculations
    cout << degrees << " degrees = " << radians << " radians" << endl;
    cout << "sin(" << degrees << ") = " << sin(radians) << endl;
    cout << "cos(" << degrees << ") = " << cos(radians) << endl;
    cout << "tan(" << degrees << ") = " << tan(radians) << endl;

    return 0;
}
