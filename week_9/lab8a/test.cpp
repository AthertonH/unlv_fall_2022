#include <iostream>
using namespace std;


#include <iostream>
using namespace std;

int main()
{
	int size = 3;
	char character = 'a';

    // Keeps track of what row is currently printing
    for (int i = 0; i <= size; i++)
    {
        // Keeps track of what column is currently printing
        for (int j = 0; j < i; j++)
        {
            cout << character;
        }
        if(i != size)
		cout << endl;
    }
}