/*
    Name: Harrison Atherton, 5005662748, 1019, #10B
    Description: Program to read a csv file, and put it into a readable table using
    iomanip. Calculations are made to determine the total, average total, number
    of unique users, as well as the tax.
    Input: The user wil be prompted to enter in a file name.
    Output: A table with calculations will be outputted to the terminal.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

// Struct to create a purchaseType
struct purchaseType
{
    string customerID;
    string productName;
    double price;
    int qtyPurchased;
    double taxRate;
    double total;
};

// Prototypes for functions
void openFile(ifstream&, string);
void readFile(ifstream&, purchaseType[]);
void printPurchaseData(purchaseType[], int);

int main()
{   
    ifstream iFile;
    purchaseType purchases[10];

    // Prompt for user
    string prompt = "Enter file name\n**";

    // Calling the functions
    openFile(iFile, prompt);
    readFile(iFile, purchases);
    printPurchaseData(purchases, 10);
    return 0;
}

// Function to open file
void openFile(ifstream& iFile, string prompt)
{
    string fileName = "";

    // Loop to ensure file is opened
    do
    {
        cout << prompt;
        cin >> fileName;
        iFile.open(fileName);

        if(!iFile.is_open())
            cout << "\nError: Invalid File" << endl;
            
    } while(!iFile.is_open());
}

void readFile(ifstream& iFile, purchaseType purchases[])
{
    int count = 0;
    string priceString = "";
    string qtyPurchasedString = "";
    string taxRateString = "";

    while(count < 10)
    {
        // getline, using ',' as delimiter
        getline(iFile, purchases[count].customerID, ',');
        getline(iFile, purchases[count].productName, ',');
        getline(iFile, priceString, ',');
        getline(iFile, qtyPurchasedString, ',');
        getline(iFile, taxRateString, '\n');
        // Converting string to doubles and integers
        purchases[count].price = stod(priceString);
        purchases[count].qtyPurchased = stoi(qtyPurchasedString);
        purchases[count].taxRate = stod(taxRateString);
        // Calculation to determine the total, add it to the struct
        double priceQuantity = purchases[count].price * 
        purchases[count].qtyPurchased;
        purchases[count].total = priceQuantity + 
        (priceQuantity * purchases[count].taxRate);
        // Increment count
        count++;
    }  
}

// Function to print the purchase data
void printPurchaseData(purchaseType purchases[], int size)
{
    int count = 0;
    int uniqueUsers = 0;
    double averageTotal = 0;

    // Templates
    string template1 = "+-------------+--------------+-------"
    "+----------+----------+--------+\n";   
    string template2 = "| Customer ID | Product Name | Price |"
    " Quantity | Tax Rate | Total  |\n";

    cout << endl << template1 << template2 << template1;

    // Print out the vector to a table using iomanip
    while (count < 10)
    {
        cout << fixed << setprecision(2);
        cout << "|" << setw(12) << right << purchases[count].customerID << " ";
        cout << "|" << setw(13) << right << purchases[count].productName << " ";
        cout << "|" << setw(6) << right << purchases[count].price << " ";
        cout << "|" << setw(9) << right << purchases[count].qtyPurchased << " ";
        cout << "|" << setw(9) << right << purchases[count].taxRate*100 << " ";
        cout << "| " << setw(6) << right << purchases[count].total << " |\n";
        count++;
    }
    cout << template1;

    // Loop to find the unique users
    for(int i = 0; i < 10; i++)
    {
        if(purchases[i].customerID != purchases[i+1].customerID)
            uniqueUsers += 1;
        averageTotal += purchases[i].total;
    }
    // Print to the terminal
    cout << "Unique users:  " << uniqueUsers << endl
         << "Average total: $" << averageTotal/10;
}