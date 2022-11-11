/*
    Name: Harrison Atherton, 5005662748, 1016, #6
    Description: Crossword puzzle with user interaction. The program will keep track of
    how many remaining guesses the user has, as well as what letters have already been
    used. If a user has correctly guessed a letter, the board will change accordingly.
    If the user completes the level within the remaining guesses, the player wins,
    the game will end, and the user will be prompted as to whether or not if they would
    like to play again. If the user does not complete the level within the remaining
    guesses, the player will lose, and they will be prompted as to whether or not if they
    would like to play again. 3 different levels are available
    Input: The user will enter in a level that they would like to play, adn then enter in
    what letter they would like to guess
    Output: The board will print to the terminal with underscores, once the user has
    guessed any correct letter, the board will be updated

    What did the fish say when he swam into the wall?
    Dam.

    A man took his date to a zoo. They were disappointed to find that it 
    only contained one animal: a dog.
    It was a shitzu.
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Declare function prototypes
vector<vector<char>> readData(string fileName);
vector<vector<char>> replace(vector<vector<char>> board);
void print2dBoard(vector<vector<char>> board);
string chooseLevel();
void playGame();
void playGame(vector<vector<char>> boardUnderscores,vector<vector<char> > boardAnswers);

int main()
{
    // Initialize 2 boards
    vector<vector<char>> boardUnderscores;
    vector<vector<char>> boardAnswers;
    char answer = ' ';
    // Pretty stuff to make it pretty
    cout << "\n     Welcome to\n\n"
         << "         W \n"
         << "     C R O S S\n"
         << "         R\n"
         << "         D\n\n";
    // Do while loop to begin the game
    do
    {
        boardAnswers = readData(chooseLevel());
        cout << endl;
        boardUnderscores = replace(boardAnswers);
        playGame(boardAnswers, boardUnderscores);
        
        cout << "Play again? (y/n)\n";
        cin >> answer;
        if(toupper(answer) == 'Y')
            continue;
        if(toupper(answer) == 'N')
        {
            cout << "Thank you for playing CrossWord!";
            break;
        }
        if((toupper(answer) != 'Y') || (toupper(answer) != 'N'))
            cout << "Please, answer Y or N.";
    } while ((answer != 'Y') && (answer != 'N'));

    return 0;
}
// Read data in the file
vector<vector<char>> readData(string fileName)
{
    vector<vector<char>> board;

    ifstream file(fileName);
    if(file)
    {
        string line;
        while (getline(file, line))
        {
            vector<char> row;                       
            for (unsigned int i = 0; i < line.length(); i++) 
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
vector<vector<char>> replace(vector<vector<char> > board)
{
    // Replace alphas with underscores
    for (unsigned int i = 0; i < board.size(); i++) // Loop rows
    {
        for (unsigned int j = 0; j < board[i].size(); j++) // Loop columns
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
void print2dBoard(vector<vector<char>> board)
{
    for (unsigned int i = 0; i < board.size(); i++)
    {
        for (unsigned int j = 0; j < board[i].size(); j++)
        {
            cout << board[i][j];
        }
        cout << " \n";
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
        // Prompt user to enter in a level
        cout << "Enter level to play:\n";
        cin >> level;
        // If statements to change level number to actual level
        if(level == "1") level = "level1.txt";
        else if(level == "2") level = "level2.txt";
        else if(level == "3") level = "level3.txt";
        // Open the level
        fileReader.open(level);
        // If level could not be found
        if(!fileReader.is_open())
        {
            cout << "Could not open " << level << endl;
        }
    } while(!fileReader.is_open());
    // Return the string
    return level;
}
// Initialize the game
void playGame(vector<vector<char>> boardAnswers,
vector<vector<char>> boardUnderscores)
{
    int remainingGuesses = 5;
    vector<char> guesses;
    bool foundLetter = false;
    // Do while loop to ensure the game is played until answers found
    // or guesses are gone
    do
    {
        // Flag to ensure that a letter is found
        foundLetter = false;
        // Variable to enter in guess
        char guess = ' ';
        print2dBoard(boardUnderscores);
        // Prompt user to enter a letter
        cout << "\nEnter a letter:\n";
        cin >> guess;
        char uppercaseGuess = toupper(guess);
        if(find(guesses.begin(), guesses.end(), uppercaseGuess) != guesses.end())
            cout << "\nThe letter is already guessed, try again!\n";  
        else
        {
            cout << "The letter is not on the board";
            guesses.push_back(uppercaseGuess);
        }
        // Print updated board to terminal
        for (unsigned int i = 0; i < boardAnswers.size(); i++)
        {
            for (unsigned int j = 0; j < boardAnswers[i].size(); j++)
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
        // Ensure that incorrect guesses prints if game hasn't ended
        if((boardUnderscores != boardAnswers) || (remainingGuesses != 0))
        cout << "Remaining incorrect guesses: " << remainingGuesses << endl << endl;
    } while ((boardUnderscores != boardAnswers) && (remainingGuesses != 0));
    // Final game announcements prints to terminal
    if(boardUnderscores == boardAnswers)
    {
        print2dBoard(boardUnderscores);
        cout << "\nCongratulations! you solved the level!\n";
    }
    if(remainingGuesses == 0)
    {
        cout << "\nBetter luck next time!\n";
    }
}
