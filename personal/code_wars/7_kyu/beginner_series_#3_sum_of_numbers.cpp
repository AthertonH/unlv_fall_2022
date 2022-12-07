#include <iostream>
using namespace std;

/*
Given two integers a and b, which can be positive or negative, find the sum 
of all the integers between and including them and return it. If the two numbers 
are equal return a or b.
Note: a and b are not ordered!
*/

// int get_sum(int a, int b)
// {
//   for(int i = a; i <= b; i++)
//         a += i;
//     return a;
// }

int get_sum(int a, int b)
{
    if(a == b)
        return a;
    for(int i = a; i <= b; i++)
        a += i;
    return a;
}

int main()
{
    cout << get_sum(-2, 5);
    return 0;
}