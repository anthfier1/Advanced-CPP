// Anthony Fierro

#include "Cars.h"
#include <iostream>
#include <string>
using namespace std;

Cars::Cars()
{
}


Cars::Cars(int year, string name, int cylinders, int hp, int carWeight, string aspir, string drive)
{
	modelYear = year;
	modelName = name;
	engineSize = cylinders;
	horsepower = hp;
	weight = carWeight;
	aspiration = aspir;
	driveType = drive;

}

Cars::~Cars()
{
}

void Cars::setModelYear(int year) {
	modelYear = year;
	if (modelYear < 1901 || modelYear > 2018) {
		year = 0;
		throw  BadInput("bad Input");
	}
}

void Cars::setModelName(string name) { modelName = name; }

void Cars::setEngineSize(int cyl) {
	engineSize = cyl;
	if (engineSize != 4 && engineSize != 5 && engineSize != 6 && engineSize != 8 && engineSize != 10 && engineSize != 12)
		throw  BadInput("bad Input");
}

void Cars::setHorsepower(int hp) {
	horsepower = hp;
	if ((horsepower >= 'a' && horsepower <= 'z') && horsepower >= 'A' && horsepower <= 'Z')
		throw  BadInput("bad Input");
	if (horsepower < 85 || horsepower > 1000)
		throw  BadInput("bad Input");
}

void Cars::setWeight(int w)
{
	weight = w;
	if (weight >= 'a' && weight <= 'z' && weight >= 'A' && weight <= 'Z')
		throw  BadInput("bad Input");
	if (weight < 1750 || weight > 4500)
		throw  BadInput("bad Input");
}

void Cars::setAspirationType(string aspir)
{
	aspiration = aspir;
	if (aspiration != "turbo charged" && aspiration != "twin turbo charged" && aspiration != "super charged" && aspiration != "naturally aspirated")
		throw BadInput("bad Input");
}

void Cars::setDriveType(string drive) {
	driveType = drive;
	if (driveType != "all wheel drive" && driveType != "rear wheel drive" && driveType != "front wheel drive")
		throw  BadInput("bad Input");
}

bool Cars::operator>(Cars &right)
{

	int comparisonPoints = 0;

	if (this != &right)
	{


		if (engineSize - 2 > right.engineSize)
			comparisonPoints++;
		if (engineSize - 2 == right.engineSize && horsepower - 75 > right.horsepower)
			comparisonPoints++;
		if (horsepower - 50 > right.horsepower)
			comparisonPoints++;
		if (weight + 300 < right.weight)
			comparisonPoints++;
		if (weight + 300 > right.weight && horsepower - 100 > right.horsepower)
			comparisonPoints++;
		if ((aspiration == "turbo charged") || ((aspiration) == "super charged") || (aspiration == " twin turbo charged") && horsepower - 75 > right.horsepower)
			comparisonPoints++;
		if (aspiration == "naturally aspirated" && horsepower - 75 > right.horsepower)
			comparisonPoints++;
		if (driveType == "rear wheel drive" || (driveType == " all wheel drive" && horsepower > right.horsepower))
			comparisonPoints++;

		if (comparisonPoints >= 3)
			return true;
		else
			return false;
	}
}

void Cars::comparison(const Cars & car1, const Cars & car2)
{
	if (&car1 < &car2)
		cout << "The " << car1.modelName << " would win in a drag race against the " << car2.modelName << "." << endl;
	else
		cout << "The " << car2.modelName << " would win in a drag race against the " << car1.modelName << "." << endl;


}


istream & operator>>(istream &is, Cars &car)
{
	bool yearAgain, hpAgain, cylAgain, wAgain, aspAgain, driveAgain;
	yearAgain = hpAgain = cylAgain = wAgain = aspAgain = driveAgain = true;

	cout << "\n\tEnter the model year of your car : ";
	while (yearAgain) {
		try {
			if (is >> car.modelYear) {
				car.setModelYear(car.modelYear);
				yearAgain = false;
			}
			else {
				is.clear();
				is.ignore(100, '\n');
				throw Cars::BadInput("Bad Input");
			}
		}
		catch (Cars::BadInput &e) {

			cout << "Invalid input. Please enter a year from 1901 - 2018: ";
			yearAgain = true;
		}
	}

	cout << "\n\t Enter the model name of your car: ";
	getline(is >> ws, car.modelName);
	car.setModelName(car.modelName);


	cout << "\n\t Enter the horsepower of your car: ";
	while (hpAgain) {
		try {
			is >> car.horsepower;
			car.setHorsepower(car.horsepower);
			hpAgain = false;
		}
		catch (Cars::BadInput &e) {

			cout << " Please enter a range from 85 - 1000. ";
			hpAgain = true;
		}
	}

	cout << "\n\t Enter the number of cylinders your car has : ";
	while (cylAgain)
	{
		try {
			is >> car.engineSize;
			car.setEngineSize(car.engineSize);
			cylAgain = false;
		}
		catch (Cars::BadInput &e) {

			cout << " Please enter 4, 5, 6, 8, 10 or 12. ";
			cylAgain = true;
		}
	}

	cout << "\n\t Enter the weight (in pounds) of your car: ";
	while (wAgain)
		try {
		is >> car.weight; car.setWeight(car.weight); wAgain = false;
	}
	catch (Cars::BadInput &e) {

		cout << " Please enter a range from 1750 - 4500. ";
		wAgain = true;
	}

	cout << "\n\t Enter the aspiration type of your car. \n" << "\tEnter natuarlly aspirated, turbo charged, twin turbo charged, or supercharged: ";
	while (aspAgain) {
		try {
			getline(is >> ws, car.aspiration);
			car.setAspirationType(car.aspiration);
			aspAgain = false;
		}
		catch (Cars::BadInput &e) {

			cout << "\tPlease enter natuarlly aspirated, turbo charged, twin turbo charged, or supercharged: ";
			aspAgain = true;
		}
	}
	cout << "\n\t Enter the drive type of your car:\n ex) rear wheel drive, all wheel drive, front wheel drive : ";
	while (driveAgain) {
		try {
			getline(is >> ws, car.driveType);
			car.setDriveType(car.driveType);
			driveAgain = false;
		}
		catch (Cars::BadInput &e) {
			cout << "\tPlease enter all wheel drive, rear wheel drive, or front wheel drive: ";
			driveAgain = true;
		}
	}
	return is;
}
