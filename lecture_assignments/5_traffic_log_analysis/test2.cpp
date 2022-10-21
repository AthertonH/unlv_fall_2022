#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

const int ARRAY_SIZE = 1200;

int main()
{
    // Declare variables
    ifstream fileReader;
    ofstream fileWriter;
    string fileName;

    string licensePlate[ARRAY_SIZE] = {};
    string date[ARRAY_SIZE] = {};
    string time[ARRAY_SIZE] = {};
    string weightString = "";
    string speedString = "";
    int weight[ARRAY_SIZE] = {};
    int speed[ARRAY_SIZE] = {};
    int count = 0;
    int violations = 0;

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
        getline(fileReader, speedString, '\n');
        weight[count] = stoi(weightString);
        speed[count] = stoi(speedString);
        count++;
    }

    for(int i = 0; i < count; i++)
    {
        if(weight[i] < 5000 && speed[i] > 45)
        {
            violations++;
        }
        else if(weight[i] > 5000 && speed[i] > 30)
        {
            violations++;
        }
    }
    cout << violations;

}