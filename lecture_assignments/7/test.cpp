#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    ifstream fileReader;
    ofstream fileWriter;
    string filePath = "test.csv";
    vector<string> newFile = {};
    string removeString = "name";

    fileReader.open(filePath);

    while(!fileReader.eof())
    {
        string line = " ";
        getline(fileReader, line, '\n');
        if(line != removeString)
            newFile.push_back(line);
        else
            continue;
    }

    fileWriter.open("test.csv");

    for(int i = 0; i < newFile.size(); i++)
    {
        fileWriter << newFile[i] << endl;
    }


}