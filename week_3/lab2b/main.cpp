/*
    Name: Harrison Atherton, 5005662748, 1018, 2B#
    Description: Receive user input to calculate the
    circumference and area of the radius in a box.
    Input: User inputs in radius
    Output: Output the calculations to the interface 
    (circumference and area) surrounded by a box

    If you're American when you go in the bathroom and
    American when you come out, what are you in the bathroom?
    European
*/

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

const double PI = 3.141592;

int main()
{
    double radius = 0;
    
    // Prompt user input
    printf("Enter the radius of a circle\n**");
    cin >> radius;
    double circumference = 2*PI*radius;
    double area = (PI*radius*radius);

    // Set decimal place precision to two
    cout << fixed << setprecision(2);

    // Initialize fixed box size
    string separator = "+--------+---------------+---------+\n";
    string h1 = "radius", h2 = "circumference", h3 = "area";
    string headers = "| " + h1 + " | " + h2 + " | " + h3 + "    |\n";

    // Output box and calculations
    cout << "\n" << separator;
    cout << headers;
    cout << separator;
    cout << left;
    cout << "| " << setw(6) << radius;
    cout << " | " << setw(13) << circumference;
    cout << " | " << setw(8) << area << "|\n";
    cout << separator;

    return 0;
}
