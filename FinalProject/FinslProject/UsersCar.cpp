// Anthony Fierro


#include "Cars.h"
#include "UsersCar.h"
#include <iostream>
#include <string>
using namespace std;


UserCar::UserCar(int year, string name, int cylinders, int hp, int carWeight, string aspir, string drive)
{
	modelYear = year;
	modelName = name;
	engineSize = cylinders;
	horsepower = hp;
	weight = carWeight;
	aspiration = aspir;
	driveType = drive;
}

UserCar::UserCar() {}

UserCar::~UserCar() {}



void UserCar::showDetails(Cars &car)
{
	cout
		<< "Model Name: " << car.getModelName() << endl
		<< "Your " << car.getModelYear() << " " << car.getModelName() << " has a(n) " << car.getEngineSize() << " cylinder engine " << endl
		<< "with " << car.getHorsepower() << " horsepower, that is " << car.getAspirationType() << " and is " << car.getDriveType() << endl;
}
