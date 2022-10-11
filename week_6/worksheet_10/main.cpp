#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    string fileName;
    ifstream fin;

    do
    {
        cout << "Name of file: ";
        cin >> fileName;

        fin.open(fileName);

        if(!fin.is_open())
            {
                cout << "\nFailed to read/open file.\n\n";
                cin.clear();
                cin.ignore(200, '\n');
            }
        else if(fin.is_open())
        {
            string line;
            while(getline(fin, line))
            {
                cout << line << endl;
            }
            fin.close();
            return 0;
        }
    }while(!fin.is_open());
}