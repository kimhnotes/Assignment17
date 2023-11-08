#pragma once
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

//PreCondition: spaces (boolean true or false)
//PostCondition: returns a string including space character(s) or without space character 
string inputString(string prompt, bool spaces)
{
	string input = "";

	cout << prompt;
	if (spaces)
		getline(cin, input);
	else
	{
		cin >> input;
		cin.clear();
		cin.ignore(999, '\n');
	}
	return input;
}

// Preconditions: empty (boolean true or false)
// Postconditions: returns a string that is not empty (empty = false) or empty (empty = true)
string inputString(string prompt, bool spaces, bool empty)
{
	string input = "";
	do
	{
		cout << prompt;
		if (spaces)
			getline(cin, input);
		else
		{
			cin >> input;
			cin.clear();
			cin.ignore(999, '\n');
		}
		if (empty && input == "")
			cout << "ERROR: Invalid input. Must not be empty.\n";
		else
			break;
	} while (true);
	return input;
}

//PreCondition: NA
//PostCondition: returns a valid state abbreviation
string inputStateString(string prompt, bool spaces, bool empty, bool state)
{
	string input = "";
	string states[50] = { "AL", "AK", "AZ", "AR", "CA", "CO", "CT", "DE", "FL", "GA",
						  "HI", "ID", "IL", "IN", "IA", "KS", "KY", "LA", "ME", "MD",
						  "MA", "MI", "MN", "MS", "MO", "MT", "NE", "NV", "NH", "NJ",
						  "NM", "NY", "NC", "ND", "OH", "OK", "OR", "PA", "RI", "SC",
						  "SD", "TN", "TX", "UT", "VT", "VA", "WA", "WV", "WI", "WY" };
	do
	{
		cout << prompt;
		if (spaces)
			getline(cin, input);
		else
		{
			cin >> input;
			cin.clear();
			cin.ignore(999, '\n');
		}
		if (empty && input == "")
			cout << "ERROR: Invalid input. Must not be empty.\n";
		else
		{
			bool found = false;
			for (int i = 0; i < 50; i++)
				if (input == states[i])
				{
					found = true;
					break;
				}
			if (found)
				break;
			else
				cout << "ERROR: Invalid input. Must be a valid state abbreviation.\n";
		}
	} while (true);
	return input;
}

//PreCondition: valid 5 digit zip code
//PostCondition: returns a valid zip code
string inputZipString(string prompt, bool spaces, bool empty, bool zip)
{
	string input = "";
	do
	{
		cout << prompt;
		if (spaces)
			getline(cin, input);
		else
		{
			cin >> input;
			cin.clear();
			cin.ignore(999, '\n');
		}
		if (empty && input == "")
			cout << "ERROR: Invalid input. Must not be empty.\n";
		else
		{
			if (zip && input.length() == 5)
			{
				bool found = true;
				for (int i = 0; i < 5; i++)
					if (!isdigit(input.at(i)))
					{
						found = false;
						break;
					}
				if (found)
					break;
				else
					cout << "ERROR: Invalid input. Must be a valid zip code.\n";
			}
			else
				cout << "ERROR: Invalid input. Must be a valid zip code.\n";
		}
	} while (true);
	return input;
}

//PreCondition: valid 10 digit phone number
//PostCondition: returns a valid phone number
string inputPhoneString(string prompt, bool spaces, bool empty, bool phone)
{
	string input = "";
	do
	{
		cout << prompt;
		if (spaces)
			getline(cin, input);
		else
		{
			cin >> input;
			cin.clear();
			cin.ignore(999, '\n');
		}
		if (empty && input == "")
			cout << "ERROR: Invalid input. Must not be empty.\n";
		else
		{
			if (phone && input.length() == 10)
			{
				bool found = true;
				for (int i = 0; i < 10; i++)
					if (!isdigit(input.at(i)))
					{
						found = false;
						break;
					}
				if (found)
					break;
				else
					cout << "ERROR: Invalid input. Must be a valid phone number.\n";
			}
			else
				cout << "ERROR: Invalid input. Must be a valid phone number.\n";
		}
	} while (true);
	return input;
}

//PreCondition: valid string of options
//PostCondition: returns an uppercase  of the option (char)
char inputChar(string prompt, string options)
{
	char input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			cout << "ERROR: Invalid input. Must be a character type.\n";
			cin.clear();
			cin.ignore(999, '\n');
		}
		else
		{
			bool found = false;
			for (int i = 0; i < options.length(); i++)
				if ((toupper(options.at(i))) == toupper(input))
				{
					found = true;
					break;
				}
			if (found)
			{
				cin.clear();
				cin.ignore(999, '\n');
				break;
			}
			else
				cout << "ERROR: Invalid input. Must be one of '" << options << "' character.\n";
		}
	} while (true);
	return toupper(input);
}

//PreCondition: valid yes (char) or no (char)
//PostCondition: returns an uppercase  yes (char) or no (char) 
char inputChar(string prompt, char yes, char no)
{
	char input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			cout << "ERROR: Invalid input. Must be a character type.\n";
			cin.clear();
			cin.ignore(999, '\n');
		}
		else if (tolower(input) != tolower(yes) && tolower(input) != tolower(no))
			cout << "ERROR: Invalid input. Must be a '" << static_cast<char>(toupper(yes)) << "' or '" << static_cast<char>(toupper(no)) << "' character.\n";
		else
		{
			cin.clear();
			cin.ignore(999, '\n');
			break;
		}
	} while (true);
	return toupper(input);
}

//PreCondition: alphaOrDigit (boolean true or false)
//PostCondition: returns an alphabet or a digit character
char inputChar(string prompt, bool alphaOrDigit)
{
	char input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			cout << "ERROR: Invalid input. Must be a character type.\n";
			cin.clear();
			cin.ignore(999, '\n');
		}
		else if (alphaOrDigit && !isalpha(input))
			cout << "ERROR: Invalid input. Must be an alphabet character.\n";
		else if (!alphaOrDigit && !isdigit(input))
			cout << "ERROR: Invalid input. Must be a digit character.\n";
		else
		{
			cin.clear();
			cin.ignore(999, '\n');
			break;
		}
	} while (true);
	return input;
}

//PreCondition: NA
//PostCondition: returns any character
char inputChar(string prompt)
{
	char input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			cout << "ERROR: Invalid input. Must be a character type.\n";
			cin.clear();
			cin.ignore(999, '\n');
		}
		else
			break;
	} while (true);
	cin.clear();
	cin.ignore(999, '\n');
	return toupper(input);
}

//PreCondition: NA
//PostCondition: returns any integer value
int inputInteger(string prompt)
{
	int input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			cout << "ERROR: Invalid input. Must be an integer type.\n";
			cin.clear();
			cin.ignore(999, '\n');
		}
		else
			break;
	} while (true);
	cin.clear();
	cin.ignore(999, '\n');
	return input;
}

//PreCondition: posNeg (boolean true or false)
//PostCondition: returns a positive integer value (posNeg = true) or a negative integer value (poseNeg = false)
int inputInteger(string prompt, bool posNeg)
{
	int input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			cout << "ERROR: Invalid input. Must be an integer type.\n";
			cin.clear();
			cin.ignore(999, '\n');
		}
		else if (posNeg && input <= 0)
			cout << "ERROR: Invalid input. Must be a positive number.\n";
		else if (!posNeg && input >= 0)
			cout << "ERROR: Invalid input. Must be a negative number.\n";
		else
			break;
	} while (true);
	cin.clear();
	cin.ignore(999, '\n');
	return input;
}

//PreCondition: start (integer) and greater (boolean true or false)
//PostCondition: returns an integer value greater than start or lesser than start
int inputInteger(string prompt, int start, bool greater)
{
	int input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			cout << "ERROR: Invalid input. Must be an integer type.\n";
			cin.clear();
			cin.ignore(999, '\n');
		}
		else if (greater && input < start)
			cout << "ERROR: Invalid input. Must be a greater than or equal to " << start << ".\n";
		else if (!greater && input > start)
			cout << "ERROR: Invalid input. Must be a lesser than or equal to " << start << ".\n";
		else
			break;
	} while (true);
	cin.clear();
	cin.ignore(999, '\n');
	return input;
}

//PreCondition: startRange (integer) and endRange (integer)
//PostCondition: returns an integer value within range (startRannge and endRange)
int inputInteger(string prompt, int startRange, int endRange)
{
	int input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			cout << "ERROR: Invalid input. Must be an integer type.\n";
			cin.clear();
			cin.ignore(999, '\n');
		}
		else if (!(input >= min(startRange, endRange) && input <= max(startRange, endRange)))
			cout << "ERROR: Invalid input. Must be from " << startRange << ".." << endRange << ".\n";
		else
			break;
	} while (true);
	cin.clear();
	cin.ignore(999, '\n');
	return input;
}

//PreCondition: NA
//PostCondition: returns any double value
double inputDouble(string prompt)
{
	double input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			cout << "ERROR: Invalid input. Must be a double type.\n";
			cin.clear();
			cin.ignore(999, '\n');
		}
		else
			break;
	} while (true);
	cin.clear();
	cin.ignore(999, '\n');
	return input;
}

//PreCondition: posNeg (boolean true or false)
//PostCondition: returns a positive double value (posNeg = true) or a negative double value (poseNeg = false)
double inputDouble(string prompt, bool posNeg)
{
	double input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			cout << "ERROR: Invalid input. Must be a double type.\n";
			cin.clear();
			cin.ignore(999, '\n');
		}
		else if (posNeg && input <= 0.0)
			cout << "ERROR: Invalid input. Must be a positive number.\n";
		else if (!posNeg && input >= 0.0)
			cout << "ERROR: Invalid input. Must be a negative number.\n";
		else
			break;
	} while (true);
	cin.clear();
	cin.ignore(999, '\n');
	return input;
}

//PreCondition: start(integer) and greater(boolean true or false)
//PostCondition: returns an integer value greater than start or lesser than start
double inputDouble(string prompt, double start, bool posNeg)
{
	double input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			cout << "ERROR: Invalid input. Must be a double type.\n";
			cin.clear();
			cin.ignore(999, '\n');
		}
		else if (posNeg && input <= start)
			cout << "ERROR: Invalid input. Must be greater than or equal to " << start << ".\n";
		else if (!posNeg && input >= start)
			cout << "ERROR: Invalid input. Must be lesser than or equal to " << start << ".\n";
		else
			break;
	} while (true);
	cin.clear();
	cin.ignore(999, '\n');
	return input;
}

//PreCondition: startRange (integer) and endRange (integer)
//PostCondition: returns an integer value within range (startRannge and endRange)
double inputDouble(string prompt, double startRange, double endRange)
{
	double input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			cout << "ERROR: Invalid input. Must be a double type.\n";
			cin.clear();
			cin.ignore(999, '\n');
		}
		else if (!(input >= min(startRange, endRange) && input <= max(startRange, endRange)))
			cout << "ERROR: Invalid input. Must be from " << startRange << ".." << endRange << ".\n";
		else
			break;
	} while (true);
	cin.clear();
	cin.ignore(999, '\n');
	return input;
}

//PreCondition: NA
//PostCondition: returns a valid date
string inputDate(string prompt)
{
	string input = "";
	do
	{
		cout << prompt;
		getline(cin, input);
		if (input.length() != 10)
			cout << "ERROR: Invalid input. Must be in the format of mm/dd/yyyy.\n";
		else if (input.at(2) != '/' || input.at(5) != '/')
			cout << "ERROR: Invalid input. Must be in the format of mm/dd/yyyy.\n";
		else if (!isdigit(input.at(0)) || !isdigit(input.at(1)) || !isdigit(input.at(3)) || !isdigit(input.at(4)) || !isdigit(input.at(6)) || !isdigit(input.at(7)) || !isdigit(input.at(8)) || !isdigit(input.at(9)))
			cout << "ERROR: Invalid input. Must be in the format of mm/dd/yyyy.\n";
		else
		{
			int month = stoi(input.substr(0, 2));
			int day = stoi(input.substr(3, 2));
			int year = stoi(input.substr(6, 4));
			if (month < 1 || month > 12)
				cout << "ERROR: Invalid input. Must be in the format of mm/dd/yyyy.\n";
			else if (day < 1 || day > 31)
				cout << "ERROR: Invalid input. Must be in the format of mm/dd/yyyy.\n";
			else if (year < 1900 || year > 2100)
				cout << "ERROR: Invalid input. Must be in the format of mm/dd/yyyy.\n";
			else
				break;
		}
	} while (true);
	return input;
}

// Precondition: NA
// Postcondition: returns a valid time
string inputTime(string prompt)
{
	string input = "";
	do
	{
		cout << prompt;
		getline(cin, input);
		if (input.length() != 5)
			cout << "ERROR: Invalid input. Must be in the format of hh:mm.\n";
		else if (input.at(2) != ':')
			cout << "ERROR: Invalid input. Must be in the format of hh:mm.\n";
		else if (!isdigit(input.at(0)) || !isdigit(input.at(1)) || !isdigit(input.at(3)) || !isdigit(input.at(4)))
			cout << "ERROR: Invalid input. Must be in the format of hh:mm.\n";
		else
		{
			int hour = stoi(input.substr(0, 2));
			int minute = stoi(input.substr(3, 2));
			if (hour < 0 || hour > 23)
				cout << "ERROR: Invalid input. Must be in the format of hh:mm.\n";
			else if (minute < 0 || minute > 59)
				cout << "ERROR: Invalid input. Must be in the format of hh:mm.\n";
			else
				break;
		}
	} while (true);
	return input;
}

// Precondition: NA
// Postcondition: returns a valid boolean value
bool inputBoolean(string prompt)
{
	int input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			cout << "ERROR: Invalid input. Must be an integer type.\n";
			cin.clear();
			cin.ignore(999, '\n');
		}
		else if (input != 0 && input != 1)
			cout << "ERROR: Invalid input. Must be 0 or 1.\n";
		else
			break;
	} while (true);
	cin.clear();
	cin.ignore(999, '\n');
	return input;
}
