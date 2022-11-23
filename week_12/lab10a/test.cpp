#include <iostream>
#include <iomanip>
using namespace std;

struct studentType
{
    string firstName;
    string lastName;
    int grade;
    char letterGrade;
};

void getStudentData(studentType&);
void getLetterGrade(studentType&);
void printStudentData(studentType&);

int main()
{
    studentType myStudent;
    getStudentData(myStudent);
    getLetterGrade(myStudent);
    printStudentData(myStudent);
}

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

void getLetterGrade(studentType& student)
{
    do
    {
        cout << endl << "Enter a grade\n**";
        cin >> student.grade;

        if(cin.fail())
        {
            cout << endl << "Error: Invalid grade\n";
            cin.clear();
            cin.ignore(200, '\n');
        }
        else if(student.grade < 0 || student.grade > 4)
        {
            cout << endl << "Error: Invalid grade\n";
        }

    } while (student.grade < 0 || student.grade > 4);

    switch(student.grade)
    {
        case 0:
            student.letterGrade = 'F';
            break;
        case 1:
            student.letterGrade = 'D';
            break;
        case 2:
            student.letterGrade = 'C';
            break;
        case 3:
            student.letterGrade = 'B';
            break;
        case 4:
            student.letterGrade = 'A';
            break;
    }
}

void printStudentData(studentType& student)
{
    cout << endl << "Data entered" << endl
         << "  student.firstName   = " << student.firstName << endl
         << "  student.lastName    = " << student.lastName << endl
         << "  student.grade       = " << student.grade << endl
         << "  student.letterGrade = " << student.letterGrade << endl;
}