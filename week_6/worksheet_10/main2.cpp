#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    string text1;
    string text2;
    string line;
    ifstream fin;
    ofstream fout;

    cout << "Enter the name of the text that you want to copy: ";
    cin >> text1;
    cout << "\nEnter the name of the text that you wish to copy it to: ";
    cin >> text2;

    fin.open(text1);
    fout.open(text2);

    if(text1 == text2)
    {
        cout << "\nFiles cannot have the same name.";
    }
    else if(fin.is_open() && fout.is_open())
    {
        while(!fin.eof())
        {
            getline(fin, line);
            fout << line << endl;
        }
    }
    fin.close();
    fout.close();
    cout << "\nFile copied successfully";
}