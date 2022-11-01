#include <iostream>

using namespace std;

int getIntegerInput(string prompt, int min, int max)
{
    cout << prompt;
}


int main() {
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
	writeUpsideDownTriangle(size, character);
	writeRightsideUpTriangle(size, character);
	cout << endl;
	
	// Terminate the program
	return 0;
}

// Function definitions
// YOUR CODE HERE

