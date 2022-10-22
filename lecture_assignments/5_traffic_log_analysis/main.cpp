/*
    Name: Harrison Atherton, 5005662748, 1016, #5
    Description: A data reader and writer. The program will determine if the car
    has exceeded the speed limit. If the speed limit has been exceeded, it will be
    logged into files, seperated by date. The files will contain their license plate
    as well as the time of when it had taken place.
    Input: User is prompted to enter in a file that contains the data
    Output: Files will be created, organized by date. It will determine which cars
    have exceeded the speed limit, and print out a statement in the terminal in regards
    to how many violations are within that file.
*/
#include <iostream>
#include <fstream>
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

    // Do while loop to ensure the user enters in a file name
    do
    {
        cout << "Open File: ";
        cin >> fileName;
        fileReader.open(fileName);

        if(!fileReader.is_open())
        {
            cout << "Could not open " << fileName << endl;
        }

    } while(!fileReader.is_open());

    // Read each line that is seperated by a comma, convert the weight and speed into
    // an integer
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

    // For loop to open files and calculate if they have exceeded the limit
    for(int i = 0; i < count; i++)
    {
        // Checks if the file is open, if it is not, it will create it
        if(!fileWriter.is_open())
            {
                fileWriter.open("[" + date[i] + "]" + " Report.txt");
            }
        // Calculations to determine if they have exceeded the speed limit based on
        // weight of vehicle
        if((weight[i] < 5000 && speed[i] > 45) || (weight[i] > 5000 && speed[i] > 30))
        {
            fileWriter << "[" << time[i] << "] " << licensePlate[i] << endl;
            violations++;
        }
        // Checks to see if the date is the same as the proceeding date, if it is not
        // it will close the current file, and create a new one at the top of the loop
        if(date[i] != date[i+1])
        {
            fileWriter.close();
        }
    }
    
    // Print how many violations have occurred to the terminal.
    cout << violations << " violations logged." << endl;

    return 0;
}
