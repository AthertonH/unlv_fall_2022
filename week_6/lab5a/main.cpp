/*
    Name: Harrison Atherton, 5005662748, 1019, #5A
    Description: Using nested loops, an upside down triangle
    and a right side up triangle will be outputted
    Input: User inserts how many stars they want
    Output: Visualization of stars in a triangle like fashion.
*/

#include <iostream>

using namespace std;

int main()
{
    // Initialize variables
    int amountOfStars = 0;
    int rows = 0;
    int columns = 0;

    // Do statement to ensure user inserts between 2 and 20
    do
    {
        cout << "Enter a count between 2 and 20\n**";
        cin >> amountOfStars;
        if(amountOfStars <= 1 || amountOfStars > 20)
        {
            cin.clear();
            cin.ignore(200, '\n');
            cout << "\nError: Invalid entry, please retry\n";
        }
    }while (amountOfStars <= 1 || amountOfStars > 20);

    cout << endl;
    // For loop to print upsidedown triangle.
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

    // While loop to print rightside up triangle
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
    return 0;
}
