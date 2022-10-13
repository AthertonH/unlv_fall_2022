#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int main()
{
	ifstream fileReader;
	string filename = "";
	int total = 0;
	do
	{
		cout << "Open file: ";
		getline(cin, filename);
		
		fileReader.open(filename);	
		
		if(fileReader.is_open() == false)
		{
			cout << "Could not open " << filename << endl;
		}
	}
	while(fileReader.is_open() == false);
	
	while(!fileReader.eof())
	{
        string line = "";
		getline(fileReader, line);
        cout << line << endl;
        
	}	
	
	return 0;
}