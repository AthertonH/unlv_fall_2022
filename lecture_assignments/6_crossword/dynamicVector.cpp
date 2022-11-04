#include <vector>
#include <iostream>
#include <fstream>
using namespace std;




int main()
{
    vector<vector<char>> vector2d;
    ifstream fileReader;
    int width = 19;
    int height = 5;

    fileReader.open("level1.txt");

    for(int i = 1; i <= height; i++)
    {
        vector<char> newRow;

        for(int j = 1; j <= width; j++)
        {
            newRow.push_back(j);
        }
        vector2d.push_back(newRow);
    }


}
