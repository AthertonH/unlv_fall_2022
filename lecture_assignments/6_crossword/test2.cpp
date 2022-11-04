#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	vector<vector<char>> vector2d;
    char character = ' ';
    ifstream fileReader;
    ofstream fileWriter;
    string fileName;
	
    // Do while loop to ensure the user enters in a file name
    do
    {
        cout << "Open File: ";
        cin >> fileName;
        fileReader.open(fileName);

        if(!fileReader.is_open())
        {
            cout << "Could not open " << fileName << endl;
        }
    } while(!fileReader.is_open());

    while(!fileReader.eof())
    {
        vector2d.push_back(fileReader);
    }
    fileReader.close();


    
	

	
	return 0;
}