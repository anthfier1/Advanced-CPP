// Anthony Fierro

#include "Cars.h"
#include "Nissan.h"
#include <iostream>
#include <string>
using namespace std;


Nissan::Nissan()
{
	modelYear = 1999;
	modelName = "Skyline GT-R";
	engineSize = 6;
	horsepower = 276;
	weight = 3146;
	aspiration = "turbo charged";
	driveType = "all wheel drive";
}

Nissan::~Nissan() {}

void Nissan::showDetails(Cars &car)
{
	cout
		<< "Model Name: " << car.getModelName() << endl
		<< "The " << car.getModelYear() << " " << car.getModelName() << " has a(n) " << car.getEngineSize() << " cylinder " << car.getAspirationType() << "engine." << endl
		<< " With " << car.getHorsepower() << " horsepower, and is " << car.getDriveType() << ". " << endl;
}
