#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main()
{

    string fileName = "level.txt";
    vector<vector<char>> board; // 2d vector to store data

    ifstream file(fileName); // open file

    if (fileName)
    {
        string line;

        //! checkpoint: read and make sure you understand this part/how it works
        //! don't blindly just copy my code
        while (getline(file, line)) // get line from file
        {
            vector<char> row;                       // we will store each line/row in a vector
            for (int i = 0; i < line.length(); i++) // this will loop through each charatcer in the line
            {
                row.push_back(line[i]); // add each character to the row vector
            }
            board.push_back(row); // add the row vector to the board vector
        }
        //! end of checkpoint if you read it, you will know how to fix the errors in the code
    }
    else
    {
        cout << "File not found\n";
    }
    file.close();
}
    