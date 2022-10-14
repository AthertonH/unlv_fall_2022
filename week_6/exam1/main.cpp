#include <iostream>

using namespace std;

const double EXPENSES = 47365.21;

int main()
{
    double milkProf = 0;
    double milkPrice = 3.56;
    double cheddarPrice = 87.31;
    double goudaPrice = 106.99;
    int milk = 0;
    int gallonsBought = 0;
    double gallonPrice = 0;
    double cheddar = 0;
    double gouda = 0;

    cout << "How many gallons bought?\n";
    cin >> gallonsBought;

    if(gallonsBought < 0)
    {
        cout << "Invalid.";
    }
    cout << "Price per gallon: ";
    cin >> gallonPrice;
    if(gallonsBought >= 40000)
    {
        milk += 80000;
        milkProf = milk *3.56;
        gallonsBought = 80000 * 3.56;
    }
    else
    {
        milk = gallonsBought * 2;
        milkProf = milk * 3.56;
        gallonsBought = 0;
    }
    if(gallonsBought > 0)
    {
        cheddar += (gallonsBought * .6)/100;
        gouda += (gallonsBought * .4)/100;
    }
    double cheddarProf = ((gallonsBought * .6) * gallonPrice) - (cheddar * cheddarPrice);
    double goudProf = ((gallonsBought *.4) * gallonPrice) - (gouda * goudaPrice);

    cout << "Bottles made: " << milk << endl;
    cout << "Profit: $" << milkProf << endl;
    cout << "Cheddar made: " << cheddar << endl;
    cout << "Cheddar profit: " << cheddarProf << endl;
    cout << "Gouda made: " << gouda << endl;
    cout << "Goud profit: " << goudProf << endl;
    double totalProfit = milkProf + cheddarProf + goudProf;
    cout << "Total Profit: " << totalProfit << endl;

    return 0;
}