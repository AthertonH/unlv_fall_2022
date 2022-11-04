#include <iostream>
#include<string>
using namespace std;
int frequency_Substr(string mainWord,string subWord)
{
    int count=0;
    for (int i = 0; i <mainWord.size()-1; i++)
    {
        int m = 0;
        for (int j = 0; j < subWord.size(); j++)
        {
            if (mainWord[i] == subWord[j])
            {
                m++;
            }
            i++;
        }
        if (m == subWord.size())
        {
            count++;
        }
    
    }
    cout << "total number of time substring occur in string is " << count << endl;
    return count;
}
int main()
{
    string x, y;
    cout << "enter string" << endl;
    cin >> x;
    cout << "enter substring" << endl;
    cin >> y;
    frequency_Substr(x, y);
    return 0;
}