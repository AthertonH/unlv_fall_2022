#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <stdio.h>

#include <algorithm>
#include <cctype>
#include <string>

using namespace std;

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
vector<string> getInput();
string validateArguments(vector<string> args);
void executeCommand(vector<string> args);
void commandLoop();




int main(int argc, char const *argv[]) 
{
	string user = "", pass = "";
	if(argc != 3) cout << USAGE_MSG;

	getCredentials(argc, argv, user, pass);

	if (validateCredentials(user, pass)) 
	{
        header();
		commandLoop();
		
        

        // 2.1 call the loop to get commands from the user
	    // YOUR CODE HERE



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
		cout << rowCnt - 1 << " row(s) in set.\n";
		return true;
	}
	return false;
}

// Fill this function out for section 1.1
void getCredentials(int argc, char const *argv[], string &user, string &pass) 
{
	user = argv[1];
	pass = argv[2];
	cout << "User: " << argv[1] << endl << "Pass: " << argv[2] << endl;
}

// Fill this function out for section 1.2
bool validateCredentials(string u, string p) 
{
	if(u == USER && p == PASS)
	{
		cout << WELCOME_MSG + USER + "\n";
		return true;
	}
	else
	{
		cout << INVALID_CREDENTIALS_MSG;
		return false;
	}
}

// 2.1 add getInput() function
vector<string> getInput()
{
	vector<string> arguments {};
	string userInput = "";

	do
	{
		cout << COMMAND_PROMPT;
		getline(cin, userInput);

		// Convert user inputted string into all lowercase
		toLower(userInput);

		if(userInput == "quit")
			break;
		arguments.push_back(userInput);
		
	} while (true);
	
	return arguments;
}



// 2.1 add validateArguments(vector<string>) function
string validateArguments(vector<string> args)
{
	// LOOP USED FOR TESTING
	cout << "Arguments: ";
	for(int i = 0; i < args.size(); i++)
	{
		if(args[i] == args.back())
			cout << args[i];
		else
			cout << args[i] << ", ";
	}
	cout << endl;
	// LOOP USED FOR TESTING

	return "";

}



// 2.1 add executeCommand(vector<string>) function
void exectueCommand(vector<string> args)
{
	cout << args[0];
}



// 2.1 add commandLoop() function
void commandLoop()
{
	vector<string> arguments = {};

	validateArguments(getInput());

}

// 2.3 TO DO THIS, ARGUMENTS MUST BE PASSED TO THE EXECUTECOMMAND FUNCTION SO THE
// COMMAND CAN BE EXECTUED

/*
	DO NOT REMOVE
	
	Copyright 2022 Alex St. Aubin. All Rights Reserved.

	Unauthorized reproductions of this handout and any accompanying code
	are strictly forbidden under Nevada State and US Federal law.
*/
