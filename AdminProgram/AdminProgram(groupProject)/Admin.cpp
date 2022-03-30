//
//
//
//


#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "Password.h"
using namespace std;

// Use this enum to decode where items are in the sales array.
enum menu { DONUT, BAGEL, ALFAJORES, CHURRO, PICARONE, CHOCOLATE_COOKIE, SUGAR_COOKIE, BROWNIE, CHOCOLATE_CAKE, CARROT_CAKE };

struct ItemSales {

	double
		quantityMade,
		quantitySold,
		quantityRevenue;

};


struct DailySales {


	// Item Sales array
	ItemSales * itemSalesArr;
	int arraySize; // This will be 10

	DailySales() {
		arraySize = 10;
		DailySales::itemSalesArr[arraySize];
	}



	// Payments received (all expressed in USD value)
	double
		paymentsUSD,
		paymentsEUR,
		paymentsPEN,
		paymentsCreditCard;
};


void makeNewPassword(Password &password, string newPassword, fstream &readWritePasswordFile, const string passwordFileName);
void enterPassword(Password & password, fstream & readWritePasswordFile, const string passwordFileName);
void printHeader();

int main() {
	DailySales *salesArr{ 0 };
	Password password;
	string newPassword, tempPassword, passwordCheck, passwordFileName = "AdminPassword.txt", binaryFile = "AdminBinaryFile.txt";
	fstream readWritePasswordFile, bfile;
	int numOfDays = 0;


	readWritePasswordFile.open(passwordFileName, ios::in);
	if (readWritePasswordFile.fail()) { // if there is no file already made, the admin has not made a pword yet, so we have to have them create one

		cout
			<< "\tCreate a password that is 6-15 characters long with 1 uppercase letter, 1 lowercase letter, " << endl
			<< "\t1 digit, and 1 og these special characters [!, @, #, $, %] " << endl;

		cout << "\tMake a password to access the admin files:  ";

		makeNewPassword(password, newPassword, readWritePasswordFile, passwordFileName);
	}

	else if (readWritePasswordFile.good()) { // if there is a file already, the admin already made a password. 
		cout << "\tWelcome back!" << endl << "\tEnter your password : ";

		enterPassword(password, readWritePasswordFile, passwordFileName);
	}

	;
	;

	printHeader();

	bfile.open(binaryFile, ios::in | ios::binary);


	for (int i = 0; i < salesArr->arraySize; i++) {
		bfile.read(reinterpret_cast<char*> (&salesArr[i].itemSalesArr[i].quantityMade), sizeof(salesArr[i].itemSalesArr[i].quantityMade));
		bfile.read(reinterpret_cast<char*> (&salesArr[i].itemSalesArr[i].quantitySold), sizeof(salesArr[i].itemSalesArr[i].quantitySold));
		bfile.read(reinterpret_cast<char*> (&salesArr[i].itemSalesArr[i].quantityRevenue), sizeof(salesArr[i].itemSalesArr[i].quantityRevenue));
	}
	bfile.read(reinterpret_cast<char*> (&salesArr[i].paymentsUSD), sizeof(salesArr[i].paymentsUSD));
	bfile.read(reinterpret_cast<char*> (&salesArr[i].paymentsEUR), sizeof(salesArr[i].paymentsEUR));
	bfile.read(reinterpret_cast<char*> (&salesArr[i].paymentsPEN), sizeof(salesArr[i].paymentsPEN));
	bfile.read(reinterpret_cast<char*> (&salesArr[i].paymentsCreditCard), sizeof(salesArr[i].paymentsCreditCard));

	numOfDays++;

	while (bfile.good())
	{
		for (int i = 0; i < salesArr->arraySize; i++) {

			bfile.read(reinterpret_cast<char*> (&salesArr[i].itemSalesArr[i].quantityMade), sizeof(salesArr[i].itemSalesArr[i].quantityMade));
			bfile.read(reinterpret_cast<char*> (&salesArr[i].itemSalesArr[i].quantitySold), sizeof(salesArr[i].itemSalesArr[i].quantitySold));
			bfile.read(reinterpret_cast<char*> (&salesArr[i].itemSalesArr[i].quantityRevenue), sizeof(salesArr[i].itemSalesArr[i].quantityRevenue));
		}
		bfile.read(reinterpret_cast<char*> (&salesArr[i].paymentsUSD), sizeof(salesArr[i].paymentsUSD));
		bfile.read(reinterpret_cast<char*> (&salesArr[i].paymentsEUR), sizeof(salesArr[i].paymentsEUR));
		bfile.read(reinterpret_cast<char*> (&salesArr[i].paymentsPEN), sizeof(salesArr[i].paymentsPEN));
		bfile.read(reinterpret_cast<char*> (&salesArr[i].paymentsCreditCard), sizeof(salesArr[i].paymentsCreditCard));

		numOfDays++;

	}
	cout << "There are " << numOfDays << " worth of sales in the file";
	// make new item array read same as ^^
	DailySales *itemArr[numOfDays];
	// print out the array with flipped axis or make a legend x/y/z.
	//make function that prints out specific items of specific days.
	//
	//


	system("pause");
	return 0;
}


void makeNewPassword(Password & password, string newPassword, fstream &readWritePasswordFile, const string passwordFileName)
{
	bool again = true;

	while (again) {
		try {

			getline(cin >> ws, newPassword);      // hold the new password in a string
			password.setPassword(newPassword);    // set the new password to the class password
			again = false;
		}
		catch (Password::InvalidPassword &e) {

			cout << e.getInvalidParameters() << endl;

			password.reportInvalidParameters();
			cout << "\n\tEnter a password with the correct parameters: ";
			again = true;
		}
	}
	// once the password is correctly made we open a binary file and store the password in it for later reference
	readWritePasswordFile.open(passwordFileName, ios::out);
	if (readWritePasswordFile.fail())
		cout << "failed to open the file";

	readWritePasswordFile << newPassword;

	cout << "\n\tPassword saved!\n";
	system("pause");
	system("cls");
	readWritePasswordFile.close();
}

void enterPassword(Password & password, fstream & readWritePasswordFile, const string passwordFileName)
{
	string passwordCheck, tempPassword;
	bool again = true;
	while (again) {
		try {
			getline(cin >> ws, tempPassword); // put the users input into a temp pword
			getline(readWritePasswordFile, passwordCheck);
			password.setPassword(passwordCheck); // set the password from the file to the actual password
			password.matchPassword(tempPassword); // see if the two passwords match.
			again = false;
		}
		catch (Password::InvalidPassword &e) {
			cout << "\tInvalid password. Try again: ";
			again = true;
		}

		readWritePasswordFile.close();
		cout << "\n\tSuccessfully logged in." << endl;
		system("pause");
		system("cls");
	}
}


void printHeader() {

	const int WIDTH = 8;
	cout << setw(WIDTH) << "       Donuts";
	cout << setw(10) << "Bagels";
	cout << setw(WIDTH) << "  Alfajores";
	cout << setw(10) << "Churros";
	cout << setw(WIDTH) << "  Picarone";
	cout << setw(10) << "   ChocolateCookie";
	cout << setw(WIDTH) << "  SugarCookie";
	cout << setw(10) << "Brownie";
	cout << setw(WIDTH) << " ChocolateCake";
	cout << setw(WIDTH) << " CarrotCake";
	/*cout << "Revenue" << setw(WIDTH);
	cout << "USD Payment" << setw(WIDTH);
	cout << "EUR Payment" << setw(WIDTH);
	cout << "PEN Payment" << setw(WIDTH);
	cout << "Credit Card Payment" << setw(WIDTH);*/



	cout << endl;
}
