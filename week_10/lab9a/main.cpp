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
const double MIN = 0.5;
const double MAX = 20.5;
double getDoubleInput(string, double, double);
bool checkFailure(double, double, double);
void getDoubleInputs(double &, double &);
void addSubtract(double&, double&);
void multiplyDivide(double&, double&);

int main()
{

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

void getDoubleInputs(double &input1, double &input2)
{
    string prompt1 = "Enter double between 0.500000 and 20.500000";
    string prompt2 = "Enter another double between 0.500000 and 20.500000";

    getDoubleInput(prompt1, MIN, MAX);
    cin >> input1;
    getDoubleInput(prompt2, MIN, MAX);
    cin >> input2;
}

void addSubtract(double& num1, double& num2)
{

}