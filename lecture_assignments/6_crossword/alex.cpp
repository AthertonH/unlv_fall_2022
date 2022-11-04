#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main()
{
    vector<vector<int>> vec;
    string row = "";
    int comma_location = 0, current_num = 0;
    ifstream iFile;
    iFile.open("numbers.csv");
    getline(iFile, row);

    while(getline(iFile, row))
    {
        vec.push_back(vector<int>());

        while(row.find(",") != string::npos)
        {
            comma_location = row.find(",");
            current_num = stoi(row.substr(0, comma_location));
            vec[vec.size()-1].push_back(current_num);
            row = row.substr(comma_location+1, row.length());
        }
        vec[vec.size()-1].push_back(stoi(row));
    }

    for(int i = 0; i < vec.size(); i++)
    {
        for(int j = 0; j < vec[i].size(); j++)
        {
            cout << vec[i][j]
                 << ((j != vec[i].size() - 1) ? ", " : "\n");
        }
    }
}