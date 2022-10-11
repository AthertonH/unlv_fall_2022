#include <iostream>

using namespace std;

int main()
{
    int amountOfStars = 0;
    int rows = 0;
    int columns = 0;

    do
    {
        cout << "Enter a count between 2 and 20\n**";
        cin >> amountOfStars;
        if(amountOfStars < 1 || amountOfStars >= 20)
        {
            cout << "Error: Invalid entry, please retry\n";
        }
    }while (amountOfStars < 1 || amountOfStars >= 20);

    // Keeps track of what row is currently printing
    for (int i = amountOfStars; i > 0; i--)
    {
        // Nested loop
        // Keeps track of what column is currently printing
        for (int j = 0; j < i; j++)
        {
            cout << "*";
        }
        if(i != 1)
        {
            cout << endl;
        }
    }
    while(rows <= amountOfStars)
    {
        columns = 1;
        while(columns <= rows)
        {
            cout << "*";
            columns++;
        }
        cout << endl;
        rows++;
    }
}