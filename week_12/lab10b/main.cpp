#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct purchaseType
{
    string customerID;
    string productName;
    double price;
    int qtyPurchased;
    double taxRate;
};

void openFile(ifstream&, string);
void readFile(ifstream&, purchaseType);

int main()
{   
    ifstream iFile;
    string prompt = "Enter file name\n**";

    openFile(iFile, prompt);
    
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

    while(!iFile.eof())
    {
        getline(iFile, purchases[count].customerID, ',');
    }
}