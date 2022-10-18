#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream fileReader;
    string filename = "";
    int violations = 0;
    
    cout << "Open File: ";
    getline(cin, filename);

    fileReader.open(filename);

    while(!fileReader.eof())
    {
        string licensePlate = "";
        string date = "";
        string time = "";
        string weight = "";
        string speed = "";
        
        getline(fileReader, licensePlate, ',');
        getline(fileReader, date, ',');
        getline(fileReader, time, ',');
        getline(fileReader, weight, ',');
        getline(fileReader, speed, '\n');

        int weight2 = stoi(weight);
        int speed2 = stoi (speed);

        if(weight2 < 5000 && speed2 > 45)
        {
            violations++;
        }
        else if(weight2 > 5000 && speed2 > 30)
        {
            violations++;
        }
    }
}