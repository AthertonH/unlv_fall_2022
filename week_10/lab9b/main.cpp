/*
    Name: Harrison Atherton, 5005662748, 1019, #9B
    Description: Using functions to add and multiply integers, as well as functions
    and loops to print strings multiplied by the integers
    Input: User will be prompted to enter in two integers, and then prompted to enter
    in two strings.
    Output: Addition calculation for integers, strings combined as one word, 
    multiplication calculation for integers, strings multiplied by integers.
*/
#include <iostream>
using namespace std;

// Declare function prototypes
int add(int num1, int num2);
string add(string str1, string str2);
int multiply(int num1, int num2);
string multiply(string str, int num);

int main()
{
    // Declare variables
    int num1 = 0;
    int num2 = 0;
    string str1 = "";
    string str2 = "";

    // Do while loop to ensure user enters in a good integer
    do
    {
        cout << "Enter an integer between 1 and 50\n**";
        cin >> num1;
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(200, '\n');
            cout << "\nError: Invalid input!\n";
        }
        else if(num1 < 1 || num1 > 50)
        cout << "\nError: Invalid input!\n";
    } while ((num1 < 1 || num1 > 50));
    cout << endl;

    // Do while loop to ensure user enters in a good integer
    do
    {
        cout << "Enter another integer between 1 and 50\n**";
        cin >> num2;
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(200, '\n');
            cout << "\nError: Invalid input!\n";
        }
        else if(num2 < 1 || num2 > 50)
        cout << "\nError: Invalid input!\n";
    } while ((num2 < 1 || num2 > 50));

    // Prompt user for two strings
    cout << "\nEnter a string\n**";
    cin >> str1;
    cout << "\nEnter another string\n**";
    cin >> str2;
    cout << endl;

    // Call the functions
    add(num1, num2);
    cout << endl;
    add(str1, str2);
    cout << endl;
    multiply(num1,num2);
    cout << endl;
    multiply(str1, num1);
    cout << endl;
    multiply(str2, num2);
}

// Function to add two integers
int add(int num1, int num2)
{
    cout << num1 << " + " << num2 << " = " << num1 + num2;
    return num1 + num2;
}

// Function to add two strings
string add(string str1, string str2)
{
    cout << str1 << " + " << str2 << " = " << str1+str2;
    return str1+str2;
}

// Function to multiply two integers
int multiply(int num1, int num2)
{
    cout << num1 << " * " << num2 << " = " << num1*num2;
    return num1*num2;
}

// Function to multiply two strings
string multiply(string str, int num)
{
    string newString = "";
    for(int i = 0; i < num; i++)
    {
        newString += str;
    }
    cout << str << " * " << num << " = " << newString;
    return newString;
}
