#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

vector<vector<char>> readData(string fileName);
vector<vector<char>> replace(vector<vector<char>> board);
void print2dVector(vector<vector<char>> board);

int main()
{
    vector<vector<char>> data1;
    vector<vector<char>> data2;
    ifstream fileReader;
    ofstream fileWriter;
    string level = "";

    // Do while loop to ensure the user enters in a file name
    do
    {
        cout << "Open File: ";
        cin >> level;
        fileReader.open(level);

        if(!fileReader.is_open())
        {
            cout << "Could not open " << level << endl;
        }

    } while(!fileReader.is_open());

    data1 = readData(level);

    // print data from files
    cout << "Before replace\n";
    print2dVector(data1);
    cout << '\n';

    cout << "------------------------------------------------------------\n";

    cout
        << "\nAfter replace using method 1 or replace1\n";
    data2 = replace(data1);
    print2dVector(data2);

    return 0;
}


// Read data in the file
vector<vector<char>> readData(string fileName)
{
    vector<vector<char>> board;

    ifstream file(fileName);
    if (file)
    {
        string line;
        while (getline(file, line))
        {
            vector<char> row;                       
            for (int i = 0; i < line.length(); i++) 
            {
                row.push_back(line[i]);
            }
            board.push_back(row);
        }
    }
    else
    {
        cout << "File not found\n";
    }
    file.close();
    return board;
}

vector<vector<char>> replace(vector<vector<char>> board)
{
    for (int i = 0; i < board.size(); i++) // loop rows
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            if (isalpha(board[i][j]))
            {
                board[i][j] = '_';
            }
        }
    }
    return board;
}

void print2dVector(vector<vector<char>> board)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

}

