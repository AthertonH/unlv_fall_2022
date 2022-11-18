#include <iostream>
#include <cstdlib>
using namespace std;

int main(int argc, char* argv[])
{
    cout << "ArgC: " << argc << endl;

    int wholeNumber = 0;
    double floatingPointValue = 0;

    for(int i = 0; i < argc; i++)
    {
        cout << "ArgV[" << i << "]" << argv[i] << endl;
    }

    wholeNumber = atoi(argv[1]);
    floatingPointValue = atof(argv[2]);
    cout << "Number: " << wholeNumber << endl;
    cout << "Floating: " << floatingPointValue << endl;

    return 0;
}