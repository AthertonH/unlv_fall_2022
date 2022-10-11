/*
    Name: Harrison Atherton, 5005662748, 1018, #4B
    Description: Ask user to enter a number between 2 and 10000.
    Return the sum of both odd and even numbers, using do... while,
    for, and while loops.
    Input: Input a single integer between 2 and 10000.
    Output: Output the sum of both even and odd of those numbers
    incremented.
*/

#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

int main()
{
    // Initialize variables
    int count = 0;
    int oddSum = 0;
    int evenSum = 0;
    int j = 0;

    // Do loop to enter the count in
    do {
        cout << "Enter a count between 2 and 10000\n**";
        cin >> count;
        if(cin.fail()){
            cin.clear();
            cin.ignore(200, '\n');
            cout << "\nError: Invalid entry, please retry\n";
        } else if(count < 2 || count > 10000){
        cout << "\nError: Invalid entry, please retry\n";
        } else{
            break;
        }
        } while(true);
    

    // For loop to determine Even Sum
    for(int i = 0; i <= count; i++){
        if(i % 2 == 0){
            evenSum += i;
        }
    }

    // While loop to determine Odd Sum
    while(j <= count){
        if(j % 2 != 0){
            oddSum += j;
        }
        j++;
    }

    cout << "\nSum of even numbers: " << evenSum;
    cout << "\nSum of odd numbers:  " << oddSum;

    return 0;

}
