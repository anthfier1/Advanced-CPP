/*
	Matthew Burckardt
	CIT 237 Group 5 : Youssef Sajid / Matthew Burckardt / Anthony Fierro
	3/13/18
*/


#ifndef PASSWORD_H
#define PASSWORD_H

#include <string>
using namespace std;

// ==================================
// === ASSOCIATED CONSTANTS =========
// ==================================

// For use with validity parameters
enum PasswordValidity { LENGTH, UPPER, LOWER, DIGIT, SPECIAL };

// Array of (legal) special characters
const int SPECIAL_CHARS_SIZE = 5;
const char SPECIAL_CHARS[SPECIAL_CHARS_SIZE] = { '!', '@', '#', '$', '%' };

// 
const int
LENGTH_MAX = 15,
LENGTH_MIN = 6,
UPPER_MIN = 1,
LOWER_MIN = 1,
DIGIT_MIN = 1,
SPECIAL_MIN = 1;

// =====================================

class Password {

public:

	// Sets password and updates validity
	void setPassword(string pw);

	// Returns true/false if provided string matches/mismatches the actual password.
	bool matchPassword(string entry) { return entry == getPassword(); }

	// Getter
	bool getValidity() { return isValid; }

	// Explication
	string reportInvalidParameters();

	// Exception class - holds the error message string produced by Password::reportInvalidParameters()
	class InvalidPassword {
	private:
		string invalidParameters;
	public:
		InvalidPassword(string errorMessage) { invalidParameters = errorMessage; }
		string getInvalidParameters() { return invalidParameters; }
	};

	// Constructors

	Password();

	Password(string pw);


	// ===========================================================================

private:

	string password;
	bool isValid;
	int validityParameters[5]; // Tracks the validity parameters. If valid, vp[LENGTH] == ( vp[UPPER] + vp[LOWER] + vp[DIGIT] + vp[SPECIAL] )

	// *** 3/14/18 This constant moved outside of class.
	// Methods referencing this should use "strlen(SPECIAL_CHARS)"
	//const char SPECIAL_CHARS[5] = { '!', '@', '#', '$', '%' };
	// !!! Fix this later so that it's static and we don't have to create this array for every password object.


	// Counters: These functions count various sets of characters in the password string and save the count to validtyParameters[].

	void countLength();

	void countUpper();

	void countLower();

	void countDigit();

	void countSpecial();

	void updateValidityParameters(); // Utilizes all "count" methods

	// Validators (Check validityParameter[] values against requirement CONSTANTS)

	bool isValidLength();

	bool isValidUpper();

	bool isValidLower();

	bool isValidDigit();

	bool isValidSpecial();

	bool isLegalCharacters();

	// Utilizes SPECIAL_CHARS[]
	bool isSpecial(char ch);

	// Utilizes all other "isValid" methods
	bool checkValidity();

	// Private because we need to keep the password SECURE.
	string getPassword() { return password; }

};


#endif // !PASSWORD_H;