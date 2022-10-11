#include <iostream>

using namespace std;

// Declare variables
char choice = '\0';
int numOfMatches = 0;
int remainingMatches = 21;
bool playAgain = false;
bool turn = false;
int removed = 0;

void gameIntroduction()
{
    do
    {
        // Offer choice to begin first or second
        cout << "\n\nWould you like to go first? (Y/N): ";
        cin >> choice;

        // Receive user input for choice to go first or second
        if(toupper(choice) == 'Y')
        {
            turn = true;
            playAgain = true;
        }
        else if(toupper(choice) == 'N')
        {
            turn = false;
            playAgain = true;
        }
        else
        {
            cout << "\nPlease enter Y or N.";
        }
    } while(playAgain == false);
}

int main()
{
    
}