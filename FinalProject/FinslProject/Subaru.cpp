// Anthony Fierro

#include "Cars.h"
#include "Subaru.h"
#include <iostream>
#include <string>
using namespace std;


Subaru::Subaru()
{
	modelYear = 1999;
	modelName = "Impreza 22B STi";
	engineSize = 4;
	horsepower = 225;
	weight = 2745;
	aspiration = "turbo charged";
	driveType = "all wheel drive";
}

Subaru::~Subaru() {}

void Subaru::showDetails(Cars &car)
{
	cout
		<< "Model Name: " << car.getModelName() << endl
		<< "The " << car.getModelYear() << " " << car.getModelName() << " has a(n) " << car.getEngineSize() << " cylinder " << car.getAspirationType() << "engine." << endl
		<< " With " << car.getHorsepower() << " horsepower, and is " << car.getDriveType() << ". " << endl;
}
