#include <iostream>
#include <fstream>
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