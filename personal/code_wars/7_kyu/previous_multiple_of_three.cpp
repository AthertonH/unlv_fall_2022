#include <iostream>
#include <vector>
using namespace std;


int prev_mult_of_three (int n) 
{
    while(n > 0)
    {
        if(n%3 == 0)
            return n;
        else
            n /= 10;
    }
    return -1;
}

int main()
{
    cout << prev_mult_of_three(952406);
}