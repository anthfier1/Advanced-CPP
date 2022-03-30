/* You are developing a software package that requires users to enter their own passwords.
Your software requires that user passwords meet the following criteria:
the password should be at least 6 characters long and no more than 15 characters
the password should contain at least one uppercase and at at least one lowercase letter
the password should have at least one digit.
the password should contain one of the following characters: ! @ # $ % but no other special characters
Write a program that asks the user for a password and verifies that it meets the stated criteria.
If it doesn't, the program should display a message telling the user why. Your program should allow the user to try again if their password is not valid.*/
// Anthony Fierro
// 1/28/18

#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

void printBanner(ostream &output = cout);
char *getPassword(char password[]); 
void checkRequirments(const char password[], bool &upper, bool &lower, bool &digit, bool &specialChar);
void printError(const char password[], bool upper, bool lower, bool digit, bool specialChar, ostream &output = cout);

int main()
{
	char *password; 
	password = nullptr;
	bool upper = false, lower = false, digit = false, specialChar = false; // im using bool variables as flags to show that the requirments are met
	password = new char[NULL];


	printBanner();

	while (upper == false || lower == false || digit == false || specialChar == false || strlen(password) < 6 || strlen(password) > 15) // while atleast one of the requirments are not met the program will continue to loop 
	{
	
		cout << "\nEnter password: ";
		*password = *getPassword(password); // gets the users password

		checkRequirments(password, upper, lower, digit, specialChar); // checks to see if it meets all the requirments

		printError(password, upper, lower, digit, specialChar); // prints out any errors that user made reguarding the requirments

	}

	cout << "\nYour password has been verified.";
	
	delete[] password;
	password = nullptr;

	system("pause");
	return 0;
}

void printBanner(ostream & output)
{
	//ask the user for a password and show requirments
	output 
		<< "\nCreate your password."
		<< "\nPasswords must meet the following requirments:"
		<< "\n Your password must contain at least six characters."
		<< "\n Your password must contain at least one uppercase letter."
		<< "\n Your assword must contain at least one lowercase letter."
		<< "\n Your password must contain at least one digit."
		<< "\n Your password must contain at least one special character (! @ # $ %).";
}

char * getPassword(char password[])
{
	// have the user enter a password
	cin >> ws;
	cin.getline(password, 80);
	return password; // return the password to the char array
}

void checkRequirments(const char password[], bool &upper, bool &lower, bool &digit, bool &specialChar)
{

	// i used a boolean variable for each requirment to flag if the password has the correct requirments

	for (int i = 0; i < strlen(password); i++)
	{
		if (isupper(password[i]))
			upper = true;
		if (islower(password[i]))
			lower = true;
		if (isdigit(password[i]))
			digit = true;
		if (password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i] == '$' || password[i] == '%')
			specialChar = true;
	}
}

void printError(const char password[], bool upper, bool lower, bool digit, bool specialChar, ostream &output)
{

	// if the password does not equal at least 6 characters or is longer than 15 characters it will rint an error.
	// if one or more boolean variables return false the error message prints out with the specific requirment that they are missing in their password.

	if (strlen(password) < 6)
		output << "\n Your password needs to be at least six characters long.";
	if (strlen(password) > 15)
		output << "\n Your password must be no more than 15 characters long.";
	if (upper == false)
		output << "\n Your password does not contain at least one uppercase letter.";
	if (lower == false)
		output << "\n Your password does not contain at least one lowercase letter.";
	if (digit == false)
		output << "\n Your password does not have at least one digit.";
	if (specialChar == false)
		output << "\n Your password does not have at least one one special character";
}
