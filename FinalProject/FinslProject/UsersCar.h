// Anthony Fierro

#pragma once
#ifndef USERSCAR_H
#define USERSCAR_H

#include "Cars.h"
#include <iostream>
#include <string>
using namespace std;

class UserCar : public Cars
{
public:
	UserCar();
	UserCar(int, string, int, int, int, string, string);
	~UserCar();
	virtual void showDetails(Cars &) override;



private:

};

#endif // !USERSCAR_H
