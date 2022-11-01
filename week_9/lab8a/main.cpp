/*
    Name: Harrison Atherton, 5005662748, 1019, #8A
    Description: Using functions to print out an upside down and right side up
	triangle
    Input: User will enter an integer between the values of 2 and 20, as well as
	a character to output
    Output: The character will be outputted in an upside down triangle and right
	side up triangle according to the size that the user has inputted
*/

#include <iostream>
using namespace std;

// Function prototypes
int getIntegerInput(string prompt, int min, int max);
char getCharacterInput(string prompt);
void writeUpsideDownTriangle(int size, char character);
void writeRightsideUpTriangle(int size, char character);

int main()
{
	// Minimums/maximums
	const int MIN = 2;
	const int MAX = 20;
	// Prompt for integer input
	string prompt1 = "Enter a count between " +
		to_string(MIN) + " and " +
		to_string(MAX) + "\n**";
	// Prompt for character input
	string prompt2 = "\nEnter a character\n**";
	
	// Get size of triangle
	int size = getIntegerInput(prompt1, MIN, MAX);
	// Get character to use when printing triangle
	char character = getCharacterInput(prompt2);
	
	// Write both triangles
	cout << endl << endl;
	writeUpsideDownTriangle(size, character);
	writeRightsideUpTriangle(size, character);
	cout << endl;
	
	// Terminate the program
	return 0;
}

// Function definitions
// Receive an integer amount for triangle
int getIntegerInput(string prompt, int min, int max)
{
	int choice = 0;

	do
	{
		cout << prompt;
		cin >> choice;
		if((choice > max) || (choice < min))
		{
			cin.clear();
			cin.ignore(200, '\n');
			cout << "\nError: Invalid entry, please retry\n";
		}
	} while ((choice > max) || (choice < min));

	return choice;
}

// Receive character input for triangle
char getCharacterInput(string prompt)
{
	char choice;
	cout << prompt;
	cin >> choice;
	return choice;
}

// Write the triangle Upside Down
void writeUpsideDownTriangle(int size, char character)
{
    // Keeps track of what row is currently printing
    for (int i = size; i > 0; i--)
    {
        // Keeps track of what column is currently printing
        for (int j = 0; j < i; j++)
        {
            cout << character;
        }
        if(i != 1)
        {
            cout << endl;
        }
    }
}

// Write the triangle Rightside Up
void writeRightsideUpTriangle(int size, char character)
{
    // Keeps track of what row is currently printing
    for (int i = 0; i <= size; i++)
    {
        // Keeps track of what column is currently printing
        for (int j = 0; j < i; j++)
        {
            cout << character;
        }
		cout << endl;
    }
}
