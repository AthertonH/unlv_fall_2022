/*
    Name: Harrison Atherton, 5005662748, 1018, 1A#
    Description: Practice using variables and constants, of types ints and doubles.
    Input: Use the data type specified with the values 5, 2, 5.0, 2.0 as defined 
    constants. The result of the expression should be saved in an appropriate variable.  
    Output: Output to the terminal along with the informative message.
*/

#include <iostream>

using namespace std;

const int FIVE = 5;
const int TWO = 2;
const double FIVE_DOUBLE = 5.0;
const double TWO_DOUBLE = 2.0;


int main()
{
    int sum = FIVE+TWO;
    int sub = FIVE-TWO;
    int mult = FIVE*TWO;
    int div = FIVE/TWO;
    int rem = FIVE%TWO;
    double double_div = FIVE_DOUBLE/TWO_DOUBLE;
    
    cout << "5 + 2 = " << sum << endl;
    cout << "5 - 2 = " << sub << endl;
    cout << "5 * 2 = " << mult << endl;
    cout << "5 / 2 = " << div << endl;
    cout << "5 % 2 = " << rem << endl;
    cout << "5.0 / 2.0 = " << double_div << endl;

    return 0;
}