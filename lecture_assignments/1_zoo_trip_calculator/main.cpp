/*
    Name: Harrison Atherton, 5005662748, 1016, 1B#
    Description: Ask for user input on how many people are going, and how much money
    they have. Calculations will be made in order to let the user know how many buses
    they will need, how much tickets will cost, how much tax will be, and how much will
    be left over for food.
    Input: The user will be prompted with two questions, one asking them how many people
    are in the class and another asking how much money they have in the pool.
    Output: The output will tell the user how many buses they need reserved, how much
    tickets will cost, how much tax will be, and how much will be left over for food.
*/

#include <iostream>
#include <cmath>

using namespace std;

const double stateTax = .0685;
const double zooAdmission = 7.95;

int main()
{
    int people, money;
    int busRoom = 12;

    // Initialize user input to be stored into variables.
    cout << "How many people are in the class? ";
    cin >> people;
    cout << "How much money is in the pool? $";
    cin >> money;

    // If statement to determine how many buses are needed.
    int buses = people / busRoom;
    if(people < busRoom)
    {
        buses = 1;
    }
    else if(people%busRoom != 0)
    {
        buses += 1;
    }

    // Calculations for tickets, tax, and food.
    double tickets = people * zooAdmission;
    double tax = tickets * stateTax;
    double food = (money - tickets - tax) / people;

    // Calculations multiplied, floored, then divided, in order
    // to get the lowest possible point within 2 decimals.
    double tax_calc = (floor((tax*100)) / 100);
    double food_calc = (floor((food*100)) / 100);

    // Output calculations.
    cout << buses << " Buses need to be reserved." << endl;
    cout << "Tickets will cost $" << tickets << endl;
    cout << "Tax will be $" << tax_calc << endl;
    cout << "Each person will have $" << food_calc << " for food." << endl;

    return 0;
}
