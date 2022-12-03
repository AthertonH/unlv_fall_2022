/*
    Name: Harrison Atherton, 5005662748, 1016, #7
    Description: A database that receives input from users. A table will be 
	printed to the user depending on what tables are within the databaes, and
	what the headers are within the databse
    Input: The user is able to enter different commands that can be executed.
	If the command does not meet the proper condition, the user will be noticed
	and the program will continue until it is told to quit
    Output: A table that includes all other tables, and keeps track of what tables
	have been created.

*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <stdio.h>

#include <algorithm>
#include <cctype>
#include <string>

using namespace std;

const string VALID = "TEST PASSED";

const string USER = "meowmin";
const string PASS = "1w@ntch1cken";

const string COMMAND_PROMPT = ">";
const string COMMAND_DELIMITER = " ";

const string QUIT_CMD = "quit";
const string SHOW_CMD = "show";
const string CREATE_CMD = "create";
const string DELETE_CMD = "delete";

const string TABLE_FILETYPE = ".csv";
const string TABLE_FILE_DIRECTORY = "data/";
const string TABLES_TABLE = "data/tables.csv";

const string SHOW_ARG_1 = "tables";

const string USAGE_MSG = "Usage: ./a.out <username> <password>\n";
const string WELCOME_MSG = "Welcome ";

const string VALID_ARG_MSG = "";
const string QUIT_ARG_CNT_MSG = "QUIT Error: invalid argument count";
const string SHOW_ARG_CNT_MSG = "SHOW Error: invalid argument count";
const string CREATE_ARG_CNT_MSG = "CREATE Error: invalid argument count";
const string DELETE_ARG_CNT_MSG = "DELETE Error: invalid argument count";

const string TABLE_CREATE_SUCCESS_MSG = " table created successfully";
const string TABLE_DELETE_SUCCESS_MSG = " table removed successfully";
const string INVALID_CREDENTIALS_MSG = "Error: invalid credentials\n";
const string INV_CMD_MSG = "Error: invalid command name";
const string SHOW_INV_OPT_MSG = "SHOW Error: invalid option";
const string CREATE_INV_TABLE_NAME_MSG = "CREATE Error: table name should only contain"
" alpha numeric characters, '-', or '_'";
const string CREATE_EXISTS_MSG = "CREATE Error: table already exists";
const string CREATE_INV_HEADERS_MSG = "CREATE Error: column names should be separated"
" by delimiter and should only contain alpha numeric characters, '-', or '_'";
const string DELETE_UNDELETABLE_MSG = "DELETE Error: table cannot be deleted";
const string DELETE_INV_TABLE_NAME_MSG = "DELETE Error: invalid table name";

void header();
string toLower(string);
void getCredentials(int, char const *[], string&, string&);
bool validateCredentials(string, string);
bool validateCharacters(string);
void removeString(string, string);
vector<string> getInput();
string validateArguments(vector<string> args);
void executeCommand(vector<string> args);
void commandLoop();

int main(int argc, char const *argv[]) 
{
	string user = "", pass = "";
	if(argc != 3) cout << USAGE_MSG;

	// Ensure that the users credentials are valid
	getCredentials(argc, argv, user, pass);

	// If the credentials are valid, run the program
	if (validateCredentials(user, pass)) 
	{
        header();
		commandLoop();
    }

	return 0;
}

// used for section 1
// prints header
void header() 
{
	cout << "+---------------------------------------------------------------------+\n"
		 << "|   __   __  _______  _______  _     _    _______  _______  ___       |\n"
		 << "|  |  |_|  ||       ||       || | _ | |  |       ||       ||   |      |\n"
		 << "|  |       ||    ___||   _   || || || |  |  _____||   _   ||   |      |\n"
		 << "|  |       ||   |___ |  | |  ||       |  | |_____ |  | |  ||   |      |\n"
		 << "|  |       ||    ___||  |_|  ||       |  |_____  ||  |_|  ||   |___   |\n"
		 << "|  | ||_|| ||   |___ |       ||   _   |   _____| ||      | |       |  |\n"
		 << "|  |_|   |_||_______||_______||__| |__|  |_______||____||_||_______|  |\n"
		 << "|                                                               v1.0.0|\n"
		 << "+---------------------------------------------------------------------+\n";
}

// Used for section 2
// lowercases string and returns it
string toLower(string s) 
{
	for (char &x:s) x = static_cast<char>(tolower(x));
	return s;
}

// Used for section 3
// Prints the csv at the passed file path
bool printTable(string file) 
{
	string current = "", rest = "", delimiter = ",";
	int rowCnt = 0;
	ifstream toShow(file);
	getline(toShow, current);
	int colCnt = count(current.begin(), current.end(), delimiter[0]) + 1;
	toShow.seekg(0);
	vector<unsigned int> widths(colCnt, 0);
	while(getline(toShow, rest)) 
	{
		for (int i = 0; i < colCnt; i++)
		{
			current = rest.substr(0, rest.find(delimiter));
			rest = rest.erase(0, rest.find(delimiter) + 1);
			if (current.size() > widths[i])
				widths[i] = current.size();
		}
		rowCnt++;
	}
	if(rowCnt > 1) 
	{
		toShow.clear();
		toShow.seekg(0);
		cout << file.substr(file.find("data/") + 5, file.length() - 9) << " table:\n";
		cout << setfill('-') << right;
		for (int i = 0; i < colCnt; i++) cout << "+" << setw(widths[i] + 3);
		cout << "+" << endl;
		getline(toShow, current);
		vector<string> ret;
		string token = "";
		while(current.find(delimiter) != string::npos) 
		{
			token = current.substr(0, current.find(delimiter));
			current = current.erase(0, current.find(delimiter) + delimiter.length());
			ret.push_back(token);
		}
		ret.push_back(current);
		cout << setfill(' ') << left;
		for (unsigned int i = 0; i < widths.size(); i++)
			cout << "| " << setw(widths[i]) << ret[i] << " ";
		cout << "|" << endl;
		cout << setfill('-') << right;
		for (int i = 0; i < colCnt; i++)
			cout << "+" << setw(widths[i] + 3);
		cout << "+" << endl;
		while(getline(toShow, current)) 
		{
			ret.clear();
			while(current.find(delimiter) != string::npos) 
			{
				token = current.substr(0, current.find(delimiter));
				current = current.erase(0, current.find(delimiter) + delimiter.length());
				ret.push_back(token);
			}
			ret.push_back(current);
			cout << setfill(' ') << left;
			for (unsigned int i = 0; i < widths.size(); i++)
				cout << "| " << setw(widths[i]) << ret[i] << " ";
			cout << "|" << endl;
		}
		cout << setfill('-') << right;
		for (int i = 0; i < colCnt; i++)
			cout << "+" << setw(widths[i] + 3);
		cout << "+" << endl;
		cout << rowCnt - 1 << " row(s) in set.";
		return true;
	}
	return false;
}

// Fill this function out for section 1.1
void getCredentials(int argc, char const *argv[], string &user, string &pass) 
{
	// argv[1] represents username
	user = argv[1];
	// argv[2] represents password
	pass = argv[2];
}

// Fill this function out for section 1.2
bool validateCredentials(string u, string p) 
{
	// Ensure the the USER and PASS are correct, return true
	if(u == USER && p == PASS)
	{
		cout << WELCOME_MSG + USER + "\n";
		return true;
	}
	// Print out invalid credentials message to terminal, return false
	cout << INVALID_CREDENTIALS_MSG;
	return false;
}

bool validateCharacters(string testString)
{
    for(unsigned int i = 0; i < testString.length(); i++)
    {
        // Looping through the name to validate characters
        if(testString[i] < 96 || testString[i] > 123)
			return true;
		if(testString[i] != '-')
			return true;
        if(testString[i] != '_')  
			return true;
        if(testString[i] == ',' && testString[i+1] == ',')
			return true;
    }
    return false;
}

void removeString(string path, string eraseLine) 
{
    ifstream fileReader;
	ofstream fileWriter;
    fileReader.open(path);
	string line = "";
    

    // Opening a temporary file
    fileWriter.open("temporaryFile.csv");

    while (getline(fileReader, line)) 
	{
		// Writing all lines except the one we're deleting
        if (line != eraseLine)
        fileWriter << line << endl;
	}
        
	// Renaming the temporary file to the original file
	const char *newFile = path.c_str();
    remove(newFile);
    rename("temporaryFile.csv", newFile);

    // Closing the files
    fileWriter.close();
    fileReader.close();
}

// 2.1 add getInput() function
vector<string> getInput()
{
	cout << COMMAND_PROMPT;
	vector<string> arguments {};
	string userInput = "";

	getline(cin, userInput);
	// Convert user inputted string into all lowercase
    // Split the strings using stringstream
    stringstream s_stream(userInput);
    while(s_stream.good())
    {
        string substr;
        getline(s_stream, substr, ' ');
        arguments.push_back(substr);
    }
    // Return individual strings
	return arguments;
}

// 2.1 add validateArguments(vector<string>) function
string validateArguments(vector<string> args)
{
	ifstream fileReader;
    string fileName;


	// ****QUIT COMMAND****
    if(toLower(args[0]) == QUIT_CMD)
    {
        if(args.size() == 1)
            return VALID_ARG_MSG;
        return QUIT_ARG_CNT_MSG;
	}

	// ****CREATE CMD COMMAND****
	if(toLower(args[0]) == CREATE_CMD)
	{
		if(args.size() == 3)
		{
			// If characters are invalid, try to open the file
			if(validateCharacters(args[1]) == true)
				return CREATE_INV_TABLE_NAME_MSG;
			// Try to open the file
			fileReader.open(TABLE_FILE_DIRECTORY + args[1] + TABLE_FILETYPE);
			// If the file successfully opens, that means it exists
			if(fileReader.is_open())
				return CREATE_EXISTS_MSG;
			// If it doesn't open, then it is valid and can be made
			// If the <attribute_list> contains a ',' before or at the end
			// of the command, a message will be outputted to the user
			if(args[2][0] == ',' || args[2].back() == ',')
				return CREATE_INV_HEADERS_MSG;
			// Iterate through <attribute_list> to verify the characters
			// are valid
			if(validateCharacters(args[2]) == true)
				return CREATE_INV_HEADERS_MSG;
			// **Else, all flags are valid and the table can be created**
			return VALID_ARG_MSG;
		}
		return CREATE_ARG_CNT_MSG;
	}

    // ****SHOW ALL TABLES COMMAND****
    if(toLower(args[0]) == SHOW_CMD)
    {
        // If size of show cmd is 2
        if(args.size() == 2)
        {
            // Valid
            if(toLower(args[1]) == SHOW_ARG_1)
                return VALID_ARG_MSG;
            // Invalid
            return SHOW_INV_OPT_MSG;
        }
        // If size of show cmd is not 2
        return SHOW_ARG_CNT_MSG;
    }

    // ****DELETE A TABLE****
    if(toLower(args[0]) == DELETE_CMD)
    {
        ifstream deleteTable;
        if(args.size() == 2)
        {
            if(args[1] + TABLE_FILETYPE == "tables.csv" )
                return DELETE_UNDELETABLE_MSG;
            
            // Try to open the table
            deleteTable.open(TABLE_FILE_DIRECTORY + args[1] + TABLE_FILETYPE);
            // If the table opens return Valid
            if(deleteTable.is_open())
            {
                deleteTable.close();
                return VALID_ARG_MSG;
            }
            // If the table does not open, return invalid
            return DELETE_INV_TABLE_NAME_MSG;
        }
        return DELETE_ARG_CNT_MSG;
    }

	// ****INVALID COMMAND MESSAGE****
	return INV_CMD_MSG;
}

// 2.1 add executeCommand(vector<string>) function
void executeCommand(vector<string> args)
{
	// Main file to write to
    ofstream fileWriter;
	// Name of the files that we've created
    ofstream fileWriterDatabase;

    // ****QUIT THE PROGRAM****
    if((toLower(args[0]) == QUIT_CMD) && (args.back() == VALID_ARG_MSG))
	{
		exit(0);
	}
	// Showing what happens inside the function
	cout << args.back();

    // ****WRITE THE TABLE****
    if((toLower(args[0]) == CREATE_CMD) && (args.back() == VALID_ARG_MSG))
    {
		// Variables
        string fileName = TABLE_FILE_DIRECTORY + args[1] + TABLE_FILETYPE;
		vector<string> headers = {};
		stringstream s_stream(args[2]);

        // Seperate args[2] from commas
    	while(s_stream.good())
    	{
        	string substr;
        	getline(s_stream, substr, ',');
        	headers.push_back(substr);
    	}

		// Open the new file
        fileWriter.open(fileName);

		// Write the headers to the file
		for(unsigned int i = 0; i < headers.size(); i++)
			fileWriter << headers[i] << endl;

		// Write the name of the table to the tables file
        fileWriterDatabase.open(TABLES_TABLE, ios_base::app);
        fileWriterDatabase << args[1] << endl;
        cout << args[1] << TABLE_CREATE_SUCCESS_MSG;

        // Close the files
        fileWriter.close();
        fileWriterDatabase.close();
    }

    // ****PRINT THE TABLE****
    if((toLower(args[0]) == SHOW_CMD) && (args.back() == VALID_ARG_MSG))
        printTable(TABLES_TABLE);

    // ****DELETE THE TABLE****
    if((toLower(args[0]) == DELETE_CMD) && (args.back() == VALID_ARG_MSG))
	{
		string filepath = "data/" + args[1] + ".csv";
		// Remove line from table
		removeString("data/tables.csv", args[1]);
		// Remove the table
		remove(filepath.c_str());
		cout << args[1] << TABLE_DELETE_SUCCESS_MSG;
	}
}

// 2.1 add commandLoop() function
// Main logic of program
void commandLoop()
{
	do
	{
		vector<string> arguments = getInput();
		string newArgument = validateArguments(arguments);
		arguments.push_back(newArgument);
		executeCommand(arguments);
		cout << endl;
	} while (true);
}

/*
	DO NOT REMOVE
	
	Copyright 2022 Alex St. Aubin. All Rights Reserved.

	Unauthorized reproductions of this handout and any accompanying code
	are strictly forbidden under Nevada State and US Federal law.
*/

// GO to where the file is
// g++ -g test.cpp
// gdb a.out
// (for break point type break and then the line number)
// r (command line arguments)