#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

struct purchaseType
{
    string customerID;
    string productName;
    double price;
    int qtyPurchased;
    double taxRate;
    double total;
};

void openFile(ifstream&, string);
void readFile(ifstream&, purchaseType[]);
void printPurchaseData(purchaseType[], int);

int main()
{   
    ifstream iFile;
    purchaseType purchases[10];

    string prompt = "Enter file name\n**";
    openFile(iFile, prompt);
    readFile(iFile, purchases);
    printPurchaseData(purchases, 10);
}

void openFile(ifstream& iFile, string prompt)
{
    string fileName = "";
    do
    {
        cout << prompt;
        cin >> fileName;
        iFile.open(fileName);

        if(!iFile.is_open())
        {
            cout << "Could not open " << fileName << endl;
        }

    } while(!iFile.is_open());
}

void readFile(ifstream& iFile, purchaseType purchases[])
{
    int count = 0;

    double priceDigit = 0.0;
    int quantityDigit = 0;
    double taxRateDigit = 0.0;
    double total = 0.0;

    while(count < 10)
    {
        getline(iFile, purchases[count].customerID, ',');
        getline(iFile, purchases[count].productName, ',');
        getline(iFile, priceString, ',');
        getline(iFile, qtyPurchasedString, ',');
        getline(iFile, taxRateString, '\n');
        purchases[count].price = stod(priceString);
        purchases[count].qtyPurchased = stoi(qtyPurchasedString);
        purchases[count].price = stod(taxRateString);
        count++;
    }  
}

void printPurchaseData(purchaseType purchases[], int size)
{
    int count = 0;


    string template1 = "+-------------+--------------+-------"
    "+----------+----------+-------+\n";
    string template2 = "| Customer ID | Product Name | Price |"
    "Quantity | Tax Rate | Total |\n";
    
    string template3 = "|" + purchases[count].customerID + "|" + 
    purchases[count].productName + "|" + purchases[count].price +
    "|" + purchases[count].qtyPurchased + "|" +
    purchases[count].taxRate + "|";

    cout << template1 << template2 << template1;

    while (count < 10)
    {
        cout << template3;
        count ++;
    }
    
    


}