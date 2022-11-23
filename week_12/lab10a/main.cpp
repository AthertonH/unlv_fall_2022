/*
    Name: Harrison Atherton, 5005662748, 1019, #10A
    Description: A simple program using structure and functions to print out
    the first name, last name, and grade of a student
    Input: User will be prompted to enter in a first name, last name, and number for
    their letter grade.
    Output: The terminal will output the students first name, last name, number they 
    entered, and the equivalent letter grade.

    What does a storm cloud wear under his raincoat?
    Thunderwear.

    Have you ever had a dream that you, um, you had, your, you- you could, 
    you’ll do, you- you wants, you, you could do so, you- you’ll do, you could- 
    you, you want, you want them to do you so much you could do anything?
*/

#include <iostream>
using namespace std;

// Initialize the structure
struct studentType
{
    string firstName;
    string lastName;
    int grade;
    char letterGrade;
};

// Call prototypes after the structure has been initialized
void getStudentData(studentType&);
void getLetterGrade(studentType&);
void printStudentData(studentType&);

// Initialize main and call the functions
int main()
{
    studentType myStudent;
    getStudentData(myStudent);
    getLetterGrade(myStudent);
    printStudentData(myStudent);

    return 0;
}

// Function to receive the first and last name of the student
void getStudentData(studentType& student)
{
    string name = "";

    cout << "Enter a first name\n**";
    cin >> name;
    student.firstName = name;
    cout << endl << "Enter a last name\n**";
    cin >> name;
    student.lastName = name;
}

// Function to receive the letter grade of the student
void getLetterGrade(studentType& student)
{
    int grade = 0;

    do
    {
        cout << endl << "Enter a grade\n**";
        cin >> grade;

        // Shout out to Caelan for helping me with the cin.fail() ._.
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(200, '\n');
            cout << endl << "Error: Invalid grade";
            continue;
        }
        if(grade < 0 || grade > 4)
        {
            cout << endl << "Error: Invalid grade";
            continue;
        }
        break;
    } while (true);

    // Switch statement to input the letter grade in the structure
    switch(grade)
    {
        case 0:
            student.letterGrade = 'F';
            student.grade = 0;
            break;
        case 1:
            student.letterGrade = 'D';
            student.grade = 1;
            break;
        case 2:
            student.letterGrade = 'C';
            student.grade = 2;
            break;
        case 3:
            student.letterGrade = 'B';
            student.grade = 3;
            break;
        case 4:
            student.letterGrade = 'A';
            student.grade = 4;
            break;
    }
}

// Function to print student data
void printStudentData(studentType& student)
{
    cout << endl << "Data entered" << endl
         << "  student.firstName   = " << student.firstName << endl
         << "  student.lastName    = " << student.lastName << endl
         << "  student.grade       = " << student.grade << endl
         << "  student.letterGrade = " << student.letterGrade << endl;
}
