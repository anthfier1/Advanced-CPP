// Anthony Fierro
#include "Cars.h"
#include "Chevy.h"
#include <iostream>
#include <string>
using namespace std;


Chevy::Chevy()
{
	modelYear = 2018;
	modelName = "Camaro ZL1";
	engineSize = 8;
	horsepower = 450;
	weight = 4113;
	aspiration = "naturally aspirated";
	driveType = "rear wheel drive";
}

Chevy::~Chevy() {}

void Chevy::showDetails(Cars &car)
{
	cout
		<< "Model Name: " << car.getModelName() << endl
		<< "The " << car.getModelYear() << " " << car.getModelName() << " has a(n) " << car.getEngineSize() << " cylinder " << car.getAspirationType() << "engine." << endl
		<< " With " << car.getHorsepower() << " horsepower, and is " << car.getDriveType() << ". " << endl;
}
