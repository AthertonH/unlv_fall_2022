#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    int runningTotal = 0;
    string fileName;
    ifstream fin;

    do
    {
        cout << "Enter a file name\n**";
        cin >> fileName;

        fin.open(fileName);

        if(fin.is_open())
        {
            string line;
            while(getline(fin, line))
            {
                runningTotal = runningTotal + stoi(line);
                cout << 
                cout << line << endl;
            }
            fin.close();
            cout << runningTotal << endl;
        }   
    } while (!fin.is_open());
}