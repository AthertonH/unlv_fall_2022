/*
    Name: Harrison Atherton, 5005662748, 1019, #9A
    Description: Using functions and references to manipulate two user inputted doubles
    Input: User will be prompted to enter two doubles
    Output: Calculations using two seperate functions will determine the sum, difference,
    division, and mulitplication of given inputs.
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
void addSubtract(double, double);
void multiplyDivide(double, double);

int main()
{
    // Declare variables & references
    double input1 = 0;
    double input2 = 0;
    // Call functions
    getDoubleInputs(input1,input2);
    cout << fixed << setprecision(2);
    addSubtract(input1, input2);
    multiplyDivide(input1, input2);
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
        cout << endl;
		
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
		cout << "Error: Invalid input!\n";
        return false;
    }
    return true;
}

void getDoubleInputs(double &input1, double &input2)
{
    string prompt1 = "Enter double between 0.500000 and 20.500000\n**";
    string prompt2 = "Enter another double between 0.500000 and 20.500000\n**";
    // Call getDoubleInput function to determine the reference
    input1 = getDoubleInput(prompt1, MIN, MAX);
    input2 = getDoubleInput(prompt2, MIN, MAX);
}

void addSubtract(double num1, double num2)
{
    // Declare variables
    double a = num1;
    double b = num2;
    num1 = a + b;
    num2 = a - b;
    // Output to terminal
    cout << a << " + " << b << " = " << num1 << endl
         << a << " - " << b << " = " << num2 << endl;
}

void multiplyDivide(double num1, double num2)
{
    // Declare variables
    double a = num1;
    double b = num2;
    num1 = a * b;
    num2 = a / b;
    // Output to terminal
    cout << a << " * " << b << " = " << num1 << endl
         << a << " / " << b << " = " << num2;
}