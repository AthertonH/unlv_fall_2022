#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
    // Declare variables
    ifstream fileReader;
    string fileName;

    string licensePlate[] = {};
    string date[] = {};
    string time[] = {};
    string weightString = "";
    string speedString = "";
    int weight[] = {};
    int speed[] = {};
    string line;
    int count = 0;

    do
    {
        cout << "Open File: ";
        cin >> fileName;
        fileReader.open(fileName);

        if(!fileReader.is_open())
        {
            cout << "Could not open " << fileName;
        }

    } while(!fileReader.is_open());

    while(!fileReader.eof())
    {
        getline(fileReader, licensePlate[count], ',');
        getline(fileReader, date[count], ',');
        getline(fileReader, time[count], ',');
        getline(fileReader, weightString, ',');
        weight[count] = stoi(weightString);
        getline(fileReader, speedString, ',');
        speed[count] = stoi(speedString);

        cout << weight << endl << speed << endl;
        count++;
    }

}