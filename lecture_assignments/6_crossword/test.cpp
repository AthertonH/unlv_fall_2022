#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<vector<char>> readData(string fileName);
vector<vector<char>> replace(vector<vector<char>> board);
void print2dVector(vector<vector<char>> board);

int main()
{
    vector<vector<char> > boardUnderscores;
    vector<vector<char> > boardAnswers;
    ifstream fileReader;
    ofstream fileWriter;
    string level = "";
    int remainingGuesses = 5;
    vector<char> guesses;
    bool foundLetter;

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

    boardAnswers = readData(level);
    boardUnderscores = replace(boardAnswers);

    // print data from files
    do
    {
        foundLetter = false;
        char guess = ' ';
        print2dVector(boardUnderscores);
        
        cout << "Enter a letter:\n";
        do
        {
            cin >> guess;
            guesses.push_back(guess);
        } while (!cin.fail());
        
        
        cout << "Guesses\n";
        for(int i = 0; i < guesses.size(); i++)
        {
            cout << guesses[i] << " ";
        }
        

        for (int i = 0; i < boardAnswers.size(); i++) // loop rows
        {
            for (int j = 0; j < boardAnswers[i].size(); j++)
            {
                if (toupper(guess) == boardAnswers[i][j])
                {
                    boardUnderscores[i][j] = toupper(guess);
                    foundLetter = true;
                }
            }
        }
        if(!foundLetter) remainingGuesses -= 1;
        cout << endl << "Remaining incorrect guesses: " << remainingGuesses << endl;
    } while ((boardUnderscores != boardAnswers) || (remainingGuesses != 0));
    
    

    return 0;
}

// Read data in the file
vector<vector<char> > readData(string fileName)
{
    vector<vector<char> > board;

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

vector<vector<char> > replace(vector<vector<char> > board)
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

void print2dVector(vector<vector<char> > board)
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