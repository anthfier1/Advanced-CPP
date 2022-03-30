// Anthony Fierro

#pragma once
#ifndef CARS_H
#define CARS_H


#include <iostream>
#include <string>
using namespace std;


class Cars
{
private:


protected:
	int modelYear, engineSize, horsepower, weight;
	string aspiration, driveType, modelName;

public:
	// points to tally which car will win in the drag racing setting
	static int comparisonPoints;

	// constructors and deconstructor
	Cars();

	Cars(int, string, int, int, int, string, string);

	~Cars();

	// setters
	void setModelYear(int);

	void setModelName(string);

	void setEngineSize(int);

	void setHorsepower(int);

	void setWeight(int);

	void setAspirationType(string);

	void setDriveType(string);

	// getters 

	virtual int getModelYear() { return modelYear; }

	virtual string getModelName() { return modelName; }

	virtual int getEngineSize() { return engineSize; }

	virtual int getHorsepower() { return horsepower; }

	virtual int getWeight() { return weight; }

	virtual string getAspirationType() { return aspiration; }

	virtual string getDriveType() { return driveType; }

	// overloaded operators
	friend istream& operator >>(istream& is, Cars &);

	bool operator> (Cars &right);

	// static comparison function to compare 2 cars
	static void comparison(const Cars &car1, const Cars &car2);

	// pure virtual function to show details of the cars. 
	virtual void showDetails(Cars &car) = 0;


	// exception class to catch an exception
	class BadInput {

	public:

		string invalidInput;
		BadInput(string error) { invalidInput = error; }


	};


#endif // !CARS_H

};