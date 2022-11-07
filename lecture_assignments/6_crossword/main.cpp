#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

vector<vector<char>> readData(string fileName);
vector<vector<char>> replace1(vector<vector<char>> v);
vector<vector<char>> replace2(vector<vector<char>> v);
void print2dVector(vector<vector<char>> v);
string chooseLevel();

int main()
{

    
    vector<vector<char>> data1;
    vector<vector<char>> data2; 

    // read data from files
    data1 = readData(chooseLevel());
    // data2 = readData(chooseLevel());

    // print data from files
    cout << "Before replace\n";
    print2dVector(data1);
    cout << '\n';
    print2dVector(data2);

    cout << "------------------------------------------------------------\n";

    cout
        << "\nAfter replace using method 1 or replace1\n";
    data1 = replace1(data1);
    print2dVector(data1);

    cout << "\nAfter replace using method 2 or replace2\n";
    data2 = replace2(data2);
    print2dVector(data2);

    return 0;
}

string chooseLevel()
{
    string level = "";
    cout << "Enter level to play:\n";
    cin >> level;
    return level;
}

// Read data in the file
vector<vector<char>> readData(string fileName)
{
    vector<vector<char>> board;

    ifstream file(fileName);
    if (file)
    {
        string line;
        while (getline(file, line))
        {
            vector<char> row;                       
            for (int i = 0; i < line.length(); i++) 
            {
                row.push_back(line[i]);
            }
            board.push_back(row);
        }
    }
    else
    {
        cout << "File not found\n";
    }
    file.close();
    return board;
}


vector<vector<char>> replace1(vector<vector<char>> v)
{
    for (int i = 0; i < v.size(); i++) // loop rows
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            if (isalpha(v[i][j]))
            {
                v[i][j] = '_';
            }
        }
    }
    return v;
}

vector<vector<char>> replace2(vector<vector<char>> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            if (v[j][i] != '#' && v[j][i] != ' ')
            {
                v[j][i] = '_';
            }
        }
    }
    return v;
}

void print2dVector(vector<vector<char>> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}