#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	vector<vector<int>> vector2d;
    ifstream fileReader;
    ofstream fileWriter;
    string fileName;

	int height = 0;
    string row = "";
    int width = row.length();
	
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

    // Read each line that is seperated by a comma, convert the weight and speed into
    // an integer
    while(!fileReader.eof())
    {
        getline(fileReader, row, '\n');
        height++;
    }

    cout << height << endl << row.length();
	
	for(int i = 1; i <= height; i++)
	{
		//Create a new row to add to our 2D vector
		vector<int> newRow;
		
		//Add elements to the row
		for(int j = 1; j <= width; j++)
		{
			newRow.push_back(i*j);
		}
		
		//Add the row to the vector
		vector2d.push_back(newRow);
	}
	
	for(unsigned int i = 0; i < vector2d.size(); i++)
	{
		for(unsigned int j = 0; j < vector2d[i].size(); j++)
		{
			cout << setw(4) << vector2d.at(i).at(j) << " ";
		}
		cout << endl;
	}
	
	return 0;
}