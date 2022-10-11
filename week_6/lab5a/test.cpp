#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int rows;
    int i;
    int j;

    cout << "Enter number of rows: ";
    cin >> rows;

    int k=rows;
    i=1;

    while (i <= rows)
    {  
        j=1;
        while(j <= i)
        {
            cout << "*";
            j++;
        }
        cout << endl ;
        i++;
    }
}