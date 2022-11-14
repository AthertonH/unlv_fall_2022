#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// prototype of function

// read data example
/**
 * @brief This function reads the file and stores the data in a vector
 * idea: read the file line by line, then using for loop to read each character
 *      and store it in a vector (row). After we done with each line/row, we push
 *      the row into the board vector.
 * @param fileName - the name of the file
 * @return vector<vector<char>> - the vector containing the data from the file
 */
vector<vector<char>> readData(string fileName);

// using nested for loops and isAlpha()
/**
 * @brief This function replace all the alphabets in the board with '_'
 * idea: using nested for loops to go through the board, and check if the character
 *     is an alphabet, if it is, replace it with '_' by using isAlpha() function
 * Notes: isAlpha() function is from cctype library. It returns true if the character
 *    is an alphabet, otherwise, it returns false.
 * Notes: 1st for loop is for going through the rows, 2nd for loop is for going through the columns
 * @param v - the vector containing the data from the file
 * @return vector<vector<char>> - return the board with all alphabets replaced with '_'
 */
vector<vector<char>> replace(vector<vector<char>> v);

// using nested loops and if statements
/**
 * @brief same as replace1() function, but using if statements instead of isAlpha()
 *
 * @param v
 * @return vector<vector<char>>
 */
vector<vector<char>> replace2(vector<vector<char>> v);

// print 2d vector
/**
 * @brief This function prints the 2d vector -> literlly take from textbook (307-310 - Richard L. Halterman book)
 *
 * @param v - the vector containing the data from the file
 */
void print2dBoard(vector<vector<char>> v);

int main()
{
    vector<vector<char>> data1;
    vector<vector<char>> data2;

    data1 = readData("level1.txt");
    cout << endl;
    data2 = replace(data1);


    return 0;
}
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

vector<vector<char>> replace(vector<vector<char>> v)
{
    for (int i = 0; i < v.size(); i++) 
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

void print2dBoard(vector<vector<char>> v)
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