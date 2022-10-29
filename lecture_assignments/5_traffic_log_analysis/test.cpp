// /* Name: JOSHUA_GUTIERREZ, SECTION_1005, ASSIGNMENT_#5
// Description: Recording traffic violations based on weight and speed while outputting
// violations to separate output file
// Input: User input for file name
// Output: Output number of violations and file output to log violations
// */
// #include <iostream>
// #include <fstream>
// #include <string>
// using namespace std;

// int main()
// {
//     //Initialize variables
//     const int ARRAY_SIZE = 1000;
//     string plate[ARRAY_SIZE] = {""};
//     string date[ARRAY_SIZE] = {""};
//     string time[ARRAY_SIZE] = {""};
//     string weight = "";
//     string speed = "";
//     int weight2[ARRAY_SIZE] = {};
//     int speed2[ARRAY_SIZE] = {};
//     int count = 0;
//     int speeding = 0;
//     bool flag = true;

//     string dateBefore = " ";
//     string fileName = " ";
//     ifstream iFile;
//     ofstream oFile;


//     do
//     {
//         cout << "Open File: ";
//         getline(cin, fileName);
//         cout << endl;

//         iFile.open(fileName);
//         if(!iFile.is_open())
//         {
//             iFile.clear();
//             iFile.ignore(100, '\n');
//             cout << "Could not open " << fileName << endl;
//         }

//     }while(!iFile.is_open());

//     while(!iFile.eof())
//     {
//         getline(iFile, date[count], ',');
//         getline(iFile, plate[count], ',');
//         getline(iFile, time[count], ',');
//         getline(iFile, weight, ',');
//         getline (iFile, speed, '\n');
//         weight2[count] = stoi(weight);
//         speed2[count] = stoi(speed);

//         count++;
//     }

//     for(int i = 0; i < count; i++)
//     {
//         flag = false;
//         if(weight2 < 5000 && speed2 > 45)
//         {
//             flag = true;
//         }
//         else if(weight2 > 5000 && speed2 > 30)
//         {
//             flag = true;
//         }
//         if(flag)
//         {
//             if(speeding==0)
//             {
//                 dateBefore = date[i];
//                 oFile.open("["+date[i]+"] Report.txt");
//             }
//             else if(dateBefore == date[i])
//             {
//                 oFile << "["+time[i]+"] " << plate[i] << endl;
//             }
//             else
//             {
//                 oFile.close();
//                 oFile.open("["+date[i]+"] Report.txt");
//                 oFile << "["+time[i]+"] " << plate[i] << endl;
//                 dateBefore = date[i];
//             }
//         } count++;
//     }

//     iFile.close();
//     oFile.close();

//     cout << speeding << " violations logged.";

//     return 0;

// }