// Matthew Burckardt
// 2/13/2018
// CheckSum

/*
This program will process a user entered number of any given length

WITHOUT USING: arrays, vectors, or strings (this includes c-strings).

To work around this limitation, the input will be written to a file.
Once finished writting, the program will read the sequence of numbers:
first assessing length and then doubling every two digits FROM RIGHT TO LEFT.
*/

#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;


int main() {
	fstream flStream;
	char digit = ' '; // Processes user-entered digits
	int sum = 0; // The sum for check sum.
	int num = 0; // Holds the value of digit converted from char to int
	int count = 0; // Used to count number of digits
	bool debug = false; // Visualizes process in console output. Toggle FALSE for simplified ouput.


					   // Open file for output (implicitly overwrites)
	flStream.open("numFile.txt", ios::out);

	// This shouldn't be able to fail, but check.
	cout << (flStream.fail() ? "Somehow failed to create file to write to, idk man\n" : "Successfully created file to hold number.\n");

	// Read and write digits one by one
	cout << "Please enter a number for check sum analysis: ";
	cin.get(digit);

	while (isdigit(digit)) { //****** change the digit to understand better how this works replace with \n
		if(debug) cout << digit << " : good digit\n";
		flStream << digit;
		if(debug) cout << "wrote digit to file\n";
		cin.get(digit);
	}

	// Close file and re-open as file input
	flStream.close();
	if (debug) cout << "\nFile closed.";
	flStream.open("numFile.txt", ios::in);
	if (debug) cout << "\nFile opened for input.";

	// Check length of digit sequence
	count = 0;

	flStream.get(digit);
	while (flStream.good()) { // This will turn false once we reach the eof
		count++;
		if (debug) cout << "\nGot digit: " << digit << ". Incrementing digit count...";
		flStream.get(digit); // This is a dummy action to advance through the file. We're not doing anything with this data yet.

	}
	// Clean up file stream
	if (debug) cout << endl << (flStream.good() ? "File stream currently has no bad flags" : "File stream currently has a bad flag"); // Should be false
	flStream.clear(); // Reset flags.
	if (debug) cout << endl << (flStream.good() ? "File stream currently has no bad flags" : "File stream currently has a bad flag"); // Should be true
	flStream.seekg(ios::beg); // Return to start of file.


							  // Report count
	cout << "\nDigits in file: " << count;


	// Now that we know the length, we know which digits to double in value.
	// Recall that "sum" is our variable to hold the sum
	for (int i = 1; i < count + 1; i++) {
		flStream.get(digit);
		num = (digit - '0'); // Uses ASCII values to convert char to int
		if (debug) cout << "\nRead char " << digit << " as int " << num;
		if (debug) cout << "\nSum before increment: " << sum;

		// Even length: double every odd digit
		if (count % 2 == 0) {
			if (i % 2 != 0) // Odd numbers get doubled
				sum += num * 2;
			else
				sum += num;
		}

		// Odd length: double every even digit
		if (count % 2 != 0) {
			if (i % 2 == 0)
				sum += num * 2;
			else
				sum += num;

		}
		if (debug) cout << "..." << sum << " <- sum after increment.";

	}

	cout << "\nSum with appropriate digits doubled in value: " << sum;


	// Clean up
	cout << endl;
	system("pause");
	return 0;
}