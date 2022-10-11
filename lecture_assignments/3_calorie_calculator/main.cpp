/*
    Name: Harrison Atherton, 5005662748, 1016, #3
    Description: A program that calculates the necessary amount of
    calories needed to maintain, lose, or gain weight.
    Input: User is prompted with several questions in regards to
    height, weight, age, activity level, and gender.
    Output: The program will store user inputs to variables, and
    calculate the necessary amount of calories needed to maintain,
    lose, or gain weight.
*/

#include <iostream>
#include <cmath>
using namespace std;


int main(){

    // Initialize variables
    int age = 0;
    int weight = 0;
    int height = 0;
    int activity = 0;
    char gender = '\0';
    double bmr = 0;
    double amr = 0;

    // Template header
    cout << endl
    <<".@  @, (&           .(%(.               *#(,              .   \n"
    <<"(@  @( &@      .@@@@@@@@@@@@@#     @@@@@@@@@@@@@#        @@@. \n"
    <<"(@  @( &@    /@@@@@@@@@@@@@@@@@@&@@@@@@@@@@@@@@@@@@    .@@@@@,\n"
    <<"(@@@@@@@@   @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@   .@@@@@,\n"
    <<"(@@@@@@@@   @@@@@@@@@@@@@@@@  .@@@@@@@@@@@@@@@@@@@@@(  .@@@@@,\n"
    <<" @@@@@@@#   @@@@@@@@@@@@@@      @@@@@@@@@@@@@@@@@@@@/  .@@@@@,\n"
    <<"    @@.     &@@@@@@@@@@@.   @@   @@@@@@@@@@@@@@@@@@@   .@@@@@,\n"
    <<"    @@.                   @@@@@   @@@@                 .@@@@@,\n"
    <<"    @@.       #@@@@@@@@@@@@@@@@@   &#  .@@@@@@@@@@     .@@@@@,\n"
    <<"    @@.         @@@@@@@@@@@@@@@@@.    %@@@@@@@@@#         ,@@,\n"
    <<"    @@.           @@@@@@@@@@@@@@@@,  @@@@@@@@@%           ,@@.\n"
    <<"    @@.             %@@@@@@@@@@@@@@@@@@@@@@@.             ,@@,\n"
    <<"    @@.                %@@@@@@@@@@@@@@@@@,                ,@@,\n"
    <<"    @@.                    &@@@@@@@@@,                    ,@@,\n"
    <<"    @@.                     &@@@@@,                       ,@@,\n"
    <<endl
    <<"             Welcome to the Calorie Calculator App\n"; 
    
    // Prompt user for age, store age in variable
    cout << "To get started, enter your age in years:\n";
    cin >> age;
    if(cin.fail()) // Failure if statement and prompt
    {
        cout << "Invalid Age!";
        return 0;
    } if(age < 10 || age > 79){
        cout << "Age must be between 10 and 79 years!";
        return 0;
    }

    // Prompt user for weight, store weight in variable
    cout << "Enter weight in lbs:\n";
    cin >> weight;
    if(cin.fail()) // Failure if statement and prompt
    {
        cout << "Invalid Weight!";
        return 0;
    } if(weight < 50 || weight > 400){
        cout << "Weight must be between 50 lbs and 400 lbs!";
        return 0;
    }

    // Prompt user for height, store height in variable
    cout << "Enter height in inches:\n";
    cin >> height;
    if(cin.fail()) // Failure if statement and prompt
    {
        cout << "Invalid Height!";
        return 0;
    } if(height < 40 || height > 90){
        cout << "Heigh must be between 40\" and 90\"!";
        return 0;
    }

    // If statement to determine gender of user, which is then used
    // to transfer to the bmr calculation
    cout << "Enter 'M' for male or 'F' for female:\n";
    cin >> gender;
    if(toupper(gender) == 'M'){
        bmr = 65 + (6.2 * weight) + (12.7 * height) - (6.8 * age);
    } else if(toupper(gender) == 'F'){
        bmr = 655 + (4.3 * weight) + (4.3 * height) - (4.7 * age);
    } else{
        cout << "Invalid entry!";
        return 0;
    }

    // Prompt user for their activity level, with 5 options
    cout << "Select activity level:\n";
    cout << "1. Inactive: little to no exercise.\n"
    << "2. Lightly active: Exercising 1 - 3 days/week\n"
    << "3. Moderately active: Exercising 3 - 5 days/week\n"
    << "4. Active: Exercising 6 - 7 days/week\n"
    << "5. Very active: Exercising hard 6 - 7 days/week\n";

    cin >> activity;

    // Switch statement to determine their final amr
    switch(activity){
        case 1:
            amr = bmr * 1.2;
            break;
        case 2:
            amr = bmr * 1.375;
            break;
        case 3:
            amr = bmr * 1.55;
            break;
        case 4:
            amr = bmr * 1.725;
            break;
        case 5:
            amr = bmr * 1.9;
            break;
        default:
            cout << "Invalid activity level!";
            return 0;
    }

    // Display results needed to maintain, lose, and gain weight.
    cout << "To maintain your current weight, you need to consume an" 
    << " average of " << round(amr) << " calories/day.\n";
    cout << "To lose weight, you need to consume an average of " 
    << round(amr * .8) << " calories/day.\n";
    cout << "To gain weight, you need to consume an average of "
    << round(amr * 1.2) << " calories/day.\n\n";

    cout << "*Disclaimer: always consult your doctor before" << 
    " committing to a diet plan\n";

    return 0;
}
