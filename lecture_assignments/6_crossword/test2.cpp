#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

vector<string> readData(string fileName);
vector<string> replace(vector<string> board);
void print2dVector(vector<string> board);

int main()
{
    vector<string> boardUnderscores;
    vector<string> boardAnswers;
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

    boardUnderscores = readData(level);

    // print data from files
    do
    {
        char guess = ' ';
        cout << endl;
        print2dVector(boardUnderscores);
        cout << endl;
        boardAnswers = replace(boardUnderscores);
        print2dVector(boardAnswers);

        cout << "Enter a letter:\n";
        cin >> guess;

        for (int i = 0; i < boardAnswers.size(); i++) // loop rows
        {
            for (int j = 0; j < boardAnswers[i].size(); j++)
            {
                if (boardAnswers[i][j] == guess)
                {
                    boardUnderscores[i][j] = guess;
                }
            }
        }
    } while (boardUnderscores != boardAnswers);
    
    

    return 0;
}


// Read data in the file
vector<string> readData(string fileName)
{
    vector<char> board;

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

vector<string> replace(vector<string> board)
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

void print2dVector(vector<string> board)
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