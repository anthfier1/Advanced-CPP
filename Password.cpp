/*
Matthew Burckardt
CIT 237 Group 5 : Youssef Sajid / Matthew Burckardt / Anthony Fierro
3/13/18
*/

#include "Password.h"
#include <sstream>




bool Password::checkValidity() {

	// Checks for required characters
	// This phrasing reduces work performed: as soon as an invalid parameter is found, the other OR CONDITIONS are skipped and return false is executed
	if (!isValidLength() || !isValidUpper() || !isValidLower() || !isValidDigit() || !isValidSpecial())
		return false;

	// Checks for illegal characters.
	// If unequal, illegal characters are present in the password.
	if (validityParameters[LENGTH] == (validityParameters[UPPER] + validityParameters[LOWER] + validityParameters[DIGIT] + validityParameters[SPECIAL]))
		return true;
	else
		return false;

}

string Password::reportInvalidParameters() {
	stringstream msg;
	if (!isValidLength())
		msg << "\n\tInvalid length (" << validityParameters[LENGTH] << "). Must be between " << LENGTH_MIN << " and " << LENGTH_MAX << ".";
	if (!isValidUpper())
		msg << "\n\tInvalid number of uppercase characters (" << validityParameters[UPPER] << "). Must be at least " << UPPER_MIN << ".";
	if (!isValidLower())
		msg << "\n\tInvalid number of lowercase characters (" << validityParameters[LOWER] << "). Must be at least " << LOWER_MIN << ".";
	if (!isValidDigit())
		msg << "\n\tInvalid number of digit characters (" << validityParameters[DIGIT] << "). Must be at least " << DIGIT_MIN << ".";
	if (!isValidSpecial())
		msg << "\n\tInvalid number of special characters (" << validityParameters[SPECIAL] << "). Must be at least " << SPECIAL_MIN << ".";
	if (validityParameters[LENGTH] != (validityParameters[UPPER] + validityParameters[LOWER] + validityParameters[DIGIT] + validityParameters[SPECIAL])) {
		int illegalChars = validityParameters[LENGTH] - (validityParameters[UPPER] + validityParameters[LOWER] + validityParameters[DIGIT] + validityParameters[SPECIAL]);
		msg << "\n\tPassword contained (" << illegalChars << ") illegal characters.";
	}

	return msg.str();
}

void Password::setPassword(string pw) {
	Password::password = pw;
	updateValidityParameters();
	isValid = checkValidity();

	// Exception integrated 4/4/18
	if (!isValid) {
		Password::password = "";
		throw InvalidPassword(reportInvalidParameters());
	}
}

Password::Password() {}

Password::Password(string pw) {
	setPassword(pw);
}

// COUNTERS ===========================================

// Calls all counters
void Password::updateValidityParameters() {

	Password::countLength();
	Password::countUpper();
	Password::countLower();
	Password::countDigit();
	Password::countSpecial();
}

// ---

void Password::countLength() {
	int counter = 0;
	for (int i = 0; i < password.length(); i++) {
		counter++;
	}
	validityParameters[LENGTH] = counter;
}

void Password::countUpper() {
	int counter = 0;
	for (int i = 0; i < password.length(); i++) {
		if (password[i] >= 'A' && password[i] <= 'Z')
			counter++;
	}
	validityParameters[UPPER] = counter;
}

void Password::countLower() {
	int counter = 0;
	for (int i = 0; i < password.length(); i++) {
		if (password[i] >= 'a' && password[i] <= 'z')
			counter++;
	}
	validityParameters[LOWER] = counter;
}

void Password::countDigit() {
	int counter = 0;
	for (int i = 0; i < password.length(); i++) {
		if (password[i] >= '0' && password[i] <= '9')
			counter++;
	}
	validityParameters[DIGIT] = counter;
}

void Password::countSpecial() {
	int counter = 0;
	for (int i = 0; i < password.length(); i++) {
		if (isSpecial(password[i]))
			counter++;
	}
	validityParameters[SPECIAL] = counter;
}


// -----------------------------------------------------

bool Password::isSpecial(char ch) {
	for (int i = 0; i < strlen(SPECIAL_CHARS); i++)
		if (ch == SPECIAL_CHARS[i])
			return true;
	return false;
}


// VALIDATORS ===========================================

bool Password::isValidLength() {
	if (validityParameters[LENGTH] < LENGTH_MIN || validityParameters[LENGTH] > LENGTH_MAX)
		return false;

	return true;
}

bool Password::isValidUpper() {
	if (validityParameters[UPPER] < UPPER_MIN)
		return false;

	return true;
}

bool Password::isValidLower() {
	if (validityParameters[LOWER] < LOWER_MIN)
		return false;

	return true;
}

bool Password::isValidDigit() {
	if (validityParameters[DIGIT] < DIGIT_MIN)
		return false;

	return true;
}

bool Password::isValidSpecial() {
	if (validityParameters[SPECIAL] < SPECIAL_MIN)
		return false;

	return true;

}
bool Password::isLegalCharacters() {
	if (validityParameters[LENGTH] == (validityParameters[UPPER] + validityParameters[LOWER] + validityParameters[DIGIT] + validityParameters[SPECIAL]))
		return true;

	return false;
}








