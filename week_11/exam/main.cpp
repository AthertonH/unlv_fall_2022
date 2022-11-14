#include <iostream>
using namespace std;

int a = 0;
int b = 3;
int c = 2;


int main()
{
    while(a < 5)
    {
        a = a + 1;
        b += 3;
        continue;
        c = c * 2;
    }

    cout << "a: " << a << "\nb: " << b << "\nc: " << c;
}
