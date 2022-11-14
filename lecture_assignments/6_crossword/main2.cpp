/* Name: JOSHUA_GUTIERREZ, SECTION_1005, ASSIGNMENT_#5
Description: Recording traffic violations based on weight and speed while outputting
violations to separate output file
Input: User input for file name
Output: Output number of violations and file output to log violations
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

void print2dBoard(vector<vector<char>> board);

int main()
{
    int input = 0;
    int guesses = 0;
    char input2 = ' ';
    bool flag = false;
    const int ARRAY_SIZE = 100;
    string i[ARRAY_SIZE] = {""};
    string j[ARRAY_SIZE] = {""};
    ifstream iFile;

    do
    {
        cout << "Enter level to play:" << endl;
        cin >> input;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Invalid Entry!\n";
        }

        else if (input > 3 || input < 1)
        {
            cout << "Level files could not be found!\n";
        }

    } while (input > 3 || input < 1 || cin.fail());

    cout << endl;

    string fileName = ("level" + to_string(input) + string(".txt"));
    iFile.open(fileName);

    vector<vector<char> > contents;
    vector<vector<char> > unsolvedBoard;
    vector<vector<char> > solvedBoard;

    string line = " ";

    while (getline(iFile, line))
    {
        vector<char> row;
        for (int i = 0; i < line.length(); i++)
        {
            row.push_back(line[i]);
        }
        contents.push_back(row);
        unsolvedBoard.push_back(row);
        solvedBoard.push_back(row);
    }

    for (int i = 0; i < contents.size(); i++) // this will loop through each row
    {
        for (int j = 0; j < contents[i].size(); j++) // this will loop through each column
        {
            if (isalpha(contents[i][j]))
            {
                contents[i][j] = '_';
            }
            cout << contents[i][j];
        }
        cout << endl;
    }

    cout << endl;

    do
    {
        bool foundLetter = false;
        cout << "Enter a letter:\n";
        cin >> input2;

        cout << "Remaining incorrect guesses: " << guesses << endl;
        cout << endl;

        for (unsigned int i = 0; i < solvedBoard.size(); i++)
        {
            for (unsigned int j = 0; j < solvedBoard[i].size(); j++)
            {
                if (input == solvedBoard[i][j])
                {
                    unsolvedBoard[i][j] = input2;
                    // Flag to confirm a letter has been found
                    foundLetter = true; 
                }
            }
        }
    }while(unsolvedBoard != solvedBoard);
}

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