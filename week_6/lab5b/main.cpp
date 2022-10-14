/*
    Name: Harrison Atherton, 5005662748, 1019, #5B
    Description: Ask user to input a file name, add totals from the files
	and report an error when one has occured.
    Input: File name
    Output: Display the sum of each line, report an error if sum cannot be
	obtained. Return the total sum at the end of the file.
*/

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream fileReader;
	string filename = "";
	int total = 0;
	int num1 = 0;
	int num2 = 0;
	int sum = 0;
	char buffer [80];

	// Prompt user to enter in a file name until a valid one is selected
	do
	{
		cout << "Enter file name\n**";
		getline(cin, filename);
		
		fileReader.open(filename);	
		
		if(fileReader.is_open() == false)
		{
			cout << "\nError: Invalid file name" << endl;
		}
	}
	while(fileReader.is_open() == false);

	cout << endl;

	// Loop through until the end of the file
	while(!fileReader.eof())
	{
		fileReader >> num1;
		fileReader >> num2;

		// If the fileReader does not recognize an integer, clear and continue
		if(fileReader.fail())
		{
			cout << "Error in line\n";
			fileReader.clear();
			fileReader.getline(buffer, 80);
		}
		// Print out sum, and add it to the total.
		else
		{
			sum = num1 + num2;
			total += sum;
			cout << num1 << " + " << num2 << " = " << sum << endl;
		}
	}
	fileReader.close();

	cout << "\nRunning total = " << total;

	return 0;
}