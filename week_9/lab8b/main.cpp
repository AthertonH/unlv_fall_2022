/*
    Name: Harrison Atherton, 5005662748, 1019, #8B
    Description: Using functions to set flags, determine the circumference and
    area of the given radius
    Input: User will be prompted to enter in a double as a radius
    Output: Calculations for the circumference and area of the given radius will be
    given.
*/
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// Declare constant variables and function prototypes
const double PI = 3.14159;
const double MIN = 0.500000;
const double MAX = 20.500000;
double getDoubleInput(string prompt, double min, double max);
bool checkFailure(double input, double min, double max);
double circumference(double radius);
double area(double radius);

int main()
{
	string prompt1 = "Enter a circle radius between " +
		to_string(MIN) + " and " +
		to_string(MAX) + "\n**";
    
    double radius = getDoubleInput(prompt1, MIN, MAX);

    // Print calculations to terminal
    cout << fixed << setprecision(2) << endl
         << "Radius: " << static_cast<double>(radius) << endl
         << "Circumference: " << circumference(radius) << endl 
         << "Area: " << area(radius);
}

// Get users input for a double
double getDoubleInput(string prompt, double min, double max)
{
    double choice = 0;

    // Do while loop to ensure that the user enters in a number within range
	do
	{
		cout << prompt;
		cin >> choice;
		
	} while (!checkFailure(choice, MIN, MAX));
	return choice;
}

// Flag to determine if user has entered in the correct range of number
bool checkFailure(double input, double min, double max)
{
    if((input > max) || (input < min))
    {
        cin.clear();
		cin.ignore(200, '\n');
		cout << "\nError: Invalid radius!\n";
        return false;
    }
    return true;
}

// Calculation to determine the circumference of the given radius
double circumference(double radius)
{
    return 2*PI*radius;
}

// Calculation to determine the area of the given radius
double area(double radius)
{
    return PI*pow(radius,2);
}
