#include <iostream>

using namespace std;

int main()
{
    string name = "";
    bool found = false;

    // 2 parallel arrays
    string names[] = {"harrison", "clinton", "adam", "ariel", "greg"};
    string favoriteColor[] = {"purple", "yellow", "green", "orange", "red"};

    // get a name to search for
    cout << "Enter a name\n**";
    cin >> name;

    // search for name
    for(int i = 0; i < 5; i++)
    {
        if(names[i] == name)
        {
            cout << endl << name << "'s favorite color is " << favoriteColor[i] << endl;
            found = true;
        }
    }

    // name wasn't found
    if(!found)
    {

    }
}