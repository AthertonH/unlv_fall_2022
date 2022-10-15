#include <iostream>
using namespace std;

// Declare variables
string choice = "\0";
int numOfMatches = 0;
int remainingMatches = 21;
bool playAgain = true;
bool turn = false;
bool reset = true;
bool flag = true;
int removed = 0;

void beginGame()
{
    if(reset == true)
    {
        do
        {
            // Offer choice to begin first or second
            cout << "\nWould you like to go first? (Y/N): ";
            getline(cin, choice);

            // Receive user input for choice to go first or second
            if(choice == "Y" || choice == "y")
            {
                turn = true;
                reset = false;
            }
            else if(choice == "N" || choice == "n")
            {
                turn = false;
                reset = false;
            }
            else
            {
                cout << "\nPlease, answer Y or N.\n";
            }
        } while(reset == true);
    }
}

void playerTurn()
{
    if(turn == true && reset == false && remainingMatches != 1)
    {
        // Display matches to terminal
        cout << "\nPlayer turn - Matches: ";
        for(int i = 1; i <= remainingMatches; i++)
        {
            if(i % 5 == 0)
            {
                cout << "| ";
            }
            else
            {
                cout << "|";
            }
        }

        // Display how many to remove, change turn to false
        do
        {
            cout << "\n\nRemove (1 - 3): ";
            cin >> numOfMatches;

            // If statement to ensure player chooses between 1-3
            if(numOfMatches == 1 || numOfMatches == 2 || numOfMatches == 3)
            {
                remainingMatches -= numOfMatches;
                turn = false;
            }
            else if(cin.fail())
            {
                cout << "\nPlease, type 1, 2, or 3 as your response.";
                cin.clear();
                cin.ignore(200, '\n');
                continue;
            }
            else if(numOfMatches > 3)
            {
                cout << "\nCannot remove more than three matches.";
            }
            else
            {
                cout << "\nMust remove at least one match.";
            }
        } while(numOfMatches != 1 && numOfMatches != 2 && numOfMatches != 3);
    }
}

void computerTurn()
{
    if(turn == false && reset == false && remainingMatches != 1)
    {
        cout << "\nComputer Turn - Matches: ";

        // Display matches to terminal
        for(int i = 1; i <= remainingMatches; i++)
        {
            if(i % 5 == 0)
            {
                cout << "| ";
            }
            else
            {
                cout << "|";
            }
            turn = true;
        }

        // Computer logic to remove the sticks
        if(remainingMatches % 4 == 0)
        {
            removed = 3;
            remainingMatches -= removed;
        }
        else if(remainingMatches % 4 == 1)
        {
            removed = 1;
            remainingMatches -= removed;
        }
        else if(remainingMatches % 4 == 2)
        {
            removed = 1;
            remainingMatches -= removed;
        }
        else if(remainingMatches % 4 == 3)
        {
            removed = 2;
            remainingMatches -= removed;
        }
        cout << "\n\nComputer removes " << removed << "." << endl;
    }
}

void endGame()
{
    if(remainingMatches == 1 && turn == true)
    {
        // Flag set to print this message out only once. Flag then set to false.
        if(flag == true)
        {
            cin.clear();
            cin.ignore(200, '\n');
            cout << "\nPlayer turn - Matches: |\n";
            cout << "\nGame Over - Computer wins.\n";
            flag = false;
        }
        cout << "\nWould you like to play again? (Y/N): ";
        getline(cin, choice);
        do
        {
            if(choice == "Y" || choice == "y")
            {
                remainingMatches = 21;
                playAgain = true;
                reset = true;
                flag = true;
            }
            else if(choice == "N" || choice == "n")
            {
                playAgain = false;
            }
            else
            {
                cout << "\nPlease, answer Y or N.\n";
                flag = false;
            }
        }while(!playAgain);
    } else if(remainingMatches == 1 && turn == false)
    {
        // Flag set to print this message out only once. Flag then set to false.
        if(flag == true)
        {
            cin.clear();
            cin.ignore(200, '\n');
            cout << "\nComputer turn - Matches: |\n";
            cout << "\nGame Over - Player wins.\n";
            flag = false;
        }
        cout << "\nWould you like to play again? (Y/N): ";
        getline(cin, choice);
        do
        {
            if(choice == "Y" || choice == "y")
            {  
                remainingMatches = 21;
                playAgain = true;
                reset = true;
                flag = true;
            }
            else if(choice == "N" || choice == "n")
            { 
                playAgain = false;
            }
            else
            {
                cout << "\nPlease, answer Y or N.\n";
            }
        } while (!playAgain);
    }
}

int main()
{
    do
    {
        beginGame();
        playerTurn();
        computerTurn();
        endGame();
    } while (playAgain == true);

    return 0;
}