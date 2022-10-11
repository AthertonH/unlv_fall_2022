#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    double updated_zebra = 5 * pow(1 + .05, 12);
    double updated_rabbit = .5 * pow(1 + .1, 12);

    cout << updated_zebra << endl << updated_rabbit;

}