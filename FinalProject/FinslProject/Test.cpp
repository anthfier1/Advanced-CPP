// This program allows the user to see 3 different car manufactures most iconic cars as well as putting in the information about their own car.
// The user also has an option allowing the user to compare the three different cars as well as comparing the cars to their car in a drag racing setting
// and it will output a prediction of what car will win. 
// DUE : 5/10/18
// Anthony Fierro

#include "Cars.h"
#include "Chevy.h"
#include "Subaru.h"
#include "Nissan.h"
#include "UsersCar.h"
#include <iostream>
#include <string>
using namespace std;

void printMenu();
void getUserCarValues(string &, int &, int &, int &, string &, string &);

enum { CHEVY, SUBARU, NISSAN, USERCAR, COMPARE, QUIT };

int main() {

	char goAgain = 'y';
	Chevy camaro;
	Subaru impreza;
	Nissan gtr;
	UserCar usersCar;
	string userModel, userAspiration, userDriveType, badChoice = "Invalid choice. Try again: ";
	int userHp, userWeight, userCylinders, choice, compare;
	bool tryAgain, again = true;


	do {
		compare = 0;
		choice = 0;
		tryAgain = true;

		printMenu();

		cout << "Please type the number of the option you'd like to choose: ";
		// have the user enter the choice they want if it is outside of the range it throws an exception

		while (tryAgain) {
			try {
				cin >> choice;
				tryAgain = false;

				if (choice > 6 || choice < 0)
					throw badChoice;
			}
			catch (string badChoice) {
				cout << badChoice ;
				tryAgain = true;

			}
		}

		// with cases 1 - 5 allow the user to look at different model cars or have them make their own as well as compare them. 
		switch (choice)
		{
		case CHEVY + 1:  camaro.showDetails(camaro);cout << endl << endl; break;
		case SUBARU + 1: impreza.showDetails(impreza); cout << endl << endl; break;
		case NISSAN + 1: gtr.showDetails(gtr); cout << endl << endl; break;
		case USERCAR + 1: cin >> usersCar; usersCar.showDetails(usersCar); cout << endl << endl; break;
		case COMPARE + 1: {

			// if the user chooses to compare they have an option of what cars they like to see compared. 
			cout
				<< "Which two cars would you like to compare?/n "
				<< "\n\n\t 6) Chevrolete vs. Subaru \n"
				<< "\t 7) Chevrolete vs. Nissan \n"
				<< "\t 8) Chevrolete vs. your own car (if you've entered one) \n"
				<< "\t 9) Subaru vs. Nissan \n"
				<< "\t 10) Subaru vs. your own car (if you've entered one) \n"
				<< "\t 11) Nissan vs. your own car (if you've entered one) \n";
			cin >> compare;
			switch (compare) {
			case 6: camaro.comparison(camaro, impreza); break;
			case 7: camaro.comparison(camaro, gtr); break;
			case 8: camaro.comparison(camaro, usersCar); break;
			case 9: impreza.comparison(impreza, gtr); break;
			case 10: impreza.comparison(impreza, usersCar); break;
			case 11: gtr.comparison(gtr, usersCar); break;
			default: break;
			}

		}break;

		case QUIT + 1: cout << "Quitting the program."; system("pause"); return 0;

		}
		cout << "Do you want to make another choice? (Y/N): "; cin >> goAgain;
		while (goAgain != 'y' && goAgain != 'Y' && goAgain != 'N' && goAgain != 'n')
		{
			cout << "Try again: "; cin >> goAgain;
		}
		if (goAgain == 'y' || goAgain == 'Y')
			again = true;
		else if (goAgain == 'n' || goAgain == 'N')
			again = false;

	} while (again == true);



	system("Pause");
	return 0;

}

void printMenu() {

	cout
		<< "\t Please select the option you'd like see : \n"
		<< "\t 1) Display Chevroletes most iconic car. \n"
		<< "\t 2) Display Subarus most iconic car. \n"
		<< "\t 3) Display Nissans most iconic car. \n"
		<< "\t 4) Input the in the details of your own car. \n"
		<< "\t 5) Compare two cars to see which one would win a drag race setting\n"
		<< "\t 6) Quit \n";
}

void getUserCarValues(string &name, int &hp, int &cyl, int &weight, string &aspir, string &drive)
{
	cout << "\n\t Enter the model name of your car: "; getline(cin >> ws, name);
	cout << "\n\t Enter the horsepower of your car: "; cin >> hp;
	cout << "\n\t Enter the number of cylinders your car has : "; cin >> cyl;
	cout << "\n\t Enter the weight of your car: "; cin >> weight;
	cout << "\n\t Enter the aspiration type of your car: "; getline(cin >> ws, aspir);
	cout << "\n\t Enter the drive type of your car:\n ex) real wheel drive, all wheel drive, front wheel drive : "; getline(cin >> ws, drive);

}
