#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Declare function prototypes
vector<vector<char>> readData(string fileName);
vector<vector<char>> replace(vector<vector<char>> board);
void print2dVector(vector<vector<char>> board);
string chooseLevel();
void playGame();
void playGame(vector<vector<char> > boardUnderscores, 
vector<vector<char> > boardAnswers);

int main()
{
    // Initialize 2 boards
    vector<vector<char> > boardUnderscores;
    vector<vector<char> > boardAnswers;

    boardAnswers = readData(chooseLevel());
    boardUnderscores = replace(boardAnswers);
    playGame(boardAnswers, boardUnderscores);
    
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

// Replaces characters with underscores
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

// Prints the 2D Vector to the terminal
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

// Choose what level is to be played
string chooseLevel()
{
    string level = "";
    ifstream fileReader;
    ofstream fileWriter;
    // Ensures that the user enters in the correct level
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
    // Return the string
    return level;
}

// Initialize the game
void playGame(vector<vector<char> > boardAnswers,
vector<vector<char> > boardUnderscores)
{

    int remainingGuesses = 5;
    vector<char> guesses;
    bool foundLetter;
    // Do while loop to ensure the game is played until answers found
    // or guesses are gone
    do
    {
        foundLetter = false;
        char guess = ' ';
        print2dVector(boardUnderscores);
        // Prompt user to enter a letter
        cout << "Enter a letter:\n";
        cin >> guess;
        guesses.push_back(toupper(guess));
        // Print guesses to terminal (testing)
        cout << "Guesses\n";
        for(int i = 0; i < guesses.size(); i++)
        {
            cout << guesses[i] << " ";
        }
        // Print updated board to terminal
        for (int i = 0; i < boardAnswers.size(); i++)
        {
            for (int j = 0; j < boardAnswers[i].size(); j++)
            {
                if (toupper(guess) == boardAnswers[i][j])
                {
                    boardUnderscores[i][j] = toupper(guess);
                    // Flag to confirm a letter has been found
                    foundLetter = true; 
                }
            }
        }
        // If a letter is not found, the remaining guesses is reduced
        if(!foundLetter) remainingGuesses -= 1;
        cout << endl << "Remaining incorrect guesses: " << remainingGuesses << endl;
    } while ((boardUnderscores != boardAnswers) && (remainingGuesses != 0));
}