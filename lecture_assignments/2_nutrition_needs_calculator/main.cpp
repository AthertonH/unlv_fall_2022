/*
    Name: Harrison Atherton, 5005662748, 1016, #2
    Description: A program that calculates how much food is needed
    for the zebras and rabbits at the zoo.
    Input: A user will be presented with a prompt, asking how many
    months, the number of zebras, and the number of rabbits.
    Output: The program will output calculations to the user. The
    calculations include how much food is needed per day to grow
    a zebra/rabbit, how much food they will need to keep the
    zebra/rabbit(s) alive per month as well as the total. The user
    is presented with a table listing out the data.
*/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    // Initialize constants, as well as user inputted variables.
    const double BABY_ZEBRA = 5;
    const double ZEBRA_GROWTH_RATE = .05;

    const double LITTLE_RABBIT = .5;
    const double RABBIT_GROWTH_RATE = .1;

    int numOfMonth = 0;
    int numOfZebra = 0;
    int numOfRabbit = 0;

	//Print Zoo Banner
	cout << "+---------------------------------------------------------------------------+ \n"
		 << "|    UU     UU  NNNN     NN  LL       VV      VV         CCCCCC    SSSSSSSS | \n"
		 << "|   /UU    /UU /NN/NN   /NN /LL      /VV     /VV        CC////CC  SS//////  | \n"
		 << "|   /UU    /UU /NN//NN  /NN /LL      /VV     /VV       CC    //  /SS        | \n"
		 << "|   /UU    /UU /NN //NN /NN /LL      //VV    VV       /CC        /SSSSSSSSS | \n"
		 << "|   /UU    /UU /NN  //NN/NN /LL       //VV  VV        /CC        ////////SS | \n"
		 << "|   /UU    /UU /NN   //NNNN /LL        //VVVV         //CC    CC        /SS | \n"
		 << "|   //UUUUUUU  /NN    //NNN /LLLLLLLL   //VV           //CCCCCC   SSSSSSSS  | \n"
		 << "|    ///////   //      ///  ////////     //              //////   ////////  | \n"
		 << "|                                                                           | \n"
		 << "|             ZZZZZZZZ           OOOOOOO         OOOOOOO                    | \n"
		 << "|                 /ZZ           OO/////OO       OO/////OO                   | \n"
		 << "|                /ZZ           OO     //OO     OO     //OO                  | \n"
		 << "|               /ZZ           /OO      /OO    /OO      /OO                  | \n"
		 << "|              /ZZ            /OO      /OO    /OO      /OO                  | \n"
		 << "|             /ZZ             //OO     OO     //OO     OO                   | \n"
		 << "|           //ZZZZZZZZZZ       //OOOOOOO       //OOOOOOO                    | \n"
		 << "|           ///////////         ///////         ///////                     | \n"
		 << "+---------------------------------------------------------------------------+ \n\n";

    cout << "\n*****************************************************************************" <<endl;
    cout << "             Welcome to the UNLV Zoo - Food Supply Department!" <<endl;
    cout << "*****************************************************************************\n" <<endl;

    cout << "The food/day for a baby zebra is constant (lbs): " << 
    static_cast<int>(BABY_ZEBRA) << endl;
    cout << "The food/day for a baby rabbit is constant (lbs): " << 
    LITTLE_RABBIT << endl;

    // Set precision to prepare program to output expected data
    cout << fixed << setprecision(2);

	// Ask the user for the number of months of growth to calculate
    cout << "After growing the number of months: \n" << "**";
    cin >> numOfMonth;

    // Calculate food requirements for zebras and rabbits, as well 
    // as zebra to rabbit ratio
    double updatedZebra = BABY_ZEBRA * pow(1 + ZEBRA_GROWTH_RATE,
    numOfMonth);
    double updatedRabbit = LITTLE_RABBIT * pow(1 + RABBIT_GROWTH_RATE,
    numOfMonth);
    double zebraVsRabbit = floor(updatedZebra / updatedRabbit);

	// Report the updated food requirements for zebras and rabbits as
    // well as the zebra to rabbit ratio
    cout << "The food/day for a bigger zebra is: " << updatedZebra
    << endl;
    cout << "The food/day for a bigger rabbit is: " << updatedRabbit
    << endl;
    cout << "Zebra eats " << static_cast<int>(zebraVsRabbit) <<
    " times as much as rabbits\n\n";

	// Ask the user for the number of zebras and rabbits to feed
    cout << "The number of Zebra: \n**";
    cin >> numOfZebra;
    cout << "The number of Rabbit: \n**";
    cin >> numOfRabbit;


    // Calculate individual amount of food needed for zebra and rabbit
    // by x amount of months, as well as total amount needed
    double zebraTotalFood = updatedZebra * numOfZebra;
    double rabbitTotalFood = updatedRabbit * numOfRabbit;
    double totalFood = zebraTotalFood + rabbitTotalFood;

    // Report the updated food requirements for zebras and rabbits by x
    // amount of months, as well as total amount needed.
    cout << "For Zebras, total food/day in " << numOfMonth << 
    " months is: " << zebraTotalFood << endl;
    cout << "For Rabbits, total food/day in " << numOfMonth << 
    " months is: " << rabbitTotalFood << endl;
    cout << "Overall, total food/day in " << numOfMonth << 
    " months is: " << totalFood << endl;
    
	//Print formatted results
    cout << setfill(' ') << fixed << setprecision(2)
	     << "\n/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\\n"
		 << "|" << setw(40) << "|\n"
		 << "|             UNLV CS Zoo              |\n"
		 << "|         4505 S Maryland Pkwy         |\n"
		 << "|          Las Vegas,NV 89154          |\n"
		 << "|            (702) 895-3011            |\n"
		 << "|" << setw(40) << "|\n"
         << "|" << setw(40) << "|\n"
         << "|" << left << " Baby Zebra(lbs/d):" << setw(18) << right << BABY_ZEBRA << " |\n"
         << "|" << left << " Growth Rate(month):" << setw(16) << right << ZEBRA_GROWTH_RATE*100 << "% |\n"
         << "|" << left << " Baby Rabbit(lbs/d):" << setw(17) << right << static_cast<double>(LITTLE_RABBIT) << " |\n"
         << "|" << left << " Growth Rate(month):" << setw(16) << right << RABBIT_GROWTH_RATE*100 << "% |\n"
         << "|" << setw(40) << "|\n"
         << "|" << left << " Growth Month:" << setw(23) << right << numOfMonth << " |\n"
         << "|" << left << " Grown Zebra(lbs/d):" << setw(17) << right << updatedZebra << " |\n"
         << "|" << left << " Grown Rabbit(lbs/d):" << setw(16) << right << updatedRabbit << " |\n"
         << "|" << setw(40) << "|\n"
         << "|" << left << " Zebra amount:" << setw(23) << right << numOfZebra << " |\n"
         << "|" << left << " Rabbit amount:" << setw(22) << right << numOfRabbit << " |\n"
         << "|" << left << " Total Food(lbs/d):" << setfill('*') << setw(18) << right << ceil(totalFood) << " |\n"
         << "|" << setfill(' ') << setw(40) << "|\n"
         << "\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/"<< endl;

    return 0;
 }