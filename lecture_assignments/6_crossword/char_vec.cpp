#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <cctype>
using namespace std;

int main()
{
    ifstream iFile;
    string fileName = "";
    vector<vector<int>> vector2d;
    int width = 0;
    int height = 0;
    string row = " ";
    char currentLetter = ' ';

    do
    {
        cout << "Enter level to play:\n";
        cin >> fileName;
        iFile.open(fileName);

        if(!iFile.is_open())
        {
            cout << "Invalid Entry!\n";
        }
    } while(!iFile.is_open());

    while(getline(iFile, row))
    {
        width = row.length();
        height++;
    }
    cout << width << endl << height << endl;




    for(int i = 1; i <= height; i++)
	{
		//Create a new row to add to our 2D vector
		vector<int> newRow;
		
		//Add elements to the row
		for(int j = 1; j <= width; j++)
		{
			newRow.push_back(i);
		}
		
		//Add the row to the vector
		vector2d.push_back(newRow);
	}
	
	for(unsigned int i = 0; i < vector2d.size(); i++)
	{
		for(unsigned int j = 0; j < vector2d[i].size(); j++)
		{
			cout << vector2d.at(i).at(j) << " ";
		}
		cout << endl;
	}





}