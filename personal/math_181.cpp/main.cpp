#include <iostream>

using namespace std;

int main()
{
    string names[7] = {"Daniely", "Joshua", "Izaiah", "Nathan", "Destiny", "Harrison", "Cabe"};
    int questions = 82;
    int index = 0;


    for(int i = 2; i <= questions; i++)
    {
        if(i % 2 == 0)
        {
            cout << i << ": ";
            if(index != 6)
            {
            cout << names[index] << endl;
            index += 1;
            }
            else
            {
            cout << names[index] << endl;;
            index = 0;
            }
        }

    }

}